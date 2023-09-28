#include <iostream>
#include <vector>

using namespace std;

long long int bitN = 1;
vector<vector<int>> tree(200001);
int value[200001] = {0};
pair<int,int> range[200001];
int order = 1;

void dfs(int node = 1, int pre = 0)
{
    range[node].first = order++;
    vector<int>::iterator iter;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(*iter == pre) continue;
        dfs(*iter, node);
    }
    range[node].second = order++;
}

long long int bitTree[600000] = {0};

void update(int index, int key)
{
    while(index <= bitN){
        bitTree[index] += key;
        index += index & (-index);
    }
}

long long int check(int index)
{
    long long int ans = 0;
    while(index){
        ans += bitTree[index];
        index -= index & (-index);
    }
    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;

    while(2*n > bitN){
        bitN *= 2;
    }

    for(int i = 1;i <= n;i++){
        cin >> value[i];
    }

    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs();

    for(int i = 1;i <= n;i++){
        update(range[i].first, value[i]);
        update(range[i].second, value[i]);
    }

    for(int i = 0;i < q;i++){
        int Query, a, b;
        cin >> Query >> a;
        if(Query == 1){
            cin >> b;
            update(range[a].first, b-value[a]);
            update(range[a].second, b-value[a]);
            value[a] = b;
        }
        else if(Query == 2){
            cout << (check(range[a].second) - check(range[a].first-1)) / 2 << endl;
        }
    }


    return 0;
}
