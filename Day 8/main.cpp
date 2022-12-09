#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int toInt(size_t inp) {
    return static_cast<int>(inp);
}

int viewDistance(int x ,int y, vector<vector<int>> v) {
    int posHeight{v[x][y]};
    //+x
    int tempPX{x+1};
    int distPX{};
    while (tempPX < toInt(v.size())) {
        if(v[tempPX][y] >= posHeight) {
            distPX++;
            break;
        }
        if(v[tempPX][y] < posHeight) {
            distPX++;
        }
        ++tempPX;
    }

    //-x
    int tempMX{x-1};
    int distMX{};
    while (tempMX >= 0) {
        if(v[tempMX][y] >= posHeight) {
            distMX++;
            break;
        }
        if(v[tempMX][y] < posHeight) {
            distMX++;
        }
        --tempMX;
    }

    //+y
    int tempPY{y+1};
    int distPY{};
    while (tempPY < toInt(v.size())) {
        if(v[x][tempPY] >= posHeight) {
            distPY++;
            break;
        }
        if(v[x][tempPY] < posHeight) {
            distPY++;
        }
        ++tempPY;
    }

    //-y
    int tempMY{y-1};
    int distMY{};
    while (tempMY >= 0) {
        if(v[x][tempMY] >= posHeight) {
            distMY++;
            break;
        }
        if(v[x][tempMY] < posHeight) {
            distMY++;
        }
        --tempMY;
    }

    //return scenic score
    return (distPX * distMX * distPY * distMY);
}

int main()
{
    fstream fs{"input.txt"};

    char inp[120];

    vector<vector<int>> grid;
    vector<vector<bool>> visible;

    int line{};
    while (fs.getline(inp, 120)) {
        string str{inp};
        grid.push_back(vector<int>());
        visible.push_back(vector<bool>());
        for (char c : str) {
            int temp{c-'0'};
            grid[line].push_back(temp);
            visible[line].push_back(false);
        }
        line++;
    }

    //forward horisontal -- ok
    for (int u{}; u < toInt(grid.size()); u++) {
        int curr_height{-1};
        for (int i{}; i < toInt(grid[u].size()); i++) {
            if(grid[u][i] > curr_height) {
                curr_height = grid[u][i];
                visible[u][i] = true;
            }
        }
    }

    //reverse horizontal -- ok
    for (int u{}; u < toInt(grid.size()); u++) {
        int curr_height{-1};
        for (int i{toInt(grid[u].size())-1}; i >= 0; i--) {
            if(grid[u][i] > curr_height) {
                curr_height = grid[u][i];
                visible[u][i] = true;
            }
        }
    }

    //forward vertical -- ok
    for (int u{}; u < toInt(grid.size()); u++) {
        int curr_height{-1};
        for (int i{}; i < toInt(grid.size()); i++) {
            if(grid[i][u] > curr_height) {
                curr_height = grid[i][u];
                visible[i][u] = true;
            }
        }
    }

    //reverse vertical -- ok
    for (int u{toInt(grid.size())-1}; u >= 0; u--) {
        int curr_height{-1};
        for (int i{toInt(grid.size())-1}; i >= 0; i--) {
            if(grid[i][u] > curr_height) {
                curr_height = grid[i][u];
                visible[i][u] = true;
            }
        }
    }

    //get all visible
    int totalVisible{};
    int bestViewDist{};
    for (int u{}; u < toInt(grid.size()); u++) {
        for (int i{}; i < toInt(grid[u].size()); i++) {
            if (visible[u][i]) {
                totalVisible++;
                
            }
            int temp{viewDistance(u, i, grid)};
            if(temp > bestViewDist) {
                bestViewDist = temp;
            }
        }
    }
     
    cout << "Visible: " << totalVisible << endl;
    cout << "Best viewDist: " << bestViewDist << endl;

    return 0;
}