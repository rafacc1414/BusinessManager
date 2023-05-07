#include "CCustomersModel.hpp"
#include "GeneralTypes.hpp"

#include "gtest/gtest.h"

namespace CCustomersModelTests
{
    /* FIXME: The test cases depends share the same CCustomersModelTests object. Find a way to destroy the singleton for each test */
    CCustomersModel *customer_model = CCustomersModel::GetInstance();
    s_customer customer_created = {0, "rafael", "AVD La mejor del mundo", "682198437"};
    s_customer customer_updated = {0, "rafael", "AVD La peor del mundo", "681111117"};
    s_customer customer_deleted = {};
    unsigned int wrong_id = 25;

    /* This test is named "Create", and belongs to the "CCustomersModelTests" */
    TEST(CCustomersModelTests, Create)
    {
        /* test case. */
        EXPECT_EQ(true, customer_model->Create(customer_created));
        EXPECT_EQ(false, customer_model->Create(customer_created));

    }

    /* This test is named "Read", and belongs to the "CCustomersModelTests" */
    TEST(CCustomersModelTests, Read)
    {
        s_customer customer_output = {};

        /* test case. */
        EXPECT_EQ(true, customer_model->Read(customer_created.id, customer_output));
        EXPECT_EQ(0, customer_output.id);
        EXPECT_EQ(customer_created.name, customer_output.name);
        EXPECT_EQ(customer_created.address, customer_output.address);
        EXPECT_EQ(customer_created.telephone, customer_output.telephone);
        EXPECT_EQ(false, customer_model->Read(wrong_id, customer_output));
    }

    /* This test is named "Update", and belongs to the "CCustomersModelTests" */
    TEST(CCustomersModelTests, Update)
    {
        s_customer customer_output = {};
        s_customer customer_wrong_update = {};
        customer_wrong_update.id = wrong_id;

        /* Read what it is created */
        EXPECT_EQ(true, customer_model->Read(customer_created.id, customer_output));
        EXPECT_EQ(customer_created.id, customer_output.id);
        EXPECT_EQ(customer_created.name, customer_output.name);
        EXPECT_EQ(customer_created.address, customer_output.address);
        EXPECT_EQ(customer_created.telephone, customer_output.telephone);

        /* Update */
        EXPECT_EQ(true, customer_model->Update(customer_updated));
        EXPECT_EQ(true, customer_model->Read(customer_created.id, customer_output));
        EXPECT_EQ(customer_updated.id, customer_output.id);
        EXPECT_EQ(customer_updated.name, customer_output.name);
        EXPECT_EQ(customer_updated.address, customer_output.address);
        EXPECT_EQ(customer_updated.telephone, customer_output.telephone);

        /* Update wrong id */
        EXPECT_EQ(false, customer_model->Update(customer_wrong_update));
    }

    /* This test is named "Delete", and belongs to the "CCustomersModelTests" */
    TEST(CCustomersModelTests, Delete)
    {
        s_customer customer_wrong_delete = {};

        /* Delete */
        customer_wrong_delete.id = wrong_id;
        EXPECT_EQ(true, customer_model->Delete(customer_deleted));
        EXPECT_EQ(false, customer_model->Delete(customer_wrong_delete));
        EXPECT_EQ(false, customer_model->Read(customer_deleted.id, customer_wrong_delete));
    }
}
