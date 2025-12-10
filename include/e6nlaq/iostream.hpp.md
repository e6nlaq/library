---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/io.hpp
    title: "\u6539\u884C\u3092\u51FA\u529B\u3059\u308B"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
  bundledCode: "#line 2 \"include/e6nlaq/iostream.hpp\"\n\n#define E6NLAQ_IOSTREAM_HPP\n\
    \n#include <cassert>\n#include <iostream>\n#include <string>\n#include <vector>\n\
    \nnamespace e6nlaq {\n\n#ifdef __GNUC__\nnamespace {\n__int128_t parse(const std::string&\
    \ s) {\n    __int128_t ret = 0;\n    for (const char c : s) {\n        if ('0'\
    \ <= c && c <= '9') {\n            ret = 10 * ret + (c - '0');\n        }\n  \
    \  }\n\n    if (!s.empty() && s[0] == '-') {\n        ret = -ret;\n    }\n\n \
    \   return ret;\n}\n}  // namespace\n\n// https://kenkoooo.hatenablog.com/entry/2016/11/30/163533\n\
    inline std::ostream& operator<<(std::ostream& dest, __int128_t value) {\n    std::ostream::sentry\
    \ s(dest);\n    if (s) {\n        __uint128_t tmp = value < 0 ? -value : value;\n\
    \        char buffer[128];\n        char* d = std::end(buffer);\n        do {\n\
    \            --d;\n            *d = \"0123456789\"[tmp % 10];\n            tmp\
    \ /= 10;\n        } while (tmp != 0);\n        if (value < 0) {\n            --d;\n\
    \            *d = '-';\n        }\n        int len = std::end(buffer) - d;\n \
    \       if (dest.rdbuf()->sputn(d, len) != len) {\n            dest.setstate(std::ios_base::badbit);\n\
    \        }\n    }\n    return dest;\n}\n\ninline std::istream& operator>>(std::istream&\
    \ is, __int128_t& value) {\n    std::string tmp;\n    is >> tmp;\n\n    value\
    \ = parse(tmp);\n\n    return is;\n}\n#endif  // __GNUC__\n\ntemplate <typename\
    \ T>\ninline std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n\
    #if defined(LOCAL) && !defined(ALLOW_ZERO_VEC_CIN)\n    assert(v.size() != 0);\n\
    #endif\n    for (auto& elem : v) {\n        is >> elem;\n    }\n\n    return is;\n\
    }\n\n}  // namespace e6nlaq\n"
  code: "#pragma once\n\n#define E6NLAQ_IOSTREAM_HPP\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <string>\n#include <vector>\n\nnamespace e6nlaq {\n\n#ifdef\
    \ __GNUC__\nnamespace {\n__int128_t parse(const std::string& s) {\n    __int128_t\
    \ ret = 0;\n    for (const char c : s) {\n        if ('0' <= c && c <= '9') {\n\
    \            ret = 10 * ret + (c - '0');\n        }\n    }\n\n    if (!s.empty()\
    \ && s[0] == '-') {\n        ret = -ret;\n    }\n\n    return ret;\n}\n}  // namespace\n\
    \n// https://kenkoooo.hatenablog.com/entry/2016/11/30/163533\ninline std::ostream&\
    \ operator<<(std::ostream& dest, __int128_t value) {\n    std::ostream::sentry\
    \ s(dest);\n    if (s) {\n        __uint128_t tmp = value < 0 ? -value : value;\n\
    \        char buffer[128];\n        char* d = std::end(buffer);\n        do {\n\
    \            --d;\n            *d = \"0123456789\"[tmp % 10];\n            tmp\
    \ /= 10;\n        } while (tmp != 0);\n        if (value < 0) {\n            --d;\n\
    \            *d = '-';\n        }\n        int len = std::end(buffer) - d;\n \
    \       if (dest.rdbuf()->sputn(d, len) != len) {\n            dest.setstate(std::ios_base::badbit);\n\
    \        }\n    }\n    return dest;\n}\n\ninline std::istream& operator>>(std::istream&\
    \ is, __int128_t& value) {\n    std::string tmp;\n    is >> tmp;\n\n    value\
    \ = parse(tmp);\n\n    return is;\n}\n#endif  // __GNUC__\n\ntemplate <typename\
    \ T>\ninline std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n\
    #if defined(LOCAL) && !defined(ALLOW_ZERO_VEC_CIN)\n    assert(v.size() != 0);\n\
    #endif\n    for (auto& elem : v) {\n        is >> elem;\n    }\n\n    return is;\n\
    }\n\n}  // namespace e6nlaq\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/iostream.hpp
  requiredBy:
  - include/e6nlaq/io.hpp
  timestamp: '2025-12-11 00:03:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/iostream.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/iostream.hpp
- /library/include/e6nlaq/iostream.hpp.html
title: include/e6nlaq/iostream.hpp
---
