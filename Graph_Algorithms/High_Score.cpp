#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
#include <set>

using namespace std;

class tunnels
{
    public:
        int start;
        int ends;
        int value;
};

bool cmp(tunnels a, tunnels b)
{
    if(a.start == b.start){
        return a.ends < b.ends;
    }
    else{
        return a.start < b.start;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<tunnels> route(m);
    vector<vector<int>> check(n+1);
    for(int i = 0;i < m;i++){
        cin >> route[i].start >> route[i].ends >> route[i].value;
        check[route[i].start].push_back(route[i].ends);
    }

    //sort(route.begin(), route.end(), cmp);

    long long int score[2501] = {0};
    fill(score+2, score+1+n, LONG_MIN/2);
    for(int i = 0;i < n-1;i++){
        for(int t = 0;t < m;t++){
            if(score[route[t].ends] < score[route[t].start] + route[t].value){
                score[route[t].ends] = score[route[t].start] + route[t].value;
            }
        }
    }

    set<int> cycle;
    int visited[2501] = {0};
    long long int last = score[n];
    for(int i = 0;i < n-1;i++){
        for(int t = 0;t < m;t++){
            if(score[route[t].ends] < score[route[t].start] + route[t].value){
                score[route[t].ends] = score[route[t].start] + route[t].value;
                cycle.insert(route[t].ends);
            }
        }
    }



    queue<int> circle;
    circle.push(1);
    visited[1] = 1;
    vector<int>::iterator it;
    while(!circle.empty()){
        int node = circle.front();
        for(it = check[node].begin();it != check[node].end();it++){
            if(!visited[*it]){
                visited[*it] = 1;
                circle.push(*it);
            }
        }
        circle.pop();
    }

    set<int> cycle2;
    set<int>::iterator ti;
    for(ti = cycle.begin();ti != cycle.end();ti++){
        if(visited[*ti]){
            cycle2.insert(*ti);
        }
    }


    fill(visited+1, visited+1+n, 0);
    for(ti = cycle2.begin();ti != cycle2.end();ti++){
        fill(visited+1, visited+1+n, 0);
        circle.push(*ti);
        visited[*ti] = 1;
        while(!circle.empty()){
            int node = circle.front();
            for(it = check[node].begin();it != check[node].end();it++){
                if(!visited[*it]){
                    visited[*it] = 1;
                    circle.push(*it);
                }
            }
            circle.pop();
        }
        if(visited[n] == 1){
            break;
        }
    }



    if(visited[n]){
        cout << -1 << endl;
    }
    else{
        cout << score[n] << endl;
    }

    return 0;
}
