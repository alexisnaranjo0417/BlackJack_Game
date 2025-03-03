/* 
 * File:   main.cpp
 * Author: Alexis Naranjo
 * Created on November 7, 2018, 7:00 PM
 * Purpose: BlackJack
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <ctime> 
#include <fstream>
using namespace std;

//User Libraries

//Global Constants Physics/Math/Conversions/Array

//Function Prototypes
void betRtr(float, float, float, char, string, int, int);
void filDeck(string c[],int n);
void prnDeck(string [],int,int);

//Execution begins with main
int main(int argc, char** argv) {
    
    //Set the random seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned int plyrH,dlrH,plyrCh;
    string name;
    float aBet,bBet,cBet,y1,y2,y3;
    char pBet;
    const int NUMCRDS=52;
    string deck[NUMCRDS];
    
    //Opens an input file for bets, and a output file for hits and stands.
    ifstream input;
    ofstream output;
    input.open("bets.dat");                 //Opens file to display bets at
    input>>aBet>>bBet>>cBet;                //$1.00,$2.50,$5.00.
    output.open("hns.dat");
    
    //Map or process the variables to their outputs
    const unsigned int plyrC1 = rand()%11+1;//Players first card.
    const unsigned int plyrC2 = rand()%11+1;//Players second card.
    const unsigned int dlrC1 = rand()%11+1; //Dealers first card.
    const unsigned int dlrC2 = rand()%11+1; //Dealers second card.
    plyrH = plyrC1 + plyrC2;                //Adds Players two cards for hand.
    dlrH = dlrC1 + dlrC2;                   //Adds Dealers two cards for hand.
    y1=(sqrt(4))/2;                         //Calculates players money win at a
                                            //$1.00 bet.
    y2=(sqrt(25))/2;                        //Calculates players money win at a
                                            //$2.50 bet.
    y3=(sqrt(100))/2;                       //Calculates players money win at a
                                            //$5.00 bet.
    
    //Display or return the output
    cout<<"This game of blackjack will choose from this deck of cards."<<endl;
    filDeck(deck,NUMCRDS);
    prnDeck(deck,NUMCRDS,NUMCRDS/4);
    //Shows player what to enter for what bet, and displays bets within file.
    cout<<fixed<<setprecision(2)<<"Enter a for a $"<<aBet<<"."<<endl;
    cout<<fixed<<setprecision(2)<<"Enter b for a $"<<bBet<<"."<<endl;
    cout<<fixed<<setprecision(2)<<"Enter c for a $"<<cBet<<"."<<endl;
    cout<<"Please enter a bet and a name for yourself."<<endl;
    //Ask the user to enter a bet and a name to display at the end.
    cin>>pBet>>name;
    switch(pBet){
        case 'a':cout<<fixed<<setprecision(2)<<"$"<<aBet
                <<" bet entered."<<endl;break;
        case 'b':cout<<fixed<<setprecision(2)<<"$"<<bBet
                <<" bet entered."<<endl;break;
        case 'c':cout<<fixed<<setprecision(2)<<"$"<<cBet
                <<" bet entered."<<endl;break;
    } 
    cout<<"Dealers first card"<<endl;
    cout<<setw(10)<<static_cast<int>(dlrC1)<<endl; //Displays dealers
                                                   //first card.
    cout<<"---------------------"<<endl;
    cout<<setw(14)<<"Your Hand"<<endl;
    cout<<setw(8)<<static_cast<int>(plyrC1);      //Displays players first card.
    cout<<setw(4)<<static_cast<int>(plyrC2)<<endl;//Displays players
                                                  //second card.
    if(plyrH>21){                                 //If players original hand is
        cout<<"---------------------"<<endl;      //greater than 21 it will
        cout<<setw(12)<<"Bust!"<<endl;            //display bust.
        cout<<"---------------------"<<endl;
        cout<<setw(8)<<dlrC1;
        cout<<setw(4)<<static_cast<int>(dlrC2)<<endl;
        cout<<setw(10)<<static_cast<int>(dlrH)<<endl;
        //This decides the winner of the game.
        betRtr(y1, y2, y3, pBet, name, plyrH, dlrH); 
    }
    else if(plyrH<=21){
        cout<<setw(10)<<static_cast<int>(plyrH)<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Enter 1 to hit or enter 2 to stand."<<endl;
        cout<<"Your hand is "<<plyrH<<endl;
        cout<<"---------------------"<<endl;
        //Will repeatedly ask the user to input 1 or 2 until the user bust
        //or user enters 2 to stand.
        do {
            //User inputs his or her choice to hit with 1 or stand with 2.
            cin>>plyrCh;
            output<<plyrCh<<endl;
            if(plyrCh==1 || plyrCh==2){
                switch(plyrCh){
                    case 1://Players hit will be added to their hand.
                           plyrH += rand()%11+1;
                           cout<<"Your hand is "<<plyrH<<endl;
                           cout<<"Enter 1 to hit or enter 2 to stand."<<endl;
                           cout<<"---------------------"<<endl;break;
                    case 2://If the player doesn't bust with their original
                           // hand or if the player doesn't bust while
                           // hitting and decides to stand then
                           //this set of code is ran.
                           cout<<setw(15)<<"Dealers Hand"<<endl;
                           //Displays dealers first card.
                           cout<<setw(8)<<dlrC1;
                           //Displays dealers second card.
                           cout<<setw(4)<<static_cast<int>(dlrC2)<<endl;
                           //Displays dealers original hand.
                           cout<<setw(10)<<static_cast<int>(dlrH)<<endl;
                           //If the players hand is greater than dealers
                           // original hand it will continue to hit until
                           //it beats the players hand or it bust.
                           while(dlrH<plyrH && dlrH<22){
                               dlrH += rand()%11+1;
                               cout<<setw(10)<<dlrH<<endl;
                           }
                           //Displays a bust for the dealer if it's original
                           //or new hand is over 21.
                           if(dlrH>21){
                               cout<<"---------------------"<<endl;
                               cout<<setw(12)<<"Bust!"<<endl;
                           }
                           cout<<"---------------------"<<endl;
                           //This decides the winner of the game.
                           betRtr(y1, y2, y3, pBet, name, plyrH, dlrH);           
                }
            }
            else{
                cout<<"Invalid input, try again."<<endl;
                cout<<"Enter 1 to hit or enter 2 to stand."<<endl;
            }
        }    
        //This allows the code above to run as long as the players hand is
        //less than 22.
        while(plyrH<22 && plyrCh==1);
    }    
    if(plyrH>21){
        //If the players new hand is over 21 then the
        //code below is ran.
        cout<<setw(12)<<"Bust!"<<endl;
        cout<<"---------------------"<<endl;
        cout<<setw(15)<<"Dealers Hand"<<endl;
        cout<<setw(8)<<dlrC1;
        cout<<setw(4)<<static_cast<int>(dlrC2)<<endl;
        cout<<"---------------------"<<endl;
        if(dlrH>21){
            cout<<setw(12)<<"Bust!"<<endl;
            cout<<"---------------------"<<endl;
        }
        cout<<setw(10)<<static_cast<int>(dlrH)<<endl;
        //This decides the winner of the game.
        betRtr(y1, y2, y3, pBet, name, plyrH, dlrH);   
    }
    
    //Closes files.
    input.close();
    output.close();
    
    return 0;
}

void betRtr(float y1, float y2, float y3, char pBet, string name,
            int plyrH, int dlrH){
    cout<<setw(4)<<"Winner is ";
    //If both the players and the dealers hands
    //are over 21 then no one wins.
    if(plyrH > 21 && dlrH > 21){
        cout<<"no one."<<endl;
    }
    //If the players hand is greater than 21
    //the dealer wins.
    else if(plyrH > 21){
        cout<<"Dealer."<<endl;
    }
    //If the dealers hand is greater than 21
    //the player wins.
    else if(dlrH > 21){
        cout<<name<<"."<<endl;
    }
    //If none of the above occur then this set is tested.
    else{
        //If the players hand is greater than
        //the dealers hand than the player wins.
        if (plyrH > dlrH){
            cout<<name<<"."<<endl;
        }
        //If the dealers hand is greater than
        //the players hand than the dealer wins.
        else if (dlrH > plyrH){
            cout<<"Dealer."<<endl;
        }
        //If the players hand is equal to the dealers
        //hand then no one wins.
        else if(plyrH = dlrH){
            cout<<"no one."<<endl;
        }
    }
    //Displays money return for a bet at $1.00 where
    //no one wins.
    if(pBet=='a'){
        if(plyrH > 21 && dlrH > 21 || plyrH == dlrH){
            cout<<"You keep your $1.00"<<endl;
        }
        //Displays money won or loss for a bet at
        //$1.00 where no one wins.
        else{
            plyrH>dlrH && plyrH<=21 || dlrH>21 ?
                cout<<"You win $"<<y1 : cout<<"You lose $"<<y1;
        }
    }
    //Displays money return for a bet at $2.50 where
    //no one wins.
    else if(pBet=='b'){
        if(plyrH > 21 && dlrH > 21 || plyrH == dlrH){
            cout<<"You keep your $2.50"<<endl;
        }
        //Displays money won or loss for a bet at
        //$2.50 where no one wins.
        else{
            plyrH>dlrH && plyrH<=21 || dlrH>21 ?
                cout<<"You win $"<<y2 : cout<<"You lose $"<<y2;
        }
    }
    //Displays money return for a bet at $5.00 where
    //no one wins.
    else if(pBet=='c'){
        if(plyrH > 21 && dlrH > 21 || plyrH == dlrH){
            cout<<"You keep your $5.00"<<endl;
        }
        //Displays money won or loss for a bet at
        //$5.00 where no one wins.
        else{
            plyrH>dlrH && plyrH<=21 || dlrH>21 ?
                cout<<"You win $"<<y3 : cout<<"You lose $"<<y3;
        }
    }
    exit(0);
}

void prnDeck(string c[],int n,int perLine){
    for(int i=0;i<n;i++){
        cout<<c[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void filDeck(string c[],int n){
    //Spades, Hearts, Clubs, Diamonds
    char suit[]={'S','H','C','D'};
    char face[]={'A','2','3','4','5','6','7','8','9','T','J','Q','K'};
    for(int i=0;i<n;i++){
        c[i]=face[i%13];
        c[i]+=suit[i/13];
    }
}