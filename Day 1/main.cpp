#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<int> cals{};
    cals.push_back(0);

    char arr[32];
    int index{};

    while (cin.getline(arr, 32)) {

        string str{arr};

        if (str == "") {
            index++;
            cals.push_back(0);
        } else {
            cals[index] = cals[index] + stoi(str);
        }

    }

    sort(begin(cals), end(cals));

    cout << cals.size() << endl;
    cout << *(end(cals)-1) << endl;
    cout << *(end(cals)-1) + *(end(cals)-2) + *(end(cals)-3) << endl;

    return 0;

}