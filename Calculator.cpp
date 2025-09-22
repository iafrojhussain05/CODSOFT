#include <iostream>
using namespace std;

int main()
{
    double num1, num2, result;
    int choice;

    cout << "Simple Calculator\n";

    // Input two numbers
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Show menu
    cout << "\nChoose operation:\n";
    cout << "1. Addition (+)\n";
    cout << "2. Subtraction (-)\n";
    cout << "3. Multiplication (*)\n";
    cout << "4. Division (/)\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Perform operation
    switch (choice)
    {
    case 1:
        result = num1 + num2;
        cout << "Result: " << result << endl;
        break;
    case 2:
        result = num1 - num2;
        cout << "Result: " << result << endl;
        break;
    case 3:
        result = num1 * num2;
        cout << "Result: " << result << endl;
        break;
    case 4:
        if (num2 != 0)
            result = num1 / num2;
        else
        {
            cout << "Error! Division by zero not allowed." << endl;
            return 0;
        }
        cout << "Result: " << result << endl;
        break;
    default:
        cout << "Invalid choice! Please select between 1-4." << endl;
    }

    return 0;
}