#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
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
    for(int i = 0;i < n;i++){
        for(int weight = 0;weight <= k;weight++ ){
            if(weight - coin[i] >= 0){
                combination[weight] += combination[weight-coin[i]];
                combination[weight] %= 1000000007;
            }
        }
    }


    cout << combination[k] << endl;

    return 0;
}
