#include <iostream>

using namespace std;

int rectangle[501][501] = {0};
int cutting(int length,int width)
{
    if(length == width){
        return 0;
    }

    if(length > width){
        swap(length, width);
    }
    if(rectangle[length][width]){
        return rectangle[length][width];
    }

    int cut_min = 100000000, temp;
    for(int i = 1;i < width;i++){
        temp = 1+cutting(length, i)+cutting(length, width-i);
        if(cut_min > temp){
            cut_min = temp;
        }
    }
    for(int i = 1;i < length;i++){
        temp = 1+cutting(i, width)+cutting(length-i, width);
        if(cut_min > temp){
            cut_min = temp;
        }
    }

    rectangle[length][width] = cut_min;
    return rectangle[length][width];
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << cutting(a,b) << endl;
    return 0;
}
