// @e6nlaq/library / (C) 2025 e6nlaq

#include <cstdlib>
#ifndef E6NLAQ_MATH_INTEGER_HPP
#define E6NLAQ_MATH_INTEGER_HPP 1

#include <bit>
#include <cassert>
#include <concepts>
#include <limits>
#include <stdexcept>

namespace e6nlaq {

/**
 * @brief 符号なし整数の桁数を計算します
 * @tparam T 符号なし整数型
 * @param n 桁数を計算する整数
 * @return int 10進数表記での桁数
 * @note 計算量: O(1)
 * @see https://x.com/ngtkana/status/1980504937290428680
 */
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

/**
 * @brief 符号付き整数の桁数を計算します
 * @tparam T 符号付き整数型
 * @param n 桁数を計算する整数
 * @return int 10進数表記での桁数（符号は除く）
 * @note 計算量: O(1)
 */
template <std::signed_integral T>
int digits(T n) {
    return digits(static_cast<std::make_unsigned_t<T>>(n < 0 ? -n : n));
}

/**
 * @brief 非負整数の平方根の整数部を計算します（切り捨て）
 * @tparam T 整数型
 * @param n 非負整数（n >= 0）
 * @return T floor(√n) の値
 * @note 計算量: O(log log N) / 実質O(1)
 * @note ニュートン法を使用して実装されています
 * @throw std::invalid_argument nが負の場合にスローされます
 */
template <std::integral T>
T isqrt(T n) {
    if (n < 0) {
        throw std::invalid_argument("isqrt: n must be non-negative");
    }
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

/**
 * @brief 与えられた整数が平方数かどうかを判定します
 * @tparam T 整数型
 * @param N 判定する整数
 * @return bool Nが平方数の場合はtrue、そうでない場合はfalse
 * @note 計算量: isqrt(N) に依存
 * @note 例外を投げないことが保証されています
 */
template <std::integral T>
inline bool is_square(const T N) noexcept {
    T r = isqrt(N);  // 切り捨てした平方根
    return (r * r) == N;
}

/**
 * @brief 切り上げ(無限大方向)除算を行います
 * @tparam T 整数型
 * @param a 被除数
 * @param b 0でない除数 (b != 0)
 * @return T ceil(a / b) の値（正の無限大方向に丸め）
 * @throw std::invalid_argument bが0の場合
 * @note 計算量: O(1)
 * @note a や b が負の場合も正の無限大方向に丸めます
 */
template <std::integral T>
inline constexpr T divup(T a, T b) {
    if (b == 0) {
        throw std::invalid_argument("divup: division by zero");
    }

    if (a < 0 || b < 0) {
        throw std::invalid_argument("divup: a or b is negative");
    }

    return (a + b - 1) / b;
}

/**
 * @brief 数学的な意味での剰余を計算します（負の数にも対応）
 * @tparam T 整数型
 * @param x 被除数
 * @param m 正の除数 (m > 0)
 * @return T x mod m の値（0以上m未満）
 * @note 計算量: O(1)
 * @note 常に0以上m未満の値を返します
 * @see https://qiita.com/happyisland44/items/8e4feb6805eecee29f83
 */
template <std::integral T>
inline constexpr T mmod(T x, T m) {
    m = std::abs(m);
    return (x % m + m) % m;
}

/**
 * @brief 非負整数の階乗を計算します
 * @param n 非負整数 (n >= 0)
 * @return long long n! の値
 * @note 計算量: O(n)
 * @note nが0の場合は1を返します
 * @warning nが大きいとオーバーフローする可能性があります（20! = 2,432,902,008,176,640,000）
 * @throw std::invalid_argument nが負の場合にスローされます
 */
inline constexpr long long fact(const long long n) {
    if (n < 0) {
        throw std::invalid_argument("fact: n must be non-negative");
    }

    long long res = 1;
    for (long long i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

}  // namespace e6nlaq

#endif  // E6NLAQ_MATH_INTEGER_HPP