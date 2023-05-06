#include "CBillsView.hpp"
#include "GeneralTypes.hpp"
#include <algorithm>
#include <iostream>

/* This line of code is initializing a static member variable `CBillsView_` of the `CBillsView` class
to a null pointer. This variable is used to implement the singleton design pattern, ensuring that
only one instance of the `CBillsView` class is created throughout the lifetime of the program. */
CBillsView *CBillsView::m_bills_view = nullptr;

/**
 * This function returns a singleton instance of the CBillsView class.
 * 
 * @return The function `CBillsView::GetInstance()` returns a pointer to an instance of the
 * `CBillsView` class. If an instance of the class does not already exist, the function creates a new
 * instance and returns a pointer to it.
 */
CBillsView *CBillsView::GetInstance()
{
    if (m_bills_view == nullptr)
    {
        m_bills_view = new CBillsView();
    }
    return m_bills_view;
}

/**
 * The function runs a menu-driven CRUD (Create, Read, Update, Delete) interface for managing bills.
 * 
 * @return void, which means it is not returning any value.
 */
void CBillsView::run()
{
    e_crud_options option = e_crud_options::NO_OPTION;
    m_bills_model = CBillsModel::GetInstance();

    do
    {
        option = ShowMenu();
        switch (option)
        {
        /* TODO: DELETE this option in final version */
        case SHOW_ALL:
            ShowAllBills();
            view.WaitEnter();
            break;

        case CREATE:
            Create();
            view.WaitEnter();
            break;
        case READ:
            Read();
            view.WaitEnter();
            break;
        case UPDATE:
            Update();
            view.WaitEnter();
            break;
        case DELETE:
            Delete();
            view.WaitEnter();
            break;
        case NO_OPTION:
        default:
            break;
        }
    } while (option != NO_OPTION);

    return;
}

/**
 * The function displays a menu for CRUD operations on bills and returns the selected option.
 * 
 * @return a value of the enum type `e_crud_options`.
 */
e_crud_options CBillsView::ShowMenu() const
{
    unsigned int option = e_crud_options::NO_OPTION;
    bool retry_condition = true;
    do
    {
        /* Show the menu */
        std::printf("\n");
        std::printf("BILLS PANEL\n");

        /* TODO: Delete this option in final version */
        std::printf("%d. Show all bills\n", e_crud_options::SHOW_ALL);

        std::printf("%d. Create bill\n", e_crud_options::CREATE);
        std::printf("%d. Read bill\n", e_crud_options::READ);
        std::printf("%d. Update bill\n", e_crud_options::UPDATE);
        std::printf("%d. Delete bill\n", e_crud_options::DELETE);
        std::printf("%d. Back\n", e_crud_options::NO_OPTION);
        std::printf("Choose an option: ");
        option = view.GetNumber();
        std::printf("\n");

        retry_condition = (option < 0) || (option > e_crud_options::DELETE);
        if (retry_condition)
        {
            std::printf("The option selected is not allowed!\n");
        }
    } while (retry_condition);

    return (e_crud_options)option;
}

/**
 * This function creates a bill by getting the ID and amount from the user and passing it to the model.
 * 
 * @return nothing, as the return statement is followed by a semicolon and there is no value or
 * variable being returned.
 */
void CBillsView::Create()
{
    unsigned int id = 0;
    unsigned int amount;

    /* Get the inputs for creating a client */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    std::printf("Introduce the amount: ");
    amount = view.GetNumber();
    if (m_bills_model->CheckID(id)) {
        std::printf("Error: The id already exists!\n");
        return;
    };

    /* Build the information */
    s_bill bill = {};
    bill.id = id;
    bill.amount = amount;

    /* Create the client */
    bool result = m_bills_model->Create(bill);
    if (false == result) {
        std::printf("Error: The bill could not be created!\n");
        return;
    }

    std::printf("Bill Created!\n");

    return;
}

/**
 * The function reads input for creating a bill, builds the information, and calls the Read function of
 * the bills model.
 * 
 * @return nothing, as the return statement is followed by a semicolon and there is no value or
 * variable being returned.
 */
void CBillsView::Read() const
{
    unsigned int id = 0;

    /* Get the inputs for creating a client */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (false == m_bills_model->CheckID(id)) {
        std::printf("Error: The id does exists!\n");
        return;
    };

    /* Store the output information */
    s_bill bill = {};

    /* Create the client */
    bool result = m_bills_model->Read(id, bill);
    if (false == result) {
        std::printf("Error: The bill could not be read!\n");
        return;
    }

    std::printf("Amount: %d\n", bill.amount);
    std::printf("Bill Read!\n");

    return;
}

/**
 * This function updates a bill by getting the ID and amount from the user and passing it to the bills
 * model.
 * 
 * @return nothing, as the return statement is followed by a semicolon and there is no value or
 * variable being returned.
 */
void CBillsView::Update()
{
    unsigned int id = 0;
    unsigned int amount;

    /* Get the inputs for creating a client */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (false == m_bills_model->CheckID(id)) {
        std::printf("Error: The id does exists!\n");
        return;
    };
    std::printf("Introduce the amount to be updated: ");
    amount = view.GetNumber();

    /* Build the information */
    s_bill bill = {};
    bill.id = id;
    bill.amount = amount;

    /* Create the client */
    bool result = m_bills_model->Update(bill);
    if (false == result) {
        std::printf("Error: The bill could not be updated!\n");
        return;
    }

    std::printf("Bill Updated!\n");

    return;
}

/**
 * This function prompts the user to input an ID, creates a bill object with that ID, and then calls
 * the Delete function of the bills model with that object.
 * 
 * @return nothing, as indicated by the `void` return type.
 */
void CBillsView::Delete()
{
    unsigned int id = 0;
    unsigned int amount;

    /* Get the inputs for creating a client */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (false == m_bills_model->CheckID(id)) {
        std::printf("Error: The id does exists!\n");
        return;
    };

    /* Build the information */
    s_bill bill = {};
    bill.id = id;
    bill.amount = amount;

    /* Create the client */
    bool result = m_bills_model->Delete(bill);
    if (false == result) {
        std::printf("Error: The bill could not be deleted!\n");
        return;
    }

    std::printf("Bill Deleted!\n");

    return;
}

/**
 * The function displays all the bills stored in a map using a lambda function and an algorithm.
 * 
 * @return void, which means it is not returning any value.
 */
void CBillsView::ShowAllBills() const
{
    std::map<int, s_bill> bill_info = m_bills_model->GetAllBills();

    if (bill_info.empty())
    {
        std::printf("There is no bills stored yet!\n");
        return;
    }

    /* FIXME: lambda function show the bills information */
    auto print_bill = [](std::pair<int, s_bill> pair)
    {
        std::printf("%d: %d\n",pair.first, pair.second.amount);
    };

    std::printf("List with all the bills: \n");

    /* FIXME: Iterate over the bill map and show its information using an algorithm*/
    std::for_each(bill_info.begin(), bill_info.end(), print_bill);

    return;
}