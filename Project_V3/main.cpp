/* 
 * File:   main.cpp
 * Author: Alexis Naranjo
 * Created on August 28, 2018, 11:27 AM
 * Purpose: BlackJack
 */

//System Libraries
#include <iostream>
#include <cstdlib>
using namespace std;

//User Libraries

//Global Constants Physics/Math/Conversions/Array

//Function Prototypes

//Execution begins with main
int main(int argc, char** argv) {
    
//Set the random seed.
    srand(static_cast<unsigned int>(time(0)));
    
//Declare Variables
    unsigned int plyrH,dlrH,plyrCh;
    
    //Initialize Variables
    
    //Map or process the variables to their outputs
    const unsigned int plyrC1 = rand()%11+1;//Players first card.
    const unsigned int plyrC2 = rand()%11+1;//Players second card.
    const unsigned int dlrC1 = rand()%11+1; //Dealers first card.
    const unsigned int dlrC2 = rand()%11+1; //Dealers second card.
    plyrH = plyrC1 + plyrC2;                //Adds Players two cards for hand.
    dlrH = dlrC1 + dlrC2;                   //Adds Dealers two cards for hand.
    
    //Display or return the output
    cout<<"Dealers first card"<<endl;
    cout<<static_cast<int>(dlrC1)<<endl; //Displays dealers first card.
    cout<<"---------------------"<<endl;
    cout<<"Your Hand"<<endl;
    cout<<static_cast<int>(plyrC1)<<" "; //Displays players first card.
    cout<<static_cast<int>(plyrC2)<<endl;//Displays players second card.
    if(plyrH>21){                        //If players original hand is
        cout<<"Bust!"<<endl;             //greater than 21 it will 
    }                                    //display bust.
    cout<<static_cast<int>(plyrH)<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter 1 to hit or enter 2 to stand."<<endl;
    cout<<"Your hand is "<<plyrH<<endl;
    cout<<"---------------------"<<endl;
    //Will repeatedly ask the user to input 1 or 2 until the user bust
    //or user enters 2 to stand.
    do {
    //User inputs his or her choice to hit with 1 or stand with 2.
    cin>>plyrCh;
    switch(plyrCh){
        case 1:plyrH += rand()%11+1;//Players hit will be added to their hand.
               cout<<"Your hand is "<<plyrH<<endl;
               cout<<"Enter 1 to hit or enter 2 to stand."<<endl;
               cout<<"---------------------"<<endl;break;
        case 2://If the player doesn't bust with their original hand or
               //if the player doesn't bust while hitting and decides
               //to stand then this set of code is ran.
               cout<<"Dealers Hand"<<endl;
               //Displays dealers first card.
               cout<<dlrC1<<" ";
               //Displays dealers second card.
               cout<<static_cast<int>(dlrC2)<<endl;
               //Displays dealers original hand.
               cout<<static_cast<int>(dlrH)<<endl;
               //If the players hand is greater than dealers original hand
               //it will continue to hit until it beats the players
               //hand or it bust.
               while(dlrH<plyrH && dlrH<22){
                   dlrH += rand()%11+1;
                   cout<<dlrH<<endl;
               }
               //Displays a bust for the dealer if it's original or new hand
               //is over 21.
               if(dlrH>21){
                   cout<<"Bust!"<<endl;
               }
               cout<<"---------------------"<<endl;
               //This decides the winner of the game.
               cout<<"Winner is";
               //If both the players and the dealers hands are over 21
               //then no one wins.
               if(plyrH > 21 && dlrH > 21){
                   cout<<" no one.";
               }
               //If the players hand is greater than 21 the dealer wins.
               else if(plyrH > 21){
                   cout<<" Dealer."<<endl;
               }
               //If the dealers hand is greater than 21 the player wins.
               else if(dlrH > 21){
                   cout<<" You."<<endl;
               }
               //If none of the above occur then this set is tested.
               else{
                   //If the players hand is greater than the dealers
                   //hand than the player wins.
                   if (plyrH > dlrH){
                       cout<<" You."<<endl;
                   }
                   //If the dealers hand is greater than the players
                   //hand than the dealer wins.
                   else if (dlrH > plyrH){
                       cout<<" Dealer."<<endl;
                   }
                   //If the players hand is equal to the dealers hand then
                   //no one wins.
                   else if(plyrH = dlrH){
                   cout<<" no one."<<endl;
                   }
               }
               return 0;break;
        }
    }
    //This allows the code above to run as long as the players hand is
    //less than 22.
    while(plyrH<22);
    //If the players original hand or new hand is over 21 then the
    //code below is ran.
    cout<<"Bust!"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Dealers Hand"<<endl;
               cout<<dlrC1<<" ";
               cout<<static_cast<int>(dlrC2)<<endl;
               cout<<"---------------------"<<endl;
               if(dlrH>21){
                   cout<<"Bust!"<<endl;
               }
               cout<<static_cast<int>(dlrH)<<endl;
    cout<<"Winner is";
               if(plyrH > 21 && dlrH > 21){
                   cout<<" no one.";
               }
               else if(plyrH > 21){
                   cout<<" Dealer."<<endl;
               }
               else if(dlrH > 21){
                   cout<<" You."<<endl;
               }
               else{
                   if (plyrH > dlrH){
                       cout<<" You."<<endl;
                   }
                   else if (dlrH > plyrH){
                       cout<<" Dealer."<<endl;
                   }
                   else if(plyrH = dlrH){
                   cout<<" no one."<<endl;
                   }
               }

    return 0;
}

