#include "CCustomersModel.hpp"
#include "GeneralTypes.hpp"

/* This line of code is defining a static member variable `m_customers_model` of the `CCustomersModel`
class and initializing it to `nullptr`. This variable is used to implement the singleton design
pattern, which ensures that only one instance of the `CCustomersModel` class is created throughout
the lifetime of the program. The `GetInstance()` function checks if `m_customers_model` is
`nullptr`, and if it is, it creates a new instance of the `CCustomersModel` class and assigns its
address to `m_customers_model`. Subsequent calls to `GetInstance()` will return the same instance of
the `CCustomersModel` class. */
CCustomersModel *CCustomersModel::m_customers_model = nullptr;

/**
 * The function returns a singleton instance of the CCustomersModel class.
 * 
 * @return The function `GetInstance()` returns a pointer to the singleton instance of the
 * `CCustomersModel` class.
 */
CCustomersModel *CCustomersModel::GetInstance()
{
    if (m_customers_model == nullptr)
    {
        m_customers_model = new CCustomersModel();
    }
    return m_customers_model;
}

/**
 * The function creates a new customer in a C++ customers model if the customer ID does not already
 * exist.
 * 
 * @param customer The parameter "customer" is an object of type "s_customer" which contains
 * information about a customer, such as their ID, name, address, and phone number.
 * 
 * @return a boolean value. It returns true if the customer was successfully created and false if there
 * was an error (such as the ID already existing).
 */
bool CCustomersModel::Create(s_customer customer)
{
    /* Check if the id already exists */
    bool exist = CheckID(customer.id);
    if (exist)
    {
        return false;
    }

    m_customers[customer.id] = customer;

    return true;
}

/**
 * The function reads a customer's information from a map and returns it in a struct if the customer ID
 * exists.
 * 
 * @param id The ID of the customer to be read from the model.
 * @param customer The parameter "customer" is a reference to a structure of type "s_customer". This
 * structure likely contains information about a customer, such as their ID, name, address, and
 * telephone number. The function "Read" takes an ID as input and searches for a customer with that ID
 * in a map
 * 
 * @return a boolean value. It returns true if the customer with the given id exists in the model and
 * the customer data is successfully read into the output parameter "customer". It returns false if the
 * customer with the given id does not exist in the model.
 */
bool CCustomersModel::Read(unsigned int id, s_customer &customer) const
{
    /* Check if the id already exists */
    bool exist = CheckID(id);
    if (!exist) {
        return false;
    }

    /* Get the customer */
    auto it = m_customers.find(id);

    /* Build the output*/
    customer.id = it->second.id;
    customer.name = it->second.name;
    customer.address = it->second.address;
    customer.telephone = it->second.telephone;

    return true;
} 

/**
 * This function updates a customer in a model if the customer ID already exists.
 * 
 * @param customer The parameter "customer" is an object of type "s_customer" which contains
 * information about a customer, such as their ID, name, address, and phone number. This function
 * updates the information of an existing customer in the "m_customers" map using the customer's ID as
 * the key.
 * 
 * @return a boolean value. It returns true if the customer with the given ID exists and is updated
 * successfully, and false if the customer with the given ID does not exist.
 */
bool CCustomersModel::Update(s_customer customer)
{
    /* Check if the id already exists */
    bool exist = CheckID(customer.id);
    if (!exist) {
        return false;
    }

    m_customers[customer.id] = customer;

    return true;
}

/**
 * This function deletes a customer from a map if their ID exists in the map.
 * 
 * @param customer The parameter "customer" is an object of the "s_customer" struct, which contains
 * information about a customer such as their ID, name, address, and phone number. This function is
 * designed to delete a customer from a map of customers stored in the "m_customers" member variable of
 * the
 * 
 * @return This function returns a boolean value. It returns true if the customer with the given ID was
 * successfully deleted from the map, and false if the customer was not found in the map.
 */
bool CCustomersModel::Delete(s_customer customer)
{
    /* Check if the id already exists */
    bool exist = CheckID(customer.id);
    if (!exist) {
        return false;
    }

    /* Delete the customer from the map */
    auto it = m_customers.find(customer.id);
    m_customers.erase(it);

    return true;
}

/**
 * The function checks if a given ID already exists in a map of customers.
 * 
 * @param id The parameter "id" is an unsigned integer representing the ID of a customer that needs to
 * be checked for existence in the "m_customers" map.
 * 
 * @return a boolean value. It returns true if the given ID already exists in the `m_customers` map,
 * and false otherwise.
 */
bool CCustomersModel::CheckID(unsigned int id) const
{
    /* Check if the id already exists */
    auto it = m_customers.find(id);
    if (it != m_customers.end())
    {
        return true;
    }
    
    return false;
}

/**
 * The function returns a map of all customers in the model.
 * 
 * @return A `std::map` object that contains integer keys and `s_customer` values, representing all the
 * customers in the `CCustomersModel` object.
 */
std::map<int, s_customer> CCustomersModel::GetAllCustomers() const
{
    return m_customers;
}