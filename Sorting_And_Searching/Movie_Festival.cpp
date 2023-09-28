#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if(a.second != b.second){
        return a.second < b.second;
    }
    else{
        return a.first > b.first;
    }
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> time;
    int a, b;
    pair<int, int> temp;

    for(int i = 0;i < n;i++){
        cin >> temp.first >> temp.second;
        time.push_back(temp);
    }

    sort(time.begin(), time.end(), compare);

    int ans = 0;
    int time_end = 0;
    for(int i = 0;i < n;i++){
        if(time_end <= time[i].first){
            ans++;
            time_end = time[i].second;
        }
    }

    cout << ans << endl;

    return 0;
}
