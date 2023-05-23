#include <iostream>
using namespace std;
string name1 = ""; // Gobal
string name2 = ""; // Variables
class XO
{
public:
    char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    ;
    int number;
    int row, col;
    char turn;
    bool draw;
    // Default Constuctor with no arguments
    XO()
    {
        char arr[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
        turn = 'X';   // initially we are giving turn is 'X'
        draw = false; // and at starting there will be no draw
    }
    // void display()
    // {
    //     cout << turn << endl;
    //     cout << row << endl;
    //     cout << col << endl;
    // }

    void displayBoard(); // To show the Table/Matrix
    void playerTurn();   // To know who's turn
    bool winCondition(); // For checking winning conditions and draw condition
    void result();       // To just print Who won or it is draw
};

void XO ::displayBoard()
{
    cout << " ______________" << endl;
    cout << "|    |    |    |" << endl;
    cout << "|" << arr[0][0] << "   |" << arr[0][1] << "   |" << arr[0][2] << "   |" << endl;
    cout << "|____|____|____|" << endl;
    cout << "|    |    |    |" << endl;
    cout << "|" << arr[1][0] << "   |" << arr[1][1] << "   |" << arr[1][2] << "   |" << endl;
    cout << "|____|____|____|" << endl;
    cout << "|    |    |    |" << endl;
    cout << "|" << arr[2][0] << "   |" << arr[2][1] << "   |" << arr[2][2] << "   |" << endl;
    cout << "|____|____|____|" << endl
         << endl;
}

void XO ::playerTurn()
{
    // int number;

    if (turn == 'X') // Player1's turn Enter his box number
    {
        cout << name1 << "'s (X) turn \nChoose your number :" << endl;
        cin >> number;
    }
    else if (turn == 'O') // Player2's turn Enter his box number
    {
        cout << name2 << "'s (O) turn \nChoose your number :" << endl;
        cin >> number;
    }

    switch (number) // if number is between 1 to 9 we will give row and column accordingly
    {               // eg: if number = 1 means in Matrix it's location is at (1st row, 1st col)
    case 1:         // if number not = 1 to 9 then we print 'Invalid number'
        row = 0;
        col = 0;
        break;
    case 2:
        row = 0;
        col = 1;
        break;
    case 3:
        row = 0;
        col = 2;
        break;
    case 4:
        row = 1;
        col = 0;
        break;
    case 5:
        row = 1;
        col = 1;
        break;
    case 6:
        row = 1;
        col = 2;
        break;
    case 7:
        row = 2;
        col = 0;
        break;
    case 8:
        row = 2;
        col = 1;
        break;
    case 9:
        row = 2;
        col = 2;
        break;

    default:
        cout << "Invalid Number \n";
        break;
    }

    // eg : if 'X' turn and in matrix if the box is not filled with 'X' or 'O' then
    //  at that place keep 'X' and give turn to 'O' and vice versa

    if (turn == 'X' && arr[row][col] != 'X' && arr[row][col] != 'O')
    {
        arr[row][col] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && arr[row][col] != 'X' && arr[row][col] != 'O')
    {
        arr[row][col] = 'O';
        turn = 'X';
    }

    // If player give a number but at that place it is already filled the ask to choose another number
    // And after this again show the new updated table/matrix

    else
    {
        cout << "Sorry it is already Filled" << endl;
        cout << "Choose another Number \n";
        playerTurn();
    }
    displayBoard();
}

bool XO ::winCondition() // Checking Winning Conditions
{
    // if(arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2] || arr[0][0] == arr [1][0] && arr[0][0] == arr[2][0])

    // checking that rows OR columns are equal or not, if equal return false to stop the loop
    for (int i = 0; i < 3; i++)
    {
        if (arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2] || arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
            return false;
    }

    // Checking diagonals are equal or not, if equal return false to stop the loop
    if (arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] || arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
        return false;

    // Checking if there are any other places/boxes need to fill, if yes continue loop return true
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] != 'X' && arr[i][j] != 'O')
                return true;
        }
    }

    // If every box is filled then make draw has true and return false to terminate the loop
    draw = true;
    return false;
}

void XO ::result() // For printing who is the Winnner
{
    // If it is 'X' turn and it is not draw then he is the winner
    if (turn == 'X' && draw == false)
        cout << name1 << " is the Winner \n";

    // If it is 'O' turn and it is not draw then he is the winner
    else if (turn == 'O' && draw == false)
        cout << name2 << " is the Winner \n";

    // If it is draw then print Draw
    else
        cout << "\n ** It is a Draw **\n";
}

int main()
{
    // First Welcome our players to our game
    cout << "\n ***************************\n";
    cout << "\n Welcome to Tic Tac Toe Game " << endl;
    cout << "\n ***************************\n";

    // Enter Players names and tell who is going to take 'X' & 'O'
    cout << "Enter Player1 name : " << endl;
    // getline(cin, name1);
    cin>>name1;
    cout << "Enter Player2 name : " << endl;
    // getline(cin, name2);
    cin>>name2;
    cout << name1 << " will be 'X' \n";
    cout << name2 << " will be '0' \n";

    // Creating 'game' object of class XO
    XO game;

    // First display the table/box/matrix with box numbers in it
    game.displayBoard(); // Invoking displayBoard function


    // Run the game until one wins or it draws
    while (game.winCondition())
    {
        game.playerTurn(); // Invoking this function
        game.winCondition();
    }


    // print the output who's won or is it draw
    game.result();


    // game.display();
    // game.displayBoard();
    // game.playerTurn();
    // game.display();

    return 0;
}
