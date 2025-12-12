---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/type_traits.hpp
    title: include/e6nlaq/internal/type_traits.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Fenwick_tree
  bundledCode: "#line 2 \"include/e6nlaq/fenwicktree.hpp\"\n\n// This file is a fork\
    \ of AtCoder Library.\n\n#define E6NLAQ_FENWICKTREE_HPP\n\n#include <cassert>\n\
    #include <vector>\n\n#line 2 \"include/e6nlaq/internal/type_traits.hpp\"\n\n//\
    \ This file is a fork of AtCoder Library.\n\n#define E6NLAQ_INTERNAL_TYPE_TRAITS_HPP\n\
    \n#line 8 \"include/e6nlaq/internal/type_traits.hpp\"\n#include <type_traits>\n\
    \nnamespace e6nlaq {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class\
    \ T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
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
    }  // namespace internal\n\n}  // namespace e6nlaq\n#line 11 \"include/e6nlaq/fenwicktree.hpp\"\
    \n\nnamespace e6nlaq {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T>\nstruct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n   public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n)\
    \ : _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n   private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int\
    \ r) {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ e6nlaq\n"
  code: "#pragma once\n\n// This file is a fork of AtCoder Library.\n\n#define E6NLAQ_FENWICKTREE_HPP\n\
    \n#include <cassert>\n#include <vector>\n\n#include \"internal/type_traits.hpp\"\
    \n\nnamespace e6nlaq {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T>\nstruct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n   public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n)\
    \ : _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p &&\
    \ p < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n   private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int\
    \ r) {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ e6nlaq\n"
  dependsOn:
  - include/e6nlaq/internal/type_traits.hpp
  isVerificationFile: false
  path: include/e6nlaq/fenwicktree.hpp
  requiredBy:
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-12 17:20:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/fenwicktree.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/fenwicktree.hpp
- /library/include/e6nlaq/fenwicktree.hpp.html
title: include/e6nlaq/fenwicktree.hpp
---
