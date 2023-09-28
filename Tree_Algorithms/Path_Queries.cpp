#include <iostream>
#include <vector>

using namespace std;

int n, q;

long long int bit[600000] = {0};
int value[200001], start[200001] = {0}, finish[200001] = {0};
vector<vector<int>> path(200001);
int order = 0;
void dfs(int node, int last_node)
{
    order++;
    start[node] = order;
    vector<int>::iterator iter;
    for(iter = path[node].begin();iter != path[node].end();iter++){
        if(*iter == last_node) continue;
        dfs(*iter, node);
    }
    finish[node] = order;
}

long long int query(int node)
{
    long long int ans = 0;
    while(node){
        ans += bit[node];
        node -= node & (-node);
    }
    return ans;
}

void update(int node, int key)
{
    while(node <= n){
        bit[node] += key;
        node += node & (-node);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;

    for(int i = 1;i <= n;i++){
        cin >> value[i];
    }
    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    dfs(1, -1);

    for(int i = 1;i <= n;i++){
        update(start[i], value[i]);
        update(finish[i]+1, -value[i]);
    }

    for(int i = 0;i < q;i++){
        int Query, a, b;
        cin >> Query;
        if(Query == 1){
            cin >> a >> b;
            update(start[a], b-value[a]);
            update(finish[a]+1, value[a]-b);
            value[a] = b;
        }
        else{
            cin >> a;
            cout << query(start[a]) << endl;
        }
    }




    return 0;
}
