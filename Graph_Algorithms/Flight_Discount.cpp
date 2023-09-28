#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int a;
    vector<vector<pair<int,int>>> flight(100001);
    pair<int,int> temp;
    for(int i = 0;i < m;i++){
        cin >> a >> temp.second >> temp.first;
        flight[a].push_back(temp);
    }

    long long int distance[2][100001] = {0};
    fill(distance[0]+1, distance[0]+1+n,1e18);
    fill(distance[1]+1, distance[1]+1+n,1e18);
    priority_queue<pair<long long int, pair<int,int>>, vector<pair<long long int, pair<int,int>>>, greater<pair<long long int, pair<int,int>>>> discount;
    discount.push({0,{1,0}});
    while(!discount.empty()){
        pair<long long int, pair<int,int>> now = discount.top();
        discount.pop();
        if(now.first > distance[now.second.second][now.second.first]) continue;
        vector<pair<int, int>>::iterator iter;
        for(iter = flight[now.second.first].begin();iter != flight[now.second.first].end();iter++){
            if(distance[now.second.second][iter->second] > now.first + iter->first){
                distance[now.second.second][iter->second] = now.first + iter->first;
                discount.push({distance[now.second.second][iter->second], {iter->second, now.second.second}});
            }
            if(now.second.second == 0){
                if(distance[1][iter->second] > now.first + iter->first/2){
                    distance[1][iter->second] = now.first + iter->first/2;
                    discount.push({distance[1][iter->second], {iter->second, 1}});
                }
            }
        }
    }

    cout << distance[1][n] << endl;

    return 0;
}
