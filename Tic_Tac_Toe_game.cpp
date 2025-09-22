#include <iostream>
using namespace std;

char board[3][3];

// Initialize the board
void initializeBoard()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// Display the board
void displayBoard()
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "| ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Check if move is valid
bool isValidMove(int row, int col)
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3)
    {
        return board[row][col] == ' ';
    }
    return false;
}

// Check for win
bool checkWin(char player)
{
    // Rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // Diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Check for draw
bool isDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    char currentPlayer = 'X';
    bool playAgain = true;

    while (playAgain)
    {
        initializeBoard();
        bool gameOver = false;

        while (!gameOver)
        {
            displayBoard();
            int row, col;
            cout << "Player " << currentPlayer << ", enter your move (row[0-2] and col[0-2]): ";
            cin >> row >> col;

            if (isValidMove(row, col))
            {
                board[row][col] = currentPlayer;

                if (checkWin(currentPlayer))
                {
                    displayBoard();
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    gameOver = true;
                }
                else if (isDraw())
                {
                    displayBoard();
                    cout << "The game is a draw!" << endl;
                    gameOver = true;
                }
                else
                {
                    // Switch players
                    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
                }
            }
            else
            {
                cout << "Invalid move, try again." << endl;
            }
        }

        string choice;
        cout << "Do you want to play again? (yes/no): ";
        cin >> choice;

        if (choice != "yes" && choice != "Yes")
        {
            playAgain = false;
            cout << "Thanks for playing Tic-Tac-Toe!" << endl;
        }
        else
        {
            currentPlayer = 'X'; // Reset starting player
        }
    }

    return 0;
}