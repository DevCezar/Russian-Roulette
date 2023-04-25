#include<iostream>
#include<Windows.h>
#include "RussianRoulette.h"
using namespace std; 

//Function Prototypes
int roundsAsk();
int livesAsk();

// Global Variables
int rounds,
    lives;

int main() {
    bool play = true;       // Set to true so you can play
    bool spinAgain = true;
    int position = 0;
    string spinny;

    while (play) { 
        // Preround Questions Start
        roundsAsk();        // Asking how many rounds;
        livesAsk();         // Asking how many lives;
        RRPG game(rounds, lives); // Setting parameters;
        game.gun();
        game.statsDisplay();        // Displaying Parameters
        // Preround Questions End

        // Parameters being set for bot / player start
        bot bob(lives);     // Setting bot lives;
        player one(lives);  // Setting player lives;
        // Parameters being set for bot / player end

        // Declares who starts
        if (one.DiceRoll() > bob.DiceRoll()) {
            cout << "You start the game\n\n" << endl;
        } else {
            cout << "Bot Starts\n\n" << endl;
            Sleep(1500);
            cout << "Bob shot the gun\n";
            game.shootGun();
            bob.displayLives();
            cout << "\n";
        }
        // Declares who starts - end;

        // Keep spinning until lives run out
        while (one.getLives() > 0 && bob.getLives() > 0) {
            // asking to spin start
            do { 
                cout << "Would you like to spin the barrel? Y/N: ";
                cin >> spinny;
                if (spinny == "Y" || spinny == "y") {
                    cout << "Spinning...";
                    Sleep(1500);
                    spinAgain = true;
                    cout << "The barrel was spun" << endl;
                    game.gun(); 
                } else if (spinny == "N" || spinny == "n") {
                    system("cls");
                    Sleep(80);
                    cout << "You pulled the trigger...";
                    Sleep(1200);
                    spinAgain = false;
                    if (game.shootGun() == true) { 
                        cout << "you got shot" << endl;
                        game.gun();
                        if (one.removeLife() == 0) {
                            play = false;
                        }
                        one.displayLives();
                        cout << "Automatically spinning the barrel to reset chances." << endl; 
                    } else {
                        cout << "Lucky duck it was a blank..." << endl;
                        Sleep(1500);
                        one.displayLives();
                    } 
                }
            } while (spinAgain); 

            // Bot's turn
            if (bob.getLives() > 0) {
                cout << "\nBot's turn: " << endl;
                Sleep(1500);
                if (game.shootGun() == true) {
                    cout << "Unlucky bob got shot\n\n";
                    game.gun();
                    if (bob.removeLife() == 0) {
                        cout << "Bob the bot died.\n\n" << endl;
                    } else {
                        bob.displayLives();
                    cout << "Automatically spinning the barrel to reset chances." << endl; 
                    }
                } else {
                    cout << "the gun went click'" << endl;
                    bob.displayLives();
                    cout << "\n\n";
                }
            }
        }

        if (one.getLives() == 0) {
            system("cls");
            cout << "\t\t\tGame Over. You died." << endl;
        } else if (bob.getLives() == 0) {
            system("cls");
            cout << "\t\t\tCongratulations! You won!" << endl;
        }
    } 

    return 0;
}

int roundsAsk() {
    cout << "How many Rounds? " << endl;
    cin >> rounds;
    return rounds;
}

int livesAsk(){
    cout << "How many lives? " << endl;
    cin >> lives;
    return lives;
}

// Add scores plus rounds functionality (Need rounds to update score)
// plus add ability to change bullets in the chamber(OPTIONAL)
