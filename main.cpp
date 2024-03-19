#include <iostream>
#include <stdlib.h>
using namespace std;

//class game where all functions of the game runs
class game {
private:
    //Intializing variables used within class only
    int choice;
    int row,column;
    //Array for the board
    char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
public:
    //Intializing public variables 
    char turn = 'X';
    bool draw = false;
    void display_board();
    void player_turn();
    bool gameover();
};

void game::display_board(){
    //Rander Game Board LAYOUT
       cout << "\t\t-------------\n"; 
    for (int i = 0; i < 3; i++) { 
        cout << "\t\t| "; 
        for (int j = 0; j < 3; j++) { 
            cout << board[i][j] << " | "; 
        } 
        cout << "\n\t\t-------------\n"; 
    }
    }
    
void game::player_turn(){
        //Function to get the player input and update the board
        if(turn == 'X'){
            cout<<"\n\tPlayer - 1 [X] turn : ";
        }
        else if(turn == 'O'){
            cout<<"\n\tPlayer - 2 [O] turn : ";
        }
        //Taking input from user
        cin>> choice;
        //switch case to get which row and column will be update
        switch(choice){
            case 1: row=0; column=0; break;
            case 2: row=0; column=1; break;
            case 3: row=0; column=2; break;
            case 4: row=1; column=0; break;
            case 5: row=1; column=1; break;
            case 6: row=1; column=2; break;
            case 7: row=2; column=0; break;
            case 8: row=2; column=1; break;
            case 9: row=2; column=2; break;
            default:
                cout<<"Invalid Move";
        }
    
        if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O'){
            //updating the position for 'X' symbol if
            //it is not already occupied
            board[row][column] = 'X';
            turn = 'O';
        }else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O'){
            //updating the position for 'O' symbol if
            //it is not already occupied
            board[row][column] = 'O';
            turn = 'X';
        }else {
            //if input position already filled
            cout<<"Box already filled!n Please choose another!!\n\n";
            player_turn();
        }
    }

bool game::gameover(){
        //Function to get the game status
        
        //checking the win for Simple Rows and Simple Column
        for(int i=0; i<3; i++)
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        return false;
    
        //checking the win for both diagonal
        if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;
    
        //Checking the game is in continue mode or not
        for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
        if(board[i][j] != 'X' && board[i][j] != 'O')return true;
    
        //Checking the if game already draw
        draw = true;
        return false;
}

int main()
{
    //Program Main Method
    game tictac; //object intialization
    cout<<"\tT I C K  T A C  T O E ";
    cout<<"\n\t\tFOR 2 PLAYERS\n";
    tictac.display_board();
    while(tictac.gameover()){
        tictac.player_turn();
        tictac.display_board();
        tictac.gameover();
    }
    if(tictac.turn == 'X' && tictac.draw == false){
        cout<<"\n\nCongratulations!Player with '0' has won the game";
    }
    else if(tictac.turn == 'O' && tictac.draw == false){
        cout<<"\n\nCongratulations!Player with 'X' has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!";

    
}  
