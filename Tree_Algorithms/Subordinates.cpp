#include <iostream>
#include <vector>

using namespace std;

vector<int> boss[200001];
int subordinate[200001] = {0};
int employee(int node)
{
    if(subordinate[node] != -1){
        return subordinate[node];
    }

    subordinate[node] = 0;
    int len = boss[node].size();
    for(int i = 0;i < len;i++){
        subordinate[node] += employee(boss[node][i])+1;

    }

    return subordinate[node];

}

int main()
{
    int n;
    cin >> n;

    int connect;
    for(int i = 2;i <= n;i++){
        cin >> connect;
        boss[connect].push_back(i);
    }

    fill(subordinate+1, subordinate+1+n, -1);
    for(int i = 1;i <= n;i++){
        if(subordinate[i] == -1){
            employee(i);
        }
        cout << subordinate[i] << " ";
    }
    return 0;
}
