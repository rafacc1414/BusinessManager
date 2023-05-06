#include "CBillsModel.hpp"
#include "GeneralTypes.hpp"
#include <iostream>

/* `CBillsModel *CBillsModel::CBillsModel_ = nullptr;` is defining a static pointer variable `CBillsModel_` of type
`CBillsModel` in the class `CBillsModel`. It is initialized to `nullptr` which means it does not point to any
memory location yet. This variable is used to implement the Singleton design pattern, where only one
instance of the class `CBillsModel` can exist at a time. The `GetInstance()` function checks if `CBillsModel_`
is `nullptr`, and if it is, it creates a new instance of `CBillsModel` and assigns it to `CBillsModel_`. If
`CBillsModel_` is not `nullptr`, it simply returns the existing instance. */
CBillsModel *CBillsModel::m_bills_model = nullptr;

/**
 * This function returns a singleton instance of the CBillsModel class.
 * 
 * @return a pointer to an instance of the CBillsModel class.
 */
CBillsModel *CBillsModel::GetInstance()
{
    if (m_bills_model == nullptr)
    {
        m_bills_model = new CBillsModel();
    }
    return m_bills_model;
}


/**
 * The function creates a new bill and adds it to a map if the bill ID does not already exist.
 * 
 * @param bill a structure or object of type s_bill, which contains information about a bill, such as
 * its ID, amount, date, and description. The function CBillsModel::Create() takes this bill object as a
 * parameter and inserts it into a map data structure. Before inserting, it checks if the bill ID
 * 
 * @return True in success, false otherwise.
 */
bool CBillsModel::Create(s_bill bill)
{
    bool exist = CheckID(bill.id);
    if (exist) {
        return false;
    }

    /* Insert the bill in the map */
    m_bills[bill.id] = bill;

    return true;
}

/**
 * The function reads the information of a bill with a given ID and fills the output structure.
 * 
 * @param id The ID of the bill that needs to be read.
 * @param bill `bill` is a reference to a structure of type `s_bill`. This structure likely contains
 * information about a bill, such as its ID and amount. The `Read` function fills in this structure
 * with the information corresponding to the given `id`.
 * 
 * @return a boolean value, either true or false.
 */
bool CBillsModel::Read(unsigned int id, s_bill &bill) const
{
    bool exist = CheckID(id);
    if (!exist) {
        return false;
    }

    /* Find the information */
    auto it = m_bills.find(id);

    /* Fill the output */
    bill.id = id;
    bill.amount =it->second.amount;
    
    return true;
}

/**
 * The function updates a bill in a collection and prints a message indicating success or failure.
 * 
 * @param bill a variable of type s_bill, which represents a bill object that needs to be updated in
 * the bills map.
 * 
 * @return True in success, false otherwise.
 */
bool CBillsModel::Update(s_bill bill)
{
    bool exist = CheckID(bill.id);
    if (!exist) {
        return false;
    }

    m_bills[bill.id] = bill;

    return true;
}

/**
 * The function deletes a bill from a map of bills based on its ID.
 * 
 * @param bill The parameter "bill" is an object of type "s_bill", which represents a bill. It is
 * passed as an argument to the "Delete" function of the "CBillsModel" class. The function uses the "id"
 * field of the "s_bill" object to find and delete the corresponding
 * 
 * @return True in success, false otherwise.
 */
bool CBillsModel::Delete(s_bill bill)
{
    bool exist = CheckID(bill.id);
    if (!exist) {
        return false;
    }

    /* Delete the client from the map */
    auto it = m_bills.find(bill.id);
    m_bills.erase(it);

    return true;
}

/**
 * The function checks if a given ID exists in a map of bills.
 * 
 * @param id The parameter "id" is an unsigned integer that represents the ID of a bill that needs to
 * be checked for existence in the "m_bills" map.
 * 
 * @return A boolean value indicating whether the given ID exists in the map of bills or not. True is
 * returned if the ID exists, and false is returned if it does not exist.
 */
bool CBillsModel::CheckID(unsigned int id) const
{
    auto it = m_bills.find(id);
    if (it != m_bills.end())
    {
        return true;
    }
    
    return false;
}

/**
 * The function returns a map of all bills stored in the object.
 * 
 * @return A constant reference to a `std::map` object with integer keys and values of type `s_bill`.
 */
std::map<int, s_bill> CBillsModel::GetAllBills() const
{
    return m_bills;
}