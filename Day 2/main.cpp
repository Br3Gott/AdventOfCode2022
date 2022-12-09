#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int score{};

    char opponent_move;

    while (cin >> opponent_move) {
        char my_move;
        cin >> my_move;

        //Rock
        if (opponent_move == 'A') {
            if (my_move == 'X') {
                score += 1 + 3;
            } else if (my_move == 'Y') {
                score += 2 + 6;
            } else if (my_move == 'Z') {
                score += 3;
            } else {
                cout << "error should not be here!" << endl;
            }
        //Paper
        } else if (opponent_move == 'B') {
            if (my_move == 'X') {
                score += 1;
            } else if (my_move == 'Y') {
                score += 2 + 3;
            } else if (my_move == 'Z') {
                score += 3 + 6;
            } else {
                cout << "error should not be here!" << endl;
            }
        //Scissors
        } else if (opponent_move == 'C') {
            if (my_move == 'X') {
                score += 1 + 6;
            } else if (my_move == 'Y') {
                score += 2;
            } else if (my_move == 'Z') {
                score += 3 + 3;
            } else {
                cout << "error should not be here!" << endl;
            }
        }

    }

    cout << "Score: " << score << endl;

    return 0;

}