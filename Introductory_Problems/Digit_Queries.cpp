#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        long long int k, digit_number = 0, real = 0;
        int digit = 1;
        cin >> k;
        while(k - (digit_number+(long long)pow(10,digit-1)*digit*9) > 0){
            digit_number += (long long)pow(10,digit-1)*digit*9;
            real += (long long)pow(10,digit-1)*9;
            digit++;
        }
        long long int number = ((k-digit_number)/digit);
        long long int position = (k-digit_number)%(digit);

        if(position == 0) cout << ((real+number)/(long long)pow(10,position)) % 10 << endl;
        else if(digit-1 > 0) cout << ((real+number+1)/(long long)pow(10,digit-position)) % 10 << endl;
        else cout << number << endl;
    }


    return 0;
}
