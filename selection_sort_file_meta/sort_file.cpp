#include "sort_file.hpp"

void read_and_sort_decide_valuetype(std::ifstream &fi, std::ofstream &fo) {
    std::string str;
    if (!(fi >> str)) return;
    fo << str << '\n';
    char c = str[0];
    switch (c) {
        case 'i':
            read_and_sort_decide_container<int>(fi, fo);
            break;
        case 's':
            read_and_sort_decide_container<std::string>(fi, fo);
            break;
        case 'u':
            read_and_sort_decide_container<unsigned int>(fi, fo);
            break;
        case 'f':
            read_and_sort_decide_container<float>(fi, fo);
            break;
        case 'd':
            read_and_sort_decide_container<double>(fi, fo);
            break;
        case 'c':
            read_and_sort_decide_container<char>(fi, fo);
            break;
        default:
            break;
    }
}