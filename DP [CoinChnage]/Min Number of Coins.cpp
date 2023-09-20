//min number of coins

#include<bits/stdc++.h>
using namespace std;
int n, sum;
int cnt = 0, ans = 0;
int mem[100][100];
int coin[100];
int const INF = 1e9+7;
int f(int i, int W) {
    if (W < 0) return INF;
    
    if (i == n) {
        if (W == 0) return 0;
        return INF;
    }
    
    
    if (mem[i][W] != -1) {
        return mem[i][W];
    }
    
    int take = 1 + f(i + 1, W - coin[i]);
    int dont_take = f(i + 1, W);
    mem[i][W] = min(take, dont_take);
    return mem[i][W];
}
int main()
{
    cin >> n >> sum;
    int cnt = INF;
    for(int i =0 ;i<n; ++i){
        cin >> coin[i];
    }
    for(int i =0 ;i<100; ++i){
        for(int j = 0; j<100; ++j){
            mem[i][j]=-1;
        }
    }
    for(int i = 0; i<n; ++i){
        cnt = min(cnt,f(i, sum));
    }
    cout << cnt << endl;
}

