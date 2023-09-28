#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    int productivity[200000];
    for(int i = 0;i < n;i++){
        cin >> productivity[i];
    }

    sort(productivity, productivity+n);

    long long int oneround = 0;
    for(int i = 0;i < n;i++){
        oneround += productivity[n-1]/productivity[i];
    }

    // binary search
    long long int middle = 0, l = 0, r = 1e18, nowproductivity = 0;
    while(l <= r){
        middle = (l+r)/2;
        nowproductivity = 0;
        for(int i = 0;i < n;i++){
            nowproductivity += middle / productivity[i];
            if(nowproductivity >= t){
                break;
            }
        }
        if(nowproductivity >= t){
            r = middle-1;
        }
        else{
            l = middle+1;
        }
    }

    cout << l << endl;

    return 0;
}
