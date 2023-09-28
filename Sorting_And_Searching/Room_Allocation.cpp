#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<pair<pair<int,int>, int>> customer(n);
    for(int i = 0;i < n;i++){
        cin >> customer[i].first.first >> customer[i].first.second;
        customer[i].second = i;
    }

    sort(customer.begin(), customer.end());

    int allocation[200000] = {0};
    int maxRoom = 0, rooms = 0;
    priority_queue<pair<int,int>> pq;
    for(int i = 0;i < n;i++){
        if(pq.empty()){
            maxRoom++;
            pq.push({-customer[i].first.second, maxRoom});
            allocation[customer[i].second] = maxRoom;
        }
        else{
            pair<int,int> minimum = pq.top();
            if(-minimum.first < customer[i].first.first){
                pq.pop();
                pq.push({-customer[i].first.second, minimum.second});
                allocation[customer[i].second] = minimum.second;
            }
            else{
                maxRoom++;
                pq.push({-customer[i].first.second, maxRoom});
                allocation[customer[i].second] = maxRoom;
            }
        }

        rooms = max(rooms, int(pq.size()));
    }

    cout << rooms << endl;
    for(int i = 0;i < n;i++){
        cout << allocation[i] << " ";
    }
    cout << endl;

    return 0;
}
