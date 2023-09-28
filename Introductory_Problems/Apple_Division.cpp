#include <iostream>
#include <limits.h>
#include <math.h>

using namespace std;

int weight[20];
long long int ans = LONG_MAX, groupa = 0, groupb = 0;

void division(int level, int stop, int weight[])
{
    if(level == stop){
        if(abs(groupa+weight[level]-groupb) < ans){
            ans = abs(groupa+weight[level]-groupb);
        }
        else if(abs(groupb+weight[level]-groupa) < ans){
            ans = abs(groupb+weight[level]-groupa);
        }
        return;
    }
    else{
        groupa += weight[level];
        division(level+1, stop, weight);
        groupa -= weight[level];
        groupb += weight[level];
        division(level+1, stop, weight);
        groupb -= weight[level];
        return;
    }

}

int main()
{

    int n;
    cin >> n;

    for(int i = 0;i < n;i++){
        cin >> weight[i];
    }



    division(0, n-1,weight);
    cout << ans << endl;

    return 0;
}
