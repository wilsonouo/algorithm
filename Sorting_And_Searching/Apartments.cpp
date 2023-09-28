#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

//不能回傳right
int binarySearch(int left, int right, long long int arrays[], int value)
{
    int middle = (left+right)/2;
    while(left <= right){
        if(arrays[middle] <= value){
            right = middle-1;
        }
        else{
            left = middle+1;
        }
        middle = (left+right)/2;
    }
    return left;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    long long int apartments[200000] = {0};
    long long int desired[200000] = {0};
    for(int i = 0;i < n;i++){
        cin >> desired[i];
    }
    for(int i = 0;i < m;i++){
        cin >> apartments[i];
    }

    sort(apartments, apartments+m, compare);
    sort(desired, desired+n, compare);
    /*for(int i = 0 ;i < m;i++){
        cout << apartments[i] << " ";
    }
    cout << endl;*/

    int ans = 0;
    int ptr = 0;
    for(int i = 0;i < n;i++){
        int t = binarySearch(0+ptr, m-1, apartments, desired[i]+k);
        if(t < m && desired[i] >= apartments[t]-k && desired[i] <= apartments[t]+k){
            ptr = t+1;
            ans++;
        }
        else if(t+1 < m && desired[i] >= apartments[t+1]-k && desired[i] <= apartments[t+1]+k){
            ptr = t+2;
            ans++;
        }
    }


    cout << ans << endl;

    return 0;
}
