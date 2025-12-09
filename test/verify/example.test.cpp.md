---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B
  bundledCode: "#line 1 \"test/verify/example.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++(i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ s(n);\n    REP(i, n) {\n        cin >> s[i];\n    }\n    int q;\n    cin >>\
    \ q;\n    int cnt = 0;\n    while (q--) {\n        int t_i;\n        cin >> t_i;\n\
    \        cnt += binary_search(ALL(s), t_i);\n    }\n    cout << cnt << endl;\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/4/ALDS1_4_B\"\
    \n#include <algorithm>\n#include <iostream>\n#include <vector>\n#define REP(i,\
    \ n) for (int i = 0; (i) < (int)(n); ++(i))\n#define ALL(x) std::begin(x), std::end(x)\n\
    using namespace std;\n\nint main() {\n    int n;\n    cin >> n;\n    vector<int>\
    \ s(n);\n    REP(i, n) {\n        cin >> s[i];\n    }\n    int q;\n    cin >>\
    \ q;\n    int cnt = 0;\n    while (q--) {\n        int t_i;\n        cin >> t_i;\n\
    \        cnt += binary_search(ALL(s), t_i);\n    }\n    cout << cnt << endl;\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/verify/example.test.cpp
  requiredBy: []
  timestamp: '2025-12-09 15:09:37+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/verify/example.test.cpp
layout: document
redirect_from:
- /verify/test/verify/example.test.cpp
- /verify/test/verify/example.test.cpp.html
title: test/verify/example.test.cpp
---
