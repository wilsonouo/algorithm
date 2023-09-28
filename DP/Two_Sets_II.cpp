#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int total = n*(n+1)/2;

    long long int combination[100001] = {0};
    combination[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int t = total/2;t >= i;t--){
            combination[t] = (combination[t] + combination[t-i]) % 1000000007;
        }
    }

    if(total % 2 == 1){
        cout << 0 << endl;
    }
    else{
        cout << (combination[total/2]*500000004) % 1000000007 << endl;
    }

    return 0;
}
