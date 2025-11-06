// @e6nlaq/library / (C) 2025 e6nlaq

#ifndef E6NLAQ_MATH_INTEGER_HPP
#define E6NLAQ_MATH_INTEGER_HPP 1

#include <bit>
#include <cassert>
#include <concepts>
#include <limits>

namespace e6nlaq {

// nの桁数
// O(1)
/// @ref https://x.com/ngtkana/status/1980504937290428680
template <std::unsigned_integral T>
int digits(T n) {
    using UnsignedT = std::make_unsigned_t<T>;
    UnsignedT x;
    if (n < 0)
        x = static_cast<UnsignedT>(-n);
    else
        x = n;
    x |= 1;

    if constexpr (sizeof(UnsignedT) <= 4) {  // 32bit or less
        static const int lower_bound_table[] = {9, 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0};
        static const unsigned int pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

        int lower_bound = lower_bound_table[std::countl_zero(static_cast<unsigned int>(x))];
        return lower_bound + (pow[lower_bound] <= x);
    } else {  // 64bit
        static const int lower_bound_table[] = {
            19, 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13, 13, 13,
            12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 7, 6, 6, 6,
            5, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0};
        static const unsigned long long pow[] = {
            1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,
            10000000000ULL, 100000000000ULL, 1000000000000ULL, 10000000000000ULL,
            100000000000000ULL, 1000000000000000ULL, 10000000000000000ULL,
            100000000000000000ULL, 1000000000000000000ULL, 10000000000000000000ULL};

        int lower_bound = lower_bound_table[std::countl_zero(x)];
        return lower_bound + (pow[lower_bound] <= x);
    }
}

template <std::signed_integral T>
int digits(T n) {
    return digits(static_cast<std::make_unsigned_t<T>>(n < 0 ? -n : n));
}

/// floor(sqrt(n))
/// nは非負整数
/// O(log log N) / 実質O(1)
/// ニュートン法を用いる
template <std::integral T>
T isqrt(T n) {
    assert(n >= 0);
    if (n == 0) {
        return 0;
    }

    using UnsignedT = std::make_unsigned_t<T>;
    UnsignedT n_unsigned = static_cast<UnsignedT>(n);

    int n_bits = std::bit_width(n_unsigned);

    T x;
    int shift = (n_bits + 1) / 2;

    constexpr int t_digits = std::numeric_limits<T>::digits;

    if (shift >= t_digits) {
        x = static_cast<T>(1) << (t_digits - 1);
    } else {
        x = static_cast<T>(1) << shift;
    }

    T y = (x + n / x) / 2;

    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }

    return x;
}

template <std::integral T>
inline bool is_squere(const T N) noexcept {
    T r = isqrt(N);  // 切り捨てした平方根
    return (r * r) == N;
}

}  // namespace e6nlaq

#endif  // E6NLAQ_MATH_INTEGER_HPP