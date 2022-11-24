#include <iostream>
template <typename iterator>
void my_selection_sort(iterator begin, iterator end) {
    typename std::remove_pointer<typename iterator::value_type>::type a;

    if constexpr (std::is_integral<typeof(a)>::value) {
        for (iterator i = begin; i != end; i++) {
            iterator minEven = i;
            for (iterator it = i; it != end; it++) {
                auto val = *it;
                if (((val % 2) == 0) && val < *minEven) minEven = it;
            }

            if (((*minEven) % 2) == 0) {
                typeof(a) tmp = *minEven;
                *minEven = *i;
                *i = tmp;
            }
            for (iterator j = begin; j != end; j++) std::cout << *j << ' ';
            std::cout << std::endl;
        } /*
         iterator rend = begin;
         rend--;
         for (iterator i = --iterator(end); i != rend; i--) {
             iterator maxOdd = i;
             for (iterator it = i; it != end; it--) {
                 auto val = *it;
                 if (val % 2 == 0 && val < *maxOdd) maxOdd = it;
             }

             auto tmp = *maxOdd;
             *maxOdd = *i;
             *i = tmp;
         }*/
    } else
        while (begin != end) {
            iterator min = begin;
            for (iterator it = ++iterator(begin); it != end; it++)
                if (*it < *min) min = it;

            std::swap(*(begin++), *min);
        }
}