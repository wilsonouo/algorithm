#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define maximum 1e9

using namespace std;

bool cmp(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b)
{
    if(a.first.first == b.first.first){
        return a.first.second > b.first.second;
    }
    else return a.first.first < b.first.first;
}

class segTree
{
    public:
    segTree *Rptr, *Lptr;
    int sum;
    segTree() {}
    segTree(int _sum, segTree* _Rptr, segTree* _Lptr) : sum(_sum), Rptr(_Rptr), Lptr(_Lptr) {}


};

void update(segTree* root, int l, int r, int index, int key){
    if(l == r) { root->sum += key; return; }
    if(root->Lptr == NULL) root->Lptr = new segTree(0, NULL, NULL);
    if(root->Rptr == NULL) root->Rptr = new segTree(0, NULL, NULL);
    int Mid = (l+r)/2;
    if(index <= Mid) update(root->Lptr, l, Mid, index, key);
    else update(root->Rptr, Mid+1, r, index, key);
    root->sum = root->Lptr->sum + root->Rptr->sum;
    return;
}

int check(segTree* root, int l, int r, int index)
{
    if(index < l || root == NULL ) { return 0; }
    if(r <= index) { return root->sum; }
    int Mid = (l+r)/2;
    return check(root->Lptr, l, Mid, index) + check(root->Rptr, Mid+1, r, index);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<pair<int,int>, int>> nest(n);
    for(int i = 0;i < n;i++){
        cin >> nest[i].first.first >> nest[i].first.second;
        nest[i].second = i;
    }

    sort(nest.begin(), nest.end(), cmp);

    segTree *root = new segTree(0, NULL, NULL), *en = new segTree(0, NULL, NULL);
    int container[200000] = {0}, containsIt[200000] = {0};
    for(int i = 0;i < n;i++){
        containsIt[nest[i].second] = i - check(root, 1, maximum, nest[i].first.second-1);
        update(root, 1, maximum, nest[i].first.second, 1);
    }

    for(int i = n-1;i >= 0;i--){
        container[nest[i].second] = check(en, 1, maximum, nest[i].first.second);
        update(en, 1, maximum, nest[i].first.second, 1);
    }

    for(int i = 0;i < n;i++){
        cout << container[i] << " ";
    }
    cout << endl;
    for(int i = 0;i < n;i++){
        cout << containsIt[i] << " ";
    }


    return 0;
}
