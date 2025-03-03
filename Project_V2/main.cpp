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
    unsigned int plyrC1,plyrC2,dlrC1,dlrC2,hit,plyrH,dlrH,plyrCh,pHit1;
    
    //Initialize Variables
    
    //Map or process the variables to their outputs
    plyrC1 = rand()%11+1;
    plyrC2 = rand()%11+1;
    dlrC1 = rand()%11+1;
    dlrC2 = rand()%11+1;
    plyrH = plyrC1 + plyrC2;
    dlrH = dlrC1 + dlrC2;
    hit = rand()%11+1;
    pHit1 = plyrH + hit;
    
    //Display or return the output
    cout<<"Dealers first card"<<endl;
    cout<<static_cast<int>(dlrC1)<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Your Hand"<<endl;
    cout<<static_cast<int>(plyrC1)<<" ";
    cout<<static_cast<int>(plyrC2)<<endl;
    if(plyrH>21){
        cout<<"Bust!"<<endl;
    }
    cout<<static_cast<int>(plyrH)<<endl;
    cout<<"---------------------"<<endl;
    cout<<"Enter 1 to hit or enter 2 to stand."<<endl;
    cout<<"Your hand is "<<plyrH<<endl;
    cout<<"---------------------"<<endl;
    do {
    cin>>plyrCh;
    switch(plyrCh){
        case 1:plyrH += rand()%11+1;
               cout<<"Your hand is "<<plyrH<<endl;
               cout<<"Enter 1 to hit or enter 2 to stand."<<endl;break;
        case 2:cout<<"Dealers Hand"<<endl;
               cout<<dlrC1<<" ";
               cout<<static_cast<int>(dlrC2)<<endl;
               if(dlrH>21){
                   cout<<"Bust!"<<endl;
               }
               cout<<static_cast<int>(dlrH)<<endl;
               cout<<"---------------------"<<endl;
               cout<<"Winner is";
               if(plyrH > 21 && dlrH > 21){
                   cout<<" no-one.";
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
                   cout<<" no-one."<<endl;
                   }
               }
               return 0;
                   break;
        }
    }
    while(plyrH<22);
    cout<<"Bust!"<<endl;
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
                   cout<<" no-one.";
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
                   cout<<" no-one."<<endl;
                   }
               }

    return 0;
}

