#include "sort_file.hpp"

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo) {
    std::string str;
    if (!(fi >> str)) return;
    fo << str << '\n';
    char c = str[0];
    if (c == 'i')
        read_and_sort_decide_container<int>(fi, fo);
    else if (c == 's')
        read_and_sort_decide_container<std::string>(fi, fo);
}