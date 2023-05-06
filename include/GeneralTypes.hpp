#ifndef GENERAL_TYPES_HPP
#define GENERAL_TYPES_HPP

typedef enum E_Crud_options
{
    NO_OPTION = 0,
    SHOW_ALL, // TODO: DELETE in final version
    CREATE,
    READ,
    UPDATE,
    DELETE
} e_crud_options;

typedef enum E_Program_options
{
    EXIT = 0,
    CLIENT_MANAGER,
    BILLS_MANAGER,
} e_program_options;

typedef struct S_Bill
{ 
    unsigned int id;
    unsigned int amount;
} s_bill;

#endif