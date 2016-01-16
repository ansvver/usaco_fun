/*
ID: shsfool1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int calc(const string &s) {
    int ret = 1;
    for (int i = 0; i < (int)s.size(); ++i) {
        ret *= s[i] - 'A' + 1;
    }
    return ret % 47;
}

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    int comet_mod = 0;
    int group_mod = 0;
    string a, b;
    fin >> a >> b;
    if (calc(a) == calc(b)) fout << "GO" << endl;
    else fout << "STAY" << endl;
    return 0;
}
