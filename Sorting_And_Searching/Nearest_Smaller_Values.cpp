#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<pair<int,int>> position;
    pair<int,int> value;
    for(int i = 1;i <=n;i++){
        cin >> value.first;
        value.second = i;
        while(!position.empty() && position.top().first >= value.first){
            position.pop();
        }
        if(position.empty()){
            cout << 0 << " ";
        }
        else{
            cout << position.top().second << " ";
        }
        position.push(value);
    }
    cout << endl;

    return 0;
}
