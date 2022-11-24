template <typename iterator>
void my_selection_sort(iterator begin, iterator end) {
    typename std::remove_pointer<typename iterator::value_type>::type a;

    if constexpr (std::is_integral<typeof(a)>::value) {
        size_t evens = 0;
        iterator odds = begin;
        for (iterator i = begin; i != end; i++) {
            if (*i % 2 == 0) {
                std::swap(*i, *odds++);
                evens++;
            }
        }
        for (iterator j = begin; j != odds; j++) {
            iterator min = j;
            for (iterator it = ++iterator(j); it != odds; it++)
                if (*it < *min) min = it;

            std::swap(*j, *min);
        }
        for (iterator j = odds; j != end; j++) {
            iterator min = j;
            for (iterator it = ++iterator(j); it != end; it++)
                if (*it < *min) min = it;

            std::swap(*j, *min);
        }
    } else
        while (begin != end) {
            iterator min = begin;
            for (iterator it = ++iterator(begin); it != end; it++)
                if (*it < *min) min = it;

            std::swap(*(begin++), *min);
        }
}