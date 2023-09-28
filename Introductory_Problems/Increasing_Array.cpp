#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long int arrays[200000] = {0};
    for(int i = 0;i < n;i++){
        cin >> arrays[i];
    }

    long long int add = 0;
    for(int i = 1;i < n;i++){
        if(arrays[i-1] > arrays[i]){
            add += arrays[i-1] - arrays[i];
            arrays[i] = arrays[i-1];
        }
    }

    cout << add << endl;

    return 0;
}
