#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;
    while(n != 1){
        cout << n << " ";
        if(n % 2 == 0){ // even number
            n /= 2;
        }
        else{
            n = n*3+1;
        }
    }
    cout << n << endl;
    return 0;
}
