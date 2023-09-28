#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(200001);
int firstMax[200001] = {0};
int secondMax[200001] = {0};
int from[200001] = {0};
void dfsRoute(int node, int last)
{
    firstMax[node] = 0;
    secondMax[node] = 0;
    int len = tree[node].size();
    for(int i = 0;i < len;i++){
        if(tree[node][i] == last) continue;
        dfsRoute(tree[node][i], node);
        if(firstMax[node] < firstMax[tree[node][i]] + 1){
            secondMax[node] = firstMax[node];
            firstMax[node] = firstMax[tree[node][i]] + 1;
            from[node] = tree[node][i];
        }
        else if(firstMax[tree[node][i]] + 1 > secondMax[node]){
            secondMax[node] = firstMax[tree[node][i]] + 1;
        }
    }
}

void dfsAns(int node, int last)
{
    int len = tree[node].size();
    for(int i = 0;i < len;i++){
        if(tree[node][i] == last) continue;
        if(from[node] == tree[node][i]){
            if(firstMax[tree[node][i]] < secondMax[node] + 1){
                secondMax[tree[node][i]] = firstMax[tree[node][i]];
                firstMax[tree[node][i]] = secondMax[node] + 1;
                from[tree[node][i]] = node;
            }
            else{
                secondMax[tree[node][i]] = max(secondMax[tree[node][i]], secondMax[node] + 1);
            }
        }
        else{
            secondMax[tree[node][i]] = firstMax[tree[node][i]];
            firstMax[tree[node][i]] = firstMax[node] + 1;
            from[tree[node][i]] = node;
        }
        dfsAns(tree[node][i], node);
    }
}

int main()
{
    int n;
    cin >> n;

    int a, b;
    for(int i = 0;i < n-1;i++){
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfsRoute(1, -1);
    dfsAns(1,-1);

    for(int i = 1;i <= n;i++){
        cout << firstMax[i] << " ";
    }
    cout << endl;

    return 0;
}
