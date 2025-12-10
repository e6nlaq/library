---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  - icon: ':warning:'
    path: include/e6nlaq/convolution.hpp
    title: include/e6nlaq/convolution.hpp
  - icon: ':warning:'
    path: include/e6nlaq/fenwicktree.hpp
    title: include/e6nlaq/fenwicktree.hpp
  - icon: ':warning:'
    path: include/e6nlaq/modint.hpp
    title: include/e6nlaq/modint.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/e6nlaq/internal/type_traits.hpp\"\n// This file\
    \ is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_TYPE_TRAITS_HPP\n#define\
    \ E6NLAQ_INTERNAL_TYPE_TRAITS_HPP 1\n\n#include <cassert>\n#include <type_traits>\n\
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
    }  // namespace internal\n\n}  // namespace e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_TYPE_TRAITS_HPP\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_TYPE_TRAITS_HPP\n\
    #define E6NLAQ_INTERNAL_TYPE_TRAITS_HPP 1\n\n#include <cassert>\n#include <type_traits>\n\
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
    }  // namespace internal\n\n}  // namespace e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_TYPE_TRAITS_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/internal/type_traits.hpp
  requiredBy:
  - include/e6nlaq/fenwicktree.hpp
  - include/e6nlaq/convolution.hpp
  - include/e6nlaq/modint.hpp
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-10 23:21:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/internal/type_traits.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/internal/type_traits.hpp
- /library/include/e6nlaq/internal/type_traits.hpp.html
title: include/e6nlaq/internal/type_traits.hpp
---
