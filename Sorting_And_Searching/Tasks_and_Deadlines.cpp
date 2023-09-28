#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    multiset<pair<int,int>> task;
    pair<int,int> temp;
    for(int i = 0;i < n;i++){
        cin >> temp.first >> temp.second;
        task.insert(temp);
    }

    set<pair<int,int>>::iterator iter;
    long long int ans = 0, now = 0;
    for(iter = task.begin();iter != task.end();iter++){
        now += iter->first;
        ans += iter->second - now;
    }

    cout << ans << endl;

    return 0;
}
