#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> arrays(n);
    for(int i = 0;i < n;i++){
        cin >> arrays[i];
    }

    long long int ans = 0;
    map<long long,int> position;
    position[0] = 1;
    long long int prefixSum = 0;
    for(int i = 0;i < n;i++){
        prefixSum += arrays[i];
        ans += position[prefixSum-x];
        position[prefixSum]++;
    }
    cout << ans << endl;
    return 0;
}
