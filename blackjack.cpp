#include <iostream>
#include <string>
#include <ctime>


using namespace std;

int main(){

    bool game_on = true;

    int num1, num2, total;
    string name;

    unsigned seed = time(0);
    srand(seed);

    num1 = (1 + rand() % 10);
    num2 = (1 + rand() % 10);
    total = num1 + num2;

    int gamechoice;
    cout << "Welcome to Blackjack!\nInput '1' to Enter Casino or Input '2' to Leave Casino: ";
    cin >> gamechoice;

    if(gamechoice == 1){
        cout << "\nPlease Enter Your Name: ";
    cin >> name;
    
    name[0]=toupper(name[0]);

    
    char begin;
    cout << "Hello " << name << "!\nPlease Enter 'B' to Begin: ";
    cin >> begin;
    }
    else if (gamechoice == 2){
        cout << "Coward...";
        game_on = false;

    }
    

    











return 0;

}
