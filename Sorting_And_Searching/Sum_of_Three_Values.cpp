#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    set<pair<int,int>> value;
    pair<int, int> temp;
    int sum = 0;
    for(int i = 0;i < n;i++){
        cin >> temp.first;
        sum += temp.first;
        temp.second = i+1;
        value.insert(temp);
    }

    set<pair<int,int>>::iterator l = value.begin(), m, r = --value.end();
    long long int mr, ml;
    temp.second = -1;
    int ans = 0;
    while(n > 3 && value.begin() != r){
        temp.first = mr = x - r->first;
        m = value.upper_bound(temp);
        m--;
        if(r == m){
            m--;
        }
        while(m != l){
            temp.first = ml = mr - m->first;
            if(ml > m->first){
                break;
            }
            l = value.upper_bound(temp);
            if(ml == l->first){
                ans = 1;
                break;
            }
            else{
                m--;
            }
        }
        if(ans){
            break;
        }
        else{
            r--;
        }
    }

    /*r++;
    m++;*/
    if(ans){
        set<int> position;
        position.insert(l->second);
        position.insert(m->second);
        position.insert(r->second);
        set<int>::iterator output = position.begin();
        cout << *(output++) << " " << *(output++) << " " << *(output) << endl;
    }
    else if(n == 3 && sum == x){
        cout << "1 2 3" << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
