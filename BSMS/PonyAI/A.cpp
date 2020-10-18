#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > edges;
    for (int i = 0; i < n; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int cur;
            cin >> cur;
            row.push_back(cur);
        }
        edges.push_back(row);
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                edges[j][i] = edges[i][j] = min(edges[i][k] + edges[k][j], edges[i][j]);
    }
    int a, b, k;
    cin >> a >> b >> k;
    int lower = -1, upper = k;
    while (upper - lower > 1) {
        int mid = (upper + lower) / 2, ok = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int d = edges[i][j];
                d = min(d, edges[i][a] + edges[b][j] + mid);
                d = min(d, edges[i][b] + edges[a][j] + mid);
                if (d + mid >= k) {
                    ok = 0;
                    break;
                }
            }
            if (!ok) break;
        }
        if (!ok)
            upper = mid;
        else
            lower = mid;
    }
    cout << lower << endl;
    return 0;
}