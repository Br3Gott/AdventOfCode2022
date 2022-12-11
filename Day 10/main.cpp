#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{

    fstream fs{"input.txt"};
    fstream fs1{"test.txt"};

    char inp[96];

    int cycleCount{1};
    int registerX{1};

    int specialSum{};

    while (fs.getline(inp, 96)) {

        string str{inp};

        bool doOp{false};
        bool summed{false};
        string op;
        int num{};

        if (str == "noop") {
            cycleCount++;
        } else {
            
            stringstream ss{str};
            ss >> op >> num;
            doOp = true;

            cycleCount++;
        }

        if (cycleCount == 20 || cycleCount == 60 || cycleCount == 100 || cycleCount == 140 || cycleCount == 180 || cycleCount == 220) {
            cout << "CycleCount: " << cycleCount << " val=> " << cycleCount*registerX << endl;
            specialSum += cycleCount*registerX;
            summed = true;
        }

        if(doOp) {
            cycleCount++;
            registerX += num;
        }

        if (!summed && (cycleCount == 20 || cycleCount == 60 || cycleCount == 100 || cycleCount == 140 || cycleCount == 180 || cycleCount == 220)) {
            cout << "CycleCount: " << cycleCount << " val=> " << cycleCount*registerX << endl;
            specialSum += cycleCount*registerX;
        }

    }

    cout << "Special sum: " << specialSum << endl;  

    fstream part2{"input.txt"};

    char inp2[96];

    int cycleCount2{1};
    int registerX2{1};
    
    int crtPos{};

    while (part2.getline(inp2, 96)) {

        string str{inp2};

        bool doOp{false};
        string op;
        int num{};

        if (str == "noop") {

            if (crtPos == registerX2-1 || crtPos == registerX2 || crtPos == registerX2+1) {
                cout << "🎅"s;
            } else {
                cout << "🎄"s;
            }

            cycleCount2++;
            if (crtPos == 39) {
                cout << endl;
                crtPos = -1;
            }
            crtPos++;
        } else {

            stringstream ss{str};
            ss >> op >> num;
            doOp = true;

            if (crtPos == registerX2-1 || crtPos == registerX2 || crtPos == registerX2+1) {
                cout << "🎅"s;
            } else {
                cout << "🎄"s;
            }
            
            cycleCount2++;
            if (crtPos == 39) {
                cout << endl;
                crtPos = -1;
            }
            crtPos++;
        }

        if(doOp) {

            if (crtPos == registerX2-1 || crtPos == registerX2 || crtPos == registerX2+1) {
                cout << "🎅"s;
            } else {
                cout << "🎄"s;
            }
            
            cycleCount2++;
            registerX2 += num;
            if (crtPos == 39) {
                cout << endl;
                crtPos = -1;
            }
            crtPos++;
        }

    }
    
    return 0;
}