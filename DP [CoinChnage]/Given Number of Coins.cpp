//given number of coin

#include<bits/stdc++.h>
using namespace std;
int n, sum;
int cnt = 0, ans = 0;
int mem[100][100];
int coin[100];
int const inf=1e9;
int find_way(int i, int val){
    if(val == 0){
        return 0;
    }
    int ans = 0;
    if(i>=n || val<0) return inf;
    if(mem[i][val]!=-1) return mem[i][val];
    int take = 1+find_way(i+1, val-coin[i]);
    int dont_take=find_way(i+1, val);
    if(take<inf) mem[i][val] = take;
    else mem[i][val] = dont_take;
    return mem[i][val];
}
int main()
{
    int num;
    cin >> n >> sum >> num;
    int cnt = 0;
    for(int i =0 ;i<n; ++i){
        cin >> coin[i];
    }
    for(int i =0 ;i<100; ++i){
        for(int j = 0; j<100; ++j){
            mem[i][j]=-1;
        }
    }
    bool ok = false;
    for(int i = 0; i<n; ++i){
        cnt = find_way(i, sum);
        if(cnt==num) ok = true;
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}


//path printing 
#include<bits/stdc++.h>
using namespace std;

int n, sum, num;
int mem[100][100];
int coin[100];
vector<int> selectedCoins; // To store the selected coins.

bool find_way(int i, int val, int usedCoins) {
    if (val == 0 && usedCoins == num) {
        return true;
    }
    
    if (i >= n || val < 0 || usedCoins > num) return false;
    
    if (mem[i][val] != -1) {
        return mem[i][val];
    }
    
    // Take the current coin
    selectedCoins.push_back(coin[i]);
    bool take = find_way(i + 1, val - coin[i], usedCoins + 1);
    if (take) return true;
    selectedCoins.pop_back(); // Backtrack
    
    // Skip the current coin
    bool dont_take = find_way(i + 1, val, usedCoins);
    
    mem[i][val] = take || dont_take;
    return mem[i][val];
}

int main() {
    cin >> n >> sum >> num;
    
    int cnt = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> coin[i];
    }
    
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            mem[i][j] = -1;
        }
    }
    
    bool result = find_way(0, sum, 0);
    
    if (result) {
        cout << "YES" << endl;
        cout << "Coins used: ";
        
        for (int i = 0; i < selectedCoins.size(); i++) {
            cout << selectedCoins[i] << " ";
        }
        
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}


//    path printing doesn't work for 
//    7 23 2
//    2 4 5 6 9 15 17     
