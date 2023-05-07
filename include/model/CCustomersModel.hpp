#ifndef CCUSTOMERSMODEL_HPP
#define CCUSTOMERSMODEL_HPP

#include "GeneralTypes.hpp"
#include "ICrudModel.hpp"
#include <map>

class CCustomersModel : public ICrudModel<s_customer>
{
protected:
    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    CCustomersModel() {}

    static CCustomersModel *m_customers_model;

private:
    std::map<int, s_customer> m_customers;

public:
    /**
     * Singletons should not be cloneable.
     */
    CCustomersModel(CCustomersModel &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const CCustomersModel &) = delete;

    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the customer existing
     * object stored in the static field.
     */
    static CCustomersModel *GetInstance();

    bool Create(s_customer customer) override;
    bool Read(unsigned int id, s_customer &customer) const override;
    bool Update(s_customer customer) override;
    bool Delete(s_customer customer) override;

    bool CheckID(unsigned int id) const;
    std::map<int, s_customer> GetAllCustomers() const;
};

#endif