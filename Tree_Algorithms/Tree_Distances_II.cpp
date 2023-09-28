#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(200001);
long long int dp[200001] = {0}, ans[200001] = {0};
int n;
void dfs1(int node, int last, int depth)
{
    ans[1] += depth;
    dp[node] = 1;
    vector<int>::iterator iter;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(*iter == last) continue;
        dfs1(*iter, node, depth+1);
        dp[node] += dp[*iter];
    }

}

void dfs2(int node, int last)
{
    vector<int>::iterator iter;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(*iter == last) continue;
        ans[*iter] = ans[node] + n - 2*dp[*iter];
        dfs2(*iter, node);
    }

}

int main()
{
    cin >> n;

    int a, b;
    for(int i = 0;i < n-1;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs1(1, -1, 0);
    dfs2(1, -1);

    for(int i = 1;i <= n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
