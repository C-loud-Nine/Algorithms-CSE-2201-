#include<bits/stdc++.h>
#define N 505

using namespace std;

char arr[N];
vector<char> result;
bool taken[N];
int n;

void print() {
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }
    cout << endl;
}

void call() {
    if (result.size() == n) {
        print();  
        return;
    }
    for (int i = 0; i < n; i++) {
        if (taken[i] == 0) {
            taken[i] = 1;
            result.push_back(arr[i]);
            call();
            taken[i] = 0;
            result.pop_back();
        }
    }
}

int main() {
    cin >> arr;
    n = strlen(arr);

    call();

    cout << endl << endl;
}
