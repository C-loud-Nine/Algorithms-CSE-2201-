#include <iostream>
using namespace std;

int w[2006];
int val[2006];
int table[2004][2004];

int knap(int n, int cap) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= cap; j++) {
            if (i == 0 || j == 0)
                table[i][j] = 0;
            else if (w[i - 1] <= j)
                table[i][j] = max(val[i - 1] + table[i - 1][j - w[i - 1]], table[i - 1][j]);
            else
                table[i][j] = table[i - 1][j];
        }
    }
    return table[n][cap];
}

void solve(void) {
    int n, s;
    cin >> s >> n;

    for (int i = 0; i < n; i++) {
        cin >> w[i] >> val[i];
    }

    cout << knap(n, s) << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
