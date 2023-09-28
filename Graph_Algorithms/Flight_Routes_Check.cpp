#include <iostream>
#include <vector>
#include <stack>
#include <set>

using namespace std;

vector<vector<int>> flight(100001);
stack<int> st;
set<pair<int,int>> group;
int start[100001] = {0}, parent[100001] = {0}, visited[100001] = {0};
int order = 0, scc = 0;
void dfs(int node)
{
    order++;
    start[node] = parent[node] = order;
    visited[node] = 1;
    st.push(node);
    vector<int>::iterator iter;
    for(iter = flight[node].begin();iter != flight[node].end();iter++){
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
        pair<int, int> groupInfo;
        groupInfo.first = scc;
        groupInfo.second = node;
        group.insert(groupInfo);
        int tempNode = -1;
        while(tempNode != node){
            tempNode = st.top();
            st.pop();
            groupInfo.second = tempNode;
            group.insert(groupInfo);
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
        flight[a].push_back(b);
    }

    for(int i = 1;i <= n;i++){
        if(!start[i]) dfs(i);
    }

    if(scc == 1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
        cout << (group.begin())->second << " " << (--group.end())->second << endl;
    }

    return 0;
}
