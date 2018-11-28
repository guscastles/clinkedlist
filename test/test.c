#include "test.h"

int test_result(int n_results, ...) {
    va_list pa;
    va_start(pa, n_results);
    size_t sum = 0;
    for (size_t i = 0; i < n_results; ++i)
        sum += va_arg(pa, int);
    va_end(pa);
    return sum;
}

