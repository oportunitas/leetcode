compile() {
    local cur_dir="$(pwd)"
    local id="$1"
    echo "$id"
    cd "$cur_dir/cpp/$id"*

    #g++-16 -S -I .. ./solution.cpp -O2
    g++-16 -O2 -I .. solution.cpp -o solution
}

analyze() {
    local cur_dir="$(pwd)"
    local id="$1"
    echo "$id"
    cd "$cur_dir/cpp/$id"*

    #g++-16 -S -I .. ./solution.cpp -O2
    g++-16 -g -O2 -std=c++23 -I .. solution.cpp -o solution
    valgrind --tool=callgrind ./solution
    kcachegrind callgrind.out.*
    
    cd "$cur_dir"
}