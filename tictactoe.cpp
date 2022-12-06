// tic tac toe game
#include <iostream>
using namespace std;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;
void draw_board()
{
    // demo board
    /*
    1 | 2 | 3
    ---------
    4 | 5 | 6
    ---------
    7 | 8 | 9
    */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << " " << board[i][j] << " ";
            if (j < 2)
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2)
        {
            cout << "-----------" << endl;
        }
    }
}
bool place_marker(int slot)
{
    // slot number = 1, row = 0, column = 0
    // slot number = 2, row = 0, column = 1
    // slot number = 3, row = 0, column = 2
    // slot number = 4, row = 1, column = 0
    // slot number = 5, row = 1, column = 1
    // slot number = 6, row = 1, column = 2
    // slot number = 7, row = 2, column = 0
    // slot number = 8, row = 2, column = 1
    // slot number = 9, row = 2, column = 2
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3; // 0%3 = 0, 1%3 = 1, 2%3 = 2, 3%3 = 0, 4%3 = 1, 5%3 = 2, 6%3 = 0, 7%3 = 1, 8%3 = 2

    if (board[row][col] != 'X' && board[row][col] != 'O')
    {
        // this slot is available to be marked with the current marker (X or O)
        /*
        1 | 2 | 3
        ---------
        4 | 5 | 6
        ---------
        7 | 8 | 9
        */
        board[row][col] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}
int winner()
{
    /*
        1 | 2 | 3
        ---------
        4 | 5 | 6
        ---------
        7 | 8 | 9
    */
    // check for rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return current_player;
        }
    }
    // check for columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return current_player;
        }
    }
    // check for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return current_player;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return current_player;
    }
    return 0;
}
void swap_player_and_marker()
{
    // this function swaps the player and marker
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }
    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}
int main()
{
    cout << "Welcome to Tic Tac Toe" << endl;
    current_player = 1;
    cout << "PLayer 1, choose your marker (X or O): ";
    cin >> current_marker;
    if (current_marker != 'X' && current_marker != 'O')
    {
        cout << "Invalid marker. Choose again: " << endl;
        cin >> current_marker;
    }
    draw_board();
    int player_won;
    // loop until the game is over , 9 times iteration for 9 moves
    for (int i = 0; i < 9; i++)
    {
        int slot;
        cout << "Player " << current_player << " it's your turn, enter a slot number: ";
        cin >> slot;
        if (slot < 1 || slot > 9)
        {
            cout << "Invalid input. Try again." << endl;
            i--;
            continue;
        }
        if (!place_marker(slot))
        {
            cout << "Slot already taken. Try again." << endl;
            i--;
            continue;
        }
        draw_board();
        player_won = winner(); // 0 means no winner, 1 means player 1 won, 2 means player 2 won
        if (player_won == 1)
        {
            cout << "Player 1 won!" << endl;
            break;
        }
        else if (player_won == 2)
        {
            cout << "Player 2 won!" << endl;
            break;
        }
        swap_player_and_marker(); // swap the player and marker for the next iteration of the loop
    }
    if (player_won == 0)
    {
        cout << "It's a draw!" << endl;
    }
    return 0;
}
