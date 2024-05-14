#include<iostream>
#include <random>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;
void game(int user,int comp,int &u,int &c) {
    if(user==comp) {
        cout<<"Tied! Try again\n";
        return;
    }
    if((user==1 && comp==3) || (user==2 && comp==1) || (user==3 && comp==2)) {
      u++;  
      cout<<"You WON!\n";
      cout<<"To exit enter 'E' and to play enter your choice:\n";
    }
    else {
      c++;
      cout<<"Computer wins!\n";
      cout<<"Try again or Exit 'E'\n";
    }
}
void computer(int com) {
    if(com==1) cout<<"Computer Choice->Rock\n";
    else if(com==2) cout<<"Computer Choice->Paper\n";
    else if(com==3) cout<<"Computer Choice->Scissor\n";
}

int main() {
    int userChoice , compChoice;
    cout<<"Let's Play Rock Paper and Scissor!\n";

    cout<<"Enter 'R' for Rock\n";
    cout<<"Enter 'P' for Paper\n";
    cout<<"Enter 'S' for Scissor\n";
    char ch;
    int comp=0,user=0;
    srand(static_cast<unsigned int>(time(0)));
    do {
        cout<<"Enter Your Choice: ";
        cin>>ch;
        compChoice = rand() % 3 + 1;
        
        switch(ch) {
            case 'R':
              userChoice=1;
              computer(compChoice);
              game(userChoice,compChoice,user,comp);
              break;
            case 'P':
              userChoice=2;
              computer(compChoice);
              game(userChoice,compChoice,user,comp);
              break;
            case 'S':
              userChoice=3;
              computer(compChoice);
              game(userChoice,compChoice,user,comp);
              break;
            case 'E':
              cout<<"Exiting!\n";
              break;
            default:
              cout<<"Invalid choice! Try again\n";
              break;
        }
    } while (ch!='E');

    cout<<"Computer points: "<<comp<<endl;
    cout<<"Your points: "<<user<<endl;
    if(comp>user) {
      cout<<"Oops You LOSE!"<<endl;
    }
    else if(user>comp) cout<<"YAY! You WON\n";
    else cout<<"Teid!";

    return 0;
}