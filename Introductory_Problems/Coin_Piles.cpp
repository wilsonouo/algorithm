#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int a, b;

    for(int i = 0;i < n;i++){
        cin >> a >> b;
        if(a < b) swap(a,b);
        if((a+b) % 3 == 0 && a <= 2*b) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
