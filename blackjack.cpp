#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

using namespace std;

int main() {
    // Declaring variables

    int pnum1, pnum2, ptotal;
    int dnum1, dnum2, dtotal;

    string name;
    char choice;
    char move;

    // Establishing random seed
    unsigned seed = time(0);
    srand(seed);

    // Game loop
    int gamechoice;
    
        cout << "Welcome to Blackjack!\nInput '1' to Enter Casino or Input '2' to Leave Casino: ";
    do { cin >> gamechoice;

        // Game executes after user input
        if (gamechoice == 1) {
            cout << "Please Enter Your Name: ";
            cin >> name;

            name[0] = toupper(name[0]);

            cout << "Hello " << name << "!\nPlease Enter 'B' to Begin or 'Q' to Quit: ";
            do {
                cin >> choice;

                if (choice == 'B' || choice == 'b') {
                    // Deal initial hands
                    pnum1 = (1 + rand() % 10);
                    pnum2 = (1 + rand() % 10);
                    ptotal = pnum1 + pnum2;

                    dnum1 = (1 + rand() % 10);
                    dnum2 = (1 + rand() % 10);
                    dtotal = dnum1 + dnum2;

                    cout << "Dealer's Hand: " << dtotal << endl;
                    cout << name << "'s Starting Hand: " << ptotal << endl;

                    // Player's turn to hit or stand
                    do {
                        cout << "Enter 'H' to Hit or 'S' to Stand: ";
                        cin >> move;

                        if (move == 'H' || move == 'h') {
                            int newCard = (1 + rand() % 10); // Deal a new card
                            ptotal += newCard; // Add to total
                            cout << name << "'s Hand: " << ptotal << endl;
                        }
                        else {cin.ignore(); cout << "Invalid Input";}

                    } while (ptotal < 21);

                    // Check if player busted
                    if (ptotal > 21) {
                        cout << name << ", you busted! Hand: " << ptotal << endl;
                    }

                } else if (choice == 'Q' || choice == 'q') {
                    exit(0);
                } else {
                    cin.ignore(); // Clear the input buffer
                    cout << "Input Error, Please Enter The Letter 'B' to Begin or 'Q' to Quit: ";
                }

            } while (choice != 'B' && choice != 'b' && choice != 'Q' && choice != 'q');

        } else if (gamechoice == 2) {
            cout << "Coward...";
            exit(0);
        } else {
            cin.ignore(); // Clear the input buffer
            cout << "Invalid Input, Please Enter '1' or '2': ";
        }

    } while (gamechoice != 1 && gamechoice != 2);

    return 0;
}
