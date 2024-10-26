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
    
    //vector: duration of read
    auto start_read_v = high_resolution_clock::now();
    vector<string> read_vect;
    string random;
    while(getline(fin, random)) {
        read_vect.push_back(random);
    }
    auto end_read_v = high_resolution_clock::now();
    auto duration_read_v = duration_cast<milliseconds>(end_read_v - start_read_v);
    auto read_v = duration_read_v.count();

    //vector: duration of sort
    auto start_sort_v = high_resolution_clock::now();
    sort(read_vect.begin(), read_vect.end());
    auto end_sort_v = high_resolution_clock::now();
    auto duration_sort_v = duration_cast<milliseconds>(end_read_v - start_read_v);
    auto sort_v = duration_sort_v.count();

    //vector: duration of insert
    auto start_insert_v = high_resolution_clock::now();
    read_vect.insert(read_vect.begin() + read_vect.size() / 2, "TESTCODE");
    auto end_insert_v = high_resolution_clock::now();
    auto duration_insert_v = duration_cast<milliseconds>(end_read_v - start_read_v);
    auto sort_v = duration_insert_v.count();

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/