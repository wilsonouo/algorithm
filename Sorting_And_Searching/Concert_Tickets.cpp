#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> price;
    for(int i = 0;i < n;i++){
        int in;
        cin >> in;
        price.insert(in);
    }

    /*for (auto it = price.begin(); it != price.end(); it++)
        cout << *it << " ";*/

    multiset<int>::iterator up;

    int want;
    for(int i = 0;i < m;i++){
        cin >> want;
        up = price.upper_bound(want);
        if(up == price.begin() && want < *(up) || price.empty()){
           cout << "-1" << endl;
        }
        else if(up == price.begin() && want >= *(up)){
            cout << *(up) << endl;
            price.erase(up);
        }
        else{
            cout << *(--up) << endl;
            price.erase(up);
        }
    }


    return 0;
}
