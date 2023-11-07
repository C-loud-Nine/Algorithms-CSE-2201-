#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int position[N];
bool taken[N];
int n;

void print() {
    for (int i = 0; i < n; i++) {
        cout << position[i] << " ";
    }
    cout << endl;
}

void generate(int idx) {
    if (idx == n) {
        print(); // Print the position array when idx reaches n.
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            taken[i] = true;
            position[idx] = i;
            generate(idx + 1);
            taken[i] = false;
        }
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        taken[i] = false;
    }

    generate(0);

    return 0;
}
