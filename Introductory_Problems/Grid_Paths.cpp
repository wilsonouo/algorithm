#include <iostream>
#include <string>

using namespace std;

enum direct {up, down, lef, rit, zero};
int instruction[48] = {0};
int board[9][9] = {0};
int ans = 0;

void path(int step, int x, int y)
{
    // reach the end
    if( (x == 1 && y == 7) || step == 48){
        if(step == 48 && x == 1 && y == 7){
            ans++;
        }
        return;
    }
    if( (board[x-1][y] == 1 && board[x+1][y] == 1 && board[x][y+1] == 0 && board[x][y-1] == 0) || (board[x-1][y] == 0 && board[x+1][y] == 0 && board[x][y-1] == 1 && board[x][y+1] == 1) ){
        return;
    }


    // up down left right
    int dir_ud[4] = {-1, 1, 0, 0};
    int dir_rl[4] = {0, 0, -1, 1};
    // visit
    if(instruction[step] == zero){
        for(int i = 0;i < 4;i++){
            if(!board[x+dir_rl[i]][y+dir_ud[i]]){
                board[x+dir_rl[i]][y+dir_ud[i]] = 1;
                path(step+1, x+dir_rl[i], y+dir_ud[i]);
                board[x+dir_rl[i]][y+dir_ud[i]] = 0;
            }
        }
    }
    else{
        if(!board[x+dir_rl[instruction[step]]][y+dir_ud[instruction[step]]]){
            board[x+dir_rl[instruction[step]]][y+dir_ud[instruction[step]]] = 1;
            path(step+1, x+dir_rl[instruction[step]], y+dir_ud[instruction[step]]);
            board[x+dir_rl[instruction[step]]][y+dir_ud[instruction[step]]] = 0;
        }
    }

    return;
}

int main()
{
    string input;
    cin >> input;
    // set the precondition
    for(int i = 0;i < 48;i++){
        if(input.at(i) == 'U'){
            instruction[i] = up;
        }
        else if(input.at(i) == 'D'){
            instruction[i] = down;
        }
        else if(input.at(i) == 'L'){
            instruction[i] = lef;
        }
        else if(input.at(i) == 'R'){
            instruction[i] = rit;
        }
        else{
            instruction[i] = zero;
        }
    }

    for(int i = 0;i < 9;i++){
        board[0][i] = 1;
        board[8][i] = 1;
        board[i][0] = 1;
        board[i][8] = 1;
    }

    // ans
    board[1][1] = 1;
    path(0, 1, 1);
    cout << ans << endl;
    return 0;
}
