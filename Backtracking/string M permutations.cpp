#include<bits/stdc++.h>
#define N 505

using namespace std;

char arr[N];
vector<char> result;
bool taken[N];
int n, m;

void print() {
    for (int i = 0; i < m; i++) {
        cout << result[i];
    }
    cout << endl;
}

void call() {
    if (result.size() == m) {
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
    cin >> arr >> m;
    n = strlen(arr);

    if (m <= n) {
        call();
    }
    else {
        cout << "Cannot generate permutations of length greater than the input string size." << endl;
    }

    cout << endl << endl;
}
