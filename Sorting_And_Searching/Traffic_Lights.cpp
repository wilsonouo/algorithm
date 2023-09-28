#include <iostream>
#include <set>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    int position;
    multiset<int> length;
    set<int> light;
    set<int>::iterator iter, leftptr, rightptr;
    // initialize
    length.insert(x);
    light.insert(0); light.insert(x);
    for(int i = 0;i < n;i++){
        cin >> position;
        iter = light.upper_bound(position);
        rightptr = iter--;
        leftptr = iter;
        length.erase(length.find(*rightptr-*leftptr));
        length.insert(*rightptr-position);
        length.insert(position-*leftptr);
        light.insert(position);
        cout << *length.rbegin() << " ";
    }

    return 0;
}
