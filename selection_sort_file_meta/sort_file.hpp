#include <deque>
#include <fstream>
#include <list>
#include <string>
#include <vector>

#include "my_sort.hpp"

template <typename T>
void read_file_to_cont(std::ifstream &fi, T &cont) {
    typename T::value_type val;
    if constexpr (std::is_same<typeof(val), char>::value) {
        while (char c = fi.get()) {
            cont.push_back(c);
            if (fi.get() == EOF) break;
        }
    } else
        while (fi >> val) cont.push_back(val);
}

template <typename T>
void read_and_sort(std::ifstream &fi, std::ofstream &fo) {
    T container;
    read_file_to_cont<T>(fi, container);
    my_selection_sort(container.begin(), container.end());
    for (auto elem : container) fo << elem << '\n';
}

template <typename V>
void read_and_sort_decide_container(std::ifstream &fi, std::ofstream &fo) {
    std::string first;
    fi >> first;
    fo << first << '\n';
    char c = first[0];
    if (c == 'l')
        read_and_sort<std::list<V>>(fi, fo);
    else if (c == 'v')
        read_and_sort<std::vector<V>>(fi, fo);
    else if (c == 'd')
        read_and_sort<std::deque<V>>(fi, fo);
}

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo);