#include <iostream>
#include <limits.h>


using namespace std;

int value[200000];
int rmq[600000];
int buildRMQ(int node, int start, int finish)
{
    if(start == finish){
        rmq[node] = value[start];
        return rmq[node];
    }

    rmq[node] = min(buildRMQ(node*2+1, start, start+(finish-start)/2), buildRMQ(node*2+2, start+(finish-start)/2+1, finish));
    return rmq[node];
}

int query(int node, int segStart, int segFinish, int start, int finish)
{
    if(segStart >= start && segFinish <= finish){
        return rmq[node];
    }

    if(segStart > finish || segFinish < start){
        return INT_MAX;
    }

    return min(query(2*node+1, segStart, segStart+(segFinish-segStart)/2, start, finish), query(2*node+2, segStart+(segFinish-segStart)/2+1, segFinish, start, finish));

}

int main()
{
    int n, q;
    cin >> n >> q;

    for(int i = 0;i < n;i++){
        cin >> value[i];
    }

    buildRMQ(0, 0, n-1);

    int a, b;
    for(int i = 0;i < q;i++){
        cin >> a >> b;
        cout << query(0, 0, n-1, a-1, b-1) << endl;
    }

    return 0;
}
