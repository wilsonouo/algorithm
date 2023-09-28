#include <iostream>
#include <limits.h>

using namespace std;

int n, k;
int coin[100];
long long int combination[1000001] = {0};
long long int minimizing(int key)
{
    if(key == 0){
        return 0;
    }
    if(key < 0){
        return 1000000000000;
    }
    if(combination[key]){
        return combination[key];
    }

    combination[key] = 1000000000000;
    for(int i = 0;i < n;i++){
        combination[key] = min(minimizing(key-coin[i])+1, combination[key]);
    }

    return combination[key];


}

int main()
{
    cin >> n >> k;

    for(int i = 0;i < n;i++){
        cin >> coin[i];
    }

    long long int ans = minimizing(k);
    if(ans == 1000000000000){
        cout << -1 << endl;
    }
    else{
        cout << minimizing(k) << endl;
    }

    return 0;
}
