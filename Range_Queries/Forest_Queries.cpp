#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    string forest;
    int tree[1001][1001] = {0};
    for(int i = 0;i < n;i++){
        cin >> forest;
        for(int t = 0;t < forest.size();t++){
            tree[i+1][t+1] = tree[i+1][t];
            if(forest[t] == '*'){
                tree[i+1][t+1]++;
            }
        }
    }

    for(int i = 0;i < q;i++){
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        int ans = 0;
        for(int i = y1;i <= y2;i++){
            ans += tree[i][x2] - tree[i][x1-1];
        }
        cout << ans << endl;
    }

    return 0;
}
