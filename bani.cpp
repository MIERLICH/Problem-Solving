#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

class Task {
 public:
    int setIns;
    int N;

    void solve() {
        ifstream fin("bani.in");
        fin >> setIns >> N;

        int result = 0;
        if (setIns == 1) {
            result = (fast_pow(2, N-1, kMod) * 1LL * 5) % kMod;
        } else {
            // 10 50 100 200 500
            // 10  =>  50, 100        - 0
            // 50  =>  10, 200        - 1
            // 100 =>  10, 100        - 2
            // 200 =>  50, 500, 100   - 3
            // 500 => 200, 10         - 4
            // int vect[N][5];
            int **vect = (int**)malloc(sizeof(int *) * N);
            for (int i = 0; i < N; i++) {
                vect[i] = (int *)malloc(sizeof(int) * 5);
            }
            vect[0][0] = vect[0][1] = vect[0][2] = vect[0][3] = vect[0][4] = 1;
            int i;
            int k;
            for (i = 1; i < N; i++) {
                k = i - 1;
                vect[i][0] = (vect[k][1] + vect[k][2] * 1LL) % kMod;
                vect[i][1] = (vect[k][0] + vect[k][3] * 1LL) % kMod;
                vect[i][2] = (vect[k][0] + vect[k][2] * 1LL) % kMod;
                vect[i][3] = (vect[i][0] + vect[k][4]* 1LL) % kMod;
                vect[i][4] = vect[i][1];
            }
            result = (1LL * vect[i-1][0] + vect[i-1][1] + vect[i-1][2]
                                + vect[i-1][3] + vect[i-1][4]) % kMod;
        }
        ofstream fout("bani.out");
        fout << fixed << result;
        fout.close();
    }
    int fast_pow(int base, int exponent, int mod) {
        if (!exponent) {
            return 1;
        }
        int aux = 1;
        while (exponent != 1) {
            if (exponent % 2 == 0) {   // par
                base = (1LL * base * base) % mod;
                exponent /= 2;
            } else {                   // impar
                aux = (1LL * aux * base) % mod;
                exponent--;
            }
        }
        return (1LL * aux * base) % mod;
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
