#include <bits/stdc++.h>
using namespace std;

struct Object {
    unsigned long long kg;
    unsigned long long repetari;

    Object(unsigned long long _kg, unsigned long long _repetari)
                            : kg(_kg), repetari(_repetari) {}
};
struct compare2 {
    bool operator()(Object a, Object b) {
        return a.repetari > b.repetari;
    }
};

class Task {
 public:
    int N, M;
    vector<Object> gantere;
    priority_queue <Object, vector<Object>, compare2> coada;
    void solve() {
        read_input();
        std::sort(gantere.begin(), gantere.end(), compare1);

        unsigned long long rezultat = 0;
        unsigned long long tmp = 0;
        unsigned long long curent_repetari = 0;
        int gantere_curente = 0;
        for (int i = 0; i < N; i++) {
            if (gantere_curente < M) {
                coada.push(gantere[i]);
                gantere_curente++;
                curent_repetari += gantere[i].repetari;
                tmp = gantere[i].kg * (curent_repetari);
                if (tmp > rezultat) {
                    rezultat = tmp;
                }
            } else {
                Object o = coada.top();
                unsigned long long low_repetari = o.repetari;
                if (low_repetari < gantere[i].repetari) {
                    coada.pop();
                    coada.push(gantere[i]);
                    curent_repetari -= low_repetari;
                    curent_repetari += gantere[i].repetari;
                    tmp = gantere[i].kg * (curent_repetari);
                    if (tmp > rezultat) {
                        rezultat = tmp;
                    }
                }
            }
        }
        ofstream fout("sala.out");
        fout << fixed << rezultat;
        fout.close();
    }
    static bool compare1(Object a, Object b) {
        if (a.kg > b.kg) {
            return true;
        }
        return false;
    }
    void read_input() {
        ifstream fin("sala.in");
        fin >> N >> M;
        unsigned long long greutate;
        unsigned long long repetari;
        for (int i = 0; i < N; i++) {
            fin >> greutate >> repetari;
            gantere.push_back(Object(greutate, repetari));
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
