#include <iostream>
#include <string>

using namespace std;

int main()
{
    string target, edited;
    cin >> target >> edited;


    int dp[5001][5001] = {0};
    int target_len = target.size(), edited_len = edited.size();
    //  initialize
    for(int i = 1;i <= target_len;i++){
        dp[0][i] = i;
    }
    for(int i = 1;i <= edited_len;i++){
        dp[i][0] = i;
    }

    for(int t = 1;t <= edited_len;t++){
        for(int i = 1;i <= target_len;i++){
            if(target[i-1] == edited[t-1]){
                dp[t][i] = dp[t-1][i-1];
            }
            else{
                dp[t][i] = 1+min(dp[t-1][i-1],min(dp[t-1][i],dp[t][i-1]));
            }
        }
    }

    cout << dp[edited_len][target_len] << endl;
    return 0;
}
