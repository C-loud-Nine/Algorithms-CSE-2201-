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

void call(int length) {
    if (length == n) {
        print();
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!result.empty() && result.back() > arr[i]) {
            continue;
        }
        if (!taken[i]) {
            taken[i] = true;
            result.push_back(arr[i]);
            call(length + 1);
            taken[i] = false;
            result.pop_back();
            while (i + 1 < n && arr[i] == arr[i + 1]) {
                i++;
            }
        }
    }
}

int main() {
    cin >> arr;
    n = strlen(arr);
    sort(arr, arr + n);

    for (int i = 1; i <= n; i++) {
        call(0); // Generate permutations of different lengths.
    }

    cout << endl << endl;
}
