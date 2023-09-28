#include <iostream>

using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    int sequence[200000];
    int leftptr = 0;
    int nowsum = 0, ans = 0;
    for(int i = 0;i < n;i++){
        cin >> sequence[i];
        nowsum += sequence[i];
        while(nowsum > x){
            nowsum -= sequence[leftptr++];
        }
        if(nowsum == x){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
