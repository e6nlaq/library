---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/iostream.hpp
    title: include/e6nlaq/iostream.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6539\u884C\u3092\u51FA\u529B\u3059\u308B"
    links: []
  bundledCode: "#line 2 \"include/e6nlaq/io.hpp\"\n\n#define E6NLAQ_IO_HPP\n\n#include\
    \ <concepts>\n#include <iostream>\n\n#line 2 \"include/e6nlaq/iostream.hpp\"\n\
    \n#define E6NLAQ_IOSTREAM_HPP\n\n#include <cassert>\n#line 7 \"include/e6nlaq/iostream.hpp\"\
    \n#include <string>\n#include <vector>\n\nnamespace e6nlaq {\n\n#ifdef __GNUC__\n\
    namespace {\n__int128_t parse(const std::string& s) {\n    __int128_t ret = 0;\n\
    \    for (const char c : s) {\n        if ('0' <= c && c <= '9') {\n         \
    \   ret = 10 * ret + (c - '0');\n        }\n    }\n\n    if (!s.empty() && s[0]\
    \ == '-') {\n        ret = -ret;\n    }\n\n    return ret;\n}\n}  // namespace\n\
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
    }\n\n}  // namespace e6nlaq\n#line 9 \"include/e6nlaq/io.hpp\"\n\nnamespace e6nlaq\
    \ {\n/**\n * @brief \u6539\u884C\u3092\u51FA\u529B\u3059\u308B\n */\ninline void\
    \ co() {\n#ifdef USE_ENDL\n    std::cout << std::endl;\n#else\n    std::cout <<\
    \ \"\\n\";\n#endif\n}\n\n/**\n * @brief \u53EF\u5909\u9577\u5F15\u6570\u3067\u4E0E\
    \u3048\u3089\u308C\u305F\u5024\u3092\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\
    \u529B\u3057\u3001\u6700\u5F8C\u306B\u6539\u884C\u3059\u308B\n * @tparam Head\
    \ \u6700\u521D\u306E\u5F15\u6570\u306E\u578B\n * @tparam Tail \u6B8B\u308A\u306E\
    \u5F15\u6570\u306E\u578B\u30D1\u30C3\u30AF\n * @param head \u6700\u521D\u306E\u5F15\
    \u6570\n * @param tail \u6B8B\u308A\u306E\u5F15\u6570\n */\ntemplate <typename\
    \ Head, typename... Tail>\ninline void co(Head head, Tail... tail) {\n    std::cout\
    \ << head;\n\n    if constexpr (sizeof...(tail) > 0) {\n        std::cout << \"\
    \ \";\n    }\n\n    co(tail...);\n}\n\n/**\n * @brief \u771F\u507D\u5024\u306B\
    \u5FDC\u3058\u3066 \"YES\" \u307E\u305F\u306F \"NO\" \u3092\u5927\u6587\u5B57\u3067\
    \u51FA\u529B\u3059\u308B\n * @tparam T bool\u306B\u5909\u63DB\u53EF\u80FD\u306A\
    \u578B\n * @param b \u771F\u507D\u5024\n */\ntemplate <typename T>\n    requires\
    \ std::convertible_to<T, bool>\ninline void YESNO(T b) {\n    co(b ? \"YES\" :\
    \ \"NO\");\n}\n\n/**\n * @brief \u771F\u507D\u5024\u306B\u5FDC\u3058\u3066 \"\
    yes\" \u307E\u305F\u306F \"no\" \u3092\u5C0F\u6587\u5B57\u3067\u51FA\u529B\u3059\
    \u308B\n * @tparam T bool\u306B\u5909\u63DB\u53EF\u80FD\u306A\u578B\n * @param\
    \ b \u771F\u507D\u5024\n */\ntemplate <typename T>\n    requires std::convertible_to<T,\
    \ bool>\ninline void yesno(T b) {\n    co(b ? \"yes\" : \"no\");\n}\n\n/**\n *\
    \ @brief \u771F\u507D\u5024\u306B\u5FDC\u3058\u3066 \"Yes\" \u307E\u305F\u306F\
    \ \"No\" \u3092\u5148\u982D\u5927\u6587\u5B57\u3067\u51FA\u529B\u3059\u308B\n\
    \ * @tparam T bool\u306B\u5909\u63DB\u53EF\u80FD\u306A\u578B\n * @param b \u771F\
    \u507D\u5024\n */\ntemplate <typename T>\n    requires std::convertible_to<T,\
    \ bool>\ninline void YesNo(T b) {\n    co(b ? \"Yes\" : \"No\");\n}\n\n/**\n *\
    \ @brief \u6761\u4EF6\u306B\u5FDC\u3058\u3066\u7570\u306A\u308B\u30E1\u30C3\u30BB\
    \u30FC\u30B8\u3092\u51FA\u529B\u3059\u308B\n * @tparam T bool\u306B\u5909\u63DB\
    \u53EF\u80FD\u306A\u578B\n * @tparam tr \u771F\u306E\u5834\u5408\u306B\u51FA\u529B\
    \u3059\u308B\u5024\u306E\u578B\n * @tparam fal \u507D\u306E\u5834\u5408\u306B\u51FA\
    \u529B\u3059\u308B\u5024\u306E\u578B\n * @param b \u6761\u4EF6\n * @param tru\
    \ \u771F\u306E\u5834\u5408\u306B\u51FA\u529B\u3059\u308B\u5024\n * @param fals\
    \ \u507D\u306E\u5834\u5408\u306B\u51FA\u529B\u3059\u308B\u5024\n */\ntemplate\
    \ <typename T, typename tr, typename fal>\n    requires std::convertible_to<T,\
    \ bool>\ninline void outif(T b, tr tru, fal fals) {\n    co(b ? tru : fals);\n\
    }\n\n/**\n * @brief \u6A19\u6E96\u5165\u51FA\u529B\u306E\u9AD8\u901F\u5316\u3092\
    \u884C\u3046\n * @note C++\u306E\u6A19\u6E96\u5165\u51FA\u529B\u3092\u9AD8\u901F\
    \u5316\u3059\u308B\u305F\u3081\u306E\u8A2D\u5B9A\u3092\u884C\u3046\n */\ninline\
    \ void fastio() noexcept {\n    std::cin.tie(nullptr);\n    std::ios::sync_with_stdio(false);\n\
    }\n\n}  // namespace e6nlaq\n"
  code: "#pragma once\n\n#define E6NLAQ_IO_HPP\n\n#include <concepts>\n#include <iostream>\n\
    \n#include \"iostream.hpp\"\n\nnamespace e6nlaq {\n/**\n * @brief \u6539\u884C\
    \u3092\u51FA\u529B\u3059\u308B\n */\ninline void co() {\n#ifdef USE_ENDL\n   \
    \ std::cout << std::endl;\n#else\n    std::cout << \"\\n\";\n#endif\n}\n\n/**\n\
    \ * @brief \u53EF\u5909\u9577\u5F15\u6570\u3067\u4E0E\u3048\u3089\u308C\u305F\u5024\
    \u3092\u7A7A\u767D\u533A\u5207\u308A\u3067\u51FA\u529B\u3057\u3001\u6700\u5F8C\
    \u306B\u6539\u884C\u3059\u308B\n * @tparam Head \u6700\u521D\u306E\u5F15\u6570\
    \u306E\u578B\n * @tparam Tail \u6B8B\u308A\u306E\u5F15\u6570\u306E\u578B\u30D1\
    \u30C3\u30AF\n * @param head \u6700\u521D\u306E\u5F15\u6570\n * @param tail \u6B8B\
    \u308A\u306E\u5F15\u6570\n */\ntemplate <typename Head, typename... Tail>\ninline\
    \ void co(Head head, Tail... tail) {\n    std::cout << head;\n\n    if constexpr\
    \ (sizeof...(tail) > 0) {\n        std::cout << \" \";\n    }\n\n    co(tail...);\n\
    }\n\n/**\n * @brief \u771F\u507D\u5024\u306B\u5FDC\u3058\u3066 \"YES\" \u307E\u305F\
    \u306F \"NO\" \u3092\u5927\u6587\u5B57\u3067\u51FA\u529B\u3059\u308B\n * @tparam\
    \ T bool\u306B\u5909\u63DB\u53EF\u80FD\u306A\u578B\n * @param b \u771F\u507D\u5024\
    \n */\ntemplate <typename T>\n    requires std::convertible_to<T, bool>\ninline\
    \ void YESNO(T b) {\n    co(b ? \"YES\" : \"NO\");\n}\n\n/**\n * @brief \u771F\
    \u507D\u5024\u306B\u5FDC\u3058\u3066 \"yes\" \u307E\u305F\u306F \"no\" \u3092\u5C0F\
    \u6587\u5B57\u3067\u51FA\u529B\u3059\u308B\n * @tparam T bool\u306B\u5909\u63DB\
    \u53EF\u80FD\u306A\u578B\n * @param b \u771F\u507D\u5024\n */\ntemplate <typename\
    \ T>\n    requires std::convertible_to<T, bool>\ninline void yesno(T b) {\n  \
    \  co(b ? \"yes\" : \"no\");\n}\n\n/**\n * @brief \u771F\u507D\u5024\u306B\u5FDC\
    \u3058\u3066 \"Yes\" \u307E\u305F\u306F \"No\" \u3092\u5148\u982D\u5927\u6587\u5B57\
    \u3067\u51FA\u529B\u3059\u308B\n * @tparam T bool\u306B\u5909\u63DB\u53EF\u80FD\
    \u306A\u578B\n * @param b \u771F\u507D\u5024\n */\ntemplate <typename T>\n   \
    \ requires std::convertible_to<T, bool>\ninline void YesNo(T b) {\n    co(b ?\
    \ \"Yes\" : \"No\");\n}\n\n/**\n * @brief \u6761\u4EF6\u306B\u5FDC\u3058\u3066\
    \u7570\u306A\u308B\u30E1\u30C3\u30BB\u30FC\u30B8\u3092\u51FA\u529B\u3059\u308B\
    \n * @tparam T bool\u306B\u5909\u63DB\u53EF\u80FD\u306A\u578B\n * @tparam tr \u771F\
    \u306E\u5834\u5408\u306B\u51FA\u529B\u3059\u308B\u5024\u306E\u578B\n * @tparam\
    \ fal \u507D\u306E\u5834\u5408\u306B\u51FA\u529B\u3059\u308B\u5024\u306E\u578B\
    \n * @param b \u6761\u4EF6\n * @param tru \u771F\u306E\u5834\u5408\u306B\u51FA\
    \u529B\u3059\u308B\u5024\n * @param fals \u507D\u306E\u5834\u5408\u306B\u51FA\u529B\
    \u3059\u308B\u5024\n */\ntemplate <typename T, typename tr, typename fal>\n  \
    \  requires std::convertible_to<T, bool>\ninline void outif(T b, tr tru, fal fals)\
    \ {\n    co(b ? tru : fals);\n}\n\n/**\n * @brief \u6A19\u6E96\u5165\u51FA\u529B\
    \u306E\u9AD8\u901F\u5316\u3092\u884C\u3046\n * @note C++\u306E\u6A19\u6E96\u5165\
    \u51FA\u529B\u3092\u9AD8\u901F\u5316\u3059\u308B\u305F\u3081\u306E\u8A2D\u5B9A\
    \u3092\u884C\u3046\n */\ninline void fastio() noexcept {\n    std::cin.tie(nullptr);\n\
    \    std::ios::sync_with_stdio(false);\n}\n\n}  // namespace e6nlaq\n"
  dependsOn:
  - include/e6nlaq/iostream.hpp
  isVerificationFile: false
  path: include/e6nlaq/io.hpp
  requiredBy: []
  timestamp: '2025-12-11 22:51:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/io.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/io.hpp
- /library/include/e6nlaq/io.hpp.html
title: "\u6539\u884C\u3092\u51FA\u529B\u3059\u308B"
---
