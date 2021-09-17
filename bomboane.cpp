#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

struct Object {
    int minb;
    int maxb;
    int pas;

    Object(int _minb, int _maxb, int _pas)
                : minb(_minb), maxb(_maxb), pas(_pas) {}
};

class Task {
 public:
    int N, M;
    vector<Object> interval_b;

    void solve() {
        read_input();
        int result = 0;

        int **matr = (int **)calloc(sizeof(int*), N);
        for (int i = 0; i < N; i++) {
            matr[i] = (int *)calloc(sizeof(int), M+1);
        }
        for (int i = interval_b[0].minb; i <= interval_b[0].maxb; i++) {
            matr[0][i] = 1;
        }

        int i;
        for (i = 1; i < N; i++) {
            for (int j = interval_b[i].minb; j <= interval_b[i].maxb; j++) {
                int inceput1 = 0;
                int inceput2 = j;
                while (inceput2 <= M) {
                    matr[i][inceput2] = ((1LL * matr[i][inceput2])
                                            + matr[i-1][inceput1]) % kMod;
                    inceput2++;
                    inceput1++;
                }
            }
        }
        result = matr[N-1][M];
        ofstream fout("bomboane.out");
        fout << fixed << result;
        fout.close();
    }
    void read_input() {
        ifstream fin("bomboane.in");
        fin >> N >> M;
        for (int i = 0, min, max; i < N; i++) {
            fin >> min >> max;
            interval_b.push_back(Object(min, max, i));
        }
        fin.close();
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
