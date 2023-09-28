#include <iostream>

using namespace std;

int bitN = 1;
long long int bit[300001] = {0};
void update(int index, int key)
{
    while(index <= bitN){
        bit[index] += key;
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
    int n , q;
    cin >> n >> q;

    while(bitN < n){
        bitN *= 2;
    }

    int value[200001];
    for(int i = 1;i <= n;i++){
        cin >> value[i];
        update(i, value[i] - value[i-1]);
    }

    int query;
    for(int i = 0;i < q;i++){
        cin >> query;
        if(query == 1){
            int a, b, add;
            cin >> a >> b >> add;
            update(a, add);
            update(b+1, -add);
        }
        else if(query == 2){
            int a;
            cin >> a;
            cout << check(a) << endl;
        }
    }
    return 0;
}
