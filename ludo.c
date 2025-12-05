#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(0));

    int pos1 = 0;
    int pos2 = 0;
    const int END = 57;
    int turn = 1;

    cout << "=== SIMPLE LUDO GAME ===\n";
    cout << "Each player has 1 token. Roll 6 to start.\n";
    cout << "Reach position " << END << " to win!\n\n";

    while (true) {
        cout << "----------------------------\n";
        cout << "Player " << turn << "'s turn. Press ENTER to roll dice.";
        cin.ignore();

        int dice = rollDice();
        cout << "You rolled a " << dice << "!\n";

        if (turn == 1) {
            if (pos1 == 0) {
                if (dice == 6) pos1 = 1;
                else cout << "Player 1 needs a 6 to start.\n";
            } else {
                pos1 += dice;
                if (pos1 > END) pos1 = END;
            }
            cout << "Player 1 is now at position " << pos1 << ".\n";
            if (pos1 == END) {
                cout << "\nPlayer 1 WINS THE GAME!\n";
                break;
            }
        } else {
            if (pos2 == 0) {
                if (dice == 6) pos2 = 1;
                else cout << "Player 2 needs a 6 to start.\n";
            } else {
                pos2 += dice;
                if (pos2 > END) pos2 = END;
            }
            cout << "Player 2 is now at position " << pos2 << ".\n";
            if (pos2 == END) {
                cout << "\nPlayer 2 WINS THE GAME!\n";
                break;
            }
        }

        if (dice != 6) turn = (turn == 1 ? 2 : 1);
        else cout << "You rolled a 6! You get another turn.\n";
    }

    return 0;
}
