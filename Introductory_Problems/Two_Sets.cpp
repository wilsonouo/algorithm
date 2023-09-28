#include <iostream>

using namespace std;

int main()
{
    long long int n;
    cin >> n;

    long long int half_set;
    int select[1000000] = {0};
    int left_size = 0;

    if( (n*(n+1)/2) % 2 == 0 ){
        cout << "YES" << endl;
        half_set = n*(n+1)/4;
        long long int goup = 0;
        int adden = n;
        while(goup < half_set){
            if(half_set - goup > adden){
                goup += adden;
                select[adden] = 1;
                adden--;
                left_size++;
            }
            else{
                adden = half_set - goup;
                select[adden] = 1;
                goup += adden;
                adden--;
                left_size++;
            }
        }

        // output
        cout << n-left_size << endl;
        for(int i = 1;i <= n;i++){
            if(select[i] == 0){
                cout << i << " ";
            }
        }
        cout << endl << left_size << endl;
        for(int i = 1;i <= n;i++){
            if(select[i] == 1){
                cout << i << " ";
            }
        }

    }
    else{
        cout << "NO" << endl;
    }



    return 0;
}
