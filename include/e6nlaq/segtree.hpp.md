---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/bit.hpp
    title: include/e6nlaq/internal/bit.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ include/e6nlaq/segtree.hpp: line 10: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_SEGTREE_HPP\n\
    #define E6NLAQ_SEGTREE_HPP 1\n\n#include <cassert>\n#include <functional>\n#include\
    \ <vector>\n\n#include \"e6nlaq/internal/bit.hpp\"\n\nnamespace e6nlaq {\n\ntemplate\
    \ <class S, auto op, auto e>\nstruct segtree {\n    static_assert(std::is_convertible_v<decltype(op),\
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
    }  // namespace e6nlaq\n\n#endif  // E6NLAQ_SEGTREE_HPP\n"
  dependsOn:
  - include/e6nlaq/internal/bit.hpp
  isVerificationFile: false
  path: include/e6nlaq/segtree.hpp
  requiredBy:
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-10 23:21:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/segtree.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/segtree.hpp
- /library/include/e6nlaq/segtree.hpp.html
title: include/e6nlaq/segtree.hpp
---
