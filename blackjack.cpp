#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

void playGame(const string& name);
bool playAgain();
int drawCard(); // Function to simulate drawing a card

int main() {
    int gameChoice;
    string name;

    // Establish random seed for card drawing
    unsigned seed = time(0);
    srand(seed);

    // Main loop for entering or leaving the casino
    do {
        cout << "Welcome to Blackjack!\n";
        cout << "Enter '1' to Enter Casino or '2' to Leave Casino: ";
        cin >> gameChoice;

        if (gameChoice == 1) {
            cout << "Please Enter Your Name: ";
            cin >> name;
            name[0] = toupper(name[0]);  // Capitalize the first letter of the name

            // Start the game loop
            playGame(name);
        } else if (gameChoice == 2) {
            cout << "Goodbye!\n";
            break;  // Exit the program
        } else {
            cout << "Invalid Input. Please Enter '1' or '2'.\n";
        }

    } while (gameChoice != 1 && gameChoice != 2);

    return 0;
}

void playGame(const string& name) {
    char choice;
    int pnum1, pnum2, ptotal, dnum1, dnum2, dtotal;
    char move;

    // Game loop (new round)
    do {
        cout << "\nHello " << name << "!\n";
        cout << "Enter 'B' to Begin or 'Q' to Quit: ";
        cin >> choice;

        if (choice == 'B' || choice == 'b') {
            // Reset the hands and totals at the start of a new round
            pnum1 = drawCard();
            pnum2 = drawCard();
            ptotal = pnum1 + pnum2;

            dnum1 = drawCard();
            dnum2 = drawCard();
            dtotal = dnum1 + dnum2;

            cout << "Dealer's Hand: " << dnum1 << " and [Hidden]" << endl;
            cout << name << "'s Starting Hand: " << ptotal << endl;

            // Player's turn (hit or stand)
            do {
                cout << "Enter 'H' to Hit or 'S' to Stand: ";
                cin >> move;

                if (move == 'H' || move == 'h') {
                    int pnewCard = drawCard();
                    ptotal += pnewCard;  // Update player's hand
                    cout << name << "'s Hand: " << ptotal << endl;

                    if (ptotal > 21) {
                        cout << name << ", you busted! Hand: " << ptotal << endl;
                        break;  // Player busted, exit loop
                    }
                }
                else if (move == 'S' || move == 's') {
                    // Dealer's turn to draw cards if player stands
                    while (dtotal < 17) {
                        int dnewCard = drawCard();
                        dtotal += dnewCard;
                        cout << "Dealer's Hand: " << dtotal << endl;
                    }

                    // Determine winner
                    if (ptotal > 21) {
                        cout << name << ", you busted! Hand: " << ptotal << endl;
                    } else if (dtotal > 21) {
                        cout << "Dealer Busted! You Win!!\n";
                    } else if (ptotal > dtotal) {
                        cout << "You Win!!\n";
                    } else if (ptotal < dtotal) {
                        cout << "Dealer Wins\n";
                    } else {
                        cout << "It's a Draw!\n";
                    }

                    // Ask if the player wants to play again
                    if (!playAgain()) {
                        return;  // Exit if the player chooses to quit
                    }

                    // Reset the hands and totals for the next round
                    ptotal = 0;
                    dtotal = 0;
                    break;  // Exit the inner loop to start a new round

                } else {
                    cout << "Invalid Input. Please Enter 'H' to Hit or 'S' to Stand: ";
                }

            } while (ptotal <= 21);  // Player continues to hit if their total is <= 21

        } else if (choice == 'Q' || choice == 'q') {
            cout << "Goodbye, " << name << "!\n";
            return;  // Exit the game loop
        } else {
            cout << "Invalid Input. Please Enter 'B' to Begin or 'Q' to Quit: ";
        }

    } while (true);
}

bool playAgain() {
    char play;
    do {
        cout << "Play Again? (y/n): ";
        cin >> play;
        if (play == 'y' || play == 'Y') {
            return true;  // Continue playing
        } else if (play == 'n' || play == 'N') {
            cout << "Thanks for playing!\n";
            return false;  // Quit the game
        }
        cout << "Invalid Input. Please enter 'y' or 'n'.\n";
    } while (true);
}

// Function to simulate drawing a card (1 to 10)
int drawCard() {
    return 1 + rand() % 10;  // Return a random number between 1 and 10
}
