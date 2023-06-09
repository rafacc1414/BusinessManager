#include "CMainWindow.hpp"
#include "GeneralTypes.hpp"
#include <iostream>

/**
 * The CMainWindow constructor initializes an instance of CBillsView.
 */
CMainWindow::CMainWindow()
{
    m_bills_manager = CBillsView::GetInstance();
    m_customer_manager = CCustomersView::GetInstance();
}

/**
 * The function runs a menu-driven program that allows the user to manage customers and bills.
 * 
 * @return nothing, as it has a return type of `void`.
 */
void CMainWindow::run()
{
    e_program_options option = e_program_options::EXIT;

    do
    {
        option = ShowMenu();
        switch (option)
        {
        case CUSTOMER_MANAGER:
            m_customer_manager->run();
            break;
        case BILLS_MANAGER:
            m_bills_manager->run();
            break;
        case EXIT:
        default:
            std::printf("Terminating the program.\n");
        break;
        }
    } while (option != EXIT);

    return;
}

/**
 * The function displays a menu for a business manager control panel and returns the selected option.
 * 
 * @return an enumerated value of type `e_program_options`, which represents the option selected by the
 * user from the menu.
 */
e_program_options CMainWindow::ShowMenu()
{
    unsigned int option = e_program_options::EXIT;
    bool retry_condition = true;
    do
    {
        /* Show the menu */
        std::printf("\n");
        std::printf("BUSSINESS MANAGER CONTROL PANEL\n");
        std::printf("1. Manage Customers\n");
        std::printf("2. Manage Bills\n");
        std::printf("0. Exit\n");
        std::printf("Choose an option: ");
        option = view.GetNumber();

        retry_condition = (option < 0) || (option > e_program_options::BILLS_MANAGER);
        if (retry_condition)
        {
            std::printf("The option selected is not allowed!\n");
        }
    } while (retry_condition);

    return (e_program_options)option;
}