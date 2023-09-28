#include <iostream>
#include <string>

using namespace std;

int visited[1002][1002] = {0};
int ans = 0;

void counting(int x, int y, int hi)
{
    visited[x][y] = 1;
    if(hi == 0){
        ans++;
    }

    pair<int,int> dir[4] = { {0,-1}, {0,1}, {-1,0}, {1,0} };
    for(int i = 0;i < 4;i++){
        if(!visited[x+dir[i].first][y+dir[i].second]){
            counting(x+dir[i].first, y+dir[i].second, 1);
        }
    }

    return;
}

int main()
{
    int row, col;
    cin >> row >> col;

    string rooms[1000];
    for(int i = 0;i < row;i++){
        cin >> rooms[i];
        int len = rooms[i].size();
        for(int t = 0;t < len;t++){
            if(rooms[i][t] == '#'){
                visited[i+1][t+1] = 1;
            }
        }
    }


    // initialize
    for(int i = 0;i <= col+1;i++){
        visited[0][i] = 1;
        visited[row+1][i] = 1;
    }
    for(int i = 0;i <= row+1;i++){
        visited[i][0] = 1;
        visited[i][col+1] = 1;
    }

    for(int i = 1;i <= row;i++){
        for(int t = 1;t <= col;t++){
            if(visited[i][t] == 0){
                counting(i,t,0);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
