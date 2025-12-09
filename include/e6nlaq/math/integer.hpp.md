---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math.hpp
    title: include/e6nlaq/math.hpp
  - icon: ':warning:'
    path: test/unit/math/integer/digits/digits-int.cpp
    title: test/unit/math/integer/digits/digits-int.cpp
  - icon: ':warning:'
    path: test/unit/math/integer/digits/digits-ll.cpp
    title: test/unit/math/integer/digits/digits-ll.cpp
  - icon: ':warning:'
    path: test/unit/math/integer/div_ceil/div_ceil.cpp
    title: test/unit/math/integer/div_ceil/div_ceil.cpp
  - icon: ':warning:'
    path: test/unit/math/integer/fact/fact.cpp
    title: test/unit/math/integer/fact/fact.cpp
  - icon: ':warning:'
    path: test/unit/math/integer/isqrt/isqrt.cpp
    title: test/unit/math/integer/isqrt/isqrt.cpp
  - icon: ':warning:'
    path: test/unit/math/integer/mmod/mmod.cpp
    title: test/unit/math/integer/mmod/mmod.cpp
  - icon: ':warning:'
    path: test/unit/math/integer/pow_ll/pow_ll.cpp
    title: test/unit/math/integer/pow_ll/pow_ll.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\
      \u7B97\u3057\u307E\u3059"
    links:
    - https://qiita.com/happyisland44/items/8e4feb6805eecee29f83
    - https://x.com/ngtkana/status/1980504937290428680
  bundledCode: "#line 1 \"include/e6nlaq/math/integer.hpp\"\n\n\n\n#include <bit>\n\
    #include <cassert>\n#include <concepts>\n#include <cstdlib>\n#include <limits>\n\
    #include <stdexcept>\n\nnamespace e6nlaq {\n\n/**\n * @brief \u7B26\u53F7\u306A\
    \u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\u3057\u307E\u3059\n * @tparam\
    \ T \u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\n * @param n \u6841\u6570\u3092\
    \u8A08\u7B97\u3059\u308B\u6574\u6570\n * @return int 10\u9032\u6570\u8868\u8A18\
    \u3067\u306E\u6841\u6570\n * @note \u8A08\u7B97\u91CF: O(1)\n * @see https://x.com/ngtkana/status/1980504937290428680\n\
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
    \ + 1ULL) / 2ULL);\n    }\n}\n\n}  // namespace e6nlaq\n\n\n"
  code: "#ifndef E6NLAQ_MATH_INTEGER_HPP\n#define E6NLAQ_MATH_INTEGER_HPP 1\n\n#include\
    \ <bit>\n#include <cassert>\n#include <concepts>\n#include <cstdlib>\n#include\
    \ <limits>\n#include <stdexcept>\n\nnamespace e6nlaq {\n\n/**\n * @brief \u7B26\
    \u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\u3057\u307E\
    \u3059\n * @tparam T \u7B26\u53F7\u306A\u3057\u6574\u6570\u578B\n * @param n \u6841\
    \u6570\u3092\u8A08\u7B97\u3059\u308B\u6574\u6570\n * @return int 10\u9032\u6570\
    \u8868\u8A18\u3067\u306E\u6841\u6570\n * @note \u8A08\u7B97\u91CF: O(1)\n * @see\
    \ https://x.com/ngtkana/status/1980504937290428680\n */\ntemplate <std::unsigned_integral\
    \ T>\nint digits(T n) {\n    using UnsignedT = std::make_unsigned_t<T>;\n    UnsignedT\
    \ x;\n    if (n < 0)\n        x = static_cast<UnsignedT>(-n);\n    else\n    \
    \    x = n;\n    x |= 1;\n\n    if constexpr (sizeof(UnsignedT) <= 4) {  // 32bit\
    \ or less\n        static const int lower_bound_table[] = {9, 9, 9, 8, 8, 8, 7,\
    \ 7, 7, 6, 6, 6, 6, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0};\n\
    \        static const unsigned int pow[] = {1, 10, 100, 1000, 10000, 100000, 1000000,\
    \ 10000000, 100000000, 1000000000};\n\n        int lower_bound = lower_bound_table[std::countl_zero(static_cast<unsigned\
    \ int>(x))];\n        return lower_bound + (pow[lower_bound] <= x);\n    } else\
    \ {  // 64bit\n        static const int lower_bound_table[] = {\n            19,\
    \ 18, 18, 18, 18, 17, 17, 17, 16, 16, 16, 16, 15, 15, 15, 14, 14, 14, 13, 13,\
    \ 13, 13,\n            12, 12, 12, 11, 11, 11, 11, 10, 10, 10, 9, 9, 9, 9, 8,\
    \ 8, 8, 7, 7, 7, 7, 6, 6, 6,\n            5, 5, 5, 5, 4, 4, 4, 3, 3, 3, 3, 2,\
    \ 2, 2, 1, 1, 1, 0};\n        static const unsigned long long pow[] = {\n    \
    \        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000,\n\
    \            10000000000ULL, 100000000000ULL, 1000000000000ULL, 10000000000000ULL,\n\
    \            100000000000000ULL, 1000000000000000ULL, 10000000000000000ULL,\n\
    \            100000000000000000ULL, 1000000000000000000ULL, 10000000000000000000ULL};\n\
    \n        int lower_bound = lower_bound_table[std::countl_zero(x)];\n        return\
    \ lower_bound + (pow[lower_bound] <= x);\n    }\n}\n\n/**\n * @brief \u7B26\u53F7\
    \u4ED8\u304D\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\u3057\u307E\u3059\
    \n * @tparam T \u7B26\u53F7\u4ED8\u304D\u6574\u6570\u578B\n * @param n \u6841\u6570\
    \u3092\u8A08\u7B97\u3059\u308B\u6574\u6570\n * @return int 10\u9032\u6570\u8868\
    \u8A18\u3067\u306E\u6841\u6570\uFF08\u7B26\u53F7\u306F\u9664\u304F\uFF09\n * @note\
    \ \u8A08\u7B97\u91CF: O(1)\n */\ntemplate <std::signed_integral T>\nint digits(T\
    \ n) {\n    return digits(static_cast<std::make_unsigned_t<T>>(n < 0 ? -n : n));\n\
    }\n\n/**\n * @brief \u975E\u8CA0\u6574\u6570\u306E\u5E73\u65B9\u6839\u306E\u6574\
    \u6570\u90E8\u3092\u8A08\u7B97\u3057\u307E\u3059\uFF08\u5207\u308A\u6368\u3066\
    \uFF09\n * @tparam T \u6574\u6570\u578B\n * @param n \u975E\u8CA0\u6574\u6570\uFF08\
    n >= 0\uFF09\n * @return T floor(\u221An) \u306E\u5024\n * @note \u8A08\u7B97\u91CF\
    : O(log log N) / \u5B9F\u8CEAO(1)\n * @note \u30CB\u30E5\u30FC\u30C8\u30F3\u6CD5\
    \u3092\u4F7F\u7528\u3057\u3066\u5B9F\u88C5\u3055\u308C\u3066\u3044\u307E\u3059\
    \n * @throw std::invalid_argument n\u304C\u8CA0\u306E\u5834\u5408\u306B\u30B9\u30ED\
    \u30FC\u3055\u308C\u307E\u3059\n */\ntemplate <std::integral T>\nT isqrt(T n)\
    \ {\n    if (n < 0) {\n        throw std::invalid_argument(\"isqrt: n must be\
    \ non-negative\");\n    }\n    if (n == 0) {\n        return 0;\n    }\n\n   \
    \ using UnsignedT = std::make_unsigned_t<T>;\n    UnsignedT n_unsigned = static_cast<UnsignedT>(n);\n\
    \n    int n_bits = std::bit_width(n_unsigned);\n\n    T x;\n    int shift = (n_bits\
    \ + 1) / 2;\n\n    constexpr int t_digits = std::numeric_limits<T>::digits;\n\n\
    \    if (shift >= t_digits) {\n        x = static_cast<T>(1) << (t_digits - 1);\n\
    \    } else {\n        x = static_cast<T>(1) << shift;\n    }\n\n    T y = (x\
    \ + n / x) / 2;\n\n    while (y < x) {\n        x = y;\n        y = (x + n / x)\
    \ / 2;\n    }\n\n    return x;\n}\n\n/**\n * @brief \u4E0E\u3048\u3089\u308C\u305F\
    \u6574\u6570\u304C\u5E73\u65B9\u6570\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\
    \u3057\u307E\u3059\n * @tparam T \u6574\u6570\u578B\n * @param N \u5224\u5B9A\u3059\
    \u308B\u6574\u6570\n * @return bool N\u304C\u5E73\u65B9\u6570\u306E\u5834\u5408\
    \u306Ftrue\u3001\u305D\u3046\u3067\u306A\u3044\u5834\u5408\u306Ffalse\n * @note\
    \ \u8A08\u7B97\u91CF: isqrt(N) \u306B\u4F9D\u5B58\n * @note \u4F8B\u5916\u3092\
    \u6295\u3052\u306A\u3044\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u3066\u3044\
    \u307E\u3059\n */\ntemplate <std::integral T>\ninline bool is_square(const T N)\
    \ noexcept {\n    T r = isqrt(N);  // \u5207\u308A\u6368\u3066\u3057\u305F\u5E73\
    \u65B9\u6839\n    return (r * r) == N;\n}\n\n/**\n * @brief \u5207\u308A\u4E0A\
    \u3052(\u7121\u9650\u5927\u65B9\u5411)\u9664\u7B97\u3092\u884C\u3044\u307E\u3059\
    \n * @tparam T \u6574\u6570\u578B\n * @param a \u88AB\u9664\u6570\n * @param b\
    \ 0\u3067\u306A\u3044\u9664\u6570 (b != 0)\n * @return T ceil(a / b) \u306E\u5024\
    \uFF08\u6B63\u306E\u7121\u9650\u5927\u65B9\u5411\u306B\u4E38\u3081\uFF09\n * @throw\
    \ std::invalid_argument b\u304C0\u306E\u5834\u5408\n * @note \u8A08\u7B97\u91CF\
    : O(1)\n * @note a \u3084 b \u304C\u8CA0\u306E\u5834\u5408\u3082\u6B63\u306E\u7121\
    \u9650\u5927\u65B9\u5411\u306B\u4E38\u3081\u307E\u3059\n */\ntemplate <std::integral\
    \ T>\ninline constexpr T div_ceil(T a, T b) {\n    if (b == 0) {\n        throw\
    \ std::invalid_argument(\"div_ceil: division by zero\");\n    }\n\n    T res =\
    \ a / b;\n    T rem = a % b;\n\n    // \u5270\u4F59\u304C\u3042\u308A\u3001\u304B\
    \u3064a\u3068b\u304C\u540C\u7B26\u53F7\uFF08\u7D50\u679C\u304C\u6B63\uFF09\u306E\
    \u5834\u5408\u306B\u5207\u308A\u4E0A\u3052\u308B\n    if (rem != 0 && (a > 0 ==\
    \ b > 0)) {\n        res++;\n    }\n    return res;\n}\n\n/**\n * @brief \u6570\
    \u5B66\u7684\u306A\u610F\u5473\u3067\u306E\u5270\u4F59\u3092\u8A08\u7B97\u3057\
    \u307E\u3059\uFF08\u8CA0\u306E\u6570\u306B\u3082\u5BFE\u5FDC\uFF09\n * @tparam\
    \ T \u6574\u6570\u578B\n * @param x \u88AB\u9664\u6570\n * @param m 0\u3067\u306A\
    \u3044\u9664\u6570 (m != 0)\n * @return T x mod m \u306E\u5024\uFF080\u4EE5\u4E0A\
    m\u672A\u6E80\uFF09\n * @note \u8A08\u7B97\u91CF: O(1)\n * @note \u5E38\u306B\
    0\u4EE5\u4E0Am\u672A\u6E80\u306E\u5024\u3092\u8FD4\u3057\u307E\u3059\n * @see\
    \ https://qiita.com/happyisland44/items/8e4feb6805eecee29f83\n */\ntemplate <std::integral\
    \ T>\ninline constexpr T mmod(T x, T m) {\n    T M = m;\n    if constexpr (std::is_signed_v<T>)\
    \ {\n        if (m < 0) {\n            if (m == std::numeric_limits<T>::min())\
    \ {\n                throw std::domain_error(\"mmod: m cannot be the minimum value\
    \ of its type\");\n            }\n            M = -m;\n        }\n    }\n    T\
    \ r = x % M;\n    return r < 0 ? r + M : r;\n}\n\n/**\n * @brief \u975E\u8CA0\u6574\
    \u6570\u306E\u968E\u4E57\u3092\u8A08\u7B97\u3057\u307E\u3059\n * @param n \u975E\
    \u8CA0\u6574\u6570 (n >= 0)\n * @return long long n! \u306E\u5024\n * @note \u8A08\
    \u7B97\u91CF: O(n)\n * @note n\u304C0\u306E\u5834\u5408\u306F1\u3092\u8FD4\u3057\
    \u307E\u3059\n * @warning n\u304C\u5927\u304D\u3044\u3068\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3059\u308B\u53EF\u80FD\u6027\u304C\u3042\u308A\u307E\u3059\
    \uFF0820! = 2,432,902,008,176,640,000\uFF09\n */\ninline constexpr unsigned long\
    \ long fact(const unsigned long long n) {\n    unsigned long long res = 1;\n \
    \   for (unsigned long long i = 2; i <= n; i++) {\n        res *= i;\n    }\n\
    \    return res;\n}\n\n/**\n * @brief \u6574\u6570\u306E\u3079\u304D\u4E57\u3092\
    \u8A08\u7B97\u3057\u307E\u3059 (x^n)\n * @param x \u5E95\n * @param n \u6307\u6570\
    \n * @return unsigned long long x^n \u306E\u5024\n * @note \u8A08\u7B97\u91CF\
    : O(log n)\n * @note \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\u3092\u4F7F\u7528\
    \u3057\u3066\u5B9F\u88C5\u3055\u308C\u3066\u3044\u307E\u3059\n * @note 0^0=1\u3067\
    \u3059\n * @warning \u7D50\u679C\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3059\u308B\u53EF\u80FD\u6027\u304C\u3042\u308A\u307E\u3059\n */\ninline unsigned\
    \ long long pow_ll(unsigned long long x, unsigned long long n) noexcept {\n  \
    \  unsigned long long ret = 1ULL;\n    while (n > 0) {\n        if (n & 1)\n \
    \           ret *= x;\n        x *= x;\n        n >>= 1;\n    }\n\n    return\
    \ ret;\n}\n\n/**\n * @brief 1\u304B\u3089n\u307E\u3067\u306E\u7DCF\u548C\u3092\
    \u8A08\u7B97\u3057\u307E\u3059\n * @param n \u975E\u8CA0\u6574\u6570\n * @return\
    \ unsigned long long 1 + 2 + ... + n \u306E\u5024\n * @note \u8A08\u7B97\u91CF\
    : O(1)\n * @note \u516C\u5F0F: n(n+1)/2 \u3092\u4F7F\u7528\u3057\u3066\u5B9F\u88C5\
    \u3055\u308C\u3066\u3044\u307E\u3059\n * @warning n\u304C\u5927\u304D\u3044\u3068\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3059\u308B\u53EF\u80FD\u6027\u304C\
    \u3042\u308A\u307E\u3059\n */\ninline unsigned long long sum_to_n(const unsigned\
    \ long long n) noexcept {\n    if (n % 2 == 0) {\n        return (n / 2ULL) *\
    \ (n + 1ULL);\n    } else {\n        return n * ((n + 1ULL) / 2ULL);\n    }\n\
    }\n\n}  // namespace e6nlaq\n\n#endif  // E6NLAQ_MATH_INTEGER_HPP"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/math/integer.hpp
  requiredBy:
  - test/unit/math/integer/isqrt/isqrt.cpp
  - test/unit/math/integer/pow_ll/pow_ll.cpp
  - test/unit/math/integer/fact/fact.cpp
  - test/unit/math/integer/div_ceil/div_ceil.cpp
  - test/unit/math/integer/mmod/mmod.cpp
  - test/unit/math/integer/digits/digits-int.cpp
  - test/unit/math/integer/digits/digits-ll.cpp
  - include/e6nlaq/math.hpp
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-09 15:09:37+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/math/integer.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/math/integer.hpp
- /library/include/e6nlaq/math/integer.hpp.html
title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\u3057\
  \u307E\u3059"
---
