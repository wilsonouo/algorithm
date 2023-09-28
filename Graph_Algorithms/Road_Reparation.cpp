#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> city(100001);
    pair<int, int> a, b;
    int cost;
    for(int i = 0;i < m;i++){
        cin >> a.second >> b.second >> cost;
        a.first = b.first = cost;
        city[a.second].push_back(b);
        city[b.second].push_back(a);
    }

    set<int> complete;
    complete.insert(1);
    vector<pair<int,int>>::iterator iter;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for(iter = city[1].begin();iter != city[1].end();iter++){
        pq.push(*iter);
    }

    long long int ans = 0;
    while(!pq.empty()){
        int node = (pq.top()).second, repare = (pq.top()).first;
        pq.pop();
        if(!complete.count(node)){
            complete.insert(node);
            for(iter = city[node].begin();iter != city[node].end();iter++){
                pq.push(*iter);
            }
            ans += repare;
        }
    }

    if(complete.size() != n){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;
}
