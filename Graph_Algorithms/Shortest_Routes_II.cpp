#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int,long long int>>> route(501);
    pair<int,long long int> tempa, tempb;
    int cost;
    for(int i = 0;i < m;i++){
        cin >> tempa.first >> tempb.first >> cost;
        tempa.second = tempb.second = cost;
        route[tempa.first].push_back(tempb);
        route[tempb.first].push_back(tempa);
    }

    vector<vector<long long int>> shortest(n+1, vector<long long int>(n+1, LONG_MAX/2));
    vector<pair<int,long long int>>::iterator iter;
    for(int i = 1;i <= n;i++){
        shortest[i][i] = 0;
        for(iter = route[i].begin();iter != route[i].end();iter++){
            if(shortest[i][iter->first] > iter->second){
                shortest[i][iter->first] = iter->second;
            }
        }
    }

    for(int i = 1;i <= n;i++){
        for(int t = 1;t <= n;t++){
            for(int k = 1;k <= n;k++){
                if(shortest[t][i] + shortest[i][k] < shortest[t][k]){
                    shortest[t][k] = shortest[t][i] + shortest[i][k];
                }
            }
        }
    }

    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        if(shortest[a][b] != LONG_MAX/2){
            cout << shortest[a][b] << endl;
        }
        else{
            cout << -1 << endl;
        }
    }

    return 0;
}
