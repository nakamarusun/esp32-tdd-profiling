#ifndef UTILS_HEADER
#define UTILS_HEADER

#include <zephyr/kernel.h>
#include <zephyr/random/rand32.h>

#ifndef DIFF_ARR_TYPE
#define ARR_TYPE int
#else
#define ARR_TYPE DIFF_ARR_TYPE
#endif

template <class T>
inline void swap(T& a, T& b) {
    T tmp = b;
    b = a;
    a = tmp;
}

void copy_array(ARR_TYPE _from[], ARR_TYPE _to[], int n) {
    for (int i = 0; i < n; ++i)
        _to[i] = _from[i];
}

int getRandom(int l, int r) {
    return 1ll * sys_rand32_get() * sys_rand32_get() * sys_rand32_get() % (r - l + 1) + l;
}

void printArray(ARR_TYPE a[], int n) {
    for (int i = 0; i < n; ++i)
        printk("%d", a[i]);
}

#endif