#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.first == b.first){
        return a.second < b.second;
    }
    else{
        return a.first < b.first;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, limitWeight;
    cin >> n >> limitWeight;

    int weight[20];
    for(int i = 0;i < n;i++){
        cin >> weight[i];
    }

    pair<int, int> best[1 << n];
    best[0] = {1, 0};

    for(int i = 1;i < (1<<n);i++){
        best[i] = {n+1, 0};
        for(int t = 0;t < n;t++){
            if(i&(1<<t)){
                pair<int,int> temp = best[i^(1<<t)];
                if(temp.second+weight[t] <= limitWeight){
                    temp.second += weight[t];
                }
                else{
                    temp.first++;
                    temp.second = weight[t];
                }
                best[i] = min(best[i], temp, cmp);
            }
        }
    }

    cout << best[(1<<n)-1].first << endl;

    return 0;
}
