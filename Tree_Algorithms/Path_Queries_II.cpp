#include <iostream>
#include <vector>

using namespace std;

int n, q;
int segTree[800000] = {0};
int value[200001];

void update(int index, int key, int node = 0, int border_left = 1, int border_right = n)
{
    if(border_left == border_right){
        segTree[node] = key;
        return;
    }

    int Mid = (border_left+border_right)/2;
    if(index <= Mid) update(index, key, node*2+1, border_left, Mid);
    else update(index, key, node*2+2, Mid+1, border_right);
    segTree[node] = max(segTree[node*2+1], segTree[node*2+2]);
}

int query(int target_left, int target_right,int node = 0, int l = 1, int r = n)
{
    if(l > target_right || r < target_left) return 0;
    if(l >= target_left && r <= target_right) return segTree[node];
    int Mid = (l+r)/2;
    return max(query(target_left, target_right, node*2+1, l, Mid), query(target_left, target_right, node*2+2, Mid+1, r));
}

vector<vector<int>> path(200001);
int parent[200001][20] = {0};
int subnode[200001] = {0};
int level[200001] = {0};
int heavy[200001] = {0};

int dfs_init(int node, int last_node)
{
    int maxSub = 0;
    subnode[node] = 1;
    vector<int>::iterator iter;
    for(iter = path[node].begin();iter != path[node].end();iter++){
        if(*iter == last_node) continue;
        level[*iter] = level[node] + 1;
        parent[*iter][0] = node;
        int sub = dfs_init(*iter, node);
        subnode[node] += sub;
        if(maxSub < sub){
            maxSub = sub;
            heavy[node] = *iter;
        }
    }
    return subnode[node];
}

int order = 1;
int group[200001] = {0};
int id[200001] = {0};

void dfs_construct(int node, int pre, int gp)
{
    id[node] = order++;
    group[node] = gp;
    update(id[node], value[node]);
    if(heavy[node] != 0) dfs_construct(heavy[node], node, gp);
    vector<int>::iterator iter;
    for(iter = path[node].begin();iter != path[node].end();iter++){
        if(*iter == pre || heavy[node] == *iter) continue;
        dfs_construct(*iter, node, *iter);
    }
}

int travel(int start, int finish)
{
    int ans = 0;
    while(start != finish){
        if(group[start] == start){
            ans = max(ans, value[start]);
            start = parent[start][0];
        }
        else if(level[group[start]] > level[finish]){
            ans = max(ans, query(id[group[start]], id[start]));
            start = parent[group[start]][0];
        }
        else{
            ans = max(ans, query(id[finish]+1, id[start]));
            break;
        }
    }
    return ans;
}

int lca(int a, int b)
{
    if(level[a] < level[b]) swap(a, b);
    int gap = level[a] - level[b];
    while(gap){
        a = parent[a][__lg(gap&(-gap))];
        gap -= gap & (-gap);
    }

    while(a != b){
        for(int i = 19;i >= 0;i--){
            if(parent[a][i] != parent[b][i] || i == 0){
                a = parent[a][i];
                b = parent[b][i];
                break;
            }
        }
    }
    return a;
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
        cin  >> a >> b;
        path[a].push_back(b);
        path[b].push_back(a);
    }

    dfs_init(1, 1);
    dfs_construct(1, 1, 1);

    fill(parent[1], parent[1]+20, 1);
    for(int i = 1;i < 20;i++){
        for(int t = 2;t <= n;t++){
            parent[t][i] = parent[parent[t][i-1]][i-1];
        }
    }

    for(int i = 0;i < q;i++){
        int Query, a, b;
        cin >> Query >> a >> b;
        if(Query == 1){
            value[a] = b;
            update(id[a], b);
        }
        else{
            int c = lca(a, b);
            cout << max(max(travel(a,c), travel(b, c)), value[c]) << endl;
        }
    }

    return 0;
}
