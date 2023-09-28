#include <iostream>
#include <limits.h>

using namespace std;

int n, q;
int value[200001];
int Index[200001] = {0};
int tree[700000] = {0};
int setup(int node, int rangeStart, int rangeEnd)
{
    if(rangeStart == rangeEnd){
        tree[node] = value[rangeStart];
        Index[rangeStart] = node;
        return tree[node];
    }

    tree[node] = min(setup(node*2+1, rangeStart, (rangeEnd-rangeStart)/2+rangeStart), setup(node*2+2, (rangeEnd-rangeStart)/2+rangeStart+1, rangeEnd));
    return tree[node];
}

void update(int node)
{
    if(node != 0){
        tree[node] = min(tree[node*2+1], tree[node*2+2]);
        update((node-1)/2);
    }
    else if(node == 0){
        tree[node] = min(tree[node*2+1], tree[node*2+2]);
    }
}

int check(int node, int rangeStart, int rangeEnd, int Start, int Finish)
{
    if(rangeStart > Finish || rangeEnd < Start){
        return INT_MAX;
    }
    if(rangeStart >= Start && rangeEnd <= Finish){
        return tree[node];
    }

    return min(check(node*2+1, rangeStart, (rangeEnd-rangeStart)/2+rangeStart, Start, Finish), check(node*2+2, (rangeEnd-rangeStart)/2+rangeStart+1, rangeEnd, Start, Finish));
}

int main()
{

    cin >> n >> q;


    for(int i = 0;i < n;i++){
        cin >> value[i];
    }

    setup(0, 0, n-1);

    int query;
    int a, b;
    for(int i = 0;i < q;i++){
        cin >> query >> a >> b;
        if(query == 1){
            tree[Index[a-1]] = b;
            update((Index[a-1]-1)/2);
        }
        else if(query == 2){
            cout << check(0, 0, n-1, a-1, b-1) << endl;
        }
    }

    return 0;
}
