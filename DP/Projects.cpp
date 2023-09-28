#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Projects
{
    public:
        int start;
        int finish;
        int money;
        bool operator <(const Projects &x) const{
            return start < x.start;
        }
};

vector<int> order;
int getid(int x)
{
    return lower_bound(order.begin(), order.end(), x) - order.begin() + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    vector<Projects> project(n);
    for(int i = 0;i < n;i++){
        cin >> project[i].start >> project[i].finish >> project[i].money;
        order.push_back(project[i].start);
        order.push_back(project[i].finish);
    }

    sort(project.begin(), project.end());
    sort(order.begin(), order.end());
    order.erase(unique(order.begin(), order.end()), order.end());

    int ptr = 0;
    long long int ans = 0;
    long long int dp[400000] = {0};
    for(int i = 0;i < n;i++){
        while(ptr < getid(project[i].start) - 1){
            ptr++;
            dp[ptr] = max(dp[ptr], dp[ptr-1]);
        }
        dp[getid(project[i].finish)] = max(dp[getid(project[i].finish)], dp[getid(project[i].start)-1] + project[i].money);
        ans = max(dp[getid(project[i].finish)], ans);
    }

    cout << ans << endl;

    return 0;
}
