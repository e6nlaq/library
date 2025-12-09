---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: include/e6nlaq/all.hpp
    title: include/e6nlaq/all.hpp
  - icon: ':warning:'
    path: include/e6nlaq/maxflow.hpp
    title: include/e6nlaq/maxflow.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"include/e6nlaq/internal/queue.hpp\"\n// This file is a fork\
    \ of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_QUEUE_HPP\n#define E6NLAQ_INTERNAL_QUEUE_HPP\
    \ 1\n\n#include <vector>\n\nnamespace e6nlaq {\n\nnamespace internal {\n\ntemplate\
    \ <class T>\nstruct simple_queue {\n    std::vector<T> payload;\n    int pos =\
    \ 0;\n    void reserve(int n) { payload.reserve(n); }\n    int size() const {\
    \ return int(payload.size()) - pos; }\n    bool empty() const { return pos ==\
    \ int(payload.size()); }\n    void push(const T& t) { payload.push_back(t); }\n\
    \    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_QUEUE_HPP\n"
  code: "// This file is a fork of AtCoder Library.\n\n#ifndef E6NLAQ_INTERNAL_QUEUE_HPP\n\
    #define E6NLAQ_INTERNAL_QUEUE_HPP 1\n\n#include <vector>\n\nnamespace e6nlaq {\n\
    \nnamespace internal {\n\ntemplate <class T>\nstruct simple_queue {\n    std::vector<T>\
    \ payload;\n    int pos = 0;\n    void reserve(int n) { payload.reserve(n); }\n\
    \    int size() const { return int(payload.size()) - pos; }\n    bool empty()\
    \ const { return pos == int(payload.size()); }\n    void push(const T& t) { payload.push_back(t);\
    \ }\n    T& front() { return payload[pos]; }\n    void clear() {\n        payload.clear();\n\
    \        pos = 0;\n    }\n    void pop() { pos++; }\n};\n\n}  // namespace internal\n\
    \n}  // namespace e6nlaq\n\n#endif  // E6NLAQ_INTERNAL_QUEUE_HPP\n"
  dependsOn: []
  isVerificationFile: false
  path: include/e6nlaq/internal/queue.hpp
  requiredBy:
  - include/e6nlaq/maxflow.hpp
  - include/e6nlaq/all.hpp
  timestamp: '2025-12-09 15:09:37+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: include/e6nlaq/internal/queue.hpp
layout: document
redirect_from:
- /library/include/e6nlaq/internal/queue.hpp
- /library/include/e6nlaq/internal/queue.hpp.html
title: include/e6nlaq/internal/queue.hpp
---
