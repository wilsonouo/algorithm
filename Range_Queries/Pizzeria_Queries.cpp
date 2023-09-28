#include <iostream>
#include <vector>

using namespace std;

template<class T> struct segTree
{
    T Findmin(T a, T b) { return min(a,b);}
    int N;
    int U = 1e9;
    vector<T> tree;
    segTree() {};
    segTree(int _N) : N(_N), tree(4*_N, U) {}
    void update(int index, T value) { update(index, value, 0, 1, N); }
    void update(int index, T value, int node, int l, int r){
        if(l == r) { tree[node] = value; return;}

        int Mid = (l+r)/2;
        if(index <= Mid) update(index, value, node*2+1, l, Mid);
        else update(index, value, node*2+2, Mid+1, r);
        tree[node] = Findmin(tree[node*2+1], tree[node*2+2]);
    }
    T query(int L, int R) { return query(0, 1, N, L, R); }
    T query(int node, int l, int r, int L, int R){
        if(l >= L && r <= R) return tree[node];
        if(l > R || r < L) return U;
        int Mid = (l+r)/2;
        return Findmin(query(node*2+1, l, Mid, L, R), query(node*2+2, Mid+1, r, L, R));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int value[200001];
    for(int i = 1;i <= n;i++){
        cin >> value[i];
    }

    segTree<int> up = segTree<int>(n), down = segTree<int>(n);

    for(int i = 1;i <= n;i++){
        down.update(i, value[i]-i);
        up.update(i, value[i]+i);
    }

    for(int i = 0;i < q;i++){
        int Query, a, b;
        cin >> Query;
        if(Query == 1){
            cin >> a >> b;
            value[a] = b;
            down.update(a, value[a]-a);
            up.update(a, value[a]+a);
        }
        else{
            cin >> a;
            int D = down.query(1, a) + a;
            int U = up.query(a, n) - a;
            cout << min(D, U) << endl;
        }
    }



    return 0;
}
