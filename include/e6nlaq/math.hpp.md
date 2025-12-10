---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/math.hpp
    title: include/e6nlaq/internal/math.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math/acl.hpp
    title: include/e6nlaq/math/acl.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math/integer.hpp
    title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\
      \u3057\u307E\u3059"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"include/e6nlaq/math/acl.hpp\"\n\n// This file is a fork\
    \ of AtCoder Library.\n\n#define E6NLAQ_MATH_ACL_HPP\n\n#include <algorithm>\n\
    #include <cassert>\n#include <tuple>\n#include <vector>\n\n#line 2 \"include/e6nlaq/internal/math.hpp\"\
    \n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_INTERNAL_MATH_HPP\n\
    \n#include <utility>\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace\
    \ e6nlaq {\n\nnamespace internal {\n\n// @param m `1 <= m`\n// @return x mod m\n\
    constexpr long long safe_mod(long long x, long long m) {\n    x %= m;\n    if\
    \ (x < 0) x += m;\n    return x;\n}\n\n// Fast modular multiplication by barrett\
    \ reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n//\
    \ NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n  \
    \  unsigned long long im;\n\n    // @param m `1 <= m`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned long long y = x * _m;\n        return (unsigned int)(z\
    \ - y + (z < y ? _m : 0));\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1\
    \ <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n>\nconstexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m>\nconstexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace e6nlaq\n#line 13 \"include/e6nlaq/math/acl.hpp\"\
    \n\nnamespace e6nlaq {\n\ninline long long pow_mod(long long x, long long n, int\
    \ m) {\n    assert(0 <= n && 1 <= m);\n    if (m == 1) return 0;\n    internal::barrett\
    \ bt((unsigned int)(m));\n    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n    while (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y,\
    \ y);\n        n >>= 1;\n    }\n    return r;\n}\n\ninline long long inv_mod(long\
    \ long x, long long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x,\
    \ m);\n    assert(z.first == 1);\n    return z.second;\n}\n\n// (rem, mod)\ninline\
    \ std::pair<long long, long long> crt(const std::vector<long long>& r,\n     \
    \                                      const std::vector<long long>& m) {\n  \
    \  assert(r.size() == m.size());\n    int n = int(r.size());\n    // Contracts:\
    \ 0 <= r0 < m0\n    long long r0 = 0, m0 = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        assert(1 <= m[i]);\n        long long r1 = internal::safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n\
    \            std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n    \
    \        if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n\
    \        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)\n\n        // (r0,\
    \ m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));\n        // r2 % m0 = r0\n        //\
    \ r2 % m1 = r1\n        // -> (r0 + x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0\
    \ (mod u1*g) (u0*g = m0, u1*g = m1)\n        // -> x = (r1 - r0) / g * inv(u0)\
    \ (mod u1)\n\n        // im = inv(u0) (mod u1) (0 <= im < u1)\n        long long\
    \ g, im;\n        std::tie(g, im) = internal::inv_gcd(m0, m1);\n\n        long\
    \ long u1 = (m1 / g);\n        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n     \
    \   if ((r1 - r0) % g) return {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g\
    \ <= m0 * m1 / g = lcm(m0, m1)\n        long long x = (r1 - r0) / g % u1 * im\
    \ % u1;\n\n        // |r0| + |m0 * x|\n        // < m0 + m0 * (u1 - 1)\n     \
    \   // = m0 + m0 * m1 / g - m0\n        // = lcm(m0, m1)\n        r0 += x * m0;\n\
    \        m0 *= u1;  // -> lcm(m0, m1)\n        if (r0 < 0) r0 += m0;\n    }\n\
    \    return {r0, m0};\n}\n\ninline long long floor_sum(long long n, long long\
    \ m, long long a, long long b) {\n    assert(0 <= n && n < (1LL << 32));\n   \
    \ assert(1 <= m && m < (1LL << 32));\n    unsigned long long ans = 0;\n    if\
    \ (a < 0) {\n        unsigned long long a2 = internal::safe_mod(a, m);\n     \
    \   ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n    }\n\
    \    if (b < 0) {\n        unsigned long long b2 = internal::safe_mod(b, m);\n\
    \        ans -= 1ULL * n * ((b2 - b) / m);\n        b = b2;\n    }\n    return\
    \ ans + internal::floor_sum_unsigned(n, m, a, b);\n}\n\n}  // namespace e6nlaq\n\
    #line 2 \"include/e6nlaq/math/integer.hpp\"\n\n#define E6NLAQ_MATH_INTEGER_HPP\n\
    \n#include <bit>\n#line 7 \"include/e6nlaq/math/integer.hpp\"\n#include <concepts>\n\
    #include <cstdlib>\n#include <limits>\n#include <stdexcept>\n\nnamespace e6nlaq\
    \ {\n\n/**\n * @brief \u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\
    \u8A08\u7B97\u3057\u307E\u3059\n * @tparam T \u7B26\u53F7\u306A\u3057\u6574\u6570\
    \u578B\n * @param n \u6841\u6570\u3092\u8A08\u7B97\u3059\u308B\u6574\u6570\n *\
    \ @return int 10\u9032\u6570\u8868\u8A18\u3067\u306E\u6841\u6570\n * @note \u8A08\
    \u7B97\u91CF: O(1)\n * @see https://x.com/ngtkana/status/1980504937290428680\n\
    \ */\ntemplate <std::unsigned_integral T>\nint digits(T n) {\n    using UnsignedT\
    \ = std::make_unsigned_t<T>;\n    UnsignedT x;\n    if (n < 0)\n        x = static_cast<UnsignedT>(-n);\n\
    \    else\n        x = n;\n    x |= 1;\n\n    if constexpr (sizeof(UnsignedT)\
    \ <= 4) {  // 32bit or less\n        static const int lower_bound_table[] = {9,\
    \ 9, 9, 8, 8, 8, 7, 7, 7, 6, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1,\
    \ 1, 1, 0, 0, 0};\n        static const unsigned int pow[] = {1, 10, 100, 1000,\
    \ 10000, 100000, 1000000, 10000000, 100000000, 1000000000};\n\n        int lower_bound\
    \ = lower_bound_table[std::countl_zero(static_cast<unsigned int>(x))];\n     \
    \   return lower_bound + (pow[lower_bound] <= x);\n    } else {  // 64bit\n  \
    \      static const int lower_bound_table[] = {\n            19, 18, 18, 18, 18,\
    \ 17, 17, 17, 16, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13, 13, 13,\n      \
    \      12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 7,\
    \ 6, 6, 6,\n            5, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0};\n\
    \        static const unsigned long long pow[] = {\n            1, 10, 100, 1000,\
    \ 10000, 100000, 1000000, 10000000, 100000000, 1000000000,\n            10000000000ULL,\
    \ 100000000000ULL, 1000000000000ULL, 10000000000000ULL,\n            100000000000000ULL,\
    \ 1000000000000000ULL, 10000000000000000ULL,\n            100000000000000000ULL,\
    \ 1000000000000000000ULL, 10000000000000000000ULL};\n\n        int lower_bound\
    \ = lower_bound_table[std::countl_zero(x)];\n        return lower_bound + (pow[lower_bound]\
    \ <= x);\n    }\n}\n\n/**\n * @brief \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u306E\
    \u6841\u6570\u3092\u8A08\u7B97\u3057\u307E\u3059\n * @tparam T \u7B26\u53F7\u4ED8\
    \u304D\u6574\u6570\u578B\n * @param n \u6841\u6570\u3092\u8A08\u7B97\u3059\u308B\
    \u6574\u6570\n * @return int 10\u9032\u6570\u8868\u8A18\u3067\u306E\u6841\u6570\
    \uFF08\u7B26\u53F7\u306F\u9664\u304F\uFF09\n * @note \u8A08\u7B97\u91CF: O(1)\n\
    \ */\ntemplate <std::signed_integral T>\nint digits(T n) {\n    return digits(static_cast<std::make_unsigned_t<T>>(n\
    \ < 0 ? -n : n));\n}\n\n/**\n * @brief \u975E\u8CA0\u6574\u6570\u306E\u5E73\u65B9\
    \u6839\u306E\u6574\u6570\u90E8\u3092\u8A08\u7B97\u3057\u307E\u3059\uFF08\u5207\
    \u308A\u6368\u3066\uFF09\n * @tparam T \u6574\u6570\u578B\n * @param n \u975E\u8CA0\
    \u6574\u6570\uFF08n >= 0\uFF09\n * @return T floor(\u221An) \u306E\u5024\n * @note\
    \ \u8A08\u7B97\u91CF: O(log log N) / \u5B9F\u8CEAO(1)\n * @note \u30CB\u30E5\u30FC\
    \u30C8\u30F3\u6CD5\u3092\u4F7F\u7528\u3057\u3066\u5B9F\u88C5\u3055\u308C\u3066\
    \u3044\u307E\u3059\n * @throw std::invalid_argument n\u304C\u8CA0\u306E\u5834\u5408\
    \u306B\u30B9\u30ED\u30FC\u3055\u308C\u307E\u3059\n */\ntemplate <std::integral\
    \ T>\nT isqrt(T n) {\n    if (n < 0) {\n        throw std::invalid_argument(\"\
    isqrt: n must be non-negative\");\n    }\n    if (n == 0) {\n        return 0;\n\
    \    }\n\n    using UnsignedT = std::make_unsigned_t<T>;\n    UnsignedT n_unsigned\
    \ = static_cast<UnsignedT>(n);\n\n    int n_bits = std::bit_width(n_unsigned);\n\
    \n    T x;\n    int shift = (n_bits + 1) / 2;\n\n    constexpr int t_digits =\
    \ std::numeric_limits<T>::digits;\n\n    if (shift >= t_digits) {\n        x =\
    \ static_cast<T>(1) << (t_digits - 1);\n    } else {\n        x = static_cast<T>(1)\
    \ << shift;\n    }\n\n    T y = (x + n / x) / 2;\n\n    while (y < x) {\n    \
    \    x = y;\n        y = (x + n / x) / 2;\n    }\n\n    return x;\n}\n\n/**\n\
    \ * @brief \u4E0E\u3048\u3089\u308C\u305F\u6574\u6570\u304C\u5E73\u65B9\u6570\u304B\
    \u3069\u3046\u304B\u3092\u5224\u5B9A\u3057\u307E\u3059\n * @tparam T \u6574\u6570\
    \u578B\n * @param N \u5224\u5B9A\u3059\u308B\u6574\u6570\n * @return bool N\u304C\
    \u5E73\u65B9\u6570\u306E\u5834\u5408\u306Ftrue\u3001\u305D\u3046\u3067\u306A\u3044\
    \u5834\u5408\u306Ffalse\n * @note \u8A08\u7B97\u91CF: isqrt(N) \u306B\u4F9D\u5B58\
    \n * @note \u4F8B\u5916\u3092\u6295\u3052\u306A\u3044\u3053\u3068\u304C\u4FDD\u8A3C\
    \u3055\u308C\u3066\u3044\u307E\u3059\n */\ntemplate <std::integral T>\ninline\
    \ bool is_square(const T N) noexcept {\n    T r = isqrt(N);  // \u5207\u308A\u6368\
    \u3066\u3057\u305F\u5E73\u65B9\u6839\n    return (r * r) == N;\n}\n\n/**\n * @brief\
    \ \u5207\u308A\u4E0A\u3052(\u7121\u9650\u5927\u65B9\u5411)\u9664\u7B97\u3092\u884C\
    \u3044\u307E\u3059\n * @tparam T \u6574\u6570\u578B\n * @param a \u88AB\u9664\u6570\
    \n * @param b 0\u3067\u306A\u3044\u9664\u6570 (b != 0)\n * @return T ceil(a /\
    \ b) \u306E\u5024\uFF08\u6B63\u306E\u7121\u9650\u5927\u65B9\u5411\u306B\u4E38\u3081\
    \uFF09\n * @throw std::invalid_argument b\u304C0\u306E\u5834\u5408\n * @note \u8A08\
    \u7B97\u91CF: O(1)\n * @note a \u3084 b \u304C\u8CA0\u306E\u5834\u5408\u3082\u6B63\
    \u306E\u7121\u9650\u5927\u65B9\u5411\u306B\u4E38\u3081\u307E\u3059\n */\ntemplate\
    \ <std::integral T>\ninline constexpr T div_ceil(T a, T b) {\n    if (b == 0)\
    \ {\n        throw std::invalid_argument(\"div_ceil: division by zero\");\n  \
    \  }\n\n    T res = a / b;\n    T rem = a % b;\n\n    // \u5270\u4F59\u304C\u3042\
    \u308A\u3001\u304B\u3064a\u3068b\u304C\u540C\u7B26\u53F7\uFF08\u7D50\u679C\u304C\
    \u6B63\uFF09\u306E\u5834\u5408\u306B\u5207\u308A\u4E0A\u3052\u308B\n    if (rem\
    \ != 0 && (a > 0 == b > 0)) {\n        res++;\n    }\n    return res;\n}\n\n/**\n\
    \ * @brief \u6570\u5B66\u7684\u306A\u610F\u5473\u3067\u306E\u5270\u4F59\u3092\u8A08\
    \u7B97\u3057\u307E\u3059\uFF08\u8CA0\u306E\u6570\u306B\u3082\u5BFE\u5FDC\uFF09\
    \n * @tparam T \u6574\u6570\u578B\n * @param x \u88AB\u9664\u6570\n * @param m\
    \ 0\u3067\u306A\u3044\u9664\u6570 (m != 0)\n * @return T x mod m \u306E\u5024\uFF08\
    0\u4EE5\u4E0Am\u672A\u6E80\uFF09\n * @note \u8A08\u7B97\u91CF: O(1)\n * @note\
    \ \u5E38\u306B0\u4EE5\u4E0Am\u672A\u6E80\u306E\u5024\u3092\u8FD4\u3057\u307E\u3059\
    \n * @see https://qiita.com/happyisland44/items/8e4feb6805eecee29f83\n */\ntemplate\
    \ <std::integral T>\ninline constexpr T mmod(T x, T m) {\n    T M = m;\n    if\
    \ constexpr (std::is_signed_v<T>) {\n        if (m < 0) {\n            if (m ==\
    \ std::numeric_limits<T>::min()) {\n                throw std::domain_error(\"\
    mmod: m cannot be the minimum value of its type\");\n            }\n         \
    \   M = -m;\n        }\n    }\n    T r = x % M;\n    return r < 0 ? r + M : r;\n\
    }\n\n/**\n * @brief \u975E\u8CA0\u6574\u6570\u306E\u968E\u4E57\u3092\u8A08\u7B97\
    \u3057\u307E\u3059\n * @param n \u975E\u8CA0\u6574\u6570 (n >= 0)\n * @return\
    \ long long n! \u306E\u5024\n * @note \u8A08\u7B97\u91CF: O(n)\n * @note n\u304C\
    0\u306E\u5834\u5408\u306F1\u3092\u8FD4\u3057\u307E\u3059\n * @warning n\u304C\u5927\
    \u304D\u3044\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\u308B\u53EF\
    \u80FD\u6027\u304C\u3042\u308A\u307E\u3059\uFF0820! = 2,432,902,008,176,640,000\uFF09\
    \n */\ninline constexpr unsigned long long fact(const unsigned long long n) {\n\
    \    unsigned long long res = 1;\n    for (unsigned long long i = 2; i <= n; i++)\
    \ {\n        res *= i;\n    }\n    return res;\n}\n\n/**\n * @brief \u6574\u6570\
    \u306E\u3079\u304D\u4E57\u3092\u8A08\u7B97\u3057\u307E\u3059 (x^n)\n * @param\
    \ x \u5E95\n * @param n \u6307\u6570\n * @return unsigned long long x^n \u306E\
    \u5024\n * @note \u8A08\u7B97\u91CF: O(log n)\n * @note \u7E70\u308A\u8FD4\u3057\
    \u4E8C\u4E57\u6CD5\u3092\u4F7F\u7528\u3057\u3066\u5B9F\u88C5\u3055\u308C\u3066\
    \u3044\u307E\u3059\n * @note 0^0=1\u3067\u3059\n * @warning \u7D50\u679C\u304C\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\u308B\u53EF\u80FD\u6027\u304C\
    \u3042\u308A\u307E\u3059\n */\ninline unsigned long long pow_ll(unsigned long\
    \ long x, unsigned long long n) noexcept {\n    unsigned long long ret = 1ULL;\n\
    \    while (n > 0) {\n        if (n & 1)\n            ret *= x;\n        x *=\
    \ x;\n        n >>= 1;\n    }\n\n    return ret;\n}\n\n/**\n * @brief 1\u304B\u3089\
    n\u307E\u3067\u306E\u7DCF\u548C\u3092\u8A08\u7B97\u3057\u307E\u3059\n * @param\
    \ n \u975E\u8CA0\u6574\u6570\n * @return unsigned long long 1 + 2 + ... + n \u306E\
    \u5024\n * @note \u8A08\u7B97\u91CF: O(1)\n * @note \u516C\u5F0F: n(n+1)/2 \u3092\
    \u4F7F\u7528\u3057\u3066\u5B9F\u88C5\u3055\u308C\u3066\u3044\u307E\u3059\n * @warning\
    \ n\u304C\u5927\u304D\u3044\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\
    \u308B\u53EF\u80FD\u6027\u304C\u3042\u308A\u307E\u3059\n */\ninline unsigned long\
    \ long sum_to_n(const unsigned long long n) noexcept {\n    if (n % 2 == 0) {\n\
    \        return (n / 2ULL) * (n + 1ULL);\n    } else {\n        return n * ((n\
    \ + 1ULL) / 2ULL);\n    }\n}\n\n}  // namespace e6nlaq\n#line 3 \"include/e6nlaq/math.hpp\"\
    \n"
  code: '#include "math/acl.hpp"

    #include "math/integer.hpp"'
  dependsOn:
  - include/e6nlaq/math/acl.hpp
  - include/e6nlaq/internal/math.hpp
  - include/e6nlaq/math/integer.hpp
  isVerificationFile: false
  path: include/e6nlaq/math.hpp
  requiredBy:
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-11 00:03:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/math.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/math.hpp
- /library/include/e6nlaq/math.hpp.html
title: include/e6nlaq/math.hpp
---
