#ifndef CMAINWINDOW_HPP
#define CMAINWINDOW_HPP

#include "./../GeneralTypes.hpp"
#include "./../../include/view/CBillsView.hpp"
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
    e_program_options ShowMenu();
};

#endif