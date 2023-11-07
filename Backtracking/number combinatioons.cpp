#include<bits/stdc++.h>
using namespace std;

const int N = 505;
bool taken[N];
int n, r;

void printCombination(int position[], int len) {
    for (int i = 0; i < len; i++) {
        cout << position[i] << " ";
    }
    cout << endl;
}

void generateCombinations(int position[], int len, int idx) {
    if (len == r) {
        printCombination(position, r);
        return;
    }

    if (idx == n) {
        return;
    }

    position[len] = idx;
    generateCombinations(position, len + 1, idx + 1);
    generateCombinations(position, len, idx + 1);
}

int main() {
    cin >> n >> r;

    int position[N];
    generateCombinations(position, 0, 0);

    return 0;
}
