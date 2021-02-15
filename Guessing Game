#include <iostream>

using namespace std;

int main(){

	//declaring variables
	int input = 0;
	int number = 0;
	int tries = 0;
	char playagain = 'y';
	
	//generating random number between 0 and 100
	srand(time(NULL)); 
	number = rand() % 101;
	
	//while loop to keep running until user guesses the number
	while(input != number && playagain == 'y'){
	
		//taking in user input
		cout << "Guess a number between 0 and 100 inclusive: ";
		cin >> input;
		
		//increasing the number of tries it took
		tries += 1;

		//if the guess is too low
		if(input < number){
			cout << "Your guess is too low\n";
		}
		
		//if the guess is too high
		else if(input > number){
			cout << "Your guess is too high\n";
		}
		
		//if the guess is correct
		else{
		
			//ask the user if they want to play again
			cout << "Your guess is correct, it took you " << tries << " tries. Do you want to play again? (y/n)\n";
			cin >> playagain;
			
			//if user input is n (no), the code will stop
			if(playagain == 'n'){
				cout << "Thanks for playing";
			}
			
			//if user input is y (yes), the code will continue with a new random number and the number of tries reset
			else{
				srand(time(NULL)); 
				number = rand() % 101;
				tries = 0;
			}
		}
	}
	//end
	return 0;
}
