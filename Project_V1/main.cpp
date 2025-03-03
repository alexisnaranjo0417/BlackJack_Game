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
    
//Set the random seed here!
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    unsigned char plyrC1,plyrC2,dlrC1,dlrC2,plyrCs,dlrCs,plyrH,dlrH;
    
    //Initialize Variables
    
    //Map or process the variables to their outputs
    plyrC1 = rand()%11+1;
    plyrC2 = rand()%11+1;
    dlrC1 = rand()%11+1;
    dlrC2 = rand()%11+1;
    plyrH = plyrC1 + plyrC2;
    dlrH = dlrC1 + dlrC2;
    
    //Display or return the output
    cout<<"Players Hand"<<endl;
    cout<<static_cast<int>(plyrC1)<<" ";
    cout<<static_cast<int>(plyrC2)<<endl;
    if(plyrH>21){
        cout<<"Bust!"<<endl;
    }
    cout<<static_cast<int>(plyrH)<<endl;
    cout<<"Dealers Hand"<<endl;
    cout<<static_cast<int>(dlrC1)<<" ";
    cout<<static_cast<int>(dlrC2)<<endl;
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
        cout<<" Player."<<endl;
    }
    else{
        if (plyrH > dlrH){
            cout<<" Player."<<endl;
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

