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
  bundledCode: "#line 1 \"test/unit/math/integer/digits/digits-int.cpp\"\n#define\
    \ LIBTEST\n#include <e6nlaq/math/integer.hpp>\n#include <iostream>\n\nint main()\
    \ {\n    int cases;\n    std::cin >> cases;\n\n    while (cases--) {\n       \
    \ int N;\n        std::cin >> N;\n\n        std::cout << e6nlaq::digits(N) <<\
    \ std::endl;\n    }\n\n    return 0;\n}\n"
  code: "#define LIBTEST\n#include <e6nlaq/math/integer.hpp>\n#include <iostream>\n\
    \nint main() {\n    int cases;\n    std::cin >> cases;\n\n    while (cases--)\
    \ {\n        int N;\n        std::cin >> N;\n\n        std::cout << e6nlaq::digits(N)\
    \ << std::endl;\n    }\n\n    return 0;\n}"
  dependsOn:
  - include/e6nlaq/math/integer.hpp
  isVerificationFile: false
  path: test/unit/math/integer/digits/digits-int.cpp
  requiredBy: []
  timestamp: '2025-12-10 00:12:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/unit/math/integer/digits/digits-int.cpp
layout: document
redirect_from:
- /library/test/unit/math/integer/digits/digits-int.cpp
- /library/test/unit/math/integer/digits/digits-int.cpp.html
title: test/unit/math/integer/digits/digits-int.cpp
---
