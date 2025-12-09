---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/internal/math.hpp
    title: include/e6nlaq/internal/math.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  - icon: ':warning:'
    path: include/e6nlaq/math.hpp
    title: include/e6nlaq/math.hpp
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
    \ include/e6nlaq/math/acl.hpp: line 11: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_MATH_ACL_HPP\n\
    #define E6NLAQ_MATH_ACL_HPP 1\n\n#include <algorithm>\n#include <cassert>\n#include\
    \ <tuple>\n#include <vector>\n\n#include \"e6nlaq/internal/math.hpp\"\n\nnamespace\
    \ e6nlaq {\n\ninline long long pow_mod(long long x, long long n, int m) {\n  \
    \  assert(0 <= n && 1 <= m);\n    if (m == 1) return 0;\n    internal::barrett\
    \ bt((unsigned int)(m));\n    unsigned int r = 1, y = (unsigned int)(internal::safe_mod(x,\
    \ m));\n    while (n) {\n        if (n & 1) r = bt.mul(r, y);\n        y = bt.mul(y,\
    \ y);\n        n >>= 1;\n    }\n    return r;\n}\n\ninline long long inv_mod(long\
    \ long x, long long m) {\n    assert(1 <= m);\n    auto z = internal::inv_gcd(x,\
    \ m);\n    assert(z.first == 1);\n    return z.second;\n}\n\n// (rem, mod)\ninline\
    \ std::pair<long long, long long> crt(const std::vector<long long>& r,\n     \
    \                                      const std::vector<long long>& m) {\n  \
    \  assert(r.size() == m.size());\n    int n = int(r.size());\n    // Contracts:\
    \ 0 <= r0 < m0\n    long long r0 = 0, m0 = 1;\n    for (int i = 0; i < n; i++)\
    \ {\n        assert(1 <= m[i]);\n        long long r1 = internal::safe_mod(r[i],\
    \ m[i]), m1 = m[i];\n        if (m0 < m1) {\n            std::swap(r0, r1);\n\
    \            std::swap(m0, m1);\n        }\n        if (m0 % m1 == 0) {\n    \
    \        if (r0 % m1 != r1) return {0, 0};\n            continue;\n        }\n\
    \        // assume: m0 > m1, lcm(m0, m1) >= 2 * max(m0, m1)\n\n        // (r0,\
    \ m0), (r1, m1) -> (r2, m2 = lcm(m0, m1));\n        // r2 % m0 = r0\n        //\
    \ r2 % m1 = r1\n        // -> (r0 + x*m0) % m1 = r1\n        // -> x*u0*g = r1-r0\
    \ (mod u1*g) (u0*g = m0, u1*g = m1)\n        // -> x = (r1 - r0) / g * inv(u0)\
    \ (mod u1)\n\n        // im = inv(u0) (mod u1) (0 <= im < u1)\n        long long\
    \ g, im;\n        std::tie(g, im) = internal::inv_gcd(m0, m1);\n\n        long\
    \ long u1 = (m1 / g);\n        // |r1 - r0| < (m0 + m1) <= lcm(m0, m1)\n     \
    \   if ((r1 - r0) % g) return {0, 0};\n\n        // u1 * u1 <= m1 * m1 / g / g\
    \ <= m0 * m1 / g = lcm(m0, m1)\n        long long x = (r1 - r0) / g % u1 * im\
    \ % u1;\n\n        // |r0| + |m0 * x|\n        // < m0 + m0 * (u1 - 1)\n     \
    \   // = m0 + m0 * m1 / g - m0\n        // = lcm(m0, m1)\n        r0 += x * m0;\n\
    \        m0 *= u1;  // -> lcm(m0, m1)\n        if (r0 < 0) r0 += m0;\n    }\n\
    \    return {r0, m0};\n}\n\ninline long long floor_sum(long long n, long long\
    \ m, long long a, long long b) {\n    assert(0 <= n && n < (1LL << 32));\n   \
    \ assert(1 <= m && m < (1LL << 32));\n    unsigned long long ans = 0;\n    if\
    \ (a < 0) {\n        unsigned long long a2 = internal::safe_mod(a, m);\n     \
    \   ans -= 1ULL * n * (n - 1) / 2 * ((a2 - a) / m);\n        a = a2;\n    }\n\
    \    if (b < 0) {\n        unsigned long long b2 = internal::safe_mod(b, m);\n\
    \        ans -= 1ULL * n * ((b2 - b) / m);\n        b = b2;\n    }\n    return\
    \ ans + internal::floor_sum_unsigned(n, m, a, b);\n}\n\n}  // namespace e6nlaq\n\
    \n#endif  // E6NLAQ_MATH_HPP\n"
  dependsOn:
  - include/e6nlaq/internal/math.hpp
  isVerificationFile: false
  path: include/e6nlaq/math/acl.hpp
  requiredBy:
  - include/e6nlaq/math.hpp
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-10 00:09:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/math/acl.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/math/acl.hpp
- /library/include/e6nlaq/math/acl.hpp.html
title: include/e6nlaq/math/acl.hpp
---
