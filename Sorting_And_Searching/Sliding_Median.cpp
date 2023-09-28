#include <iostream>
#include <set>
#include <vector>

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

    cout << iter->first << " ";
    for(int i = k;i < n;i++){
        cin >> temp.first;
        temp.second = i;
        value.push_back(temp);
        sliding.insert(temp);
        if(value[i-k].first <= iter->first && iter->first <= value[i].first){
            iter++;
        }
        else if(value[i-k].first > iter->first && iter->first > value[i].first || iter->first > value[i].first && value[i-k].second == iter->second){
            iter--;
        }
        temp.first = value[i-k].first;
        temp.second = value[i-k].second;
        sliding.erase(temp);
        cout << iter->first << " ";
    }
    return 0;
}
