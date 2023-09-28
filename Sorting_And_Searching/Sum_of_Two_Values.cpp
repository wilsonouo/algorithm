#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    multimap<int,int> value;
    pair<int,int> temp;

    for(int i = 0;i < n;i++){
        cin >> temp.first;
        temp.second = i+1;
        value.insert(temp);
    }


    int ans = 0;
    multimap<int,int>::iterator Left = value.begin(), Right = --value.end();
    while(Right != Left){
        if(x-(Right->first) > Right->first){
            break;
        }
        multimap<int,int>::iterator t = value.lower_bound(x-(Right->first));
        if(t->first == x-(Right->first)){
            Left = t;
            ans = 1;
            break;
        }
        else{
            Left = t;
            Right--;
        }
    }


    if(ans == 0 || (Left->second == Right->second)){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << Left->second << " " << Right->second << endl;
    }

    return 0;
}
