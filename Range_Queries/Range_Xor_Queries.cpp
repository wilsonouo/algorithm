#include <iostream>

using namespace std;

int bit[300000] = {0};
int bitN = 1;
void update(int node, int key)
{
    while(node <= bitN){
        bit[node] ^= key;
        node += node & (-node);
    }
}

int query(int node)
{
    int ans = 0;
    while(node){
        ans ^= bit[node];
        node -= node & (-node);
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

    int value[200001];
    for(int i = 1;i <= n;i++){
        cin >> value[i];
        update(i, value[i]);
    }

    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        int ans =  query(b) ^ query(a-1);
        cout << ans << endl;
    }

    return 0;
}
