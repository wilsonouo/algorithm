#include <iostream>

using namespace std;

int bitN = 1;
long long int bit[300000] = {0};
void update(int index, int add)
{
    while(index <= bitN){
        bit[index] += add;
        index += index & (-index);
    }
}

long long int check(int index)
{
    long long int ans = 0;
     while(index){
        ans += bit[index];
        index -= index & (-index);
    }
    return ans;
}

int main()
{
    int n, q;
    cin >> n >> q;


    while(bitN < n){
        bitN *= 2;
    }


    int value[200000];
    for(int i = 1;i <= n;i++){
        cin >> value[i];
        update(i, value[i]);
    }

    int query;
    int a, b;
    for(int i = 0;i < q;i++){
        cin >> query >> a >> b;
        if(query == 1){
            update(a, b-value[a]);
            value[a] = b;
        }
        else if (query == 2){
            cout << check(b) - check(a-1) << endl;
        }
    }


    return 0;
}
