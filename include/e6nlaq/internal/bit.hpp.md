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
    path: include/e6nlaq/lazysegtree.hpp
    title: include/e6nlaq/lazysegtree.hpp
  - icon: ':warning:'
    path: include/e6nlaq/segtree.hpp
    title: include/e6nlaq/segtree.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/e6nlaq/internal/bit.hpp\"\n// This file is a fork\
    \ of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_BITOP_HPP\n#define E6NLAQ_INTERNAL_BITOP_HPP\
    \ 1\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\n#if __cplusplus >= 202002L\n\
    #include <bit>\n#endif\n\nnamespace e6nlaq {\n\nnamespace internal {\n\n#if __cplusplus\
    \ >= 202002L\n\nusing std::bit_ceil;\n\n#else\n\n// @return same with std::bit::bit_ceil\n\
    unsigned int bit_ceil(unsigned int n) {\n    unsigned int x = 1;\n    while (x\
    \ < (unsigned int)(n)) x *= 2;\n    return x;\n}\n\n#endif\n\n// @param n `1 <=\
    \ n`\n// @return same with std::bit::countr_zero\nint countr_zero(unsigned int\
    \ n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n//\
    \ @param n `1 <= n`\n// @return same with std::bit::countr_zero\nconstexpr int\
    \ countr_zero_constexpr(unsigned int n) {\n    int x = 0;\n    while (!(n & (1\
    \ << x))) x++;\n    return x;\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_BITOP_HPP\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_BITOP_HPP\n\
    #define E6NLAQ_INTERNAL_BITOP_HPP 1\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
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
    \ namespace e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_BITOP_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/internal/bit.hpp
  requiredBy:
  - include/e6nlaq/segtree.hpp
  - include/e6nlaq/lazysegtree.hpp
  - include/e6nlaq/convolution.hpp
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-09 13:48:01+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/internal/bit.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/internal/bit.hpp
- /library/include/e6nlaq/internal/bit.hpp.html
title: include/e6nlaq/internal/bit.hpp
---
