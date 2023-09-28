#include <iostream>

using namespace std;

int value[200001];
int tree[600000] = {0};
int updateALL(int node, int l, int r)
{
    if(l == r){
        tree[node] = 1;
        return 1;
    }

    int mid = (l+r)/2;
    tree[node] = updateALL(node*2+1, l, mid) + updateALL(node*2+2, mid+1, r);
    return tree[node];
}

void update(int node, int l, int r, int index)
{
    if(l == r && l == index){
        tree[node]--;
        return;
    }
    if(index >= l && index <= r){
        tree[node]--;
        int mid = (l+r)/2;
        update(node*2+1, l, mid, index);
        update(node*2+2, mid+1, r, index);
    }

    return;
}

int check(int node, int l, int r, int index)
{
    if(l == r){
        return l;
    }

    int mid = (l+r)/2;
    if(index <= tree[node*2+1]) return check(node*2+1, l, mid, index);
    else return check(node*2+2, mid+1, r, index-tree[node*2+1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> value[i];
    }

    updateALL(0,1,n);

    int removal;
    for(int i = 0;i < n;i++){
        cin >> removal;
        int index = check(0, 1, n, removal);
        cout << value[index] << " ";
        update(0, 1, n, index);
    }


    return 0;
}
