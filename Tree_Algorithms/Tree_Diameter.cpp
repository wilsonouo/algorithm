#include <iostream>
#include <vector>

using namespace std;

int visited[200001] = {0};
int visitedOnce[200001] = {0};
vector<vector<int>> tree(200001);
int maxlevel = 0, Node = 0;
void findFirst(int node, int level)
{
    visitedOnce[node] = 1;
    visited[node] = 1;
    vector<int>::iterator iter;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(!visited[*iter]){
            findFirst(*iter, level+1);
        }
    }
    visited[node] = 0;
    if(level > maxlevel){
        maxlevel = level;
        Node = node;
    }
}

int diameter(int node, int level)
{
    visited[node] = 1;
    vector<int>::iterator iter;
    int ans = level;
    for(iter = tree[node].begin();iter != tree[node].end();iter++){
        if(visited[*iter] != 1){
            ans = max(diameter(*iter, level+1), ans);
        }
    }
    visited[node] = 0;


    return ans;
}

int main()
{
    int n;
    cin >> n;

    for(int i = 0;i < n-1;i++){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int output = 0;
    for(int i = 1;i <= n;i++){
        if(!visitedOnce[i]){
            Node = i;
            findFirst(i, 0);
            output = max(diameter(Node,0), output);
        }
    }

    cout << output << endl;

    return 0;
}
