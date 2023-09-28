#include <iostream>
#include <string>
#include <queue>
#include <stack>

#define stop 1
#define start 2
#define End 3

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;


    string labyrinth[1000];
    int visited[1002][1002] = {0};
    int step[1002][1002] = {0};
    int from[1002][1002] = {0};
    pair<int,int> position, finish;
    for(int i = 0;i < n;i++){
        cin >> labyrinth[i];
        int len = labyrinth[i].size();
        for(int t = 0;t < len;t++){
            if(labyrinth[i][t] == '#'){
                visited[i+1][t+1] = stop;
            }
            else if(labyrinth[i][t] == 'A'){
                visited[i+1][t+1] = start;
                position.first = i+1;
                position.second = t+1;
            }
            else if(labyrinth[i][t] == 'B'){
                visited[i+1][t+1] = End;
                finish.first = i+1;
                finish.second = t+1;
            }
        }
    }

    // initialize
    for(int i = 0;i <= m+1;i++){
        visited[0][i] = stop;
        visited[n+1][i] = stop;
    }
    for(int i = 0;i <= n+1;i++){
        visited[i][0] = stop;
        visited[i][m+1] = stop;
    }

    pair<int,int> dir[4] = {{0,-1}, {0,1}, {-1,0}, {1,0}}, temp;
    queue<pair<int,int>> searching;
    searching.push(position);
    step[position.first][position.second] = 0;
    while(!searching.empty() && !step[finish.first][finish.second]){
        position = searching.front();
        searching.pop();
        for(int i = 0;i < 4;i++){
            if(visited[dir[i].first+position.first][dir[i].second+position.second] == 0){
                step[dir[i].first+position.first][dir[i].second+position.second] = step[position.first][position.second] + 1;
                from[dir[i].first+position.first][dir[i].second+position.second] = i;
                visited[dir[i].first+position.first][dir[i].second+position.second] = stop;
                temp.first = dir[i].first+position.first;
                temp.second = dir[i].second+position.second;
                searching.push(temp);
            }
            else if(visited[dir[i].first+position.first][dir[i].second+position.second] == End){
                step[dir[i].first+position.first][dir[i].second+position.second] = step[position.first][position.second] + 1;
                from[dir[i].first+position.first][dir[i].second+position.second] = i;
                break;
            }
        }
    }

    if(!step[finish.first][finish.second]){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << step[finish.first][finish.second] << endl;
        int len = step[finish.first][finish.second];
        stack<char> instruction;
        for(int i = 0;i < len;i++){
            if(from[finish.first][finish.second] == 3){
                instruction.push('D');
            }
            else if(from[finish.first][finish.second] == 2){
                instruction.push('U');
            }
            else if(from[finish.first][finish.second] == 1){
                instruction.push('R');
            }
            else if(from[finish.first][finish.second] == 0){
                instruction.push('L');
            }
            int d = from[finish.first][finish.second];
            finish.first -= dir[d].first;
            finish.second -= dir[d].second;
        }
        while(!instruction.empty()){
            cout << instruction.top();
            instruction.pop();
        }
        cout << endl;
    }

    return 0;
}
