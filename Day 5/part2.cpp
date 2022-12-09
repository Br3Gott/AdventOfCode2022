#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    fstream fs{"input.txt"};

    string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    vector<string> initalTable;
    vector<vector<char>> table;

    // init table
    for (int i{}; i < 9; i++)
    {
        char line[96];

        fs.getline(line, 96);

        string str{line};

        initalTable.push_back(str);

        table.push_back(vector<char>());
    }

    for (int i{9}; i >= 0; i--)
    {
        string str{initalTable[i]};
        for (auto itc{begin(str)}; itc != end(str); itc++)
        {
            auto it = find(begin(alphabet), end(alphabet), *itc);
            if (it != end(alphabet))
            {
                int pos = distance(begin(str), itc);
                int tpos{initalTable[8].at(pos)-'0'};
                table[tpos].push_back(*itc);
            }
        }
    }

    for (int i{1}; i < 10; i++) {
        cout << i << ": ";
        for (auto it{rbegin(table[i])}; it != rend(table[i]); it++) {
            cout << *it;
        }
        cout << endl;
    }

    // proccess actions
    string trash;
    int amount;
    int from;
    int to;

    while (fs >> trash >> amount >> trash >> from >> trash >> to)
    {
        vector<char> tempv;
        for (int i{}; i < amount; i++) {
            auto tfrom{begin(table)+from};
            char temp{*(end(*tfrom)-1)};
            (*tfrom).erase(end((*tfrom))-1);
            tempv.insert(end(tempv), temp);
        }
        auto tto{begin(table)+to};
        (*tto).insert(end((*tto)), rbegin(tempv), rend(tempv));
    }

    cout << "\n";
    for (int i{1}; i < 10; i++) {
        cout << i << ": ";
        for (auto it{rbegin(table[i])}; it != rend(table[i]); it++) {
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}