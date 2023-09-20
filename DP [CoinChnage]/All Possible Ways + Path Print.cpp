//all possible ways

#include<bits/stdc++.h>
using namespace std;
int n, sum;
int cnt = 0, ans = 0;
int mem[100][100];
int find_way(int i, int val, int coin[]){
    if(val == 0){
        return 1;
    }
    if(i>=n || val<0) return 0;
    if(mem[i][val]!=-1) return mem[i][val];
    int take = find_way(i+1, val-coin[i], coin);
    int dont_take=find_way(i+1, val, coin);
    mem[i][val] = (take+dont_take);
    return mem[i][val];
}
int main()
{
    cin >> n >> sum;
    int coin[n];
    int cnt = 0;
    for(int i =0 ;i<n; ++i){
        cin >> coin[i];
    }
    for(int i =0 ;i<100; ++i){
        for(int j = 0; j<100; ++j){
            mem[i][j]=-1;
        }
    }
    for(int i = 0; i<n; ++i){
        cnt = max(cnt,find_way(i, sum, coin));
    }
    cout << cnt << endl;
}


//all possible ways with path printing
#include<bits/stdc++.h>
using namespace std;
int n, sum;
int cnt = 0, ans = 0;
int mem[100][100];
vector<vector<int>> paths; // To store all paths

void find_ways(int i, int val, int coin[], vector<int> current_path){
    if(val == 0){
        paths.push_back(current_path);
        return;
    }
    if(i >= n || val < 0) return;
    
    // Take the current coin
    current_path.push_back(coin[i]);
    find_ways(i + 1, val - coin[i], coin, current_path);
    current_path.pop_back(); // Backtrack
    
    // Skip the current coin
    find_ways(i + 1, val, coin, current_path);
}

int main() {
    cin >> n >> sum;
    int coin[n];
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cin >> coin[i];
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            mem[i][j] = -1;
        }
    }
    
    find_ways(0, sum, coin, {});
    
    if(paths.empty()){
        cout << "No possible way to make the sum." << endl;
    }
    else{
        cout << "Number of ways: " << paths.size() << endl;
        cout << "Paths:" << endl;
        for(const vector<int>& path : paths){
            for(int i = 0; i < path.size(); ++i){
                cout << path[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
