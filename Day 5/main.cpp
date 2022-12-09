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
                // cout << "Inserting: " << *itc << " into: " << tpos << endl;
                cout << *itc << " is in pos: " << pos << " which is column: " << initalTable[8].at(pos) << endl;
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
        // cout << "Amount: " << amount << " From: " << from << " to: " << to << endl;
        for (int i{}; i < amount; i++) {
            auto tfrom{begin(table)+from};
            auto tto{begin(table)+to};

            char temp{*(end(*tfrom)-1)};
            cout << "debug size: " << (*tfrom).size() << " to size: " << (*tto).size() << " temp: " << temp << " back: " << table[from].back() <<   endl;
            (*tfrom).erase(end((*tfrom))-1);
            (*tto).insert(end((*tto)), temp);
        }
    }

    for (int i{1}; i < 10; i++) {
        cout << i << ": ";
        for (auto it{rbegin(table[i])}; it != rend(table[i]); it++) {
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}