#include <iostream>
#include <vector>
#define modulo 1000000007

using namespace std;

long long int game[100001] = {0};
int visited[100001] = {0};
vector<vector<int>> routes(100001);
int dfs(int node)
{
    if(visited[node]){
        return game[node];
    }

    visited[node] = 1;
    int len = routes[node].size();
    for(int i = 0;i < len;i++){
         game[node] += dfs(routes[node][i]);
         game[node] %= modulo;
    }

    return game[node];

}

int main()
{
    int n , m;
    cin >> n >> m;


    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        routes[a].push_back(b);
    }

    game[n] = 1;
    cout << dfs(1) << endl;


    return 0;
}
