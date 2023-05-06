#include "CBillsModel.hpp"
#include "GeneralTypes.hpp"

#include <limits.h>

#include "gtest/gtest.h"

namespace CBillModelTests
{
    /* FIXME: The test cases depends share the same CBillsModel object. Find a way to destroy the singleton for each test */
    CBillsModel *bill_model = CBillsModel::GetInstance();
    s_bill bill_created = {0, 159};
    s_bill bill_updated = {0, 10};
    s_bill bill_deleted = {0, 0};
    unsigned int wrong_id = 25;

    /* This test is named "Create", and belongs to the "CBillModelTest" */
    TEST(CBillModelTest, Create)
    {
        s_bill bill = {};

        /* test case. */
        EXPECT_EQ(true, bill_model->Create(bill_created));
        EXPECT_EQ(false, bill_model->Create(bill_created));

    }

    /* This test is named "Read", and belongs to the "CBillModelTest" */
    TEST(CBillModelTest, Read)
    {
        s_bill bill_output = {};

        /* test case. */
        EXPECT_EQ(true, bill_model->Read(bill_created.id, bill_output));
        EXPECT_EQ(0, bill_output.id);
        EXPECT_EQ(159, bill_output.amount);
        EXPECT_EQ(false, bill_model->Read(wrong_id, bill_output));
    }

    /* This test is named "Update", and belongs to the "CBillModelTest" */
    TEST(CBillModelTest, Update)
    {
        s_bill bill_output = {};
        s_bill bill_wrong_update = {};
        bill_wrong_update.id = wrong_id;

        /* Read what it is created */
        EXPECT_EQ(true, bill_model->Read(bill_created.id, bill_output));
        EXPECT_EQ(0, bill_output.id);
        EXPECT_EQ(159, bill_output.amount);

        /* Update */
        EXPECT_EQ(true, bill_model->Update(bill_updated));
        EXPECT_EQ(0, bill_updated.id);
        EXPECT_EQ(10, bill_updated.amount);

        /* Update wrong id */
        EXPECT_EQ(false, bill_model->Update(bill_wrong_update));
    }

    /* This test is named "Delete", and belongs to the "CBillModelTest" */
    TEST(CBillModelTest, Delete)
    {
        s_bill bill_wrong_delete = {};

        /* Delete */
        bill_wrong_delete.id = wrong_id;
        EXPECT_EQ(true, bill_model->Delete(bill_deleted));
        EXPECT_EQ(false, bill_model->Delete(bill_wrong_delete));
    }
}
