#include <bits/stdc++.h>
#define N 505

using namespace std;

char arr[N];
vector<char> result;
bool taken[N];
int n, m;

void print() {
    for (int i = 0; i < m; i++) cout << result[i];
    cout << endl;
}

void call(int start) {
    if (result.size() == m) print();
    else
        for (int i = start; i < n; i++) {
            if (i > start && arr[i] == arr[i - 1]) continue;
            taken[i] = 1;
            result.push_back(arr[i]);
            call(i + 1);
            taken[i] = 0;
            result.pop_back();
        }
}

int main() {
    while (cin >> arr >> m) {
        n = strlen(arr);
        sort(arr, arr + n);
        call(0);
        result.clear();
    }
    return 0;
}
