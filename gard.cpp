#include <bits/stdc++.h>
using namespace std;

const int kMod = 1e9 + 7;

struct Object {
    int xStart;
    int xEnd;

    Object(int _xStart, int _xEnd) : xStart(_xStart), xEnd(_xEnd) {}
};

class Task {
 public:
    void solve() {
        read_input();
        std::sort(garduri.begin(), garduri.end(), compareByxStart);

        int renundant = 0;
        Object referinta = garduri[0];

        for (int i = 1; i < n; i++) {
        	if(referinta.xStart <= garduri[i].xStart &&
        					 garduri[i].xEnd <= referinta.xEnd) {
        		renundant = (1LL * renundant + 1)  % kMod;
        	} else {
        		referinta = garduri[i];
        	}
        }
        ofstream fout("gard.out");
        fout << fixed << renundant;
        fout.close();
    }

 private:
    int n;
    vector<Object> garduri;

    void read_input() {
        ifstream fin("gard.in");
        fin >> n;
        for (int i = 0, start, end; i < n; i++) {
            fin >> start >> end;
            garduri.push_back(Object(start, end));
        }
        fin.close();
    }
    static bool compareByxStart(const Object &a, const Object &b) {
    	if(a.xStart == b.xStart) {
    		return a.xEnd > b.xEnd;
    	}
    	return a.xStart < b.xStart;
    }
};

int main() {
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
