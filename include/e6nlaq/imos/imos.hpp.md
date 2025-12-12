---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/concepts.hpp
    title: include/e6nlaq/concepts.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: include/e6nlaq/imos.hpp
    title: include/e6nlaq/imos.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/verify/imos.test.cpp
    title: test/verify/imos.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "imos\u6CD5\u3092\u5B9F\u88C5\u3057\u305F\u30AF\u30E9\u30B9"
    links: []
  bundledCode: "#line 2 \"include/e6nlaq/imos/imos.hpp\"\n\n#define E6NLAQ_IMOS_IMOS_HPP\n\
    \n#include <stdexcept>\n#include <type_traits>\n#include <vector>\n\n#line 2 \"\
    include/e6nlaq/concepts.hpp\"\n\n#define E6NLAQ_CONCEPTS_HPP\n\nnamespace e6nlaq\
    \ {\ntemplate <typename T>\nconcept add_assignable = requires(T a, T b) {\n  \
    \  { a += b };\n};\n\ntemplate <typename T>\nconcept subtract_assignable = requires(T\
    \ a, T b) {\n    { a -= b };\n};\n}  // namespace e6nlaq\n#line 10 \"include/e6nlaq/imos/imos.hpp\"\
    \n\nnamespace e6nlaq {\n\n/**\n * @brief imos\u6CD5\u3092\u5B9F\u88C5\u3057\u305F\
    \u30AF\u30E9\u30B9\n * @tparam T \u7D2F\u7A4D\u548C\u306E\u578B\n */\ntemplate\
    \ <typename T>\n    requires add_assignable<T> && subtract_assignable<T>\nclass\
    \ imos {\n   private:\n    std::vector<T> dat;\n\n   public:\n    imos() : dat(0)\
    \ {};\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n \
    \    * @param n \u914D\u5217\u306E\u30B5\u30A4\u30BA\n     * @param init \u521D\
    \u671F\u5024\n     * @param e \u5358\u4F4D\u5143\n     */\n    explicit imos(std::size_t\
    \ n, const T& init, const T& e) : dat(n + 1, e) {\n        add(0, n, init);\n\
    \    }\n\n    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u6574\
    \u6570)\n     * @param n \u914D\u5217\u306E\u30B5\u30A4\u30BA\n     * @param init\
    \ \u521D\u671F\u5024\n     */\n    explicit imos(std::size_t n, T init = T(0))\n\
    \        requires std::is_integral_v<T>\n        : imos(n, init, 0) {}\n\n   \
    \ explicit imos(const std::vector<T>& init)\n        requires std::is_integral_v<T>\n\
    \        : dat(init.size() + 1, 0) {\n        for (std::size_t i = 0; i < init.size();\
    \ ++i) {\n            add(i, i + 1, init[i]);\n        }\n    }\n\n    explicit\
    \ imos(const std::vector<T>& init, const T& e) : dat(init.size() + 1, e) {\n \
    \       for (std::size_t i = 0; i < init.size(); ++i) {\n            add(i, i\
    \ + 1, init[i]);\n        }\n    }\n\n    /**\n     * @brief \u533A\u9593 [l,\
    \ r) \u306B x \u3092\u52A0\u3048\u308B O(1)\n     * @param l \u533A\u9593\u306E\
    \u5DE6\u7AEF\uFF08\u542B\u3080\uFF09\n     * @param r \u533A\u9593\u306E\u53F3\
    \u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\n     * @param x \u52A0\u7B97\u3059\
    \u308B\u5024\n     * @throw std::out_of_range l > r \u307E\u305F\u306F r > dat.size()\
    \ \u306E\u5834\u5408\n     */\n    void add(std::size_t l, std::size_t r, T x)\
    \ {\n        if (l > r || r > dat.size()) {\n            throw std::out_of_range(\"\
    imos::add: invalid range\");\n        }\n        dat[l] += x;\n        dat[r]\
    \ -= x;\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3057\
    \u3066\u8FD4\u3059 O(N)\n     * @return \u7D2F\u7A4D\u548C\u306E\u914D\u5217\n\
    \     */\n    std::vector<T> get() const {\n        std::vector<T> res(dat.size()\
    \ - 1);\n        res[0] = dat[0];\n        for (std::size_t i = 1; i < res.size();\
    \ i++)\n            res[i] = res[i - 1] + dat[i];\n\n        return res;\n   \
    \ }\n};\n\n}  // namespace e6nlaq\n"
  code: "#pragma once\n\n#define E6NLAQ_IMOS_IMOS_HPP\n\n#include <stdexcept>\n#include\
    \ <type_traits>\n#include <vector>\n\n#include \"../concepts.hpp\"\n\nnamespace\
    \ e6nlaq {\n\n/**\n * @brief imos\u6CD5\u3092\u5B9F\u88C5\u3057\u305F\u30AF\u30E9\
    \u30B9\n * @tparam T \u7D2F\u7A4D\u548C\u306E\u578B\n */\ntemplate <typename T>\n\
    \    requires add_assignable<T> && subtract_assignable<T>\nclass imos {\n   private:\n\
    \    std::vector<T> dat;\n\n   public:\n    imos() : dat(0) {};\n\n    /**\n \
    \    * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\n     * @param n \u914D\
    \u5217\u306E\u30B5\u30A4\u30BA\n     * @param init \u521D\u671F\u5024\n     *\
    \ @param e \u5358\u4F4D\u5143\n     */\n    explicit imos(std::size_t n, const\
    \ T& init, const T& e) : dat(n + 1, e) {\n        add(0, n, init);\n    }\n\n\
    \    /**\n     * @brief \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(\u6574\u6570\
    )\n     * @param n \u914D\u5217\u306E\u30B5\u30A4\u30BA\n     * @param init \u521D\
    \u671F\u5024\n     */\n    explicit imos(std::size_t n, T init = T(0))\n     \
    \   requires std::is_integral_v<T>\n        : imos(n, init, 0) {}\n\n    explicit\
    \ imos(const std::vector<T>& init)\n        requires std::is_integral_v<T>\n \
    \       : dat(init.size() + 1, 0) {\n        for (std::size_t i = 0; i < init.size();\
    \ ++i) {\n            add(i, i + 1, init[i]);\n        }\n    }\n\n    explicit\
    \ imos(const std::vector<T>& init, const T& e) : dat(init.size() + 1, e) {\n \
    \       for (std::size_t i = 0; i < init.size(); ++i) {\n            add(i, i\
    \ + 1, init[i]);\n        }\n    }\n\n    /**\n     * @brief \u533A\u9593 [l,\
    \ r) \u306B x \u3092\u52A0\u3048\u308B O(1)\n     * @param l \u533A\u9593\u306E\
    \u5DE6\u7AEF\uFF08\u542B\u3080\uFF09\n     * @param r \u533A\u9593\u306E\u53F3\
    \u7AEF\uFF08\u542B\u307E\u306A\u3044\uFF09\n     * @param x \u52A0\u7B97\u3059\
    \u308B\u5024\n     * @throw std::out_of_range l > r \u307E\u305F\u306F r > dat.size()\
    \ \u306E\u5834\u5408\n     */\n    void add(std::size_t l, std::size_t r, T x)\
    \ {\n        if (l > r || r > dat.size()) {\n            throw std::out_of_range(\"\
    imos::add: invalid range\");\n        }\n        dat[l] += x;\n        dat[r]\
    \ -= x;\n    }\n\n    /**\n     * @brief \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3057\
    \u3066\u8FD4\u3059 O(N)\n     * @return \u7D2F\u7A4D\u548C\u306E\u914D\u5217\n\
    \     */\n    std::vector<T> get() const {\n        std::vector<T> res(dat.size()\
    \ - 1);\n        res[0] = dat[0];\n        for (std::size_t i = 1; i < res.size();\
    \ i++)\n            res[i] = res[i - 1] + dat[i];\n\n        return res;\n   \
    \ }\n};\n\n}  // namespace e6nlaq"
  dependsOn:
  - include/e6nlaq/concepts.hpp
  isVerificationFile: false
  path: include/e6nlaq/imos/imos.hpp
  requiredBy:
  - include/e6nlaq/imos.hpp
  timestamp: '2025-12-12 17:20:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/verify/imos.test.cpp
documentation_of: include/e6nlaq/imos/imos.hpp
layout: document
title: "imos\u6CD5"
---

1次元のimos法

`+=`と`-=`が実装されている型`T`に対して使用できる。

- `imos(std::size_t n, const T& init, const T& e)`
  - 長さ`n`の配列を作成する。初期値は`init`で、単位元は`e`。
- `add(std::size_t l, std::size_t r, T x)`
  - 区間`[l, r)`に対して`x`だけ加算する。
  - 計算量は$\mathrm{O}(1)$。
- `get()`
  - 累積和を計算して返す。
  - 計算量は$\mathrm{O}(N)$。
