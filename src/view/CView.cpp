#include "CView.hpp"
#include <limits>
#include <iostream>

/**
 * This is the constructor for the CView class in C++.
 */
CView::CView()
{
}

/**
 * The function waits for the user to press the Enter key before continuing.
 * 
 * @return nothing (void).
 */
void CView::WaitEnter() const
{
    char c;

    std::printf("Press ENTER to continue...\n" );
    while ((c = std::getchar()) != 10)
    {

    }

    return;
}

/**
 * This function reads an integer input from the user and checks if it is valid, and returns the
 * integer.
 * 
 * @return an integer value, which is the number entered by the user after validating the input.
 */
int CView::GetNumber() const
{
    int number;

    /* Clear the buffer */
    std::fflush(stdin);

    // read input
    std::cin >> number;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    /* check if input is valid */
    while (std::cin.fail())
    {
        std::printf("Invalid input. Please enter a number: ");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        /* retry */
        std::cin >> number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}

/**
 * The function reads a string input from the user through the console and returns it.
 * 
 * @return The function `GetString()` returns a `std::string` object that contains the string entered
 * by the user through the console using `std::getline()`.
 */
std::string CView::GetString() const
{
    std::string str;
    std::getline(std::cin, str);

    return str;
}