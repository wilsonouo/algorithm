#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    long long int prefixsum[200001] = {0};
    int value;
    for(int i = 1;i <= n;i++){
        cin >> value;
        prefixsum[i] = value + prefixsum[i-1];
    }

    // initialize
    multiset<long long int> subarray;
    long long int ans = LONG_MIN;
    for(int i = a;i <= n;i++){
        if(i > b){
            subarray.erase(subarray.find(prefixsum[i-b-1]));
        }
        subarray.insert(prefixsum[i-a]);
        ans = max(ans, prefixsum[i]-*subarray.begin());
    }

    cout << ans << endl;


    return 0;
}
