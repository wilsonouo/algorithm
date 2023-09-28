#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;

    set<pair<int,int>> value;
    pair<int, int> temp;
    for(int i = 0;i < n;i++){
        cin >> temp.first;
        temp.second = i+1;
        value.insert(temp);
    }

    set<pair<int,int>>::iterator k = value.begin(), l, m, r = --value.end(), ltemp;
    long long int mr, ml, lk;
    temp.second = -1;
    int ans = 0;
    while(value.begin() != r){
        temp.first = mr = x - r->first;
        m = r;
        m--;
        while(m != value.begin()){
            temp.first = ml = mr - m->first;
            l = m;
            l--;
            while(l != k){
                temp.first = lk = ml - l->first;
                if(lk > l->first){
                    break;
                }
                ltemp = l;
                ltemp--;
                k = upper_bound(k,ltemp,temp);
                if(k->first == lk){
                    ans = 1;
                    break;
                }
                else{
                    l--;
                }
            }
            if(ans){
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

    if(ans){
        set<int> position;
        position.insert(l->second);
        position.insert(m->second);
        position.insert(r->second);
        position.insert(k->second);
        set<int>::iterator output = position.begin();
        cout << *(output++) << " " << *(output++) << " " << *(output++) << " " << *(output) << endl;
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
