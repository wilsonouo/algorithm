#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cin >> n;

    double combination = 0;

    cout << "0" << endl;

    for(double i = 2;i <= n;i++){
        combination = ((i*i)*(i*i-1)/2);
        combination = combination - (i-1)*(i-2)*4;
        cout << setprecision(20) << combination << endl;
    }


    return 0;
}
