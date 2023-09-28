#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int levels[200001] = {0};
int from[200001] = {0};
vector<vector<int>> flight(200001);
int route(int node, int stop)
{
    int len = flight[node].size();
    for(int i = 0;i < len;i++){
        if(levels[flight[node][i]] == INT_MIN){
            int nowlevel = route(flight[node][i], stop)+1;
            if(nowlevel > levels[node]){
                levels[node] = nowlevel;
                from[node] = flight[node][i];
            }
        }
        else{
            if(levels[flight[node][i]]+1 > levels[node]){
                levels[node] = levels[flight[node][i]]+1;
                from[node] = flight[node][i];
            }
        }

    }

    return levels[node];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        flight[a].push_back(b);
    }

    fill(levels+1, levels+n, INT_MIN);
    levels[n] = 1;
    int len = route(1, n);
    if(len > 1){
        cout << len << endl;
        int node = 1;
        for(int i = 0;i < len;i++){
            cout << node << " ";
            node = from[node];
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }


    return 0;
}
