#include <iostream>
#include <string>

using namespace std;

int main()
{
    string in;
    cin >> in;

    int table[26] = {0};

    string ans;

    int len = in.size();
    for(int i = 0;i < len;i++){
        table[in.at(i)-'A']++;
    }

    int odd_num = 0, odd = -1;
    for(int i = 0;i < 26;i++){
        if(table[i] % 2 == 1){
            odd_num++;
            odd = i;
            if(odd_num >= 2){
                cout << "NO SOLUTION" << endl;
                break;
            }
        }
    }

    // output
    for(int i = 0;i < 26;i++){
        if(table[i] % 2 == 0){
            for(int t = 0;t < table[i]/2;t++){
                cout << (char)('A'+i);
            }
        }
    }
    if(odd >= 0){
        for(int i = 0;i < table[odd];i++){
            cout << (char)('A'+odd);
        }
    }
    for(int i = 25;i >= 0;i--){
        if(table[i] % 2 == 0 && table[i] > 0){
            for(int t = 0;t < table[i]/2;t++){
                cout << (char)('A'+i);
            }
        }
    }

    return 0;
}
