#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    srand(time(0));

    int number = rand() % 100 + 1;

    int guess = 0;
    int attempts = 0;
    cout << " i have chosen a number between 1 to 100 . can you guess it? " << endl;
    while (guess != number)
    {
        cout << "Enter your guess: Number ";
        cin >> guess;
        attempts++;
        if (guess < number)
        {
            cout << "Too Low Try Again." << endl;
        }
        else if (guess > number)
        {
            cout << "To High Try Again. " << endl;
        }
        else
        {
            cout << "Congratulations You Guessed the correct number ." << endl;
            cout << "it took you " << attempts << " attempts " << endl;
        }
    }
    return 0;
}
