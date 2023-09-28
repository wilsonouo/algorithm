#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define module 1000000007

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int start;
    vector<vector<pair<int,int>>> city(100001);
    pair<int,int> temp;
    for(int i = 0;i < m;i++){
        cin >> start >> temp.first >> temp.second;
        city[start].push_back(temp);
    }

    long long int pathNum = 0;
    long long int price[100001] = {0};
    long long int numroute[100001] = {0};
    int maxLevel[100001] = {0};
    int minLevel[100001] = {0};
    numroute[1] = 1;
    fill(price+2, price+1+n, LONG_MAX);
    priority_queue<pair<long long int,int>, vector<pair<long long int,int>>, greater<pair<long long int,int>>> pq;
    pq.push({0, 1});
    vector<pair<int,int>>::iterator iter;
    while(!pq.empty()){
        pair<long long int, int> now = pq.top();
        pq.pop();
        if(now.first > price[now.second]) continue;
        for(iter = city[now.second].begin();iter != city[now.second].end();iter++){
            if(price[iter->first] > iter->second+price[now.second]){
                price[iter->first] = iter->second+price[now.second];
                numroute[iter->first] = numroute[now.second];
                maxLevel[iter->first] = maxLevel[now.second]+1;
                minLevel[iter->first] = minLevel[now.second]+1;
                pq.push({price[iter->first], iter->first});
            }
            else if(price[iter->first] == iter->second+price[now.second]){
                numroute[iter->first] += numroute[now.second];
                numroute[iter->first] %= module;
                maxLevel[iter->first] = max(maxLevel[now.second]+1, maxLevel[iter->first]);
                minLevel[iter->first] = min(minLevel[now.second]+1, minLevel[iter->first]);
            }
        }
    }

    cout << price[n] << " " << numroute[n] << " " << minLevel[n] << " " << maxLevel[n] << endl;

    return 0;
}
