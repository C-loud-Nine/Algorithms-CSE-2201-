#include<bits/stdc++.h>
using namespace std;

int n, sum;
const int INF = 1e9 + 7;
vector<int> coinValue;
vector<int> coinCount;
vector<vector<int>> mem;

int f(int i, int W) {
    if (W == 0) return 0; // No more value needed, return 0 coins.
    if (W < 0 || i == n) return -INF; // Invalid state, return a negative value.
    
    if (mem[i][W] != -1) {
        return mem[i][W];
    }
    
    int take = -INF;
    if (coinCount[i] > 0 && W >= coinValue[i]) {
        coinCount[i]--;
        take = 1 + f(i, W - coinValue[i]);
        coinCount[i]++;
    }
    
    int dont_take = f(i + 1, W);
    mem[i][W] = max(take, dont_take);
    return mem[i][W];
}

int main() {
    cin >> n >> sum;
    
    coinValue.resize(n);
    coinCount.resize(n);
    mem.resize(n, vector<int>(sum + 1, -1));
    
    for (int i = 0; i < n; ++i) {
        cin >> coinValue[i] >> coinCount[i];
    }
    
    int cnt = f(0, sum);
    
    if (cnt <= 0) {
        cout << "No possible way to make the sum." << endl;
    } else {
        cout << cnt << endl;
    }
    
    return 0;
}









//path printing
#include<bits/stdc++.h>
using namespace std;

int n, sum;
const int INF = 1e9 + 7;
vector<int> coinValue;
vector<int> coinCount;
vector<vector<int>> mem;
vector<vector<int>> selected; // To keep track of selected coins.

int f(int i, int W) {
    if (W == 0) return 0; // No more value needed, return 0 coins.
    if (W < 0 || i == n) return -INF; // Invalid state, return a negative value.
    
    if (mem[i][W] != -1) {
        return mem[i][W];
    }
    
    int take = -INF;
    if (coinCount[i] > 0 && W >= coinValue[i]) {
        coinCount[i]--;
        take = 1 + f(i, W - coinValue[i]);
        coinCount[i]++;
    }
    
    int dont_take = f(i + 1, W);
    
    if (take > dont_take) {
        selected[i][W] = 1; // Mark the coin as selected.
        mem[i][W] = take;
    } else {
        selected[i][W] = 0; // Mark the coin as not selected.
        mem[i][W] = dont_take;
    }
    
    return mem[i][W];
}

void printSelectedCoins() {
    int i = 0;
    int j = sum;
    while (i < n && j > 0) {
        if (selected[i][j] == 1) {
            cout << coinValue[i] << " ";
            j -= coinValue[i];
            coinCount[i]--; // Deduct the selected coin.
        } else {
            i++;
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> sum;
    
    coinValue.resize(n);
    coinCount.resize(n);
    mem.resize(n, vector<int>(sum + 1, -1));
    selected.resize(n, vector<int>(sum + 1, 0));
    
    for (int i = 0; i < n; ++i) {
        cin >> coinValue[i] >> coinCount[i];
    }
    
    int cnt = f(0, sum);
    
    if (cnt <= 0) {
        cout << "No possible way to make the sum." << endl;
    } else {
        cout << "Maximum number of coins: " << cnt << endl;
        cout << "Coins used: ";
        printSelectedCoins();
    }
    
    return 0;
}


// 5 11
// 1 2
// 2 3
// 5 2
// 10 1
// 20 2