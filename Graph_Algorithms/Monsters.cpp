#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
    int n , m;
    cin >> n >> m;

    string labyrinth[n];
    enum type {road, wall, player, monster};
    int mps[1002][1002] = {0};
    for(int i = 0;i < n;i++){
        for(int t = 0;t < m;t++){
            if(labyrinth[i][t] == '#'){
                mps[i+1][t+1] = wall;
            }
            else if(labyrinth[i][t] == 'M'){
                mps[i+1][t+1] = monster;
            }
            else if(labyrinth[i][t] == 'A'){
                mps[i+1][t+1] = player;
            }
        }
    }


    return 0;
}
