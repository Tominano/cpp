/*Készíts egy kő, papír, olló játékot, amelyet a gép ellen lehet játszani.
A program kérjen be egy jelet a felhasználótól,
majd véletlenszerűen sorsoljon egyet magának is a három közül.
Több meccset is lehessen játszani, és közben készüljön statisztika a nyerési arányról
százalékos formában is.*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <string.h>

using namespace std;
    int eq = 0;
    int won = 0;
    int lose = 0;
    int round = 0;

    float compare()
    {   
        int guess;
        
        cout << "What is your guess ? for stone push 0, for paper push 1 or you want scissors push 2 ? " << endl;
        cin >> guess;
        
        srand (time(NULL));
        int num = rand()% 3;

        const char str1[][10] = {"Stone","Paper","Scissors"};
        
        if(strcmp(str1[guess],str1[0]) == 0)
        {
            if(strcmp(str1[guess],str1[num]) == 0)
            {
                cout << "Same guess!"<< "Both guess are: "<< str1[guess] << endl;
                    ++eq;
            }
            
            else if(strcmp(str1[1],str1[num])== 0)
            {
                cout << "The PC won!" << "You guess: "<< str1[guess] << ". PC guess: "<< str1[num] << endl;
                    ++lose;
            }
            
            else if(strcmp(str1[2],str1[num])== 0)
            {    
                cout << "You won!"<< "You guess: "<< str1[guess] << ". PC guess: "<< str1[num] << endl;
                    ++won;
            }
        }

        if(strcmp(str1[guess],str1[1]) == 0)
        {
            if(strcmp(str1[guess],str1[num]) == 0)
            {
                cout << "Same guess!"<< "Both guess are: "<< str1[guess] << endl;
                    ++eq;
            }
            
            else if(strcmp(str1[0],str1[num])== 0)
            {
                cout << "You won!" << "You guess: "<< str1[guess] << ". PC guess: "<< str1[num] << endl;
                    ++won;
            }
            
            else if(strcmp(str1[2],str1[num])== 0)
            {
                cout << "The PC won!"<< "You guess: "<< str1[guess] << ". PC guess: "<< str1[num] << endl;
                    ++lose;
            }
        }
        
        if(strcmp(str1[guess],str1[2]) == 0)
        {   
            if(strcmp(str1[guess],str1[num]) == 0)
            {
                cout << "Same guess!"<< "Both guess are: "<< str1[guess] << endl;
                    ++eq;
            }
            
            else if(strcmp(str1[0],str1[num])== 0)
            {
                cout << "The PC won!" << "You guess: "<< str1[guess] << ". PC guess: "<< str1[num] << endl;
                    ++lose;
            }
            
            else if(strcmp(str1[1],str1[num])== 0)
            {
                cout << "You won!"<< "You guess: "<< str1[guess] << ". PC guess: "<< str1[num] << endl;
                    ++won;
            }
        }

        cout << "Same guesses: " <<eq << ". Your lost games: "<< lose << ". Your won games: " << won <<  endl;
    return won/round;       
    }



void saz(int won, int round)
    {   
        float l = (won / round) * 100;
        cout << "Percent did you won: " << l << endl;
    }

int main()
{

    
    int round1 = 0;

    cout << "How much round would you like to play?: ";
    cin >> round;
   

    do
    {
        compare();
            ++round1;
    }
    while (round > round1);

    saz(won,round);

}
