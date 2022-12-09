#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getValue(char c)
{
    if (static_cast<int>(c) >= 97)
    {
        return (static_cast<int>(c) - 96);
    }
    else
    {
        return (static_cast<int>(c) - 38);
    }
}

int main()
{

    char line1[96];
    char line2[96];
    char line3[96];
    vector<char> v;
    int sum{};

    while (cin.getline(line1, 96))
    {
        cin.getline(line2, 96);
        cin.getline(line3, 96);
        string str1{line1};
        string str2{line2};
        string str3{line3};

        for (char c : str1)
        {
            if (str2.find(c) != string::npos)
            {
                if (str3.find(c) != string::npos)
                {
                    // cout << "found: " << c << endl;
                    if (find(begin(v), end(v), c) == end(v))
                    {
                        // v.push_back(c);
                        sum += getValue(c);
                        break;
                    }
                }
            }
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}