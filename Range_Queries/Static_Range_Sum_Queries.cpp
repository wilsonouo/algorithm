#include <iostream>

using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    long long int subsum[200001] = {0};
    for(int i = 1;i <= n;i++){
        cin >> subsum[i];
        subsum[i] += subsum[i-1];
    }

    int a, b;
    for(int i = 0;i < q;i++){
        cin >> a >> b;
        cout << subsum[b] - subsum[a-1] << endl;
    }

    return 0;
}
