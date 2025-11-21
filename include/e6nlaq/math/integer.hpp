
#ifndef E6NLAQ_MATH_INTEGER_HPP
#define E6NLAQ_MATH_INTEGER_HPP 1

#include <bit>
#include <cassert>
#include <concepts>
#include <cstdlib>
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
inline constexpr T div_ceil(T a, T b) {
    if (b == 0) {
        throw std::invalid_argument("div_ceil: division by zero");
    }

    T res = a / b;
    T rem = a % b;

    // 剰余があり、かつaとbが同符号（結果が正）の場合に切り上げる
    if (rem != 0 && (a > 0 == b > 0)) {
        res++;
    }
    return res;
}

/**
 * @brief 数学的な意味での剰余を計算します（負の数にも対応）
 * @tparam T 整数型
 * @param x 被除数
 * @param m 0でない除数 (m != 0)
 * @return T x mod m の値（0以上m未満）
 * @note 計算量: O(1)
 * @note 常に0以上m未満の値を返します
 * @see https://qiita.com/happyisland44/items/8e4feb6805eecee29f83
 */
template <std::integral T>
inline constexpr T mmod(T x, T m) {
    T M = m;
    if constexpr (std::is_signed_v<T>) {
        if (m < 0) {
            if (m == std::numeric_limits<T>::min()) {
                throw std::domain_error("mmod: m cannot be the minimum value of its type");
            }
            M = -m;
        }
    }
    T r = x % M;
    return r < 0 ? r + M : r;
}

/**
 * @brief 非負整数の階乗を計算します
 * @param n 非負整数 (n >= 0)
 * @return long long n! の値
 * @note 計算量: O(n)
 * @note nが0の場合は1を返します
 * @warning nが大きいとオーバーフローする可能性があります（20! = 2,432,902,008,176,640,000）
 */
inline constexpr unsigned long long fact(const unsigned long long n) {
    unsigned long long res = 1;
    for (unsigned long long i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

/**
 * @brief 整数のべき乗を計算します (x^n)
 * @param x 底
 * @param n 指数
 * @return unsigned long long x^n の値
 * @note 計算量: O(log n)
 * @note 繰り返し二乗法を使用して実装されています
 * @note 0^0=1です
 * @warning 結果がオーバーフローする可能性があります
 */
inline unsigned long long pow_ll(unsigned long long x, unsigned long long n) noexcept {
    unsigned long long ret = 1ULL;
    while (n > 0) {
        if (n & 1)
            ret *= x;
        x *= x;
        n >>= 1;
    }

    return ret;
}

/**
 * @brief 1からnまでの総和を計算します
 * @param n 非負整数
 * @return unsigned long long 1 + 2 + ... + n の値
 * @note 計算量: O(1)
 * @note 公式: n(n+1)/2 を使用して実装されています
 * @warning nが大きいとオーバーフローする可能性があります
 */
inline unsigned long long sum_to_n(const unsigned long long n) noexcept {
    if (n % 2 == 0) {
        return (n / 2ULL) * (n + 1ULL);
    } else {
        return n * ((n + 1ULL) / 2ULL);
    }
}

}  // namespace e6nlaq

#endif  // E6NLAQ_MATH_INTEGER_HPP