/*
4/23/23
Cesar Rodriguez
Week 13 Question 1

In Designing your game, you will need at least 2 Private Attributes in .h and 2 Parameters 
from .cpp that will change the value of Private Data.

There must be a set of decisions in .cpp (preferably a loop) that adjust the Attributes.

*/
#include<iostream>
#include<Windows.h>
#include "RussianRoulette.h"
using namespace std; 


//Function Prototypes
int roundsAsk();
int livesAsk();
int spinGun();


// Global Variables
int rounds,
    lives,
    spinValue;



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
                    Sleep(800);
                    cout << "You pulled the trigger...";
                    Sleep(900);
                    spinAgain = false;
                    if (game.shootGun() == true) { 
                        cout << "you got shot" << endl;
                        if (one.removeLife() == 0) {
                            one.displayLives();
                            play = false;
                            game.gun();
                        } 
                    } else {
                        cout << "Lucky duck it was a blank..." << endl;
                        Sleep(1500);
                        one.displayLives();
                        game.gun();
                    } 
                }
            } while (spinAgain); 

            // Bot's turn
            if (bob.getLives() > 0) {
                cout << "\nBot's turn: " << endl;
                Sleep(1500);
                if (game.shootGun() == true) {
                    cout << "Unlucky bob got shot\n\n";
                    if (bob.removeLife() == 0) {
                        cout << "Bob the bot died.\n\n" << endl;
                    } else {
                        bob.displayLives();
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
