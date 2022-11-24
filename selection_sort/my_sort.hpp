// Change me instead
// All occurences of XXX need to be replaced with
// something more meaningful

template <typename iterator>
void my_selection_sort(iterator begin, iterator end) {
    while (begin != end) {
        iterator min = begin;
        for (iterator it = ++iterator(begin); it != end; it++)
            if (*it < *min) min = it;

        std::swap(*(begin++), *min);
    }
}