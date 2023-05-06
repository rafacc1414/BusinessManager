#ifndef CBILLSVIEW_HPP
#define CBILLSVIEW_HPP

#include "./../GeneralTypes.hpp"
#include "./../../include/model/CBillsModel.hpp"
#include "ICrudView.hpp"
#include "CView.hpp"

class CBillsView : public ICrudView
{

protected:
    /**
     * The Singleton's constructor should always be private to prevent direct
     * construction calls with the `new` operator.
     */
    CBillsView() {}

    static CBillsView *m_bills_view;

public:
    /**
     * Singletons should not be cloneable.
     */
    CBillsView(CBillsView &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const CBillsView &) = delete;

    /**
     * This is the static method that controls the access to the singleton
     * instance. On the first run, it creates a singleton object and places it
     * into the static field. On subsequent runs, it returns the client existing
     * object stored in the static field.
     */
    static CBillsView *GetInstance();

    void run();

private:
    CView view;
    CBillsModel *m_bills_model;

    e_crud_options ShowMenu() const override;

    void Create() override;
    void Read() const override;
    void Update() override;
    void Delete() override;

    void ShowAllBills() const;
};

#endif