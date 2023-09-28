#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int five = 0, five_total = 1;
    while(five_total*5 <= n){
        five_total *= 5;
        five += n/five_total;
    }
    cout << five << endl;
    return 0;
}
