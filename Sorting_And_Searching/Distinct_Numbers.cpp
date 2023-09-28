#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> table;
    int in;
    for(int i = 0;i < n;i++){
        cin >> in;
        if(table.find(in) == table.end()){
            table[in] = 1;
        }
    }

    cout << table.size() << endl;
    return 0;
}
