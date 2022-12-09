#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int criteria{};
int part2size{70000000};

class dir {
    public:

    dir(dir* parent, string name) : parent{parent}, name{name}, size{}, children{} {}
    ~dir() {
        for(dir* d : children) {
            delete(d);
        }
    }

    dir* getParent() { return parent; }
    string getName() { return name; }

    void incrementSize(int inc) { size += inc; }
    int getSize() { return size; }

    void addChild(dir* child) { children.push_back(child); }
    vector<dir*> getAllChildren() { return children; }
    dir* getChildByName(string name) {
        for (dir* d : children) {
            if (d->getName() == name) {
                return d;
            }
        }
        return nullptr;
    }
    int getTotalSize() {
        int total{size};
        for (dir* d : children) {
            int temp = d->getTotalSize();
            if (temp <= 100000) {
                // cout << "found dir with criteria: " << d->getName() << " with size: " << temp << endl;
                criteria += temp;
            }
            if (temp >= 4274331) {
                if (temp-4274331 < part2size) {
                    part2size = temp;
                }
                // cout << "found dir diff: " << temp-4274331 << " with size: " << temp << endl;
            }
            total += temp;
        }
        return total;
    }

    private:
    dir* parent;
    string name;
    int size;
    vector<dir*> children;
};

int main()
{

    vector<dir*> disk;
    disk.push_back(new dir(nullptr, "root"));

    dir* current = disk[0];
    current->addChild(new dir(nullptr, "/"));

    fstream fs{"input.txt"};

    char inp[96];

    while (fs.getline(inp, 96)) {
        string line{inp};

        if (find(begin(line), end(line), '$') != end(line)) {
            //handle command
            if(line.find("cd ") != string::npos) {
                
                if(line.find("..") != string::npos) {
                    current = current->getParent();
                    // cout << "leaving dir" << endl;
                } else {
                    string name{line.substr(line.find("cd ")+3, line.size())};
                    // cout << "looking for dir: " << name << endl;
                    if (current->getChildByName(name) != nullptr) {
                        current = current->getChildByName(name);
                        // cout << "Success dir!" << endl;
                    } else {
                        // cout << "ERROR!!" << endl;
                        break;
                    }
                    
                }

            }
        } else if (line.find("dir ") != string::npos) {
            //handle subdir
            string name{line.substr(line.find(' ')+1, line.size())};
            current->addChild(new dir(current, name));
            // cout << "found subdir: " << name << endl;
        } else {
            //handle file
            string num{line.substr(0, line.find(' '))};
            int size{stoi(num)};
            current->incrementSize(size);
            // cout << "new file with size: " << size << endl;
        }
    }

    int totalAvalible{70000000};
    int totalUsed{disk[0]->getTotalSize()};
    int spaceLeft{totalAvalible-totalUsed};
    int spaceUpdate{30000000};
    int spaceNeeded{spaceUpdate-spaceLeft};

    cout << "done!" << endl;
    cout << "(part 1)criteria size: " << criteria << endl;
    cout << "(part 2)need: " << spaceNeeded << endl;
    cout << "(part 2) found diff: " << part2size-4274331 << " with size: " << part2size << endl;

    delete(disk[0]);
    return 0;
}