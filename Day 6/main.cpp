#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    fstream fs{"input.txt"};

    vector<char> buff;

    char c;
    int found{};

    int globalc{};

    while (fs >> c) {
        globalc++;
        auto it = find(begin(buff), end(buff), c);
        if(it == end(buff)) {
            // cout << c << " is new" << endl;
            buff.push_back(c);
            found++;
        } else {
            
            // cout << "Reset: ";
            // for (auto i : buff) {
            //     cout << i;
            // }
            // cout << endl;

            buff.erase(begin(buff), it+1);
            // buff.clear();
            buff.push_back(c);
            found = buff.size();
        }

        // part1 set found to 4
        if (found == 14) {
            cout << "Found: ";
            for (auto i : buff) {
                cout << i;
            }
            cout << " glob: " << globalc << endl;
            //globalc - 4 for begining
            break;
        }
    }

    return 0;
}