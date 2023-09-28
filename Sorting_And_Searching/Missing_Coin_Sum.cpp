#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
    return a < b;
}

int main()
{
    int n;
    cin >> n;

    int coin[200000];
    for(int i = 0;i < n;i++){
        cin >> coin[i];
    }

    sort(coin, coin+n, cmp);

    long long int minsum = 0;
    for(int i = 0;i < n;i++){
        if(minsum+1 < coin[i]) break;
        else minsum += coin[i];
    }

    cout << minsum+1 << endl;


    return 0;
}
