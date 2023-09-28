#include <iostream>
#include <string>

using namespace std;

int main()
{
    string repetitions;
    cin >> repetitions;
    repetitions += "s";

    int len = repetitions.size();
    char lastchar;
    int Max = 0, temp = 0;

    for(int i = 0;i < len-1;i++){
        lastchar = repetitions.at(i);
        temp++;
        if(lastchar != repetitions.at(i+1)){
            if(temp > Max){
                Max = temp;
            }
            temp = 0;
        }
    }

    cout << Max << endl;

    return 0;
}
