#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> lengths;
    for(int i = 0;i < n;i++){
        int in;
        cin >> in;
        lengths.push_back(in);
    }

    sort(lengths.begin(), lengths.end());


    // find the middle
    int middle = n/2;
    long long int ans = 0, temp_ans = 0;
    for(int i = 0;i < n;i++){
        ans += abs(lengths[i]-lengths[middle]);
        temp_ans += abs(lengths[i]-lengths[middle+1]);
    }

    if(ans > temp_ans){
        ans = temp_ans;
    }


    cout << ans << endl;

    return 0;
}
