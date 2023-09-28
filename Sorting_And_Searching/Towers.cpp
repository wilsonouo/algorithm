#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;


    multiset<int> tower;
    multiset<int>::iterator iter;
    int height;
    for(int i = 0;i < n;i++){
        cin >> height;
        iter = tower.upper_bound(height);
        if(iter != tower.end()){
            tower.erase(iter);
        }
        tower.insert(height);
    }

    cout << tower.size() << endl;


    return 0;
}

