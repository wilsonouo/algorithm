#include <iostream>

using namespace std;

class Implicit_segment_tree
{
    public:
        long long int sum;
        Implicit_segment_tree *Left, *Right;
        Implicit_segment_tree(long long int _sum, Implicit_segment_tree *_l,  Implicit_segment_tree *_r){
            sum = _sum;
            Left = _l;
            Right = _r;
        }
};

void update(Implicit_segment_tree * root, int l, int r, int index, long long int key)
{
    if(index > r || index < l) return;
    root->sum += key;
    if(index == l && r == index){
        return;
    }

    if(root->Left == NULL) root->Left = new Implicit_segment_tree(0, NULL, NULL);
    if(root->Right == NULL) root->Right = new Implicit_segment_tree(0, NULL, NULL);
    update(root->Left, l, (l+r)/2, index, key);
    update(root->Right, (l+r)/2+1, r, index, key);
}

int check(Implicit_segment_tree * root, int l, int r, int start, int finish)
{
    if(l > finish || r < start || root == NULL){
        return 0;
    }
    if(start <= l && finish >= r){
        return root->sum;
    }

    return check(root->Left, l, (l+r)/2, start, finish) + check(root->Right, (l+r)/2+1, r, start, finish);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    Implicit_segment_tree *root = new Implicit_segment_tree(0, NULL, NULL);

    int value[200001];
    const int biggest = 1e9;
    for(int i = 1;i <= n;i++){
        cin >> value[i];
        update(root, 1, biggest, value[i], 1);
    }



    char query;
    int a, b;
    for(int i = 0;i < q;i++){
        cin >> query >> a >> b;
        if(query == '?'){
            cout << check(root, 1, biggest, a, b) << endl;
        }
        else if(query == '!'){
            update(root, 1, biggest, value[a], -1);
            update(root, 1, biggest, b, 1);
            value[a] = b;
        }
    }



    return 0;
}
