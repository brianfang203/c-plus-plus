#include <iostream>
#include <cstring>

using namespace std;

int main(){
    
    //declaring variables
    char str[80];
    char str2[80];
    bool found = false;
    int count = 0;

    //taking in user input
    cout << "Enter a sentence: ";
    cin.get(str, 80);
    
    //looping through characters in input to filter out spaces and punctuation
    for(int i = 0; i <= strlen(str); i++){
        if((str[i] != ' ') && (ispunct(str[i]) == false)){
            str2[count] = tolower(str[i]);
            count++;
        }
    }

    //comparing each character from the outside ends to the middle
    for(int j = 0; j < strlen(str2) / 2; j++){
        if(found == false){
            
            //if they don't match, it is not a palindrome
            if(str2[j] != str2[strlen(str2) - 1 - j]){
                found = true;
            }
        }
    }

    //printing out results
    if(found == false){
        cout << "Palindrome.";
    }
    
    else{
        cout << "Not a palindrome.";
    }

    return 0;
    
}
