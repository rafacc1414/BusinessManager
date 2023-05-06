#ifndef CBILLSMODEL_HPP
#define CBILLSMODEL_HPP

#include "GeneralTypes.hpp"
#include "ICrudModel.hpp"
#include <map>

class CBillsModel : public ICrudModel<s_bill>
{

protected:
    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    CBillsModel() {}

    static CBillsModel *m_bills_model;

private:
    std::map<int, s_bill> m_bills;

public:
    /**
     * Singletons should not be cloneable.
     */
    CBillsModel(CBillsModel &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const CBillsModel &) = delete;

    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static CBillsModel *GetInstance();

    bool Create(s_bill bill) override;
    bool Read(unsigned int id, s_bill &bill) const override;
    bool Update(s_bill bill) override;
    bool Delete(s_bill bill) override;

    bool CheckID(unsigned int id) const;
    std::map<int, s_bill> GetAllBills() const;
};

#endif