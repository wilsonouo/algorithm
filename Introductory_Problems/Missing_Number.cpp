#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    int table[200000] = {0};
    int number;

    for(int i = 0;i < n-1;i++){
        cin >> number;
        table[number] = 1;
    }

    for(int i = 1;i <= n;i++){
        if(table[i] != 1){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
