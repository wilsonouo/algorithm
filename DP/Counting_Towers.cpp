#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int tall;
    long long int counting[1000001][3];
    counting[1][1] = 1;
    counting[1][2] = 1;
    for(int i = 2;i <= 1000000;i++){
        counting[i][1] = (counting[i-1][1]*2 + counting[i-1][2]) % 1000000007;
        counting[i][2] = (counting[i-1][1] + counting[i-1][2]*4) % 1000000007;
    }

    for(int i = 0;i < t;i++){
        cin >> tall;
        cout << (counting[tall][1]+counting[tall][2]) % 1000000007 << endl;
    }
    return 0;
}
