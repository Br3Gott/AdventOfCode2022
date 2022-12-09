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

        // for (auto i : coveredRange1) {
        //     cout << i << ",";
        // }
        // cout << endl;

        // for (auto i : coveredRange2) {
        //     cout << i << ",";
        // }
        // cout << endl;

        bool covered1{true};

        auto it1{find(begin(coveredRange1), end(coveredRange1), r2Start)};
        if (it1 != end(coveredRange1))
        {
            // cout << "Entered in first" << endl;
            for (int i{r2Start}; i <= r2End; i++)
            {
                if (i != *it1)
                {
                    covered1 = false;
                }
                it1++;
            }
        } else {
            covered1 = false;
        }

        

        bool covered2{true};

        auto it2{find(begin(coveredRange2), end(coveredRange2), r1Start)};
        if (it2 != end(coveredRange2))
        {
            // cout << "Entered in second" << endl;
            for (int i{r1Start}; i <= r1End; i++)
            {
                if (i != *it2)
                {
                    // cout << i << " != " << *it2 << endl;
                    covered2 = false;
                }
                it2++;
            }
        } else {
            covered2 = false;
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