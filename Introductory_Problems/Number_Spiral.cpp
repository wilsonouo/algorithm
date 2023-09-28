#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long row, column;

    for(int i = 0;i < n;i++){
        cin >> row >> column;
        if(row >= column){
            if(row % 2 == 0){
                cout << row*row-(column-1) << endl;
            }
            else{
                cout << (row-1)*(row-1)+column << endl;
            }
        }
        else{
            if(column % 2 == 1){
                cout << column*column-(row-1) << endl;
            }
            else{
                cout << (column-1)*(column-1)+row << endl;
            }
        }
    }

    return 0;
}
