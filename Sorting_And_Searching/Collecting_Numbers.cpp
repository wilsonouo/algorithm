#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int,int>> collecting;
    pair<int, int> temp;
    for(int i = 0;i < n;i++){
        cin >> temp.first;
        temp.second = i+1;
        collecting.push_back(temp);
    }

    sort(collecting.begin(), collecting.end(), compare);

    int ans = 1;
    for(int i = 1;i < n;i++){
        if(collecting[i-1].second > collecting[i].second){
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
