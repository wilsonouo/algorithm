#include <iostream>

using namespace std;

int tree[600001] = {0};
int hotel[200001];
void update(int node, int l, int r, int index)
{
    if(l == r){
        tree[node] = hotel[l];
        return;
    }

    int mid = (l+r)/2;
    if(index <= mid) update(node*2+1, l, mid, index);
    else update(node*2+2, mid+1, r, index);
    tree[node] = max(tree[node*2+1], tree[node*2+2]);
    return;
}

int query(int node, int l, int r, int key)
{
    if(l == r){
        return l;
    }

    if(key <= tree[node*2+1]) return query(node*2+1, l, (l+r)/2, key);
    else return query(node*2+2, (l+r)/2+1, r, key);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    for(int i = 1;i <= n;i++){
        cin >> hotel[i];
        update(0, 1, n, i);
    }

    for(int i = 0;i < m;i++){
        int capacity;
        cin >> capacity;
        if(capacity > tree[0]) cout << "0" << " ";
        else{
            int hotelNumber = query(0, 1, n, capacity);
            cout << hotelNumber << " ";
            hotel[hotelNumber] -= capacity;
            update(0, 1, n, hotelNumber);
        }
    }
    cout << endl;

    return 0;
}
