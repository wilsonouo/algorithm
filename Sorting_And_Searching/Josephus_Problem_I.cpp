#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int circle_odd[100000];
    int take[100000] = {0};
    int peoplenumber = n/2;
    //  even
    for(int i = 0;i < peoplenumber;i++){
        cout << (i+1)*2 << " ";
        circle_odd[i] = 1+2*i;
    }

    //  determine the number of person is odd or even
    int ptr = 0;
    if(n%2 == 1){
        ptr = peoplenumber;
        circle_odd[peoplenumber] = 1+2*peoplenumber;
        peoplenumber++;
    }

    //  odd
    int countoutput = 0;
    int strike = 0;
    while(countoutput <= peoplenumber-2){
        strike = 0;
        while(strike < 1 || take[ptr] == 1){
            if(take[ptr] == 0){
                strike++;
            }
            ptr++;
            if(ptr > peoplenumber-1){
                ptr = 0;
            }
        }
        countoutput++;
        cout << circle_odd[ptr] << " ";
        take[ptr++] = 1;
        if(ptr > peoplenumber-1){
            ptr = 0;
        }
        //cout << countoutput << endl;
    }

    for(int i = 0;i < peoplenumber;i++){
        if(take[i] == 0){
            cout << circle_odd[i] << endl;
            break;
        }
    }

    return 0;
}
