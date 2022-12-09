#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{

    int sum{};

    char buff[96];

    while (cin.getline(buff, 96))
    {
        set<int> coveredRange1;
        set<int> coveredRange2;

        string str{buff};
        string first{begin(str), find(begin(str), end(str), ',')};
        string last{find(begin(str), end(str), ',')+1, end(str)};

        string firstfirst{begin(first), find(begin(first), end(first), '-')};
        string firstlast{find(begin(first), end(first), '-')+1, end(first)};

        int r1Start{stoi(firstfirst)};
        int r1End{stoi(firstlast)};

        string lastfirst{begin(last), find(begin(last), end(last), '-')};
        string lastlast{find(begin(last), end(last), '-')+1, end(last)};

        int r2Start{stoi(lastfirst)};
        int r2End{stoi(lastlast)};

        cout << "Range: " << r1Start << "-" << r1End << " , " << r2Start << "-" << r2End << endl;

        for (int i{r1Start}; i <= r1End; i++)
        {
            coveredRange1.insert(i);
        }

        for (int i{r2Start}; i <= r2End; i++)
        {
            coveredRange2.insert(i);
        }

        bool covered1{false};

        for (int i{r2Start}; i <= r2End; i++) {
            if (find(begin(coveredRange1), end(coveredRange1), i) != end(coveredRange1)) {
                covered1 = true;
            }
        }

        bool covered2{false};

        for (int i{r1Start}; i <= r1End; i++) {
            if (find(begin(coveredRange2), end(coveredRange2), i) != end(coveredRange2)) {
                covered2 = true;
            }
        }
        

        if (covered1 || covered2)
        {
            cout << "Covered!" << endl;
            sum++;
        } else {
            cout << "Not!" << endl;
        }
        
    }

    cout << "Total covered: " << sum << endl;

    return 0;
}