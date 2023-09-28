#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> city[100001];
int visited[100001] = {0}, from[100001] = {0};
stack<int> ans;
void dfs(int node)
{
    visited[node] = 1;
    vector<int>::iterator iter;
    int len = city[node].size();
    for(int i = 0;i < len;i++){
        if(visited[city[node][i]] == 1){
            int circle = city[node][i];
            ans.push(circle);
            ans.push(node);
            while(from[node] != circle){
                ans.push(from[node]);
                node = from[node];
            }
            ans.push(circle);
            cout << ans.size() << endl;
            while(!ans.empty()){
                cout << ans.top() << " ";
                ans.pop();
            }
            cout << endl;
            exit(0);
        }
        else if(!visited[city[node][i]]){
            from[city[node][i]] = node;
            dfs(city[node][i]);
        }

    }

    visited[node] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int a, b;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        city[a].push_back(b);
    }

    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    cout << "IMPOSSIBLE\n" ;

    return 0;
}
