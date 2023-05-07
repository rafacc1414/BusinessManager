#ifndef CCUSTOMERSVIEW_HPP
#define CCUSTOMERSVIEW_HPP

#include "GeneralTypes.hpp"
#include "CCustomersModel.hpp"
#include "ICrudView.hpp"
#include "CView.hpp"

class CCustomersView : public ICrudView
{

protected:
    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    CCustomersView() {}

    static CCustomersView *m_customers_view;

public:
    /**
     * Singletons should not be cloneable.
     */
    CCustomersView(CCustomersView &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const CCustomersView &) = delete;

    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static CCustomersView *GetInstance();
    void run();

private:
    CView view;
    CCustomersModel *m_customers_model;
    e_crud_options ShowMenu() const override;

    void Create() override;
    void Read() const override;
    void Update() override;
    void Delete() override;

    void ShowAllCustomers();
};

#endif