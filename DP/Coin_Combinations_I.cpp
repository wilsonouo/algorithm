#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

int n, k;
int coin[100];
long long int combination[1000001] = {0};
long long int minimizing(int key)
{
    if(key == 0){
        return 1;
    }
    if(combination[key]){
        return combination[key];
    }

    for(int i = 0;i < n;i++){
        if(key-coin[i] >= 0){
            combination[key] += minimizing(key-coin[i]);
        }
        else{
            break;
        }
    }

    if(combination[key] > 1000000007){
        combination[key] %= 1000000007;
    }

    return combination[key];
}

int main()
{
    int n, k;
    int coin[100];
    long long int combination[1000001] = {0};
    cin >> n >> k;

    for(int i = 0;i < n;i++){
        cin >> coin[i];
    }

    sort(coin, coin+n);

    combination[0] = 1;
    for(int weight = 0;weight <= k;weight++){
        for(int i = 1;i <= n;i++){
            if(weight - coin[i-1] >= 0){
                combination[weight] += combination[weight-coin[i-1]];
                combination[weight] %= 1000000007;
            }
        }
    }

    cout << combination[k] << endl;

    return 0;
}
