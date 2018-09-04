#include <iostream>

using namespace std;

int getHumanMove(int numMarbles);
int getComputerMove(int numMarbles);
void playTheGame(int player);

const int COMPUTER = 0;
const int HUMAN = 1;

int main(int argc, const char * argv[]) {
    int currentPlayer = -1;

    cout << "Welcome to the game of NIM!" << endl;
    cout << "===========================" << endl;
    cout << "\nThe person that takes the last marble out of the jar wins." << endl;
    cout << "Only 1-5 marbles may be removed from the jar per turn." << endl;

    do {
        char choice;
        cout << "\nWould you like to go first [Y/N]? ";
        cin >> choice;

        switch(tolower(choice)) {
            case 'y':
                currentPlayer = HUMAN;
                break;
            case 'n':
                currentPlayer = COMPUTER;
                break;
            default:
                cout << "\nPlease enter a valid choice...";
        }
    } while (currentPlayer < 0);

    playTheGame(currentPlayer);

#ifdef _WIN32
    system("pause");
#endif

    return 0;
}

int getHumanMove(int numMarbles) {
    int numToTake = 0;

    do {
        cout << "How many marbles do you want to take [1-5]? ";
        cin >> numToTake;

        if (numToTake > numMarbles)
            continue;

    } while (numToTake > 5 || numToTake <= 0);

    return numToTake;
}

int getComputerMove(int numMarbles) {
    int numToTake = numMarbles % 6;

    if (numToTake <= 0 || numToTake > 5) {
        numToTake = rand() % 5 + 1;
    }

    cout << "The computer takes " << numToTake << " marbles." << endl;

    return numToTake;
}

void playTheGame(int player) {
    int numMarbles = 35;
    int currentMove = 0;

    while (numMarbles > 0) {
        cout << "\nThere are " << numMarbles << " marbles left in the jar." << endl;

        if (player == COMPUTER) {
            currentMove = getComputerMove(numMarbles);
        } else {
            currentMove = getHumanMove(numMarbles);
        }

        numMarbles -= currentMove;

        if (numMarbles <= 0) {
            if (player == COMPUTER) {
                cout << "\nThe computer wins the game!" << endl;
            } else {
                cout << "\nThe humanoid clutches the match! Well played." << endl;
            }
        }

        player = !player;
    }
}
