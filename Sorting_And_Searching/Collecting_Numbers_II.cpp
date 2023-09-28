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
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> collecting;
    pair<int, int> temp;
    int order[200000];
    for(int i = 0;i < n;i++){
        cin >> order[i];
        temp.first = order[i];
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

    int a, b;
    int tempa, tempb;
    for(int i = 0;i < m;i++){
        cin >> a >> b;
        tempa = order[a-1]-1;
        tempb = order[b-1]-1;
        if(tempa > tempb) swap(tempa, tempb);
        // count old relationship
        int oldrelationship = 0;
        if(tempa-1 >= 0 && collecting[tempa-1].second > collecting[tempa].second){
            oldrelationship++;
        }
        if(tempb+1 <= n-1 && collecting[tempb+1].second < collecting[tempb].second){
            oldrelationship++;
        }
        if(tempa+1 != tempb){
            if(tempa+1 <= n-1 && collecting[tempa].second > collecting[tempa+1].second){
                oldrelationship++;
            }
            if(tempb-1 >= 0 && collecting[tempb].second < collecting[tempb-1].second){
                oldrelationship++;
            }
        }
        else{
            if(collecting[tempa].second > collecting[tempa+1].second){
                oldrelationship++;
            }
        }
        // new relationship
        swap(collecting[tempa].second, collecting[tempb].second);
        swap(order[a-1],order[b-1]);
        int newrelationship = 0;
        if(tempa-1 >= 0 && collecting[tempa-1].second > collecting[tempa].second){
            newrelationship++;
        }
        if(tempb+1 <= n-1 && collecting[tempb+1].second < collecting[tempb].second){
            newrelationship++;
        }
        if(tempa+1 != tempb){
            if(tempa+1 <= n-1 && collecting[tempa].second > collecting[tempa+1].second){
                newrelationship++;
            }
            if(tempb-1 >= 0 && collecting[tempb].second < collecting[tempb-1].second){
                newrelationship++;
            }
        }
        else{
            if(collecting[tempa].second > collecting[tempa+1].second){
                newrelationship++;
            }
        }

        ans += newrelationship - oldrelationship;
        cout << ans << endl;
    }


    return 0;
}
