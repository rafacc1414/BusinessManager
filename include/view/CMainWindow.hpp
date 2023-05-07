#ifndef CMAINWINDOW_HPP
#define CMAINWINDOW_HPP

#include "GeneralTypes.hpp"
#include "CBillsView.hpp"
#include "CCustomersView.hpp"
#include "CView.hpp"

class CMainWindow
{

public:
    ~CMainWindow() {}
    CMainWindow();

    void run();

private:   
    CView view;
    CBillsView *m_bills_manager;
    CCustomersView *m_customer_manager;
    e_program_options ShowMenu();
};

#endif