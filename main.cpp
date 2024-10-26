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
    auto duration_sort_v = duration_cast<milliseconds>(end_sort_v - start_sort_v);
    auto sort_v = duration_sort_v.count();

    //vector: duration of insert
    auto start_insert_v = high_resolution_clock::now();
    read_vect.insert(read_vect.begin() + read_vect.size() / 2, "TESTCODE");
    auto end_insert_v = high_resolution_clock::now();
    auto duration_insert_v = duration_cast<milliseconds>(end_insert_v - start_insert_v);
    auto insert_v = duration_insert_v.count();

    //vector: duration of delete
    auto start_delete_v = high_resolution_clock::now();
    read_vect.erase(read_vect.begin() + read_vect.size() / 2);
    auto end_delete_v = high_resolution_clock::now();
    auto duration_delete_v = duration_cast<milliseconds>(end_delete_v - start_delete_v);
    auto delete_v = duration_delete_v.count();

    cout << left << setw(13) << "Operation" << setw(13) << "Vector" << setw(13) << "List" << setw(13) << "Set" << endl;
    cout << left << setw(13) << "Read" << setw(13) << read_v << endl;
    cout << left << setw(13) << "Sort" << setw(13) << sort_v << endl;
    cout << left << setw(13) << "Insert" << setw(13) << insert_v << endl;
    cout << left << setw(13) << "Delete" << setw(13) << delete_v << endl;
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/