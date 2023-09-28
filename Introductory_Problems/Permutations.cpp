#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 1){
        cout << "1" << endl;
    }
    else if(n <= 3){
        cout << "NO SOLUTION" << endl;
    }
    else if(n == 4){
        cout << "2 4 1 3" << endl;
    }
    else{
        int odd = n-1, even = n;
        while(even > 0){
            cout << even << " ";
            even -= 2;
        }
        while(odd > 0){
            cout << odd << " ";
            odd -= 2;
        }
        cout << endl;
    }

    return 0;
}
