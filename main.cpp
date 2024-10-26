#include <iostream>
#include <fstream>
#include <chrono>
#include <set>
#include <list>
#include <string>
#include <vector>
using namespace std;
using namespace std::chrono;

int main() {
    ifstream fin("codes.txt");
    
    auto start_read_v = high_resolution_clock::now();
    vector<string> read_vect;
    string random;
    while(getline(fin, random)) {
        read_vect.push_back(random);
    }
    auto end_read_v = high_resolution_clock::now();
    auto duration_read_v = duration_cast<milliseconds>(end_read_v - start_read_v);
    auto read_v = duration_read_v.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/