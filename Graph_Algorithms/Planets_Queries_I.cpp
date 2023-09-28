#include <iostream>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    int nextPlanet[200001][31];
    for(int i = 1;i <= n;i++){
        cin >> nextPlanet[i][0];
    }

    for(int i = 1;i < 30;i++){
        for(int t = 1;t <= n;t++){
            nextPlanet[t][i] = nextPlanet[nextPlanet[t][i-1]][i-1];
        }
    }

    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        for(int i = 0;i < 30;i++){
            if(b & (1 << i)){
                a = nextPlanet[a][i];
            }
        }
        cout << a << endl;
    }
    return 0;
}
