#include <iostream>

using namespace std;

int main(){
    
	//declaring variables
    char board[3][3] = { '*', '*', '*', '*', '*', '*', '*', '*', '*' };
    char player = 'O';
    int xWins = 0;
    int oWins = 0;
    bool playagain = true;
    bool xWin = false;
    bool oWin = false;
    int rounds = 1;
    int input;
    char again = 'y';
    
    //loop through player moves
    while (playagain == true){
        
    //switching between X and O
    if (player == 'X') {
		player = 'O';
    }
	else {
		player = 'X';
	}
	    
    //taking in user input
	cout << "Enter a move (1-9): ";
	cin >> input;
    
	//assigning user move to 2d board
	if (input == 1 && board[0][0] == '*') {
		board[0][0] = player;
	}
	else if (input == 2 && board[0][1] == '*') {
		board[0][1] = player;
	}
	else if (input == 3 && board[0][2] == '*') {
		board[0][2] = player;
	}
	else if (input == 4 && board[1][0] == '*') {
		board[1][0] = player;
	}
	else if (input == 5 && board[1][1] == '*') {
		board[1][1] = player;
	}
	else if (input == 6 && board[1][2] == '*') {
		board[1][2] = player;
	}
	else if (input == 7 && board[2][0] == '*') {
		board[2][0] = player;
	}
	else if (input == 8 && board[2][1] == '*') {
		board[2][1] = player;
	}
	else if (input == 9 && board[2][2] == '*') {
		board[2][2] = player;
	}
      
  //if spot is already taken
	else {
	    cout << "Already taken!" << endl;
	    if (player == 'X') {
		    player = 'O';
        }
    	else {
    		player = 'X';
    	}
    	rounds--;
	}
	
	//printing out the current board
	for (int i = 0; i < 3; i++){
		for (int j = 0; j < 3; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	
	
	//checking X win
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
		xWin = true;
	}
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') {
		xWin = true;
	}
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
		xWin = true;
	}
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
		xWin = true;
	}
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
		xWin = true;
	}
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
		xWin = true;
	}
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
		xWin = true;
	}
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') {
		xWin = true;
	}

	//checking O win
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
		oWin = false;
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') {
		oWin = false;
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
		oWin = false;
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
		oWin = false;
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
		oWin = false;
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
		oWin = false;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
		oWin = false;
	}
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') {
		oWin = false;
	}
		
	//if X wins
	if(xWin == true){
		
		//print out X wins and adds 1 to X total wins
	    cout << "X wins!" << endl;
	    xWins ++;
	    
	    //print out X and O total wins
	    cout << "X total wins: ";
	    cout << xWins << endl;
	    cout << "O total wins: ";
	    cout << oWins << endl;
	    
	    //asks user if they want to play again
	    cout << "Would you like to play again?(y/n) : " << endl;
	    cin >> again;
	    
	    //if they don't want to play again
	    if(again == 'n'){
	        playagain = false;
	    }
	    
	    //reseting board/variables if they want to play again
	    else{
	        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){  
                    board[i][j] = '*';
                }
            }
            player = 'O';
            xWin = false;
            oWin = false;
            rounds = 0;
	    }
	}
	
	//if O wins
	if(oWin == true){
	    cout << "O wins!" << endl;
	    oWins ++;
	    cout << "X total wins: ";
	    cout << xWins << endl;
	    cout << "O total wins: ";
	    cout << oWins << endl;
	    cout << "Would you like to play again?(y/n) : " << endl;
	    cin >> again;
	    if(again == 'n'){
	        playagain = false;
	    }
	    else{
	        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){  
                    board[i][j] = '*';
                }
            }
            player = 'O';
            xWin = false;
            oWin = false;
            rounds = 0;
	    }
	}
 
    //if it's a tie
    if(rounds == 9){
        cout << "Draw" << endl;
	    cout << "X total wins: ";
	    cout << xWins << endl;
	    cout << "O total wins: ";
	    cout << oWins << endl;
	    cout << "Would you like to play again?(y/n) : " << endl;
	    cin >> again;
	    if(again == 'n'){
	        playagain = false;
	    }
	    else{
	        for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){  
                    board[i][j] = '*';
                }
            }
            player = 'O';
            xWin = false;
            oWin = false;
            rounds = 0;
	    }
    }
    
    //increasing number of rounds (used for tie)
    rounds++;
    }
	return 0;
}
