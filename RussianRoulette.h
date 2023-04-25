#pragma once 

#include<iostream>
#include<time.h>
#include<cctype>
using namespace std;


class RRPG {
    private: 
        int rounds,
            lives,
            bulletSpot,
            position = -1;
        int shoot;
        bool arr[6] = {false , false, false, false, false, false}; 
    public:
        RRPG(int amtRounds, int amtLives){
            rounds = amtRounds;
            lives = amtLives;
        }
        void statsDisplay(){
            system("cls");
            cout << "Game Rules" << endl; 
            cout << "============" << endl;
            cout << "Amount of bullets in chamber 1/6 " << endl;  
            cout << "Best of " << rounds << " round(s)" << endl;
            cout << "Starting lives: " << lives << endl;
            cout << endl;
        }
        void gun(){ 
            bool arr[6] = {false , false, false, false, false, false};
            srand(time(NULL));
            bulletSpot = (rand() % 5) + 1; // Spot in gun for the bullet
            arr[bulletSpot] = true;
            position -= 1;
            spotInLine();
        }
        int spotInLine(){ 
            position += 1; 
            return position;
        }

        int shootGun() {
            position += 1;
            if (position > 6) {
                position = -1;
            }
            bool deadOrAlive = false;
            if (position == bulletSpot){
                deadOrAlive = true;
            } else {
                deadOrAlive = false;
            }
            return deadOrAlive;
        }
};

class bot{
    private: 
        int score,
            diceroll, 
            lives;
    public: 
        bot(int setLives){
            lives = setLives;
        }
        int DiceRoll(){
            srand(time(NULL));
            int randomspot = (rand() % 9) + 1;
            return randomspot;
        }
        int removeLife(){
            lives = lives - 1; 
            return lives;
        }
        int getLives() {
            return lives;
        }
        void displayLives(){
            cout << "Bob the bots lives: " << lives << endl;
        }
};

class player{
    private:
        int score,
            diceroll, 
            lives;
    public:
        player(int setLives){
            lives = setLives;
        }
        int DiceRoll(){
            int randomspot = (rand() % 9) + 1;
            srand(time(NULL));
            return randomspot;
        }
        int removeLife(){
            lives = lives - 1; 
            return lives;
        }
        int getLives() {
            return lives;
        }
        void displayLives(){
            cout << "Your lives: " << lives << endl;
        }
};