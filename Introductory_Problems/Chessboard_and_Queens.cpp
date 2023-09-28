#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define free 0
#define visited 1
#define reserved 2

// use one dimension to present two dimension
int queenes[8][8] = {0}, ans = 0;
vector<int> check = {0, 1, 2, 3, 4, 5, 6, 7};

void eight_queens(int line)
{
    //cout << queenes[2][2] << endl;
    if(line == 7){
        int notqualify = 0;
        if(queenes[check[0]][7] != free){
            notqualify = 1;
        }
        // check diagonal
        int row = check[0], col = 7;
        // up
        while(row >= 0){
            if(queenes[row][col] == visited){
                notqualify = 1;
            }
            row--;
            col--;
        }
        // down
        row = check[0]; col = 7;
        while(row < 8){
            if(queenes[row][col] == visited){
                notqualify = 1;
            }
            row++;
            col--;
        }
        if(!notqualify){
            ans++;
        }
        return;
    }

    for(int i = 0;i < check.size();i++){
        if(queenes[check[i]][line] == free){
            // check it can put or not
            int notqualify = 0;
            // check diagonal
            int row = check[i]-1, col = line-1;
            // up
            while(row >= 0 && col >= 0){
                if(queenes[row][col] == visited){
                    notqualify = 1;
                }
                row--;
                col--;
            }
            // down
            row = check[i]+1; col = line-1;
            while(row < 8 && col >= 0){
                if(queenes[row][col] == visited){
                    notqualify = 1;
                }
                row++;
                col--;
            }
            if(!notqualify){
                int cut = check[i];
                queenes[check[i]][line] = 1;
                // move check from vector
                check.erase(check.begin()+i);
                eight_queens(line+1);
                queenes[cut][line] = 0;
                check.insert(check.begin()+i, cut);
            }
        }
    }
    return;
}

int main()
{
    string input;
    for(int k = 0;k < 8;k++){
        cin >> input;
        for(int i = 0;i < 8;i++){
            if(input.at(i) == '*'){
                queenes[k][i] = reserved;
            }
        }
    }
    eight_queens(0);
    cout << ans << endl;
    return 0;
}
