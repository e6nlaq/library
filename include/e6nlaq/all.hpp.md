---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/convolution.hpp
    title: include/e6nlaq/convolution.hpp
  - icon: ':warning:'
    path: include/e6nlaq/dsu.hpp
    title: include/e6nlaq/dsu.hpp
  - icon: ':warning:'
    path: include/e6nlaq/fenwicktree.hpp
    title: include/e6nlaq/fenwicktree.hpp
  - icon: ':warning:'
    path: include/e6nlaq/internal/bit.hpp
    title: include/e6nlaq/internal/bit.hpp
  - icon: ':warning:'
    path: include/e6nlaq/internal/csr.hpp
    title: include/e6nlaq/internal/csr.hpp
  - icon: ':warning:'
    path: include/e6nlaq/internal/math.hpp
    title: include/e6nlaq/internal/math.hpp
  - icon: ':warning:'
    path: include/e6nlaq/internal/queue.hpp
    title: include/e6nlaq/internal/queue.hpp
  - icon: ':warning:'
    path: include/e6nlaq/internal/scc.hpp
    title: include/e6nlaq/internal/scc.hpp
  - icon: ':warning:'
    path: include/e6nlaq/internal/type_traits.hpp
    title: include/e6nlaq/internal/type_traits.hpp
  - icon: ':warning:'
    path: include/e6nlaq/lazysegtree.hpp
    title: include/e6nlaq/lazysegtree.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math.hpp
    title: include/e6nlaq/math.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math/acl.hpp
    title: include/e6nlaq/math/acl.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math/integer.hpp
    title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\
      \u3057\u307E\u3059"
  - icon: ':warning:'
    path: include/e6nlaq/maxflow.hpp
    title: include/e6nlaq/maxflow.hpp
  - icon: ':warning:'
    path: include/e6nlaq/mincostflow.hpp
    title: include/e6nlaq/mincostflow.hpp
  - icon: ':warning:'
    path: include/e6nlaq/modint.hpp
    title: include/e6nlaq/modint.hpp
  - icon: ':warning:'
    path: include/e6nlaq/scc.hpp
    title: include/e6nlaq/scc.hpp
  - icon: ':warning:'
    path: include/e6nlaq/segtree.hpp
    title: include/e6nlaq/segtree.hpp
  - icon: ':warning:'
    path: include/e6nlaq/string.hpp
    title: include/e6nlaq/string.hpp
  - icon: ':warning:'
    path: include/e6nlaq/twosat.hpp
    title: include/e6nlaq/twosat.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"include/e6nlaq/convolution.hpp\"\n\n// This file is a fork\
    \ of AtCoder Library.\n\n#define E6NLAQ_CONVOLUTION_HPP\n\n#include <algorithm>\n\
    #include <array>\n#include <cassert>\n#include <type_traits>\n#include <vector>\n\
    \n#line 2 \"include/e6nlaq/internal/bit.hpp\"\n\n// This file is a fork of AtCoder\
    \ Library.\n\n#define E6NLAQ_INTERNAL_BITOP_HPP\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\n#if __cplusplus >= 202002L\n#include <bit>\n#endif\n\nnamespace e6nlaq\
    \ {\n\nnamespace internal {\n\n#if __cplusplus >= 202002L\n\nusing std::bit_ceil;\n\
    \n#else\n\n// @return same with std::bit::bit_ceil\nunsigned int bit_ceil(unsigned\
    \ int n) {\n    unsigned int x = 1;\n    while (x < (unsigned int)(n)) x *= 2;\n\
    \    return x;\n}\n\n#endif\n\n// @param n `1 <= n`\n// @return same with std::bit::countr_zero\n\
    int countr_zero(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n// @param n `1 <= n`\n// @return same with std::bit::countr_zero\n\
    constexpr int countr_zero_constexpr(unsigned int n) {\n    int x = 0;\n    while\
    \ (!(n & (1 << x))) x++;\n    return x;\n}\n\n}  // namespace internal\n\n}  //\
    \ namespace e6nlaq\n#line 2 \"include/e6nlaq/modint.hpp\"\n\n// This file is a\
    \ fork of AtCoder Library.\n\n#define E6NLAQ_MODINT_HPP\n\n#line 9 \"include/e6nlaq/modint.hpp\"\
    \n\n#line 2 \"include/e6nlaq/internal/math.hpp\"\n\n// This file is a fork of\
    \ AtCoder Library.\n\n#define E6NLAQ_INTERNAL_MATH_HPP\n\n#include <utility>\n\
    \n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace e6nlaq {\n\nnamespace\
    \ internal {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long\
    \ safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\n// Fast modular multiplication by barrett reduction\n// Reference:\
    \ https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider after Ice\
    \ Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n\
    \    // @param m `1 <= m`\n    explicit barrett(unsigned int m) : _m(m), im((unsigned\
    \ long long)(-1) / m + 1) {}\n\n    // @return m\n    unsigned int umod() const\
    \ { return _m; }\n\n    // @param a `0 <= a < m`\n    // @param b `0 <= b < m`\n\
    \    // @return `a * b % m`\n    unsigned int mul(unsigned int a, unsigned int\
    \ b) const {\n        // [1] m = 1\n        // a = b = im = 0, so okay\n\n   \
    \     // [2] m >= 2\n        // im = ceil(2^64 / m)\n        // -> im * m = 2^64\
    \ + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <= c, d < m)\n       \
    \ // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im\n     \
    \   // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) <\
    \ 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n        unsigned long\
    \ long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned long long x;\n\
    \        _umul128(z, im, &x);\n#else\n        unsigned long long x =\n       \
    \     (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n#endif\n     \
    \   unsigned long long y = x * _m;\n        return (unsigned int)(z - y + (z <\
    \ y ? _m : 0));\n    }\n};\n\n// @param n `0 <= n`\n// @param m `1 <= m`\n// @return\
    \ `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long long x, long long\
    \ n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m = (unsigned int)(m);\n\
    \    unsigned long long r = 1;\n    unsigned long long y = safe_mod(x, m);\n \
    \   while (n) {\n        if (n & 1) r = (r * y) % _m;\n        y = (y * y) % _m;\n\
    \        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n// M. Forisek and\
    \ J. Jancina,\n// Fast Primality Testing for Integers That Fit into a Machine\
    \ Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int n) {\n   \
    \ if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return true;\n\
    \    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while (d % 2\
    \ == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for (long\
    \ long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
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
    \  // namespace internal\n\n}  // namespace e6nlaq\n#line 2 \"include/e6nlaq/internal/type_traits.hpp\"\
    \n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_INTERNAL_TYPE_TRAITS_HPP\n\
    \n#line 9 \"include/e6nlaq/internal/type_traits.hpp\"\n\nnamespace e6nlaq {\n\n\
    namespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T>\nusing\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T>\nusing to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace e6nlaq\n#line 12 \"include/e6nlaq/modint.hpp\"\
    \n\nnamespace e6nlaq {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T>\nusing is_modint\
    \ = std::is_base_of<modint_base, T>;\ntemplate <class T>\nusing is_modint_t =\
    \ std::enable_if_t<is_modint<T>::value>;\n\n}  // namespace internal\n\ntemplate\
    \ <int m, std::enable_if_t<(1 <= m)>* = nullptr>\nstruct static_modint : internal::static_modint_base\
    \ {\n    using mint = static_modint;\n\n   public:\n    static constexpr int mod()\
    \ { return m; }\n    static mint raw(int v) {\n        mint x;\n        x._v =\
    \ v;\n        return x;\n    }\n\n    static_modint() : _v(0) {}\n    template\
    \ <class T, internal::is_signed_int_t<T>* = nullptr>\n    static_modint(T v) {\n\
    \        long long x = (long long)(v % (long long)(umod()));\n        if (x <\
    \ 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n    template <class\
    \ T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T v) {\n  \
    \      _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val() const\
    \ { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if (_v ==\
    \ umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--() {\n  \
    \      if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n    }\n\
    \    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n   private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id>\nstruct dynamic_modint : internal::modint_base {\n   \
    \ using mint = dynamic_modint;\n\n   public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \  private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id>\ninternal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class>\nstruct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace e6nlaq\n#line 15 \"include/e6nlaq/convolution.hpp\"\
    \n\nnamespace e6nlaq {\n\nnamespace internal {\n\ntemplate <class mint,\n    \
    \      int g = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = countr_zero_constexpr(mint::mod()\
    \ - 1);\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\n    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;\n\
    \n    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;\n    std::array<mint,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\n\n    fft_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n \
    \       }\n\n        {\n            mint prod = 1, iprod = 1;\n            for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i] = root[i + 2] *\
    \ prod;\n                irate2[i] = iroot[i + 2] * iprod;\n                prod\
    \ *= iroot[i + 2];\n                iprod *= root[i + 2];\n            }\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for (int\
    \ i = 0; i <= rank2 - 3; i++) {\n                rate3[i] = root[i + 3] * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n    int h\
    \ = internal::countr_zero((unsigned int)n);\n\n    static const fft_info<mint>\
    \ info;\n\n    int len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \    while (len < h) {\n        if (h - len == 1) {\n            int p = 1 <<\
    \ (h - len - 1);\n            mint rot = 1;\n            for (int s = 0; s < (1\
    \ << len); s++) {\n                int offset = s << (h - len);\n            \
    \    for (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n\
    \                    auto r = a[i + offset + p] * rot;\n                    a[i\
    \ + offset] = l + r;\n                    a[i + offset + p] = l - r;\n       \
    \         }\n                if (s + 1 != (1 << len))\n                    rot\
    \ *= info.rate2[countr_zero(~(unsigned int)(s))];\n            }\n           \
    \ len++;\n        } else {\n            // 4-base\n            int p = 1 << (h\
    \ - len - 2);\n            mint rot = 1, imag = info.root[2];\n            for\
    \ (int s = 0; s < (1 << len); s++) {\n                mint rot2 = rot * rot;\n\
    \                mint rot3 = rot2 * rot;\n                int offset = s << (h\
    \ - len);\n                for (int i = 0; i < p; i++) {\n                   \
    \ auto mod2 = 1ULL * mint::mod() * mint::mod();\n                    auto a0 =\
    \ 1ULL * a[i + offset].val();\n                    auto a1 = 1ULL * a[i + offset\
    \ + p].val() * rot.val();\n                    auto a2 = 1ULL * a[i + offset +\
    \ 2 * p].val() * rot2.val();\n                    auto a3 = 1ULL * a[i + offset\
    \ + 3 * p].val() * rot3.val();\n                    auto a1na3imag =\n       \
    \                 1ULL * mint(a1 + mod2 - a3).val() * imag.val();\n          \
    \          auto na2 = mod2 - a2;\n                    a[i + offset] = a0 + a2\
    \ + a1 + a3;\n                    a[i + offset + 1 * p] = a0 + a2 + (2 * mod2\
    \ - (a1 + a3));\n                    a[i + offset + 2 * p] = a0 + na2 + a1na3imag;\n\
    \                    a[i + offset + 3 * p] = a0 + na2 + (mod2 - a1na3imag);\n\
    \                }\n                if (s + 1 != (1 << len))\n               \
    \     rot *= info.rate3[countr_zero(~(unsigned int)(s))];\n            }\n   \
    \         len += 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nvoid butterfly_inv(std::vector<mint>& a) {\n    int n = int(a.size());\n\
    \    int h = internal::countr_zero((unsigned int)n);\n\n    static const fft_info<mint>\
    \ info;\n\n    int len = h;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n\
    \    while (len) {\n        if (len == 1) {\n            int p = 1 << (h - len);\n\
    \            mint irot = 1;\n            for (int s = 0; s < (1 << (len - 1));\
    \ s++) {\n                int offset = s << (h - len + 1);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto l = a[i + offset];\n   \
    \                 auto r = a[i + offset + p];\n                    a[i + offset]\
    \ = l + r;\n                    a[i + offset + p] =\n                        (unsigned\
    \ long long)(mint::mod() + l.val() - r.val()) *\n                        irot.val();\n\
    \                    ;\n                }\n                if (s + 1 != (1 <<\
    \ (len - 1)))\n                    irot *= info.irate2[countr_zero(~(unsigned\
    \ int)(s))];\n            }\n            len--;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len);\n            mint irot = 1,\
    \ iimag = info.iroot[2];\n            for (int s = 0; s < (1 << (len - 2)); s++)\
    \ {\n                mint irot2 = irot * irot;\n                mint irot3 = irot2\
    \ * irot;\n                int offset = s << (h - len + 2);\n                for\
    \ (int i = 0; i < p; i++) {\n                    auto a0 = 1ULL * a[i + offset\
    \ + 0 * p].val();\n                    auto a1 = 1ULL * a[i + offset + 1 * p].val();\n\
    \                    auto a2 = 1ULL * a[i + offset + 2 * p].val();\n         \
    \           auto a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                \
    \    auto a2na3iimag =\n                        1ULL *\n                     \
    \   mint((mint::mod() + a2 - a3) * iimag.val()).val();\n\n                   \
    \ a[i + offset] = a0 + a1 + a2 + a3;\n                    a[i + offset + 1 * p]\
    \ =\n                        (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n\
    \                    a[i + offset + 2 * p] =\n                        (a0 + a1\
    \ + (mint::mod() - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n\
    \                    a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[countr_zero(~(unsigned int)(s))];\n          \
    \  }\n            len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\n\
    \                                    const std::vector<mint>& b) {\n    int n\
    \ = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   int z = (int)internal::bit_ceil((unsigned int)(n + m - 1));\n    a.resize(z);\n\
    \    internal::butterfly(a);\n    b.resize(z);\n    internal::butterfly(b);\n\
    \    for (int i = 0; i < z; i++) {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n\
    \    a.resize(n + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i\
    \ < n + m - 1; i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\
    \ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint>\
    \ convolution(std::vector<mint>&& a, std::vector<mint>&& b) {\n    int n = int(a.size()),\
    \ m = int(b.size());\n    if (!n || !m) return {};\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    std::vector<mint> convolution(const std::vector<mint>& a,\n                  \
    \            const std::vector<mint>& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    if (std::min(n,\
    \ m) <= 60) return convolution_naive(a, b);\n    return internal::convolution_fft(a,\
    \ b);\n}\n\ntemplate <unsigned int mod = 998244353,\n          class T,\n    \
    \      std::enable_if_t<internal::is_integral<T>::value>* = nullptr>\nstd::vector<T>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\n    int n =\
    \ int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\n    using\
    \ mint = static_modint<mod>;\n\n    int z = (int)internal::bit_ceil((unsigned\
    \ int)(n + m - 1));\n    assert((mint::mod() - 1) % z == 0);\n\n    std::vector<mint>\
    \ a2(n), b2(m);\n    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n\
    \    }\n    for (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n\
    \    auto c2 = convolution(std::move(a2), std::move(b2));\n    std::vector<T>\
    \ c(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n\
    \    }\n    return c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long\
    \ long>& a,\n                                      const std::vector<long long>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n\
    \    static constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static\
    \ constexpr unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr\
    \ unsigned long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long\
    \ M1M3 = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n    static constexpr int MAX_AB_BIT\
    \ = 24;\n    static_assert(MOD1 % (1ull << MAX_AB_BIT) == 1, \"MOD1 isn't enough\
    \ to support an array length of 2^24.\");\n    static_assert(MOD2 % (1ull << MAX_AB_BIT)\
    \ == 1, \"MOD2 isn't enough to support an array length of 2^24.\");\n    static_assert(MOD3\
    \ % (1ull << MAX_AB_BIT) == 1, \"MOD3 isn't enough to support an array length\
    \ of 2^24.\");\n    assert(n + m - 1 <= (1 << MAX_AB_BIT));\n\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1)\
    \ % MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n\n    return c;\n}\n\n}  //\
    \ namespace e6nlaq\n#line 2 \"include/e6nlaq/dsu.hpp\"\n\n// This file is a fork\
    \ of AtCoder Library.\n\n#define E6NLAQ_DSU_HPP\n\n#line 10 \"include/e6nlaq/dsu.hpp\"\
    \n\nnamespace e6nlaq {\n\n// Implement (union by size) + (path compression)\n\
    // Reference:\n// Zvi Galil and Giuseppe F. Italiano,\n// Data structures and\
    \ algorithms for disjoint set union problems\nstruct dsu {\n   public:\n    dsu()\
    \ : _n(0) {}\n    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}\n\n  \
    \  int merge(int a, int b) {\n        assert(0 <= a && a < _n);\n        assert(0\
    \ <= b && b < _n);\n        int x = leader(a), y = leader(b);\n        if (x ==\
    \ y) return x;\n        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x,\
    \ y);\n        parent_or_size[x] += parent_or_size[y];\n        parent_or_size[y]\
    \ = x;\n        return x;\n    }\n\n    bool same(int a, int b) {\n        assert(0\
    \ <= a && a < _n);\n        assert(0 <= b && b < _n);\n        return leader(a)\
    \ == leader(b);\n    }\n\n    int leader(int a) {\n        assert(0 <= a && a\
    \ < _n);\n        if (parent_or_size[a] < 0) return a;\n        return parent_or_size[a]\
    \ = leader(parent_or_size[a]);\n    }\n\n    int size(int a) {\n        assert(0\
    \ <= a && a < _n);\n        return -parent_or_size[leader(a)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> leader_buf(_n), group_size(_n);\n     \
    \   for (int i = 0; i < _n; i++) {\n            leader_buf[i] = leader(i);\n \
    \           group_size[leader_buf[i]]++;\n        }\n        std::vector<std::vector<int>>\
    \ result(_n);\n        for (int i = 0; i < _n; i++) {\n            result[i].reserve(group_size[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            result[leader_buf[i]].push_back(i);\n\
    \        }\n        result.erase(\n            std::remove_if(result.begin(),\
    \ result.end(),\n                           [&](const std::vector<int>& v) { return\
    \ v.empty(); }),\n            result.end());\n        return result;\n    }\n\n\
    \   private:\n    int _n;\n    // root node: -1 * component size\n    // otherwise:\
    \ parent\n    std::vector<int> parent_or_size;\n};\n\n}  // namespace e6nlaq\n\
    #line 2 \"include/e6nlaq/fenwicktree.hpp\"\n\n// This file is a fork of AtCoder\
    \ Library.\n\n#define E6NLAQ_FENWICKTREE_HPP\n\n#line 9 \"include/e6nlaq/fenwicktree.hpp\"\
    \n\n#line 11 \"include/e6nlaq/fenwicktree.hpp\"\n\nnamespace e6nlaq {\n\n// Reference:\
    \ https://en.wikipedia.org/wiki/Fenwick_tree\ntemplate <class T>\nstruct fenwick_tree\
    \ {\n    using U = internal::to_unsigned_t<T>;\n\n   public:\n    fenwick_tree()\
    \ : _n(0) {}\n    explicit fenwick_tree(int n) : _n(n), data(n) {}\n\n    void\
    \ add(int p, T x) {\n        assert(0 <= p && p < _n);\n        p++;\n       \
    \ while (p <= _n) {\n            data[p - 1] += U(x);\n            p += p & -p;\n\
    \        }\n    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <=\
    \ r && r <= _n);\n        return sum(r) - sum(l);\n    }\n\n   private:\n    int\
    \ _n;\n    std::vector<U> data;\n\n    U sum(int r) {\n        U s = 0;\n    \
    \    while (r > 0) {\n            s += data[r - 1];\n            r -= r & -r;\n\
    \        }\n        return s;\n    }\n};\n\n}  // namespace e6nlaq\n#line 2 \"\
    include/e6nlaq/lazysegtree.hpp\"\n\n// This file is a fork of AtCoder Library.\n\
    \n#define E6NLAQ_LAZYSEGTREE_HPP\n\n#line 8 \"include/e6nlaq/lazysegtree.hpp\"\
    \n#include <functional>\n#line 10 \"include/e6nlaq/lazysegtree.hpp\"\n\n#line\
    \ 12 \"include/e6nlaq/lazysegtree.hpp\"\n\nnamespace e6nlaq {\n\n#if __cplusplus\
    \ >= 201703L\n\ntemplate <class S,\n          auto op,\n          auto e,\n  \
    \        class F,\n          auto mapping,\n          auto composition,\n    \
    \      auto id>\nstruct lazy_segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                  \"op must work as S(S, S)\");\n\
    \    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,\n \
    \                 \"e must work as S()\");\n    static_assert(\n        std::is_convertible_v<decltype(mapping),\
    \ std::function<S(F, S)>>,\n        \"mapping must work as F(F, S)\");\n    static_assert(\n\
    \        std::is_convertible_v<decltype(composition), std::function<F(F, F)>>,\n\
    \        \"compostiion must work as F(F, F)\");\n    static_assert(std::is_convertible_v<decltype(id),\
    \ std::function<F()>>,\n                  \"id must work as F()\");\n\n#else\n\
    \ntemplate <class S,\n          S (*op)(S, S),\n          S (*e)(),\n        \
    \  class F,\n          S (*mapping)(F, S),\n          F (*composition)(F, F),\n\
    \          F (*id)()>\nstruct lazy_segtree {\n\n#endif\n\n   public:\n    lazy_segtree()\
    \ : lazy_segtree(0) {}\n    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n,\
    \ e())) {}\n    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size()))\
    \ {\n        size = (int)internal::bit_ceil((unsigned int)(_n));\n        log\
    \ = internal::countr_zero((unsigned int)size);\n        d = std::vector<S>(2 *\
    \ size, e());\n        lz = std::vector<F>(size, id());\n        for (int i =\
    \ 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size - 1; i >= 1;\
    \ i--) {\n            update(i);\n        }\n    }\n\n    void set(int p, S x)\
    \ {\n        assert(0 <= p && p < _n);\n        p += size;\n        for (int i\
    \ = log; i >= 1; i--) push(p >> i);\n        d[p] = x;\n        for (int i = 1;\
    \ i <= log; i++) update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0\
    \ <= p && p < _n);\n        p += size;\n        for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n        return d[p];\n    }\n\n    S prod(int l, int r) {\n \
    \       assert(0 <= l && l <= r && r <= _n);\n        if (l == r) return e();\n\
    \n        l += size;\n        r += size;\n\n        for (int i = log; i >= 1;\
    \ i--) {\n            if (((l >> i) << i) != l) push(l >> i);\n            if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n        }\n\n        S sml = e(),\
    \ smr = e();\n        while (l < r) {\n            if (l & 1) sml = op(sml, d[l++]);\n\
    \            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n       \
    \     r >>= 1;\n        }\n\n        return op(sml, smr);\n    }\n\n    S all_prod()\
    \ { return d[1]; }\n\n    void apply(int p, F f) {\n        assert(0 <= p && p\
    \ < _n);\n        p += size;\n        for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n        d[p] = mapping(f, d[p]);\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n    void apply(int l, int r, F f) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        if (l == r) return;\n\n        l += size;\n\
    \        r += size;\n\n        for (int i = log; i >= 1; i--) {\n            if\
    \ (((l >> i) << i) != l) push(l >> i);\n            if (((r >> i) << i) != r)\
    \ push((r - 1) >> i);\n        }\n\n        {\n            int l2 = l, r2 = r;\n\
    \            while (l < r) {\n                if (l & 1) all_apply(l++, f);\n\
    \                if (r & 1) all_apply(--r, f);\n                l >>= 1;\n   \
    \             r >>= 1;\n            }\n            l = l2;\n            r = r2;\n\
    \        }\n\n        for (int i = 1; i <= log; i++) {\n            if (((l >>\
    \ i) << i) != l) update(l >> i);\n            if (((r >> i) << i) != r) update((r\
    \ - 1) >> i);\n        }\n    }\n\n    template <bool (*g)(S)>\n    int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return g(x); });\n    }\n    template\
    \ <class G>\n    int max_right(int l, G g) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(g(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        for (int i = log; i >= 1; i--) push(l >> i);\n        S sm = e();\n \
    \       do {\n            while (l % 2 == 0) l >>= 1;\n            if (!g(op(sm,\
    \ d[l]))) {\n                while (l < size) {\n                    push(l);\n\
    \                    l = (2 * l);\n                    if (g(op(sm, d[l]))) {\n\
    \                        sm = op(sm, d[l]);\n                        l++;\n  \
    \                  }\n                }\n                return l - size;\n  \
    \          }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*g)(S)>\n\
    \    int min_left(int r) {\n        return min_left(r, [](S x) { return g(x);\
    \ });\n    }\n    template <class G>\n    int min_left(int r, G g) {\n       \
    \ assert(0 <= r && r <= _n);\n        assert(g(e()));\n        if (r == 0) return\
    \ 0;\n        r += size;\n        for (int i = log; i >= 1; i--) push((r - 1)\
    \ >> i);\n        S sm = e();\n        do {\n            r--;\n            while\
    \ (r > 1 && (r % 2)) r >>= 1;\n            if (!g(op(d[r], sm))) {\n         \
    \       while (r < size) {\n                    push(r);\n                   \
    \ r = (2 * r + 1);\n                    if (g(op(d[r], sm))) {\n             \
    \           sm = op(d[r], sm);\n                        r--;\n               \
    \     }\n                }\n                return r + 1 - size;\n           \
    \ }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n      \
    \  return 0;\n    }\n\n   private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n    std::vector<F> lz;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2\
    \ * k + 1]); }\n    void all_apply(int k, F f) {\n        d[k] = mapping(f, d[k]);\n\
    \        if (k < size) lz[k] = composition(f, lz[k]);\n    }\n    void push(int\
    \ k) {\n        all_apply(2 * k, lz[k]);\n        all_apply(2 * k + 1, lz[k]);\n\
    \        lz[k] = id();\n    }\n};\n\n}  // namespace e6nlaq\n#line 2 \"include/e6nlaq/math/acl.hpp\"\
    \n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_MATH_ACL_HPP\n\
    \n#line 9 \"include/e6nlaq/math/acl.hpp\"\n#include <tuple>\n#line 11 \"include/e6nlaq/math/acl.hpp\"\
    \n\n#line 13 \"include/e6nlaq/math/acl.hpp\"\n\nnamespace e6nlaq {\n\ninline long\
    \ long pow_mod(long long x, long long n, int m) {\n    assert(0 <= n && 1 <= m);\n\
    \    if (m == 1) return 0;\n    internal::barrett bt((unsigned int)(m));\n   \
    \ unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x, m));\n    while\
    \ (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y, y);\n   \
    \     n >>= 1;\n    }\n    return r;\n}\n\ninline long long inv_mod(long long\
    \ x, long long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x, m);\n\
    \    assert(z.first == 1);\n    return z.second;\n}\n\n// (rem, mod)\ninline std::pair<long\
    \ long, long long> crt(const std::vector<long long>& r,\n                    \
    \                       const std::vector<long long>& m) {\n    assert(r.size()\
    \ == m.size());\n    int n = int(r.size());\n    // Contracts: 0 <= r0 < m0\n\
    \    long long r0 = 0, m0 = 1;\n    for (int i = 0; i < n; i++) {\n        assert(1\
    \ <= m[i]);\n        long long r1 = internal::safe_mod(r[i], m[i]), m1 = m[i];\n\
    \        if (m0 < m1) {\n            std::swap(r0, r1);\n            std::swap(m0,\
    \ m1);\n        }\n        if (m0 % m1 == 0) {\n            if (r0 % m1 != r1)\
    \ return {0, 0};\n            continue;\n        }\n        // assume: m0 > m1,\
    \ lcm(m0, m1) >= 2 * max(m0, m1)\n\n        // (r0, m0), (r1, m1) -> (r2, m2 =\
    \ lcm(m0, m1));\n        // r2 % m0 = r0\n        // r2 % m1 = r1\n        //\
    \ -> (r0 + x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0 (mod u1*g) (u0*g = m0,\
    \ u1*g = m1)\n        // -> x = (r1 - r0) / g * inv(u0) (mod u1)\n\n        //\
    \ im = inv(u0) (mod u1) (0 <= im < u1)\n        long long g, im;\n        std::tie(g,\
    \ im) = internal::inv_gcd(m0, m1);\n\n        long long u1 = (m1 / g);\n     \
    \   // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n        if ((r1 - r0) % g) return\
    \ {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g <= m0 * m1 / g = lcm(m0, m1)\n\
    \        long long x = (r1 - r0) / g % u1 * im % u1;\n\n        // |r0| + |m0\
    \ * x|\n        // < m0 + m0 * (u1 - 1)\n        // = m0 + m0 * m1 / g - m0\n\
    \        // = lcm(m0, m1)\n        r0 += x * m0;\n        m0 *= u1;  // -> lcm(m0,\
    \ m1)\n        if (r0 < 0) r0 += m0;\n    }\n    return {r0, m0};\n}\n\ninline\
    \ long long floor_sum(long long n, long long m, long long a, long long b) {\n\
    \    assert(0 <= n && n < (1LL << 32));\n    assert(1 <= m && m < (1LL << 32));\n\
    \    unsigned long long ans = 0;\n    if (a < 0) {\n        unsigned long long\
    \ a2 = internal::safe_mod(a, m);\n        ans -= 1ULL * n * (n - 1) / 2 * ((a2\
    \ - a) / m);\n        a = a2;\n    }\n    if (b < 0) {\n        unsigned long\
    \ long b2 = internal::safe_mod(b, m);\n        ans -= 1ULL * n * ((b2 - b) / m);\n\
    \        b = b2;\n    }\n    return ans + internal::floor_sum_unsigned(n, m, a,\
    \ b);\n}\n\n}  // namespace e6nlaq\n#line 2 \"include/e6nlaq/math/integer.hpp\"\
    \n\n#define E6NLAQ_MATH_INTEGER_HPP\n\n#include <bit>\n#line 7 \"include/e6nlaq/math/integer.hpp\"\
    \n#include <concepts>\n#include <cstdlib>\n#include <limits>\n#include <stdexcept>\n\
    \nnamespace e6nlaq {\n\n/**\n * @brief \u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\
    \u6841\u6570\u3092\u8A08\u7B97\u3057\u307E\u3059\n * @tparam T \u7B26\u53F7\u306A\
    \u3057\u6574\u6570\u578B\n * @param n \u6841\u6570\u3092\u8A08\u7B97\u3059\u308B\
    \u6574\u6570\n * @return int 10\u9032\u6570\u8868\u8A18\u3067\u306E\u6841\u6570\
    \n * @note \u8A08\u7B97\u91CF: O(1)\n * @see https://x.com/ngtkana/status/1980504937290428680\n\
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
    \ + 1ULL) / 2ULL);\n    }\n}\n\n}  // namespace e6nlaq\n#line 2 \"include/e6nlaq/maxflow.hpp\"\
    \n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_MAXFLOW_HPP\n\
    \n#line 11 \"include/e6nlaq/maxflow.hpp\"\n\n#line 2 \"include/e6nlaq/internal/queue.hpp\"\
    \n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_INTERNAL_QUEUE_HPP\n\
    \n#line 8 \"include/e6nlaq/internal/queue.hpp\"\n\nnamespace e6nlaq {\n\nnamespace\
    \ internal {\n\ntemplate <class T>\nstruct simple_queue {\n    std::vector<T>\
    \ payload;\n    int pos = 0;\n    void reserve(int n) { payload.reserve(n); }\n\
    \    int size() const { return int(payload.size()) - pos; }\n    bool empty()\
    \ const { return pos == int(payload.size()); }\n    void push(const T& t) { payload.push_back(t);\
    \ }\n    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace e6nlaq\n#line 13 \"include/e6nlaq/maxflow.hpp\"\n\nnamespace\
    \ e6nlaq {\n\ntemplate <class Cap>\nstruct mf_graph {\n   public:\n    mf_graph()\
    \ : _n(0) {}\n    explicit mf_graph(int n) : _n(n), g(n) {}\n\n    int add_edge(int\
    \ from, int to, Cap cap) {\n        assert(0 <= from && from < _n);\n        assert(0\
    \ <= to && to < _n);\n        assert(0 <= cap);\n        int m = int(pos.size());\n\
    \        pos.push_back({from, int(g[from].size())});\n        int from_id = int(g[from].size());\n\
    \        int to_id = int(g[to].size());\n        if (from == to) to_id++;\n  \
    \      g[from].push_back(_edge{to, to_id, cap});\n        g[to].push_back(_edge{from,\
    \ from_id, 0});\n        return m;\n    }\n\n    struct edge {\n        int from,\
    \ to;\n        Cap cap, flow;\n    };\n\n    edge get_edge(int i) {\n        int\
    \ m = int(pos.size());\n        assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) {\n        return\
    \ flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    Cap flow(int s, int\
    \ t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n        assert(0 <=\
    \ t && t < _n);\n        assert(s != t);\n\n        std::vector<int> level(_n),\
    \ iter(_n);\n        internal::simple_queue<int> que;\n\n        auto bfs = [&]()\
    \ {\n            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d =\n                    self(self, e.to, std::min(up - res,\
    \ g[e.to][e.rev].cap));\n                if (d <= 0) continue;\n             \
    \   g[v][i].cap += d;\n                g[e.to][e.rev].cap -= d;\n            \
    \    res += d;\n                if (res == up) return res;\n            }\n  \
    \          level[v] = _n;\n            return res;\n        };\n\n        Cap\
    \ flow = 0;\n        while (flow < flow_limit) {\n            bfs();\n       \
    \     if (level[t] == -1) break;\n            std::fill(iter.begin(), iter.end(),\
    \ 0);\n            Cap f = dfs(dfs, t, flow_limit - flow);\n            if (!f)\
    \ break;\n            flow += f;\n        }\n        return flow;\n    }\n\n \
    \   std::vector<bool> min_cut(int s) {\n        std::vector<bool> visited(_n);\n\
    \        internal::simple_queue<int> que;\n        que.push(s);\n        while\
    \ (!que.empty()) {\n            int p = que.front();\n            que.pop();\n\
    \            visited[p] = true;\n            for (auto e : g[p]) {\n         \
    \       if (e.cap && !visited[e.to]) {\n                    visited[e.to] = true;\n\
    \                    que.push(e.to);\n                }\n            }\n     \
    \   }\n        return visited;\n    }\n\n   private:\n    int _n;\n    struct\
    \ _edge {\n        int to, rev;\n        Cap cap;\n    };\n    std::vector<std::pair<int,\
    \ int>> pos;\n    std::vector<std::vector<_edge>> g;\n};\n\n}  // namespace e6nlaq\n\
    #line 2 \"include/e6nlaq/mincostflow.hpp\"\n\n// This file is a fork of AtCoder\
    \ Library.\n\n#define E6NLAQ_MINCOSTFLOW_HPP\n\n#line 11 \"include/e6nlaq/mincostflow.hpp\"\
    \n\n#line 2 \"include/e6nlaq/internal/csr.hpp\"\n\n// This file is a fork of AtCoder\
    \ Library.\n\n#define E6NLAQ_INTERNAL_CSR_HPP\n\n#line 10 \"include/e6nlaq/internal/csr.hpp\"\
    \n\nnamespace e6nlaq {\nnamespace internal {\n\ntemplate <class E>\nstruct csr\
    \ {\n    std::vector<int> start;\n    std::vector<E> elist;\n    explicit csr(int\
    \ n, const std::vector<std::pair<int, E>>& edges)\n        : start(n + 1), elist(edges.size())\
    \ {\n        for (auto e : edges) {\n            start[e.first + 1]++;\n     \
    \   }\n        for (int i = 1; i <= n; i++) {\n            start[i] += start[i\
    \ - 1];\n        }\n        auto counter = start;\n        for (auto e : edges)\
    \ {\n            elist[counter[e.first]++] = e.second;\n        }\n    }\n};\n\
    \n}  // namespace internal\n\n}  // namespace e6nlaq\n#line 13 \"include/e6nlaq/mincostflow.hpp\"\
    \n\nnamespace e6nlaq {\n\ntemplate <class Cap, class Cost>\nstruct mcf_graph {\n\
    \   public:\n    mcf_graph() {}\n    explicit mcf_graph(int n) : _n(n) {}\n\n\
    \    int add_edge(int from, int to, Cap cap, Cost cost) {\n        assert(0 <=\
    \ from && from < _n);\n        assert(0 <= to && to < _n);\n        assert(0 <=\
    \ cap);\n        assert(0 <= cost);\n        int m = int(_edges.size());\n   \
    \     _edges.push_back({from, to, cap, 0, cost});\n        return m;\n    }\n\n\
    \    struct edge {\n        int from, to;\n        Cap cap, flow;\n        Cost\
    \ cost;\n    };\n\n    edge get_edge(int i) {\n        int m = int(_edges.size());\n\
    \        assert(0 <= i && i < m);\n        return _edges[i];\n    }\n    std::vector<edge>\
    \ edges() { return _edges; }\n\n    std::pair<Cap, Cost> flow(int s, int t) {\n\
    \        return flow(s, t, std::numeric_limits<Cap>::max());\n    }\n    std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n        return slope(s, t, flow_limit).back();\n\
    \    }\n    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n        return\
    \ slope(s, t, std::numeric_limits<Cap>::max());\n    }\n    std::vector<std::pair<Cap,\
    \ Cost>> slope(int s, int t, Cap flow_limit) {\n        assert(0 <= s && s < _n);\n\
    \        assert(0 <= t && t < _n);\n        assert(s != t);\n\n        int m =\
    \ int(_edges.size());\n        std::vector<int> edge_idx(m);\n\n        auto g\
    \ = [&]() {\n            std::vector<int> degree(_n), redge_idx(m);\n        \
    \    std::vector<std::pair<int, _edge>> elist;\n            elist.reserve(2 *\
    \ m);\n            for (int i = 0; i < m; i++) {\n                auto e = _edges[i];\n\
    \                edge_idx[i] = degree[e.from]++;\n                redge_idx[i]\
    \ = degree[e.to]++;\n                elist.push_back({e.from, {e.to, -1, e.cap\
    \ - e.flow, e.cost}});\n                elist.push_back({e.to, {e.from, -1, e.flow,\
    \ -e.cost}});\n            }\n            auto _g = internal::csr<_edge>(_n, elist);\n\
    \            for (int i = 0; i < m; i++) {\n                auto e = _edges[i];\n\
    \                edge_idx[i] += _g.start[e.from];\n                redge_idx[i]\
    \ += _g.start[e.to];\n                _g.elist[edge_idx[i]].rev = redge_idx[i];\n\
    \                _g.elist[redge_idx[i]].rev = edge_idx[i];\n            }\n  \
    \          return _g;\n        }();\n\n        auto result = slope(g, s, t, flow_limit);\n\
    \n        for (int i = 0; i < m; i++) {\n            auto e = g.elist[edge_idx[i]];\n\
    \            _edges[i].flow = _edges[i].cap - e.cap;\n        }\n\n        return\
    \ result;\n    }\n\n   private:\n    int _n;\n    std::vector<edge> _edges;\n\n\
    \    // inside edge\n    struct _edge {\n        int to, rev;\n        Cap cap;\n\
    \        Cost cost;\n    };\n\n    std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>&\
    \ g,\n                                            int s,\n                   \
    \                         int t,\n                                           \
    \ Cap flow_limit) {\n        // variants (C = maxcost):\n        // -(n-1)C <=\
    \ dual[s] <= dual[i] <= dual[t] = 0\n        // reduced cost (= e.cost + dual[e.from]\
    \ - dual[e.to]) >= 0 for all edge\n\n        // dual_dist[i] = (dual[i], dist[i])\n\
    \        std::vector<std::pair<Cost, Cost>> dual_dist(_n);\n        std::vector<int>\
    \ prev_e(_n);\n        std::vector<bool> vis(_n);\n        struct Q {\n      \
    \      Cost key;\n            int to;\n            bool operator<(Q r) const {\
    \ return key > r.key; }\n        };\n        std::vector<int> que_min;\n     \
    \   std::vector<Q> que;\n        auto dual_ref = [&]() {\n            for (int\
    \ i = 0; i < _n; i++) {\n                dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \            }\n            std::fill(vis.begin(), vis.end(), false);\n      \
    \      que_min.clear();\n            que.clear();\n\n            // que[0..heap_r)\
    \ was heapified\n            size_t heap_r = 0;\n\n            dual_dist[s].second\
    \ = 0;\n            que_min.push_back(s);\n            while (!que_min.empty()\
    \ || !que.empty()) {\n                int v;\n                if (!que_min.empty())\
    \ {\n                    v = que_min.back();\n                    que_min.pop_back();\n\
    \                } else {\n                    while (heap_r < que.size()) {\n\
    \                        heap_r++;\n                        std::push_heap(que.begin(),\
    \ que.begin() + heap_r);\n                    }\n                    v = que.front().to;\n\
    \                    std::pop_heap(que.begin(), que.end());\n                \
    \    que.pop_back();\n                    heap_r--;\n                }\n     \
    \           if (vis[v]) continue;\n                vis[v] = true;\n          \
    \      if (v == t) break;\n                // dist[v] = shortest(s, v) + dual[s]\
    \ - dual[v]\n                // dist[v] >= 0 (all reduced cost are positive)\n\
    \                // dist[v] <= (n-1)C\n                Cost dual_v = dual_dist[v].first,\
    \ dist_v = dual_dist[v].second;\n                for (int i = g.start[v]; i <\
    \ g.start[v + 1]; i++) {\n                    auto e = g.elist[i];\n         \
    \           if (!e.cap) continue;\n                    // |-dual[e.to] + dual[v]|\
    \ <= (n-1)C\n                    // cost <= C - -(n-1)C + 0 = nC\n           \
    \         Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n             \
    \       if (dual_dist[e.to].second - dist_v > cost) {\n                      \
    \  Cost dist_to = dist_v + cost;\n                        dual_dist[e.to].second\
    \ = dist_to;\n                        prev_e[e.to] = e.rev;\n                \
    \        if (dist_to == dist_v) {\n                            que_min.push_back(e.to);\n\
    \                        } else {\n                            que.push_back(Q{dist_to,\
    \ e.to});\n                        }\n                    }\n                }\n\
    \            }\n            if (!vis[t]) {\n                return false;\n  \
    \          }\n\n            for (int v = 0; v < _n; v++) {\n                if\
    \ (!vis[v]) continue;\n                // dual[v] = dual[v] - dist[t] + dist[v]\n\
    \                //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n\
    \                //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,\n\
    \                //         t) + dual[t] + shortest(s, v) = shortest(s, v) -\n\
    \                //         shortest(s, t) >= 0 - (n-1)C\n                dual_dist[v].first\
    \ -= dual_dist[t].second - dual_dist[v].second;\n            }\n            return\
    \ true;\n        };\n        Cap flow = 0;\n        Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n        std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \        while (flow < flow_limit) {\n            if (!dual_ref()) break;\n  \
    \          Cap c = flow_limit - flow;\n            for (int v = t; v != s; v =\
    \ g.elist[prev_e[v]].to) {\n                c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n\
    \            }\n            for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n                auto& e = g.elist[prev_e[v]];\n                e.cap += c;\n\
    \                g.elist[e.rev].cap -= c;\n            }\n            Cost d =\
    \ -dual_dist[s].first;\n            flow += c;\n            cost += c * d;\n \
    \           if (prev_cost_per_flow == d) {\n                result.pop_back();\n\
    \            }\n            result.push_back({flow, cost});\n            prev_cost_per_flow\
    \ = d;\n        }\n        return result;\n    }\n};\n\n}  // namespace e6nlaq\n\
    #line 2 \"include/e6nlaq/scc.hpp\"\n\n// This file is a fork of AtCoder Library.\n\
    \n#define E6NLAQ_SCC_HPP\n\n#line 9 \"include/e6nlaq/scc.hpp\"\n\n#line 2 \"include/e6nlaq/internal/scc.hpp\"\
    \n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_INTERNAL_SCC_HPP\n\
    \n#line 10 \"include/e6nlaq/internal/scc.hpp\"\n\n#line 12 \"include/e6nlaq/internal/scc.hpp\"\
    \n\nnamespace e6nlaq {\nnamespace internal {\n\n// Reference:\n// R. Tarjan,\n\
    // Depth-First Search and Linear Graph Algorithms\nstruct scc_graph {\n   public:\n\
    \    explicit scc_graph(int n) : _n(n) {}\n\n    int num_vertices() { return _n;\
    \ }\n\n    void add_edge(int from, int to) { edges.push_back({from, {to}}); }\n\
    \n    // @return pair of (# of scc, scc id)\n    std::pair<int, std::vector<int>>\
    \ scc_ids() {\n        auto g = csr<edge>(_n, edges);\n        int now_ord = 0,\
    \ group_num = 0;\n        std::vector<int> visited, low(_n), ord(_n, -1), ids(_n);\n\
    \        visited.reserve(_n);\n        auto dfs = [&](auto self, int v) -> void\
    \ {\n            low[v] = ord[v] = now_ord++;\n            visited.push_back(v);\n\
    \            for (int i = g.start[v]; i < g.start[v + 1]; i++) {\n           \
    \     auto to = g.elist[i].to;\n                if (ord[to] == -1) {\n       \
    \             self(self, to);\n                    low[v] = std::min(low[v], low[to]);\n\
    \                } else {\n                    low[v] = std::min(low[v], ord[to]);\n\
    \                }\n            }\n            if (low[v] == ord[v]) {\n     \
    \           while (true) {\n                    int u = visited.back();\n    \
    \                visited.pop_back();\n                    ord[u] = _n;\n     \
    \               ids[u] = group_num;\n                    if (u == v) break;\n\
    \                }\n                group_num++;\n            }\n        };\n\
    \        for (int i = 0; i < _n; i++) {\n            if (ord[i] == -1) dfs(dfs,\
    \ i);\n        }\n        for (auto& x : ids) {\n            x = group_num - 1\
    \ - x;\n        }\n        return {group_num, ids};\n    }\n\n    std::vector<std::vector<int>>\
    \ scc() {\n        auto ids = scc_ids();\n        int group_num = ids.first;\n\
    \        std::vector<int> counts(group_num);\n        for (auto x : ids.second)\
    \ counts[x]++;\n        std::vector<std::vector<int>> groups(ids.first);\n   \
    \     for (int i = 0; i < group_num; i++) {\n            groups[i].reserve(counts[i]);\n\
    \        }\n        for (int i = 0; i < _n; i++) {\n            groups[ids.second[i]].push_back(i);\n\
    \        }\n        return groups;\n    }\n\n   private:\n    int _n;\n    struct\
    \ edge {\n        int to;\n    };\n    std::vector<std::pair<int, edge>> edges;\n\
    };\n\n}  // namespace internal\n\n}  // namespace e6nlaq\n#line 11 \"include/e6nlaq/scc.hpp\"\
    \n\nnamespace e6nlaq {\n\nstruct scc_graph {\n   public:\n    scc_graph() : internal(0)\
    \ {}\n    explicit scc_graph(int n) : internal(n) {}\n\n    void add_edge(int\
    \ from, int to) {\n        int n = internal.num_vertices();\n        assert(0\
    \ <= from && from < n);\n        assert(0 <= to && to < n);\n        internal.add_edge(from,\
    \ to);\n    }\n\n    std::vector<std::vector<int>> scc() { return internal.scc();\
    \ }\n\n   private:\n    internal::scc_graph internal;\n};\n\n}  // namespace e6nlaq\n\
    #line 2 \"include/e6nlaq/segtree.hpp\"\n\n// This file is a fork of AtCoder Library.\n\
    \n#define E6NLAQ_SEGTREE_HPP\n\n#line 10 \"include/e6nlaq/segtree.hpp\"\n\n#line\
    \ 12 \"include/e6nlaq/segtree.hpp\"\n\nnamespace e6nlaq {\n\ntemplate <class S,\
    \ auto op, auto e>\nstruct segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
    \ std::function<S(S, S)>>,\n                  \"op must work as S(S, S)\");\n\
    \    static_assert(std::is_convertible_v<decltype(e), std::function<S()>>,\n \
    \                 \"e must work as S()\");\n\n   public:\n    segtree() : segtree(0)\
    \ {}\n    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        size = (int)internal::bit_ceil((unsigned\
    \ int)(_n));\n        log = internal::countr_zero((unsigned int)size);\n     \
    \   d = std::vector<S>(2 * size, e());\n        for (int i = 0; i < _n; i++) d[size\
    \ + i] = v[i];\n        for (int i = size - 1; i >= 1; i--) {\n            update(i);\n\
    \        }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p <\
    \ _n);\n        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n    }\n\n    S get(int p) const {\n        assert(0 <=\
    \ p && p < _n);\n        return d[p + size];\n    }\n\n    S prod(int l, int r)\
    \ const {\n        assert(0 <= l && l <= r && r <= _n);\n        S sml = e(),\
    \ smr = e();\n        l += size;\n        r += size;\n\n        while (l < r)\
    \ {\n            if (l & 1) sml = op(sml, d[l++]);\n            if (r & 1) smr\
    \ = op(d[--r], smr);\n            l >>= 1;\n            r >>= 1;\n        }\n\
    \        return op(sml, smr);\n    }\n\n    S all_prod() const { return d[1];\
    \ }\n\n    template <bool (*f)(S)>\n    int max_right(int l) const {\n       \
    \ return max_right(l, [](S x) { return f(x); });\n    }\n    template <class F>\n\
    \    int max_right(int l, F f) const {\n        assert(0 <= l && l <= _n);\n \
    \       assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)>\n\
    \    int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F>\n    int min_left(int r, F f) const\
    \ {\n        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r\
    \ == 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n   \
    \         r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if\
    \ (!f(op(d[r], sm))) {\n                while (r < size) {\n                 \
    \   r = (2 * r + 1);\n                    if (f(op(d[r], sm))) {\n           \
    \             sm = op(d[r], sm);\n                        r--;\n             \
    \       }\n                }\n                return r + 1 - size;\n         \
    \   }\n            sm = op(d[r], sm);\n        } while ((r & -r) != r);\n    \
    \    return 0;\n    }\n\n   private:\n    int _n, size, log;\n    std::vector<S>\
    \ d;\n\n    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n\
    }  // namespace e6nlaq\n#line 2 \"include/e6nlaq/string.hpp\"\n\n// This file\
    \ is a fork of AtCoder Library.\n\n#define E6NLAQ_STRING_HPP\n\n#line 9 \"include/e6nlaq/string.hpp\"\
    \n#include <numeric>\n#include <string>\n#line 12 \"include/e6nlaq/string.hpp\"\
    \n\nnamespace e6nlaq {\n\nnamespace internal {\n\ninline std::vector<int> sa_naive(const\
    \ std::vector<int>& s) {\n    int n = int(s.size());\n    std::vector<int> sa(n);\n\
    \    std::iota(sa.begin(), sa.end(), 0);\n    std::sort(sa.begin(), sa.end(),\
    \ [&](int l, int r) {\n        if (l == r) return false;\n        while (l < n\
    \ && r < n) {\n            if (s[l] != s[r]) return s[l] < s[r];\n           \
    \ l++;\n            r++;\n        }\n        return l == n;\n    });\n    return\
    \ sa;\n}\n\ninline std::vector<int> sa_doubling(const std::vector<int>& s) {\n\
    \    int n = int(s.size());\n    std::vector<int> sa(n), rnk = s, tmp(n);\n  \
    \  std::iota(sa.begin(), sa.end(), 0);\n    for (int k = 1; k < n; k *= 2) {\n\
    \        auto cmp = [&](int x, int y) {\n            if (rnk[x] != rnk[y]) return\
    \ rnk[x] < rnk[y];\n            int rx = x + k < n ? rnk[x + k] : -1;\n      \
    \      int ry = y + k < n ? rnk[y + k] : -1;\n            return rx < ry;\n  \
    \      };\n        std::sort(sa.begin(), sa.end(), cmp);\n        tmp[sa[0]] =\
    \ 0;\n        for (int i = 1; i < n; i++) {\n            tmp[sa[i]] = tmp[sa[i\
    \ - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0);\n        }\n        std::swap(tmp,\
    \ rnk);\n    }\n    return sa;\n}\n\n// SA-IS, linear-time suffix array construction\n\
    // Reference:\n// G. Nong, S. Zhang, and W. H. Chan,\n// Two Efficient Algorithms\
    \ for Linear Time Suffix Array Construction\ntemplate <int THRESHOLD_NAIVE = 10,\
    \ int THRESHOLD_DOUBLING = 40>\nstd::vector<int> sa_is(const std::vector<int>&\
    \ s, int upper) {\n    int n = int(s.size());\n    if (n == 0) return {};\n  \
    \  if (n == 1) return {0};\n    if (n == 2) {\n        if (s[0] < s[1]) {\n  \
    \          return {0, 1};\n        } else {\n            return {1, 0};\n    \
    \    }\n    }\n    if (n < THRESHOLD_NAIVE) {\n        return sa_naive(s);\n \
    \   }\n    if (n < THRESHOLD_DOUBLING) {\n        return sa_doubling(s);\n   \
    \ }\n\n    std::vector<int> sa(n);\n    std::vector<bool> ls(n);\n    for (int\
    \ i = n - 2; i >= 0; i--) {\n        ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] :\
    \ (s[i] < s[i + 1]);\n    }\n    std::vector<int> sum_l(upper + 1), sum_s(upper\
    \ + 1);\n    for (int i = 0; i < n; i++) {\n        if (!ls[i]) {\n          \
    \  sum_s[s[i]]++;\n        } else {\n            sum_l[s[i] + 1]++;\n        }\n\
    \    }\n    for (int i = 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n\
    \        if (i < upper) sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induce =\
    \ [&](const std::vector<int>& lms) {\n        std::fill(sa.begin(), sa.end(),\
    \ -1);\n        std::vector<int> buf(upper + 1);\n        std::copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (auto d : lms) {\n            if (d\
    \ == n) continue;\n            sa[buf[s[d]]++] = d;\n        }\n        std::copy(sum_l.begin(),\
    \ sum_l.end(), buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for\
    \ (int i = 0; i < n; i++) {\n            int v = sa[i];\n            if (v >=\
    \ 1 && !ls[v - 1]) {\n                sa[buf[s[v - 1]]++] = v - 1;\n         \
    \   }\n        }\n        std::copy(sum_l.begin(), sum_l.end(), buf.begin());\n\
    \        for (int i = n - 1; i >= 0; i--) {\n            int v = sa[i];\n    \
    \        if (v >= 1 && ls[v - 1]) {\n                sa[--buf[s[v - 1] + 1]] =\
    \ v - 1;\n            }\n        }\n    };\n\n    std::vector<int> lms_map(n +\
    \ 1, -1);\n    int m = 0;\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms_map[i] = m++;\n        }\n    }\n    std::vector<int>\
    \ lms;\n    lms.reserve(m);\n    for (int i = 1; i < n; i++) {\n        if (!ls[i\
    \ - 1] && ls[i]) {\n            lms.push_back(i);\n        }\n    }\n\n    induce(lms);\n\
    \n    if (m) {\n        std::vector<int> sorted_lms;\n        sorted_lms.reserve(m);\n\
    \        for (int v : sa) {\n            if (lms_map[v] != -1) sorted_lms.push_back(v);\n\
    \        }\n        std::vector<int> rec_s(m);\n        int rec_upper = 0;\n \
    \       rec_s[lms_map[sorted_lms[0]]] = 0;\n        for (int i = 1; i < m; i++)\
    \ {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n            int\
    \ end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;\n            int end_r\
    \ = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;\n            bool same = true;\n\
    \            if (end_l - l != end_r - r) {\n                same = false;\n  \
    \          } else {\n                while (l < end_l) {\n                   \
    \ if (s[l] != s[r]) {\n                        break;\n                    }\n\
    \                    l++;\n                    r++;\n                }\n     \
    \           if (l == n || s[l] != s[r]) same = false;\n            }\n       \
    \     if (!same) rec_upper++;\n            rec_s[lms_map[sorted_lms[i]]] = rec_upper;\n\
    \        }\n\n        auto rec_sa =\n            sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s,\
    \ rec_upper);\n\n        for (int i = 0; i < m; i++) {\n            sorted_lms[i]\
    \ = lms[rec_sa[i]];\n        }\n        induce(sorted_lms);\n    }\n    return\
    \ sa;\n}\n\n}  // namespace internal\n\ninline std::vector<int> suffix_array(const\
    \ std::vector<int>& s, int upper) {\n    assert(0 <= upper);\n    for (int d :\
    \ s) {\n        assert(0 <= d && d <= upper);\n    }\n    auto sa = internal::sa_is(s,\
    \ upper);\n    return sa;\n}\n\ntemplate <class T>\nstd::vector<int> suffix_array(const\
    \ std::vector<T>& s) {\n    int n = int(s.size());\n    std::vector<int> idx(n);\n\
    \    iota(idx.begin(), idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int\
    \ l, int r) { return s[l] < s[r]; });\n    std::vector<int> s2(n);\n    int now\
    \ = 0;\n    for (int i = 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]])\
    \ now++;\n        s2[idx[i]] = now;\n    }\n    return internal::sa_is(s2, now);\n\
    }\n\ninline std::vector<int> suffix_array(const std::string& s) {\n    int n =\
    \ int(s.size());\n    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        s2[i] = s[i];\n    }\n    return internal::sa_is(s2, 255);\n}\n\n\
    // Reference:\n// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,\n// Linear-Time\
    \ Longest-Common-Prefix Computation in Suffix Arrays and Its\n// Applications\n\
    template <class T>\nstd::vector<int> lcp_array(const std::vector<T>& s,\n    \
    \                       const std::vector<int>& sa) {\n    int n = int(s.size());\n\
    \    assert(n >= 1);\n    std::vector<int> rnk(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        rnk[sa[i]] = i;\n    }\n    std::vector<int> lcp(n - 1);\n \
    \   int h = 0;\n    for (int i = 0; i < n; i++) {\n        if (h > 0) h--;\n \
    \       if (rnk[i] == 0) continue;\n        int j = sa[rnk[i] - 1];\n        for\
    \ (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i + h]) break;\n\
    \        }\n        lcp[rnk[i] - 1] = h;\n    }\n    return lcp;\n}\n\ninline\
    \ std::vector<int> lcp_array(const std::string& s, const std::vector<int>& sa)\
    \ {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int i =\
    \ 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return lcp_array(s2, sa);\n\
    }\n\n// Reference:\n// D. Gusfield,\n// Algorithms on Strings, Trees, and Sequences:\
    \ Computer Science and\n// Computational Biology\ntemplate <class T>\nstd::vector<int>\
    \ z_algorithm(const std::vector<T>& s) {\n    int n = int(s.size());\n    if (n\
    \ == 0) return {};\n    std::vector<int> z(n);\n    z[0] = 0;\n    for (int i\
    \ = 1, j = 0; i < n; i++) {\n        int& k = z[i];\n        k = (j + z[j] <=\
    \ i) ? 0 : std::min(j + z[j] - i, z[i - j]);\n        while (i + k < n && s[k]\
    \ == s[i + k]) k++;\n        if (j + z[j] < i + z[i]) j = i;\n    }\n    z[0]\
    \ = n;\n    return z;\n}\n\ninline std::vector<int> z_algorithm(const std::string&\
    \ s) {\n    int n = int(s.size());\n    std::vector<int> s2(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        s2[i] = s[i];\n    }\n    return z_algorithm(s2);\n\
    }\n\n}  // namespace e6nlaq\n#line 2 \"include/e6nlaq/twosat.hpp\"\n\n// This\
    \ file is a fork of AtCoder Library.\n\n#define E6NLAQ_TWOSAT_HPP\n\n#line 9 \"\
    include/e6nlaq/twosat.hpp\"\n\n#line 11 \"include/e6nlaq/twosat.hpp\"\n\nnamespace\
    \ e6nlaq {\n\n// Reference:\n// B. Aspvall, M. Plass, and R. Tarjan,\n// A Linear-Time\
    \ Algorithm for Testing the Truth of Certain Quantified Boolean\n// Formulas\n\
    struct two_sat {\n   public:\n    two_sat() : _n(0), scc(0) {}\n    explicit two_sat(int\
    \ n) : _n(n), _answer(n), scc(2 * n) {}\n\n    void add_clause(int i, bool f,\
    \ int j, bool g) {\n        assert(0 <= i && i < _n);\n        assert(0 <= j &&\
    \ j < _n);\n        scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));\n\
    \        scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));\n    }\n    bool\
    \ satisfiable() {\n        auto id = scc.scc_ids().second;\n        for (int i\
    \ = 0; i < _n; i++) {\n            if (id[2 * i] == id[2 * i + 1]) return false;\n\
    \            _answer[i] = id[2 * i] < id[2 * i + 1];\n        }\n        return\
    \ true;\n    }\n    std::vector<bool> answer() { return _answer; }\n\n   private:\n\
    \    int _n;\n    std::vector<bool> _answer;\n    internal::scc_graph scc;\n};\n\
    \n}  // namespace e6nlaq\n#line 13 \"include/e6nlaq/all.hpp\"\n"
  code: '#include "convolution.hpp"

    #include "dsu.hpp"

    #include "fenwicktree.hpp"

    #include "lazysegtree.hpp"

    #include "math.hpp"

    #include "maxflow.hpp"

    #include "mincostflow.hpp"

    #include "modint.hpp"

    #include "scc.hpp"

    #include "segtree.hpp"

    #include "string.hpp"

    #include "twosat.hpp"

    '
  dependsOn:
  - include/e6nlaq/convolution.hpp
  - include/e6nlaq/internal/bit.hpp
  - include/e6nlaq/modint.hpp
  - include/e6nlaq/internal/math.hpp
  - include/e6nlaq/internal/type_traits.hpp
  - include/e6nlaq/dsu.hpp
  - include/e6nlaq/fenwicktree.hpp
  - include/e6nlaq/lazysegtree.hpp
  - include/e6nlaq/math.hpp
  - include/e6nlaq/math/acl.hpp
  - include/e6nlaq/math/integer.hpp
  - include/e6nlaq/maxflow.hpp
  - include/e6nlaq/internal/queue.hpp
  - include/e6nlaq/mincostflow.hpp
  - include/e6nlaq/internal/csr.hpp
  - include/e6nlaq/scc.hpp
  - include/e6nlaq/internal/scc.hpp
  - include/e6nlaq/segtree.hpp
  - include/e6nlaq/string.hpp
  - include/e6nlaq/twosat.hpp
  isVerificationFile: false
  path: include/e6nlaq/all.hpp
  requiredBy: []
  timestamp: '2025-12-11 22:51:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/all.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/all.hpp
- /library/include/e6nlaq/all.hpp.html
title: include/e6nlaq/all.hpp
---
