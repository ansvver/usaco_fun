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
        int money_to_friend = init_money / friend_counts;
        // int kept_money = init_money % friend_counts;
        np_map[name] -= init_money;
        for (int j = 0; j < friend_counts; ++j) {
            string friend_name;
            fin >> friend_name;
            np_map[friend_name] += money_to_friend;
        }

    }
    for (vector<string>::iterator it = name_vec.begin(); it != name_vec.end(); ++it) {
        fout << *it << " " << np_map[*it] << endl;
    }
    return 0;

}


/*
SECTION: 1.1
NUMBER: 2
ID: voxsim2
PROG: gift1
LANG: C++
COMPLEXITY = O(NP + NP*number_people) -> O(NP^2)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>

using namespace std;

int main() {
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");

	list<string> nps;
	map<string, int> frs;
	int np;
	string fr;
	string gifter;
	int initial_amount;
	int number_people;

	fin >> np;

	for(int i=0; i<np; i++) { //O(NP)
		fin >> fr;
		frs[fr] = 0;
		nps.push_back(fr);
	}

	for(int i=0; i<np; i++) { //O(NP * number_people)
		fin >> fr;
		fin >> initial_amount >> number_people;
		int gift = 0;
		if(initial_amount > 0) {
			gift = initial_amount/number_people;
		}
		frs[fr] -= initial_amount;
		for(int j=0; j<number_people; j++) {
			fin >> gifter;
			frs[gifter] += gift;
		}
		if(number_people != 0) {
			frs[fr] += initial_amount % number_people;
		}
	}

	list<string>::iterator it;
	for(it = nps.begin(); it != nps.end(); it++)
		fout << *it << " " << frs[*it] << endl;
    return 0;
}

