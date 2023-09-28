#include <iostream>
#include <map>
#include <math.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int description[100000];
    for(int i = 0;i < n;i++){
        cin >> description[i];
    }

    long long int arrays[100000][101] = {0};
    //  for begining "0"
    if(!description[0]){
        for(int i = 1;i <= m;i++){
            arrays[0][i] = 1;
        }
    }
    else{
        arrays[0][description[0]]++;
    }

    for(int i = 1;i < n;i++){
        if(!description[i]){
            for(int t = 1;t <= m;t++){
                arrays[i][t] += arrays[i-1][t-1];
                arrays[i][t] %= 1000000007;
                arrays[i][t] += arrays[i-1][t];
                arrays[i][t] %= 1000000007;
                arrays[i][t] += arrays[i-1][t+1];
                arrays[i][t] %= 1000000007;
            }
        }
        else{
                arrays[i][description[i]] += arrays[i-1][description[i]-1];
                arrays[i][description[i]] %= 1000000007;
                arrays[i][description[i]] += arrays[i-1][description[i]];
                arrays[i][description[i]] %= 1000000007;
                arrays[i][description[i]] += arrays[i-1][description[i]+1];
                arrays[i][description[i]] %= 1000000007;
        }
    }

    long long int ans = 0;
    if(!description[n-1]){
        for(int t = 1;t <= m;t++){
            ans += arrays[n-1][t];
            ans %= 1000000007;
        }
    }
    else{
        ans = arrays[n-1][description[n-1]];
    }

    cout << ans << endl;

    return 0;
}
