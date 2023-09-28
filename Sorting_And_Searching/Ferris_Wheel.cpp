#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool compare(int a, int b)
{
    return a < b;
}

// ex：等於放在右邊，若值相同，會給最左邊的值
int binarySearch(int left, int right, int arrays[], int key)
{
    int middle;
    while(right >= left){
        middle = (right+left)/2;
        if(arrays[middle] > key){
            right = middle-1;
        }
        else{
            left = middle+1;
        }
    }
    return right;
}

int main()
{
    int n, x;
    cin >> n >> x;

    int childweight[200000] = {0};
    for(int i = 0;i < n;i++){
        cin >> childweight[i];
    }

    sort(childweight, childweight+n, compare);

    int ans = 0;
    int up = n-1;
    for(int i = 0;i <= up;i++){
        if(x-childweight[i] > 0){
            int t = binarySearch(i+1, up, childweight, x-childweight[i]);
            if(x-childweight[i] >= childweight[t] && t <= up){
                ans += abs(up-t)+1;
                up = t-1;
            }
            else{
                ans++;
            }
        }
        else if(x-childweight[i] == 0){
            ans++;
        }
        else{
            continue;
        }
    }

    cout << ans << endl;

    return 0;
}
