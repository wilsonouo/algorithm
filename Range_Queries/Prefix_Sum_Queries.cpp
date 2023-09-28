#include <iostream>

using namespace std;

class Node
{
    public:
        long long int sum, pref;
        Node(long long int _sum, long long int _pref) : sum(_sum), pref(_pref) {}
        Node(long long x = 0) : sum(x), pref(max(0LL, x)) {}
        friend Node operator+(const Node& a, const Node& b){
            return {a.sum+b.sum, max(a.pref, a.sum+b.pref)};
        }
} tree[600000];

int value[200001];
void setup(int node, int Left, int Right)
{
    if(Left == Right){
        tree[node] = Node(value[Left]);
        return;
    }

    int Mid = (Left+Right)/2;
    setup(node*2+1, Left, Mid);
    setup(node*2+2, Mid+1, Right);
    tree[node] = tree[node*2+1] + tree[node*2+2];
}

void update(int node, int Left, int Right, int index, int key)
{
    if(Left == Right){
        tree[node] = Node(key);
        return;
    }
    int Mid = (Left+Right)/2;
    if(index <= Mid) update(node*2+1, Left, Mid, index, key);
    else update(node*2+2, Mid+1, Right, index, key);
    tree[node] = tree[node*2+1] + tree[node*2+2];
}

Node query(int node, int Left, int Right, int l, int r)
{
    if(Left > r || Right < l) return 0;
    if(Left >= l && Right <= r) return tree[node];
    int Mid = (Left+Right)/2;
    Node q1 = query(node*2+1, Left, Mid, l, r);
    Node q2 = query(node*2+2, Mid+1, Right, l, r);
    return q1 + q2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    for(int i = 1;i <= n;i++){
        cin >> value[i];
    }

    setup(0, 1, n);

    int Query, a, b;
    for(int i = 0;i < q;i++){
        cin >> Query >> a >> b;
        if(Query == 1){
            update(0, 1, n, a, value[a] = b);
        }
        else if(Query == 2){
            cout << query(0, 1, n, a, b).pref << endl;
        }
    }

    return 0;
}
