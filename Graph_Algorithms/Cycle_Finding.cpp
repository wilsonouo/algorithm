#include <iostream>
#include <vector>
#include <map>
#include <limits.h>
#include <set>

using namespace std;

vector<vector<pair<int,int>>> node(10001);
int visited[100001] = {0};
int v[100001] = {0};
int dfs(int index, int sum)
{
    v[index] = 1;
    visited[index] = 1;
    vector<pair<int,int>>::iterator iter;
    for(iter = node[index].begin();iter != node[index].end();iter++){
        if(visited[iter->first] && sum+iter->second < 0){
            cout << "YES" << endl;
            cout << iter->first << " " << index << " ";
            if(iter->first == index) exit(0);
            return iter->first;
        }
        else if(!visited[iter->first]){
            int test = dfs(iter->first, sum+iter->second);
            if(test){
                cout << index << " ";
                if(test == index) exit(0);
                return test;
            }
        }
    }
    visited[index] = 0;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    int a, b, c;
    for(int i = 0;i < m;i++){
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b,c));
    }

    for(int i = 1;i <= n;i++){
        if(!v[i]) dfs(i, 0);
    }

    cout << "NO" << endl;

    return 0;
}
