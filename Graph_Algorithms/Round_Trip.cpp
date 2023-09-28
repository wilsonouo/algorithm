#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> city(100001);
int visitedOnce[100001] = {0};
int visited[100001] = {0};
stack<int> ans;
int dfs(int last_node, int node, int level)
{
    //cout << node << endl;
    visited[node] = 1;
    visitedOnce[node] = 1;
    vector<int>::iterator iter;
    int Find;
    for(iter = city[node].begin();iter != city[node].end();iter++){
        if(!visited[*iter]){
            Find = dfs(node, *iter, level+1);
            if(Find > 0 && Find != *iter){
                ans.push(*iter);
                return Find;
            }
            else if(Find == *iter){
                ans.push(*iter);
                return -1;
            }
            else if(Find == -1){
                return -1;
            }
            else{
                continue;
            }
        }
        else if(*iter != last_node){
            ans.push(*iter);
            return *iter;
        }
    }

    visited[node] = 0;
    return 0;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        city[a].push_back(b);
        city[b].push_back(a);
    }

    int output = 0;
    for(int i = 1;i <= n;i++){
        if(!visitedOnce[i]){
            output = dfs(-1, i, 0);
            if(output == -1){
                break;
            }
            else if(output > 0){
                ans.push(i);
                break;
            }
            else{
                continue;
            }
        }
    }

    if(!ans.empty()){
        cout << ans.size() << endl;
        while(!ans.empty()){
            cout << ans.top() << " ";
            ans.pop();
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
