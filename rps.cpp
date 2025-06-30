#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

string getChoiceName(int choice) {
    switch(choice) {
        case 1: return "✊ Rock";
        case 2: return "✋ Paper";
        case 3: return "✌️ Scissors";
        default: return "Invalid";
    }
}

int determineWinner(int user, int computer) {
    if (user == computer) return 0; // Tie
    if ((user == 1 && computer == 3) || 
        (user == 2 && computer == 1) || 
        (user == 3 && computer == 2)) return 1; // User wins
    return -1; // Computer wins
}

int main() {
    srand(time(0)); // Initialize random seed
    
    cout << "🎮 Rock Paper Scissors Game 🎮\n";
    cout << "1. Rock\n2. Paper\n3. Scissors\n\n";
    
    int userScore = 0, computerScore = 0;
    
    while(true) {
        cout << "Enter choice (1-3) or 0 to quit: ";
        int userChoice;
        cin >> userChoice;
        
        if (userChoice == 0) break;
        if (userChoice < 1 || userChoice > 3) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }
        
        int computerChoice = rand() % 3 + 1;
        
        cout << "\nYou: " << getChoiceName(userChoice) << "\n";
        cout << "Computer: " << getChoiceName(computerChoice) << "\n";
        
        int result = determineWinner(userChoice, computerChoice);
        
        if (result == 0) {
            cout << "It's a tie!\n";
        } else if (result == 1) {
            cout << "You win!\n";
            userScore++;
        } else {
            cout << "Computer wins!\n";
            computerScore++;
        }
        
        cout << "Score - You: " << userScore << " | Computer: " << computerScore << "\n\n";
    }
    
    cout << "\nFinal Score:\n";
    cout << "You: " << userScore << "\n";
    cout << "Computer: " << computerScore << "\n";
    cout << "Thanks for playing! 😊\n";
    
    return 0;
}