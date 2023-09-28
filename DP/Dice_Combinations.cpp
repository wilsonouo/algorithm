#include <iostream>

using namespace std;

long long int ans = 0;
long long int combination[1000000] = {0};

int dice(int key)
{
    if(key == 0){
        return 1;
    }
    if(combination[key]){
        return combination[key];
    }

    for(int i = 1;i <= 6;i++){
        if(key - i >= 0){
            combination[key] += dice(key-i);
            if(combination[key] > 1000000007){
                combination[key] %= 1000000007;
            }
        }
    }

    return combination[key];
}

int main()
{
    int n;
    cin >> n;

    cout << dice(n)%(1000000007) << endl;
    return 0;
}
