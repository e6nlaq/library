---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/imos.hpp
    title: include/e6nlaq/imos.hpp
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/imos/imos.hpp
    title: "imos\u6CD5\u3092\u5B9F\u88C5\u3057\u305F\u30AF\u30E9\u30B9"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/imos.test.cpp
    title: test/verify/imos.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"include/e6nlaq/concepts.hpp\"\n\n#define E6NLAQ_CONCEPTS_HPP\n\
    \nnamespace e6nlaq {\ntemplate <typename T>\nconcept add_assignable = requires(T\
    \ a, T b) {\n    { a += b };\n};\n\ntemplate <typename T>\nconcept subtract_assignable\
    \ = requires(T a, T b) {\n    { a -= b };\n};\n}  // namespace e6nlaq\n"
  code: "#pragma once\n\n#define E6NLAQ_CONCEPTS_HPP\n\nnamespace e6nlaq {\ntemplate\
    \ <typename T>\nconcept add_assignable = requires(T a, T b) {\n    { a += b };\n\
    };\n\ntemplate <typename T>\nconcept subtract_assignable = requires(T a, T b)\
    \ {\n    { a -= b };\n};\n}  // namespace e6nlaq"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/concepts.hpp
  requiredBy:
  - include/e6nlaq/imos.hpp
  - include/e6nlaq/imos/imos.hpp
  timestamp: '2025-12-11 22:55:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/imos.test.cpp
documentation_of: include/e6nlaq/concepts.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/concepts.hpp
- /library/include/e6nlaq/concepts.hpp.html
title: include/e6nlaq/concepts.hpp
---
