#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int parent[200001][20] = {0};
    int level[200001] = {0};
    for(int i = 2;i <= n;i++){
        cin >> parent[i][0];
        level[i] = level[parent[i][0]]+1;
    }

    fill(parent[1], parent[1]+17, 1);
    for(int i = 1;i < 20;i++){
        for(int t = 2;t <= n;t++){
            parent[t][i] = parent[parent[t][i-1]][i-1];
        }
    }


    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        if(level[a] > level[b]){
            swap(a,b);
        }

        int gap = level[b] - level[a];
        while(gap){
            b = parent[b][__lg(gap&(-gap))];
            gap -= gap&(-gap);
        }

        while(a != b){
            for(int next = 19;next >= 0;next--){
                if(parent[a][next] != parent[b][next]){
                    a = parent[a][next];
                    b = parent[b][next];
                    break;
                }
                else if(next == 0){
                    a = parent[a][next];
                    b = parent[b][next];
                }
            }
        }
        cout << a << endl;
    }

    return 0;
}
