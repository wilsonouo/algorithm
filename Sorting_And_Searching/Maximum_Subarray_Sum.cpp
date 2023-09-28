#include <iostream>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long temp_max = 0, ans_max = 0;
    int negative_min = INT_MIN;
    int in;
    for(int i = 0;i < n;i++){
        cin >> in;
        if(in >= 0){
            temp_max += in;
        }
        else{
            if(ans_max < temp_max){
                ans_max = temp_max;
            }

            if(temp_max + in >= 0){
                temp_max += in;
                continue;
            }
            temp_max = 0;
        }

        if(negative_min < in){
            negative_min = in;
        }
    }

    if(temp_max > ans_max){
        ans_max = temp_max;
    }

    if(negative_min >= 0){
        cout << ans_max << endl;
    }
    else{
        cout << negative_min << endl;
    }

    return 0;
}
