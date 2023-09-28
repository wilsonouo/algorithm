#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int,int> time;
    vector<int> order;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        time[a]++;
        time[b]--;
        order.push_back(a);
        order.push_back(b);
    }

    sort(order.begin(), order.end());

    int len = order.size();
    int ans = 0, temp = 0;
    for(int i = 0;i < len;i++){
        temp += time[order[i]];
        if(ans < temp){
            ans = temp;
        }
    }
    cout << ans << endl;

    return 0;
}
