#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

void swap(vector<unsigned> &A, unsigned i, unsigned j) {
    for (unsigned k = j; k > i; k--) {
        unsigned tmp = A[k];
        A[k] = A[k - 1];
        A[k - 1] = tmp;
    }
}
void step(vector<unsigned> &A, unsigned p, unsigned &K) {
    unsigned lower = p + 1, upper = p + 1 + K;
    unsigned N = A.size();
    upper = min(upper, N);
    unsigned pm = p, max = A[p];
    for (unsigned i = lower; i < upper; i++) {
        if (max < A[i]) {
            pm = i;
            max = A[i];
        }
    }
    swap(A, p, pm);
    K -= (pm - p);
}
int main() {
    unsigned T;
    cin >> T;
    vector<vector<unsigned>> A;
    vector<unsigned> K(T, 0), N(T, 0);
    for (unsigned i = 0; i < T; i++) {
        scanf("%d", &K[i]);
        scanf("%d", &N[i]);
        vector<unsigned> Ai;

        for (unsigned j = 0; j < N[i]; j++) {
            unsigned ai;
            scanf("%d", &ai);
            Ai.push_back(ai);
        }
        A.push_back(Ai);
    }
    for (unsigned i = 0; i < T; i++) {
        unsigned p = 0;
        while (K[i] > 0 && p < N[i] - 1) {
            step(A[i], p, K[i]);
            p++;
        }
        if (K[i] % 2 == 1) swap(A[i], p - 1, p);

        for (unsigned j = 0; j < N[i]; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}
