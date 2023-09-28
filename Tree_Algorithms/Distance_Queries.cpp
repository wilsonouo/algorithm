#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(200001);
int level[200001] = {0};
int parent[200001][20] = {0};
void dfs(int node = 1, int last = 0)
{
    level[node] = level[last]+1;
    vector<int>::iterator iter;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(*iter == last) continue;
        dfs(*iter, node);
        parent[*iter][0] = node;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int a, b;
    for(int i = 1;i < n;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs();

    fill(parent[1], parent[1]+20, 1);
    for(int i = 1;i < 20;i++){
        for(int t = 2;t <= n;t++){
            parent[t][i] = parent[parent[t][i-1]][i-1];
        }
    }

    for(int i = 0;i < q;i++){
        cin >> a >> b;
        if(level[b] > level[a]) swap(a, b);
        int gap = level[a] - level[b];
        int ans = gap;
        while(gap){
            a = parent[a][__lg(gap&(-gap))];
            gap -= gap&(-gap);
        }
        while(a != b){
            for(int t = 19;t >= 0;t--){
                if(parent[a][t] != parent[b][t] || t == 0){
                    a = parent[a][t];
                    b = parent[b][t];
                    ans += (2 << t);
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
