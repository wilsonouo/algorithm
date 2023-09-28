#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long int m = 1;

    while(n > 0){
        m *= 2;
        n--;
        if(m > 1000000007){
            m %= 1000000007;
        }
    }

    cout << m % 1000000007 << endl;

    return 0;
}
