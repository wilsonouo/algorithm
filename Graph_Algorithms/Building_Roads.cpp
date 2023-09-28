#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    vector<vector<int>> building(n+1);
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        building[a].push_back(b);
        building[b].push_back(a);
    }

    vector<int> ans;
    vector<int>::iterator iter;
    queue<int> bfs;
    int visited[100001] = {0};
    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            visited[i] = 1;
            bfs.push(i);
            ans.push_back(i);
            while(!bfs.empty()){
                for(iter = building[bfs.front()].begin();iter != building[bfs.front()].end();iter++){
                    if(!visited[*iter]){
                        bfs.push(*iter);
                        visited[*iter] = 1;
                    }
                }
                bfs.pop();
            }
        }
        else{
            continue;
        }
    }

    if(ans.size() > 1){
        cout << ans.size()-1 << endl;
        for(int i = 1;i < ans.size();i++){
            cout << ans[i-1] << " " << ans[i] << endl;
        }
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
