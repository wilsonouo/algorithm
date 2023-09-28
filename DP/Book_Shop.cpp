#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;

    int price[1001];
    int page[1001];
    for(int i = 1;i <= n;i++){
        cin >> price[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> page[i];
    }

    vector<vector<int>> totalpage(n+1, vector<int>(x+1,0));
    for(int i = 1;i <= n;i++){
        for(int money = 1;money <= x;money++){
            totalpage[i][money] = totalpage[i-1][money];
            if(money - price[i] >= 0){
                totalpage[i][money] = max(page[i]+totalpage[i-1][money - price[i]], totalpage[i-1][money]);
            }
        }
    }

    cout << totalpage[n][x] << endl;


    return 0;
}
