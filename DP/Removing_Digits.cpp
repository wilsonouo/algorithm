#include <iostream>

using namespace std;

long long int digits[1000001] = {0};
long long int removing(int key)
{
    if(key == 0){
        return 0;
    }

    long long int temp = key;
    long long int temp_max = 0;
    while(temp != 0){
        if(temp_max < temp%10){
            temp_max = temp % 10;
        }
        temp /= 10;
    }

    digits[key] += removing(key-temp_max)+1;

    return digits[key];
}

int main()
{
    int n;
    cin >> n;

    cout << removing(n) << endl;
    return 0;
}
