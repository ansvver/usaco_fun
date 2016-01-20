/*
ID: shsfool1
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int np;
    map<string, int> np_map;
    vector<string> name_vec;
    fin >> np;

    for (int i = 0; i < np; ++i) {
        string name = "";
        fin >> name;
        np_map.insert(pair<string, int>(name, 0));
        name_vec.push_back(name);
    }
    for (int i = 0; i < np; ++i) {
        string name = "";
        fin >> name;
        int init_money = 0;
        int friend_counts = 0;
        fin >> init_money >> friend_counts;
        int money_to_friend = 0;
        if (friend_counts != 0 && init_money > 0) {
            money_to_friend = init_money / friend_counts;
        }
        np_map[name] -= init_money;
        for (int j = 0; j < friend_counts; ++j) {
            string friend_name;
            fin >> friend_name;
            np_map[friend_name] += money_to_friend;
        }
        if (friend_counts != 0) {
            np_map[name] += init_money % friend_counts;
        }
    }
    for (vector<string>::iterator it = name_vec.begin(); it != name_vec.end(); ++it) {
        fout << *it << " " << np_map[*it] << endl;
    }
    return 0;

}
