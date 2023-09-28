#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    int value[200000];
    int maxValue = 0;
    for(int i = 0;i < n;i++){
        cin >> value[i];
        maxValue = max(maxValue, value[i]);
    }

    long long int high = 1e18, low = maxValue, middle;
    long long int maxSum = 1e18;
    while(high >= low){
        middle = (low+high)/2;
        int block = 1;
        long long int sum = 0;
        for(int i = 0;i < n;i++){
            if(sum + value[i] > middle){
                sum = 0;
                block++;
            }
            sum += value[i];
        }

        if(block > k){
            low = middle+1;
        }
        else{
            if(middle < maxSum){
                maxSum = middle;
            }
            high = middle-1;
        }
    }

    cout << maxSum << endl;

    return 0;
}
