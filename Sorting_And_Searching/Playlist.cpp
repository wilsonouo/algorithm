#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;

    set<int> cd;
    int ans = 1;
    int playlist[200000];
    int leftptr;
    for(int i = 0;i < n;i++){
        cin >> playlist[i];
        if(!cd.count(playlist[i])){
            cd.insert(playlist[i]);
        }
        else{
            if(ans < cd.size()){
                ans = cd.size();
            }
            while(playlist[leftptr] != playlist[i]){
                cd.erase(playlist[leftptr]);
                leftptr++;
            }
            leftptr++;
        }
    }

    if(ans < cd.size()){
        ans = cd.size();
    }

    cout << ans << endl;

    return 0;
}
