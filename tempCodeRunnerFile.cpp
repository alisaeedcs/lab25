    //set: duration of delete
    auto start_delete_s = high_resolution_clock::now();
    auto in = read_set.begin();
    advance(in, read_set.size() / 2);
    read_set.erase(in);
    auto end_delete_s = high_resolution_clock::now();
    auto delete_s = duration_cast<microseconds>(end_delete_s - start_delete_l);