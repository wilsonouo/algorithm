#include <iostream>
#include <string>

using namespace std;

int main()
{

    string in;
    cin >> in;

    int table[26] = {0};
    int len = in.size();
    int ans = 1, fac = 1;
    for(int i = 0;i < len;i++){
        table[in.at(i)-'a']++;
        ans *= fac++;
    }

    // reorder the position
    string creating;
    char a;
    int temp = 0;
    while((char)'a'+temp <= 'z'){
        while(table[temp] != 0){
            creating += (char)'a'+temp;
            ans /= table[temp];
            table[temp]--;
        }
        temp++;
    }

    cout << ans << endl;

    cout << creating << endl;

    int changept = len-1;
    while(changept > 0){
        if(creating.at(changept) > creating.at(changept-1)){
            //cout << creating.at(changept) << " " << creating.at(changept-1) << endl;
            // change point
            char change;
            for(int i = len-1;i > changept-1;i--){
                if(creating.at(i) > creating.at(changept-1)){
                    change = i;
                    break;
                }
            }
            for(int i = change-1;i > changept-1;i--){
                if(creating.at(i) > creating.at(changept-1) && creating.at(i) < creating.at(change)){
                    change = i;
                }
            }
            swap(creating[changept-1], creating[change]);
            // reverse
            int rvs = (len-changept) / 2;
            for(int i = 0;i < rvs;i++){
                swap(creating[changept+i], creating[len-1-i]);
            }
            cout << creating << endl;
            changept = len-1;
        }
        else{
            changept--;
        }
    }

    return 0;
}
