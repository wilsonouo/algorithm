#include <iostream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pair<long long int,int>>> route(100001);
    pair<long long int, int> temp;
    int a;
    for(int i = 0;i < m;i++){
        cin >> a >> temp.second >> temp.first;
        route[a].push_back(temp);
    }

    long long int shortest[100001] = {0};
    int visited[100001] = {0};
    fill(shortest+2, shortest+1+n, LONG_MAX);

    // put node that beside node1 into set
    vector<pair<long long int,int>>::iterator iter;
    int nowNode = 0;
    set<pair<long long int,int>> waiting;
    set<pair<long long int,int>>::iterator it;
    for(iter = route[1].begin();iter != route[1].end();iter++){
        if(shortest[iter->second] > iter->first){
            shortest[iter->second] = iter->first;
            temp.first = iter->first;
            temp.second = iter->second;
            waiting.insert(temp);
        }
    }
    visited[1] = 1;


    while(!waiting.empty()){

        nowNode = (waiting.begin())->second;
        if(!visited[nowNode]){
            visited[nowNode] = 1;
            for(iter = route[nowNode].begin();iter != route[nowNode].end();iter++){
                if(shortest[nowNode]+iter->first < shortest[iter->second] && !visited[iter->second]){
                    temp.first = shortest[iter->second] = shortest[nowNode]+iter->first;
                    temp.second = iter->second;
                    waiting.insert(temp);
                }
            }
        }
        waiting.erase(waiting.begin());
    }

    for(int i = 1;i <= n;i++){
        cout << shortest[i] << " ";
    }
    cout << endl;

    return 0;
}
