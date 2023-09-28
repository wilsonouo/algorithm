#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int books[200000];
    long long int time = 0;
    for(int i = 0;i < n;i++){
        cin >> books[i];
    }

    sort(books, books+n);
    int l = 0, r = n-1;
    long long int ltime = books[0], rtime = books[n-1];
    while(l+1 < r){
        if(ltime < rtime){
            l++;
            ltime += books[l];
        }
        else{
            r--;
            rtime += books[r];
        }
    }

    long long int ans = 0;
    if(l == n-2 && ltime < rtime){
        ans += 2*rtime;
    }
    else{
        ans += ltime + rtime;
    }

    cout << ans << endl;


    return 0;
}
