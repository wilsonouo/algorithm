#include <iostream>

using namespace std;

int game[5000];
long long int score[5001][5001] = {0};
long long int removal(int left, int right, bool player)
{
    if(left >= right){
        if(player){
            return game[left];
        }
        else{
            return 0;
        }
    }
    if(score[left][right]){
        return score[left][right];
    }


    if(player == true){
        score[left][right] = max(game[left]+removal(left+1,right,!player), game[right]+removal(left,right-1,!player));
        //cout << "player1" << endl;
    }
    else{
        score[left][right] = min(removal(left+1,right,!player), removal(left,right-1,!player));
        //cout << "player2" << endl;
    }

    return score[left][right];
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> game[i];
    }

    cout << removal(0,n-1, true) << endl;
    return 0;
}
