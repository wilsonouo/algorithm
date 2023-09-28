#include <iostream>
#include <set>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int middle = k/2;
    vector<pair<int,int>> value;
    pair<int,int> temp;
    // prepare
    multiset<pair<int,int>> sliding;
    for(int i = 0;i < k;i++){
        cin >> temp.first;
        temp.second = i;
        value.push_back(temp);
        sliding.insert(temp);
    }
    // find the middle
    set<pair<int,int>>::iterator iter = sliding.begin(), it;
    if(k % 2 == 0){
        middle--;
    }
    for(int i = 0;i < middle;i++){
        iter++;
    }
    long long int ans = 0, change = 0;
    for(it = sliding.begin();it != sliding.end();it++){
        ans += abs(iter->first - it->first);
    }

    cout << ans << " ";
    for(int i = k;i < n;i++){
        cin >> temp.first;
        temp.second = i;
        value.push_back(temp);
        sliding.insert(temp);
        ans -= abs(iter->first - value[i-k].first);
        int last = iter->first;
        if(value[i-k].first <= iter->first && iter->first <= value[i].first){
            iter++;
            change = -1;
        }
        else if(value[i-k].first > iter->first && iter->first > value[i].first || iter->first > value[i].first && value[i-k].second == iter->second){
            iter--;
            change = 1;
        }
        if(k % 2 == 0){
            ans += abs(value[i].first - iter->first) + abs(last-iter->first)*change;
        }
        else{
            ans += abs(value[i].first - iter->first);
        }
        temp.first = value[i-k].first;
        temp.second = value[i-k].second;
        sliding.erase(temp);
        cout << ans << " ";
    }
    return 0;
}
