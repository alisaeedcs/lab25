//comsc-210 | ali saeed | lab 25
//ide used; vs code

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
    ifstream fin_vect("codes.txt");
    
    //vector: duration of read
    auto start_read_v = high_resolution_clock::now();
    vector<string> read_vect;
    string random;
    while(getline(fin_vect, random)) {
        read_vect.push_back(random);
    }
    fin_vect.close();
    auto end_read_v = high_resolution_clock::now();
    auto read_v = duration_cast<microseconds>(end_read_v - start_read_v);

    //vector: duration of sort
    auto start_sort_v = high_resolution_clock::now();
    sort(read_vect.begin(), read_vect.end());
    auto end_sort_v = high_resolution_clock::now();
    auto sort_v = duration_cast<microseconds>(end_sort_v - start_sort_v);

    //vector: duration of insert
    auto start_insert_v = high_resolution_clock::now();
    read_vect.insert(read_vect.begin() + read_vect.size() / 2, "TESTCODE");
    auto end_insert_v = high_resolution_clock::now();
    auto insert_v = duration_cast<microseconds>(end_insert_v - start_insert_v);

    //vector: duration of delete
    auto start_delete_v = high_resolution_clock::now();
    read_vect.erase(read_vect.begin() + read_vect.size() / 2);
    auto end_delete_v = high_resolution_clock::now();
    auto delete_v = duration_cast<microseconds>(end_delete_v - start_delete_v);

    //list: duration of read
    ifstream fin_list("codes.txt");
    auto start_read_l = high_resolution_clock::now();
    list<string> read_list;
    string input;
    while(getline(fin_list, input)) {
        read_list.push_back(input);
    }
    fin_list.close(); //getting really quick readings compared to the other thing, should maybe test to see if its actually reading all
    auto end_read_l = high_resolution_clock::now();
    auto read_l = duration_cast<microseconds>(end_read_l - start_read_l);

    //list: duration of sort
    auto start_sort_l = high_resolution_clock::now();
    read_list.sort();
    auto end_sort_l = high_resolution_clock::now();
    auto sort_l = duration_cast<microseconds>(end_sort_l - start_sort_l);

    //list: duration of insert
    auto start_insert_l = high_resolution_clock::now();
    auto it = read_list.begin();
    advance(it, read_list.size() / 2);
    read_list.insert(it, "TESTCODE");
    auto end_insert_l = high_resolution_clock::now();
    auto insert_l = duration_cast<microseconds>(end_insert_l - start_insert_l);

    //list: duration of delete
    auto start_delete_l = high_resolution_clock::now();
    auto in = read_list.begin();
    advance(in, read_list.size() / 2);
    read_list.erase(in);
    auto end_delete_l = high_resolution_clock::now();
    auto delete_l = duration_cast<microseconds>(end_delete_l - start_delete_l);


    //set: duration of read
    ifstream fin_set("codes.txt");
    auto start_read_s = high_resolution_clock::now();
    set<string> read_set;
    string inp;
    while(getline(fin_set, inp)) {
        read_set.insert(inp);
    }
    fin_set.close();
    auto end_read_s = high_resolution_clock::now();
    auto read_s = duration_cast<microseconds>(end_read_s - start_read_s);

    //set: duration of insert
    auto start_insert_s = high_resolution_clock::now();
    read_set.insert("TESTCODE");
    auto end_insert_s = high_resolution_clock::now();
    auto insert_s = duration_cast<microseconds>(end_insert_s - start_insert_s);

    //set: duration of delete
    auto start_delete_s = high_resolution_clock::now();
    read_set.erase("TESTCODE");
    auto end_delete_s = high_resolution_clock::now();
    auto delete_s = duration_cast<microseconds>(end_delete_s - start_delete_s);


    //starting to debate if we are supposed to use microseconds instead of milliseconds so we get more accurate readings
    //figured it out since the set is also 1 for the inertion time on the sampe output or close to that it must be in microseconds
    cout << left << setw(13) << "Operation" << setw(13) << "Vector" << setw(13) << "List" << setw(13) << "Set" << endl;
    cout << left << setw(13) << "Read" << setw(13) << read_v.count() << setw(13) << read_l.count() << setw(13) << read_s.count() << endl;
    cout << left << setw(13) << "Sort" << setw(13) << sort_v.count() << setw(13) << sort_l.count() << setw(13) << "-1" << endl;
    cout << left << setw(13) << "Insert" << setw(13) << insert_v.count() << setw(13) << insert_l.count() << setw(13) << insert_s.count() << endl;
    cout << left << setw(13) << "Delete" << setw(13) << delete_v.count() << setw(13) << delete_l.count() << setw(13) << delete_s.count() << endl;
    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/