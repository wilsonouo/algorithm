#include <iostream>
#include <vector>

using namespace std;

int visited[200001] = {0};
vector<vector<int>> tree(200001);
int ans = 0;
void matching(int node)
{
    visited[node] = 1;
    vector<int>::iterator iter;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(!visited[*iter]){
            matching(*iter);
            if(visited[node] == 1 && visited[*iter] == 1){
                visited[node] = 2;
                visited[*iter] = 2;
                ans++;
            }
        }
    }

}

int main()
{
    int n;
    cin >> n;

    int a, b;
    for(int i = 0;i < n-1;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    for(int i = 1;i <= n;i++){
        if(!visited[i]){
            matching(i);
        }
    }


    cout << ans << endl;

    return 0;
}
