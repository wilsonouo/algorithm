#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> building(100001);
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        building[a].push_back(b);
        building[b].push_back(a);
    }

    vector<int>::iterator iter;
    queue<int> bfs;
    int impossible = 0;
    int team[100002] = {0};
    fill(team+1,team+n+1,-1);
    for(int i = 1;i <= n;i++){
        if(team[i] == -1){
            bfs.push(i);
            team[i] = 0;
            while(!bfs.empty()){
                for(iter = building[bfs.front()].begin();iter != building[bfs.front()].end();iter++){
                    if(team[*iter] == -1){
                        team[*iter] = (team[bfs.front()]+1) % 2;
                        bfs.push(*iter);
                    }
                    else if(team[*iter] == team[bfs.front()]){
                        impossible = 1;
                        break;
                    }
                }
                bfs.pop();
            }
        }

        if(impossible){
            break;
        }
    }

    if(impossible){
        cout << "IMPOSSIBLE";
    }
    else{
        for(int i = 1;i <= n;i++){
            cout << team[i]+1 << " ";
        }
    }
    cout << endl;

    return 0;
}
