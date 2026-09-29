#include <iostream>
using namespace std;

// Function prototype/declaration so main() can call it
void menu();

int main()
{
    menu(); // Start the menu recursive loop
    return 0;
}

void menu()
{
    int choice;
    
    cout << "\n===== Restaurant Menu =====\n";
    cout << "1. Pizza\n";
    cout << "2. Burger\n";
    cout << "3. Pasta\n";
    cout << "4. Exit\n";
    cout << "Enter Your Choice: ";
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nYou selected Pizza!\n";
        menu(); // Recursive call to prompt again
    }
    else if (choice == 2)
    {
        cout << "\nYou selected Burger!\n";
        menu(); // Recursive call to prompt again
    }
    else if (choice == 3)
    {
        cout << "\nYou selected Pasta!\n";
        menu(); // Recursive call to prompt again
    }
    else if (choice == 4)
    {
        cout << "\nThank you for visiting! Exiting...\n"; // Base case: terminates recursion
    }
    else
    {
        cout << "\nInvalid choice! Please select a valid option.\n";
        menu(); // Recursive call for retry on invalid input
    }
}
