#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> course(n+1);
    int link[100001] = {0};
    for(int i = 0;i < m;i++){
        int a, b;
        cin >> a >> b;
        course[a].push_back(b);
        link[b]++;
    }

    queue<int> schedule;
    for(int i = 1;i <= n;i++){
        if(!link[i]){
            schedule.push(i);
            link[i] = -1;
        }
    }

    queue<int> ans;
    bool cycle = false;
    for(int i = 0;i < n;i++){

        if(schedule.empty()){
            cycle = true;
            break;
        }

        int node = schedule.front();
        schedule.pop();
        ans.push(node);
        vector<int>::iterator iter;
        for(iter = course[node].begin();iter != course[node].end();iter++){
            link[*iter]--;
            if(!link[*iter]){
                schedule.push(*iter);
                link[*iter] = -1;
            }
        }

    }

    if(cycle){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        while(!ans.empty()){
            cout << ans.front() << " ";
            ans.pop();
        }
    }

    return 0;
}
