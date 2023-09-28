#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(200001);
int color[200001] = {0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> color[i];
    }

    for(int i = 1;i < n;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    return 0;
}
