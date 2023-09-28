#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int money[101];
    long long int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> money[i];
        sum += money[i];
    }

    sort(money+1, money+n);

    int combination[100001] = {0};
    int order[100001] = {0};
    long long int total = 0;
    combination[0] = 1;
    for(int i = 1;i <= n;i++){
        for(int t = 1;t <= sum;t++){
            if(t-money[i] >= 0 && combination[t-money[i]] && combination[t] != 1 && order[t-money[i]] < i){
                combination[t] = 1;
                order[t] = i;
                total++;
            }
        }
    }

    cout << total << endl;
    for(int i = 1;i <= sum;i++){
        if(combination[i]){
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
