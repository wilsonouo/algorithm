#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int combination = pow(2,n);
    int bits[70000][16] = {0};

    // initialize
    bits[1][0] = 1;

    int pointer = 0;

    for(int i = 2;i <= n;i++){
        int mid = pow(2,i-1);
        for(int t = 0;t < mid;t++){
            bits[mid+t][i-1] = 1;
            for(int k = 0;k < i-1;k++){
                bits[mid+t][k] = bits[mid-(t+1)][k];
            }
        }
    }

    int stop = pow(2,n);
    for(int i = 0;i < stop;i++){
        for(int t = n-1;t >= 0;t--){
            cout << bits[i][t];
        }
        cout << endl;
    }

    return 0;
}
