#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> planet(100001);
stack<int> st;
int start[100001] = {0}, parent[100001] = {0}, kingdom[100001] = {0}, visited[100001];
int order = 0, scc = 0;
void dfs(int node)
{
    order++;
    start[node] = parent[node] = order;
    visited[node] = 1;
    st.push(node);
    vector<int>::iterator iter;
    for(iter = planet[node].begin();iter != planet[node].end();iter++){
        if(!start[*iter]){
            dfs(*iter);
            parent[node] = min(parent[node], parent[*iter]);
        }
        else if(visited[*iter]){
            parent[node] = min(parent[node], start[*iter]);
        }
    }

    if(start[node] == parent[node]){
        scc++;
        kingdom[node] = scc;
        int tempNode = -1;
        while(tempNode != node){
            tempNode = st.top();
            st.pop();
            kingdom[tempNode] = scc;
            visited[tempNode] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        planet[a].push_back(b);
    }

    for(int i = 1;i <= n;i++){
        if(!start[i]) dfs(i);
    }

    cout << scc << endl;
    for(int i = 1;i <= n;i++){
        cout << kingdom[i] << " ";
    }
    cout << endl;

    return 0;
}
