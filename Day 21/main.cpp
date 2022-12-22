#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

class monkey {

    public:

    monkey(string name, long long num) : name{name}, num{num}, lhs{}, rhs{}, operand{'.'} {}

    monkey(string name, string lhs, string rhs, char operand) : name{name}, num{}, lhs{lhs}, rhs{rhs}, operand{operand} {}

    string name;
    long long num;
    string lhs;
    string rhs;
    char operand;

};

bool findAny(string str, string chars) {
    bool result{false};
    for (char c : chars) {
        if (str.find(c) != string::npos) {
            result = true;
        }
    }
    return result;
}

long long getValue(unordered_map<string, monkey*>& m, string name) {
    if ((m[name])->operand == '.') {
        return (m[name])->num;
    } else {
        long long lhs{getValue(m, (m[name])->lhs)};
        long long rhs{getValue(m, (m[name])->rhs)};
        long long res;
        if((m[name])->operand == '+') {
            res = lhs + rhs;
        } else if((m[name])->operand == '-') {
            res = lhs - rhs;
        } else if((m[name])->operand == '*') {
            res = lhs * rhs;
        } else if((m[name])->operand == '/') {
            res = lhs / rhs;
        }
        (m[name])->num = res;
        return res;
    }
}

int main() {

    fstream fs{"input.txt"};
    fstream fs1{"test.txt"};

    unordered_map<string, monkey*> monkeys;

    char buff[96];

    while (fs.getline(buff, 96)) {

        string str{buff};

        string name{str.substr(0, str.find(':'))};
        
        if (findAny(str, "+-*/")) {

            stringstream ss{str.substr(str.find(':')+1, str.length())};
            string lhs;
            char operand;
            string rhs;

            ss >> lhs >> operand >> rhs;

            monkeys[name] = new monkey(name, lhs, rhs, operand);

        } else {

            long long num{stoi(str.substr(str.find(':')+1, str.length()))};

            monkeys[name] = new monkey(name, num);

        }
        
    }

    cout << "Monkeys in list: " << monkeys.size() << endl;
    cout << "Root value: " << getValue(monkeys, "root") << endl;

    // already large number to reduce calc time.
    long long temp{3882224466180};

    while (true) {
        long long lhs{getValue(monkeys, (monkeys["root"])->lhs)};
        long long rhs{getValue(monkeys, (monkeys["root"])->rhs)};

        if (rhs == lhs) {
            break;
        }

        (monkeys["humn"])->num = temp;
        temp++;
    }

    cout << "humn: new value: " << temp << endl;

    return 0;
}