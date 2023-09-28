#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> message(100001);
    int a, b;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        message[a].push_back(b);
        message[b].push_back(a);
    }

    // bfs
    vector<int>::iterator iter;
    int visited[100001] = {0};
    int level[100001] = {0};
    int from[100001] = {0};
    visited[n] = 1;
    level[n] = 1;
    queue<int> route;
    route.push(n);
    while(!route.empty()){
        for(iter = message[route.front()].begin();iter != message[route.front()].end();iter++){
            if(!visited[*iter]){
                route.push(*iter);
                visited[*iter] = 1;
                level[*iter] = level[route.front()]+1;
                from[*iter] = route.front();
            }
        }
        route.pop();
    }

    if(level[1]){
        cout << level[1] << endl;
        int ans = 1;
        while(ans != n){
            cout << ans << " ";
            ans = from[ans];
        }
        cout << n;
    }
    else{
        cout << "IMPOSSIBLE";
    }
    cout << endl;
    return 0;
}
