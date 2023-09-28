#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
int subNode[200001] = {0};
vector<vector<int>> path(200001);
vector<int> pass;
map<int, int> connect;
void dfs(int node, int last_node)
{
    connect[node] = last_node;
    subNode[node]++;
    vector<int>::iterator iter;
    bool satisfy = true;
    for(iter = path[node].begin();iter != path[node].end();iter++){
        if(*iter == last_node) continue;
        dfs(*iter, node);
        if(subNode[*iter] > n/2) satisfy = false;
        subNode[node] += subNode[*iter];
    }

    if(satisfy) pass.push_back(node);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    dfs(1, -1);

    int len = pass.size();
    if(pass[len-1] == 1){
        cout << 1 << endl;
    }
    else{
        for(int i = 0;i < len;i++){
            if(n - subNode[pass[i]] <= n/2){
                cout << pass[i] << endl;
                break;
            }
        }
    }
    return 0;
}
