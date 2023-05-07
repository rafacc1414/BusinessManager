#include "CCustomersView.hpp"
#include "GeneralTypes.hpp"
#include <limits>

/* `CCustomersView *CCustomersView::m_customers_view = nullptr;` is declaring a static member variable
`m_customers_view` of type `CCustomersView*` in the `CCustomersView` class. It is initialized to
`nullptr`, which means it does not point to any object yet. This variable is used to implement the
singleton pattern, which ensures that only one instance of the `CCustomersView` class is created and
used throughout the program. */
CCustomersView *CCustomersView::m_customers_view = nullptr;

/**
 * The function returns a singleton instance of the CCustomersView class.
 * 
 * @return The function `GetInstance()` returns a pointer to an instance of the `CCustomersView` class.
 */
CCustomersView *CCustomersView::GetInstance()
{
    /**
     * This is a safer way to create an instance. instance = new Singleton is
     * dangeruous in case two instance threads wants to access at the same time
     */
    if (m_customers_view == nullptr)
    {
        m_customers_view = new CCustomersView();
    }
    return m_customers_view;
}

/**
 * This function runs a loop that displays a menu and performs CRUD operations on customer data based
 * on user input.
 * 
 * @return void, which means it is not returning any value.
 */
void CCustomersView::run()
{
    e_crud_options option = e_crud_options::NO_OPTION;
    m_customers_model = CCustomersModel::GetInstance();

    do
    {
        option = ShowMenu();
        switch (option)
        {
        /* TODO: DELETE this option in final version */
        case SHOW_ALL:
            ShowAllCustomers();
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
 * The function displays a menu for CRUD operations on customers and returns the selected option.
 * 
 * @return an enumerated value of type `e_crud_options`, which represents the option selected by the
 * user from the menu.
 */
e_crud_options CCustomersView::ShowMenu() const
{
    unsigned int option = e_crud_options::NO_OPTION;
    bool retry_condition = true;
    do
    {
        /* Show the menu */
        std::printf("\n");
        std::printf("CUSTOMERS PANEL\n");

        /* TODO: Delete this option in final version */
        std::printf("%d. Show all customers\n", e_crud_options::SHOW_ALL);

        std::printf("%d. Create customer\n", e_crud_options::CREATE);
        std::printf("%d. Read customer\n", e_crud_options::READ );
        std::printf("%d. Update customer\n", e_crud_options::UPDATE );
        std::printf("%d. Delete customer\n", e_crud_options::DELETE );
        std::printf("%d. Back\n", e_crud_options::NO_OPTION );
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
 * This function creates a new customer by getting input from the user and adding it to the customers
 * model.
 * 
 * @return nothing (void).
 */
void CCustomersView::Create()
{
    unsigned int id = 0;
    std::string name, address, telephone;

    /* Get the inputs for creating a customer */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (m_customers_model->CheckID(id)) {
        std::printf("Error: The id already exists!\n");
        return;
    };
    std::printf("Introduce the name: ");
    name = view.GetString();
    std::printf("Introduce the address: ");
    address = view.GetString();
    std::printf("Introduce the telephone: ");
    telephone = view.GetString();

    /* Build the information */
    s_customer customer = {};
    customer.id = id;
    customer.name = name;
    customer.address = address;
    customer.telephone = telephone;

    /* Create the customer */
    bool result = m_customers_model->Create(customer);
    if (false == result) {
        std::printf("Error: The customer could not be created!\n");
        return;
    }

    std::printf("Customer Created!\n");

    return;
}

/**
 * The function reads customer information from a model and prints it to the console.
 * 
 * @return nothing (void). It only prints out information about a customer if it exists in the model
 * and can be read successfully.
 */
void CCustomersView::Read() const
{
    unsigned int id = 0;

    /* Get the inputs for creating a customer */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (false == m_customers_model->CheckID(id)) {
        std::printf("Error: The id does exists!\n");
        return;
    };

    /* Build the information */
    s_customer customer = {};

    /* Create the customer */
    bool result = m_customers_model->Read(id, customer);
    if (false == result) {
        std::printf("Error: The customer could not be read!\n");
        return;
    }

    std::printf("Name: %s\n", customer.name.c_str());
    std::printf("Adress: %s\n",  customer.address.c_str());
    std::printf("Telephone: %s\n", customer.telephone.c_str());
    std::printf("Customer Read!\n");
}

/**
 * This function updates a customer's information in a model based on user input.
 * 
 * @return void.
 */
void CCustomersView::Update()
{
    unsigned int id = 0;
    std::string name, address, telephone;

    /* Get the inputs for creating a customer */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (false == m_customers_model->CheckID(id)) {
        std::printf("Error: The id does exists!\n");
        return;
    };
    std::printf("Introduce the name: ");
    name = view.GetString();
    std::printf("Introduce the address: ");
    address = view.GetString();
    std::printf("Introduce the telephone: ");
    telephone = view.GetString();

    /* Build the information */
    s_customer customer = {};
    customer.id = id;
    customer.name = name;
    customer.address = address;
    customer.telephone = telephone;

    /* Create the customer */
    bool result = m_customers_model->Update(customer);

    if (false == result) {
        std::printf("Error: The customer could not be updated!\n");
        return;
    }

    std::printf("Customer Updated!\n");

    return;
}

/**
 * The function deletes a customer from the customers model based on the ID provided by the user.
 * 
 * @return nothing, as the return type is `void`.
 */
void CCustomersView::Delete()
{
    unsigned int id = 0;
    unsigned int amount;

    /* Get the inputs for creating a customer */
    std::printf("Introduce the ID: ");
    id = view.GetNumber();
    if (false == m_customers_model->CheckID(id)) {
        std::printf("Error: The id does exists!\n");
        return;
    };

    /* Build the information */
    s_customer customer = {};
    customer.id = id;

    /* Create the customer */
    bool result = m_customers_model->Delete(customer);
    if (false == result) {
        std::printf("Error: The customer could not be deleted!\n");
        return;
    }

    std::printf("Customer Deleted!\n");

    return;
}

/**
 * The function displays a list of all customers stored in a map.
 * 
 * @return void, which means it is not returning any value.
 */
void CCustomersView::ShowAllCustomers()
{
    std::map<int, s_customer> customers_info = m_customers_model->GetAllCustomers();

    if (customers_info.empty())
    {
        std::printf("There is no customers stored yet!\n");
        return;
    }

    /* FIXME:lambda function to loop over the customer content and show it */
    auto print_customers = [&customers_info]()
    {
        for (const auto &pair : customers_info)
        {
            std::printf("%d: %s, %s, %s\n",pair.first, pair.second.name.c_str(),
                        pair.second.address.c_str(), pair.second.telephone.c_str());
        }
    };

    std::printf("List with all the customers: \n");
    print_customers();

    return;
}
