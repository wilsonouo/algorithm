#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second){
        return a.first > b.first;
    }
    else{
        return a.second < b.second;
    }
}


int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> movie(n);
    for(int i = 0;i < n;i++){
        cin >> movie[i].first >> movie[i].second;
    }

    sort(movie.begin(), movie.end(), cmp);

    pair<int,int>  temp;
    int ans = 0, people = 0;
    set<pair<int,int>> order;
    set<pair<int,int>>::iterator iter, it;
    for(int i = 0;i < n;i++){
        temp.first = movie[i].first;
        temp.second = -1;
        iter = order.upper_bound(temp);
        if(iter == order.begin() && people < k){
            temp.first = movie[i].second;
            temp.second = people++;
        }
        else if(iter == order.begin() && people >= k && iter->first != temp.first){
            continue;
        }
        else{
            iter--;
            temp.first = movie[i].second;
            temp.second = iter->second;
            order.erase(iter);
        }
        order.insert(temp);
        /*for(it = order.begin();it != order.end();it++){
            cout << it->first << " " << it->second << endl;
        }*/
        ans++;
    }

    cout << ans << endl;

    return 0;
}
