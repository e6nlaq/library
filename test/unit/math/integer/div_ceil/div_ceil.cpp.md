---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: include/e6nlaq/math/integer.hpp
    title: "\u7B26\u53F7\u306A\u3057\u6574\u6570\u306E\u6841\u6570\u3092\u8A08\u7B97\
      \u3057\u307E\u3059"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"test/unit/math/integer/div_ceil/div_ceil.cpp\"\n#define\
    \ LIBTEST\n#include <e6nlaq/math/integer.hpp>\n#include <iostream>\n\nint main()\
    \ {\n    int cases;\n    std::cin >> cases;\n    while (cases--) {\n        long\
    \ long a, b;\n        std::cin >> a >> b;\n        std::cout << e6nlaq::div_ceil(a,\
    \ b) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define LIBTEST\n#include <e6nlaq/math/integer.hpp>\n#include <iostream>\n\
    \nint main() {\n    int cases;\n    std::cin >> cases;\n    while (cases--) {\n\
    \        long long a, b;\n        std::cin >> a >> b;\n        std::cout << e6nlaq::div_ceil(a,\
    \ b) << '\\n';\n    }\n    return 0;\n}\n"
  dependsOn:
  - include/e6nlaq/math/integer.hpp
  isVerificationFile: false
  path: test/unit/math/integer/div_ceil/div_ceil.cpp
  requiredBy: []
  timestamp: '2025-12-10 00:09:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/unit/math/integer/div_ceil/div_ceil.cpp
layout: document
redirect_from:
- /library/test/unit/math/integer/div_ceil/div_ceil.cpp
- /library/test/unit/math/integer/div_ceil/div_ceil.cpp.html
title: test/unit/math/integer/div_ceil/div_ceil.cpp
---
