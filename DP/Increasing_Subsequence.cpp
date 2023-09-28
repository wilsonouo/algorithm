#include <iostream>
#include <set>
#include <limits.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sequence;
    set<int> increasing;
    set<int>::iterator iter;
    for(int i = 1;i <= n;i++){
        cin >> sequence;
        iter = increasing.lower_bound(sequence);
        if(iter != increasing.end()){
            increasing.erase(iter);
        }
        increasing.insert(sequence);
    }

    cout << increasing.size() << endl;

    return 0;
}
