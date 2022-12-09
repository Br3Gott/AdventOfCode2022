#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getValue(char c) {
    if (static_cast<int> (c) >= 97) {
        return (static_cast<int> (c) - 96);
    } else {
        return (static_cast<int> (c) - 38);
    }
}

int main () {

    char line[96];
    vector<char> v;
    int sum{};

    while (cin.getline(line, 96)) {
        string str{line};
        string first{str.substr(0, str.length() /2)};
        string last{str.substr(str.length()/2, str.length() /2)};

        // cout << first << endl;
        // cout << last << endl;

        for (char c : first) {
            if (last.find(c) != string::npos) {
                // cout << "found: " << c << endl;
                if (find(begin(v), end(v), c) == end(v)) {
                    // v.push_back(c);
                    sum += getValue(c);
                    break;
                }

            }
        }
        
    }

    // for (char c : v) {
    //     cout << c << endl;
    //     sum += getValue(c);
    // }


    // int num{};
    // int bik{};

    // string alph = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};

    // for (int i{1}; i < 53; i++) {
    //     num += i;
    //     bik += getValue(alph.at(i));
    // }

    // cout << "Num: " << sum << endl;
    // cout << "Bik: " << sum << endl;


    //p), 38 (L), 42 (P), 22 (v), 20 (t), and 19 (s
    // int test{};
    // cout << getValue('p') << endl;
    // cout << getValue('L') << endl;
    // cout << getValue('P') << endl;
    // cout << getValue('v') << endl;
    // cout << getValue('t') << endl;
    // cout << getValue('s') << endl;
    // test += getValue('p');
    // test += getValue('L');
    // test += getValue('P');
    // test += getValue('v');
    // test += getValue('t');
    // test += getValue('s');
    // cout << "Test: " << test << endl;

    cout << "Sum: " << sum << endl;

    return 0;
}