#include <iostream>
#include <string>

using namespace std;

int visited[1002][1002] = {0};
int combination[1002][1002] = {0};
long long int ans = 0;
int n;
long long int path(int x, int y)
{
    if(visited[x][y]){
        return 0;
    }

    if(combination[x][y] > 0){
        return combination[x][y];
    }
    else if(combination[x][y] < 0){
        return 0;
    }
    else if(x == n && y == n){
        combination[x][y] = 1;
        return 1;
    }

    visited[x][y] = 1;
    int dir[2][2] = { {0,1}, {1,0} };
    for(int i = 0;i < 2;i++){
        if(!visited[x+dir[i][0]][y+dir[i][1]]){
            combination[x][y] += path(x+dir[i][0], y+dir[i][1]);
        }
    }


    long long int ans = combination[x][y];
    if(combination[x][y] > 1000000007){
        combination[x][y] %= 1000000007;
        ans = combination[x][y];
    }
    else if(combination[x][y] == 0 && x != 1 && y != 1){
        combination[x][y] = -1;
    }
    visited[x][y] = 0;
    return ans;
}

int main()
{
    cin >> n;

    string maze[n+1];
    int len;
    // input
    for(int i = 1;i <= n;i++){
        cin >> maze[i];
        len = maze[i].size();
        for(int k = 0;k < len;k++){
            if(maze[i][k] == '*'){
                visited[i][k+1] = 1;
            }
        }
    }

    // set the wall
    for(int i = 0;i <= n+1;i++){
        visited[0][i] = 1;
        visited[n+1][i] = 1;
        visited[i][0] = 1;
        visited[i][n+1] = 1;
    }


    path(1,1);
    cout << combination[1][1] % 1000000007 << endl;

    return 0;
}
