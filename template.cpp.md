---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "T\u578B\u3092char\u578B\u306B\u5909\u63DB\u3057\u307E\u3059"
    links:
    - https://x.gd/7JLRg
    - https://x.gd/yonBS
    - https://zenn.dev/antyuntyun
    - https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/union-find
  bundledCode: "#line 1 \"template.cpp\"\n/*------------------------------------------------------------\n\
    \n\n               Welcome to my program!\n               @x__0 / @e6nlaq\n\n\
    \            \u3000\u3000\u2227\uFF3F\u2227        AtCoder / Codeforces  etc...\n\
    \            \u3000 ( \u3000\uFF65\u03C9\uFF65)\n            \uFF3F(__\u3064/\uFFE3\
    \uFFE3\uFFE3 /\n            \u3000\u3000\uFF3C/\u3000\u3000\u3000\u3000 /  C++\
    \ GCC 14.2.0\n            \u3000\u3000\u3000\u3000\uFFE3\uFFE3\uFFE3\uFFE3\uFFE3\
    \n                               Let's write Codes!\n\n\n------------------------------------------------------------*/\n\
    \n/* #region AtCoder Template */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u578B\u7701\u7565\nusing uint = unsigned;\nusing ll = long long;\n\
    // using ll = __int128_t;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using pll = pair<ll, ll>;\nusing vll = vector<ll>;\nusing vb = vector<bool>;\n\
    using vc = vector<char>;\nusing vs = vector<string>;\nusing vd = vector<double>;\n\
    using vld = vector<ld>;\nusing vull = vector<ull>;\nusing vpll = vector<pll>;\n\
    using pdd = pair<ld, ld>;\nusing psl = pair<string, ll>;\nusing pcl = pair<char,\
    \ ll>;\nusing vvll = vector<vll>;\nusing vvvll = vector<vvll>;\nusing vvc = vector<vc>;\n\
    using vvs = vector<vs>;\nusing vvb = vector<vb>;\nusing vvld = vector<vld>;\n\
    using vvd = vector<vd>;\nusing mll = map<ll, ll>;\nusing mcl = map<char, ll>;\n\
    using msl = map<string, ll>;\nusing sll = set<ll>;\nusing spll = set<pair<ll,\
    \ ll>>;\nusing spdd = set<pair<ld, ld>>;\nusing stll = stack<ll>;\nusing qll =\
    \ queue<ll>;\nusing qd = queue<ld>;\nusing qs = queue<string>;\nusing qc = queue<char>;\n\
    using int128_t = __int128_t;\n\ntemplate <typename Tp1, typename Tp2>\nusing unmap\
    \ = unordered_map<Tp1, Tp2>;\n\ntemplate <typename Tp>\nusing unset = unordered_set<Tp>;\n\
    \ntemplate <typename Tp>\nusing reverse_queue = priority_queue<Tp, vector<Tp>,\
    \ greater<Tp>>;\n\ntemplate <typename T>\nusing vec2 = vector<vector<T>>;\n\n\
    template <typename T>\nusing vec3 = vector<vector<vector<T>>>;\n\n#if __cplusplus\
    \ >= 202002L\n#define cpp20\n\ntemplate <typename T>\nconcept number = integral<T>\
    \ || floating_point<T>;\n\n#endif\n\n// \u30DE\u30AF\u30ED\n#define rep(i, n)\
    \ for (ll i = 0; i < (ll)(n); i++)\n#define rrep(i, n) for (ll i = (n) - 1; i\
    \ >= 0; i--)\n#define irep(i, n) for (ll i = 1; i <= (ll)(n); i++)\n#define arep(i,\
    \ a, n) for (ll i = (a); i < (ll)(n); i++)\n#define adrep(i, a, d, n) for (ll\
    \ i = (a); i < (ll)(n); i += d)\n#define until(b) while (!(b))\n\n// \u7701\u7565\
    define\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define elif else if\n\n#define exit exit(0)\n\n// \u5B9A\u6570\n\nconst string\
    \ sl = \"\";\nconstexpr char cl = '\\0';\nconstexpr ll nl = 0LL;\nconstexpr ll\
    \ INFINT = 2047483647;\nconstexpr ll INFLL = (1LL << 61);  // \u3060\u3044\u305F\
    \u3044\nconst ll mod1 = pow(10, 9) + 1;\nconstexpr char sp = ' ';\nconst ll j2_32\
    \ = pow(2, 32);\nconst ll j2_m32 = pow(2, -32);\nconst ll j2_10 = pow(2, 10);\n\
    const vector<int> dx = {0, 0, 1, -1};\nconst vector<int> dy = {1, -1, 0, 0};\n\
    const vector<int> ex = {-1, -1, -1, 0, 0, 1, 1, 1};\nconst vector<int> ey = {-1,\
    \ 0, 1, -1, 1, -1, 0, 1};\nconst string spa = \" \";\nconstexpr bool except =\
    \ true;\n\nmt19937_64 rng;\n\n// \u8272\u3005\u306A\u30C6\u30F3\u30D7\u30EC(\u5B8C\
    \u5168\u30B3\u30D4\u30DA)\n\ntemplate <class T>\nsize_t HashCombine(const size_t\
    \ seed, const T& v) {\n    return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed\
    \ << 6) + (seed >> 2));\n}\n/* pair\u7528 */\ntemplate <class T, class S>\nstruct\
    \ std::hash<std::pair<T, S>> {\n    size_t operator()(const std::pair<T, S>& keyval)\
    \ const noexcept {\n        return HashCombine(std::hash<T>()(keyval.first), keyval.second);\n\
    \    }\n};\n/* vector\u7528 */\ntemplate <class T>\nstruct std::hash<std::vector<T>>\
    \ {\n    size_t operator()(const std::vector<T>& keyval) const noexcept {\n  \
    \      size_t s = 0;\n        for (auto&& v : keyval)\n            s = HashCombine(s,\
    \ v);\n        return s;\n    }\n};\n/* tuple\u7528 */\ntemplate <int N>\nstruct\
    \ HashTupleCore {\n    template <class Tuple>\n    size_t operator()(const Tuple&\
    \ keyval) const noexcept {\n        size_t s = HashTupleCore<N - 1>()(keyval);\n\
    \        return HashCombine(s, std::get<N - 1>(keyval));\n    }\n};\ntemplate\
    \ <>\nstruct HashTupleCore<0> {\n    template <class Tuple>\n    size_t operator()(const\
    \ Tuple& keyval) const noexcept { return 0; }\n};\ntemplate <class... Args>\n\
    struct std::hash<std::tuple<Args...>> {\n    size_t operator()(const tuple<Args...>&\
    \ keyval) const noexcept {\n        return HashTupleCore<tuple_size<tuple<Args...>>::value>()(keyval);\n\
    \    }\n};\n\nstd::string\noperator\"\"_s(char const* str, std::size_t) {\n  \
    \  return str;\n}\n\nstd::string\noperator*(std::string const& str, int n) {\n\
    \    if (n < 1)\n        return \"\";\n    std::string result;\n    result.reserve(str.length()\
    \ * n);\n    for (int i = 0; i < n; ++i) {\n        result += str;\n    }\n  \
    \  return result;\n}\n\n// \u95A2\u6570\u985E\n\n// O(\u221AN)\ninline bool isprime(const\
    \ ull num) noexcept {\n    if (num < 2)\n        return false;\n    else if (num\
    \ == 2)\n        return true;\n    else if (num % 2 == 0)\n        return false;\n\
    \n    for (ull i = 3; i * i <= num; i += 2) {\n        if (num % i == 0) {\n \
    \           return false;\n        }\n    }\n    return true;\n}\n\n// O(1)\n\
    inline int ctoi(const char c) noexcept {\n    if (c >= '0' && c <= '9')\n    \
    \    return c - '0';\n    return 0;\n}\n\n// \u6570\u50240\u57CB\u3081\n// O(N)\n\
    inline string zerou(const ull i, string s) noexcept {\n    while (s.size() !=\
    \ i)\n        s = '0' + s;\n    return s;\n}\n\ninline string zerou(const ull\
    \ i, const ull n) noexcept {\n    return zerou(i, to_string(n));\n}\n\n/**\n *\
    \ @brief T\u578B\u3092char\u578B\u306B\u5909\u63DB\u3057\u307E\u3059\n *\n * @tparam\
    \ T \u5909\u63DB\u3059\u308B\u578B\n * @param i \u5909\u63DB\u3059\u308B\u6570\
    \u5024\n * @return char \u5909\u63DB\u5F8C\u306E\u6587\u5B57\n */\ninline char\
    \ to_char(const ull i) {\n    assert(i <= 9);\n    return '0' + i;\n}\n\ntemplate\
    \ <typename T1, typename T2>\n    requires totally_ordered_with<T1, T2> && assignable_from<T1&,\
    \ T2>\ninline bool chmax(T1& i, const T2 j) noexcept {\n    if (i < j) {\n   \
    \     i = j;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T1, typename T2>\n    requires totally_ordered_with<T1, T2> && assignable_from<T1&,\
    \ T2>\ninline bool chmin(T1& i, const T2 j) noexcept {\n    if (i > j) {\n   \
    \     i = j;\n        return true;\n    }\n    return false;\n}\n\n/**\n * @brief\
    \ \u914D\u5217\u5185\u306E\u5168\u8981\u7D20\u3092\u51FA\u529B\u3057\u307E\u3059\
    \n *\n * @tparam T \u914D\u5217\u306E\u578B(vector<T>)\n * @param v \u914D\u5217\
    \n * @param s \u533A\u5207\u308A\u6587\u5B57(\u898F\u5B9A\u3067\u306F\u30B9\u30DA\
    \u30FC\u30B9)\n * @author https://zenn.dev/antyuntyun\n */\ntemplate <typename\
    \ T>\ninline void print(const vector<T>& v, const string& s = \" \") noexcept\
    \ {\n    rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : \"\\n\"\
    );\n}\n\ntemplate <typename A, typename B>\ninline void print(const vector<pair<A,\
    \ B>>& v, const string& s = \"\\n\") noexcept {\n    rep(i, v.size()) cout <<\
    \ v[i].first << \" \" << v[i].second << s;\n}\n\n/// @brief \u4E8C\u6B21\u5143\
    \u914D\u5217\u306E\u5168\u8981\u7D20\u3092\u51FA\u529B\u3057\u307E\u3059\n///\
    \ @tparam T \u914D\u5217\u306E\u578B(vector<vector<T>>)\n/// @param v \u4E8C\u6B21\
    \u5143\u914D\u5217\n/// @param s \u533A\u5207\u308A\u6587\u5B57\ntemplate <typename\
    \ T>\ninline void print(const vector<vector<T>>& v, string const& s = \" \") noexcept(except)\
    \ {\n    rep(i, v.size()) {\n        rep(j, v[i].size()) cout << v[i][j] << (j\
    \ != (ll)v[i].size() - 1 ? s : \"\\n\");\n    }\n}\n\n/**\n * @brief \u6587\u5B57\
    \u5217\u3092\u53CD\u8EE2\u3057\u305F\u6587\u5B57\u5217\u3092\u8FD4\u3057\u307E\
    \u3059\n *\n * @param s \u53CD\u8EE2\u3059\u308B\u6587\u5B57\u5217\n * @return\
    \ string \u53CD\u8EE2\u5F8C\u306E\u6587\u5B57\u5217\n */\ninline string srev(string\
    \ s) noexcept {\n    reverse(all(s));\n    return s;\n}\n\ntemplate <typename\
    \ T>\ninline vector<vector<T>> make_vec2(const ull H, const ull W, const T& init)\
    \ {\n    return vector<vector<T>>(H, vector<T>(W, init));\n}\n\ntemplate <typename\
    \ T>\ninline vector<vector<T>> make_vec2(const ull H, const ull W) {\n    return\
    \ vector<vector<T>>(H, vector<T>(W));\n}\n\ntemplate <typename T>\ninline vector<vector<vector<T>>>\
    \ make_vec3(const ull X, const ull Y, const ull Z, const T& init) {\n    return\
    \ vector<vector<vector<T>>>(X, make_vec2<T>(Y, Z, init));\n}\n\ntemplate <typename\
    \ T>\ninline vector<vector<vector<T>>> make_vec3(const ull X, const ull Y, const\
    \ ull Z) {\n    return vector<vector<vector<T>>>(X, make_vec2<T>(Y, Z));\n}\n\n\
    /// @brief N\u9032\u6570\u306E\u6587\u5B57\u304B\u308910\u9032\u6570\u306E\u6570\
    \u5024\u306B\u5909\u63DB\u3057\u307E\u3059\n/// @param c N\u9032\u6570\u306E\u6587\
    \u5B57\n/// @return \u5909\u63DB\u3057\u305F10\u9032\u6570\u306E\u6570\u5024\n\
    inline int ntodec(const char c) {\n    switch (c) {\n        case '0':\n     \
    \       return 0;\n        case '1':\n            return 1;\n        case '2':\n\
    \            return 2;\n        case '3':\n            return 3;\n        case\
    \ '4':\n            return 4;\n        case '5':\n            return 5;\n    \
    \    case '6':\n            return 6;\n        case '7':\n            return 7;\n\
    \        case '8':\n            return 8;\n        case '9':\n            return\
    \ 9;\n        case 'A':\n            return 10;\n        case 'B':\n         \
    \   return 11;\n        case 'C':\n            return 12;\n        case 'D':\n\
    \            return 13;\n        case 'E':\n            return 14;\n        case\
    \ 'F':\n            return 15;\n        case 'G':\n            return 16;\n  \
    \      case 'H':\n            return 17;\n        case 'I':\n            return\
    \ 18;\n        case 'J':\n            return 19;\n        case 'K':\n        \
    \    return 20;\n        case 'L':\n            return 21;\n        case 'M':\n\
    \            return 22;\n        case 'N':\n            return 23;\n        case\
    \ 'O':\n            return 24;\n        case 'P':\n            return 25;\n  \
    \      case 'Q':\n            return 26;\n        case 'R':\n            return\
    \ 27;\n        case 'S':\n            return 28;\n        case 'T':\n        \
    \    return 29;\n        case 'U':\n            return 30;\n        case 'V':\n\
    \            return 31;\n        case 'W':\n            return 32;\n        case\
    \ 'X':\n            return 33;\n        case 'Y':\n            return 34;\n  \
    \      case 'Z':\n            return 35;\n        default:\n            return\
    \ -1;\n    }\n}\n\n/// @brief 10\u9032\u6570\u306E\u6570\u5024\u3092N\u9032\u6570\
    \u306E\u6587\u5B57\u306B\u5909\u63DB\u3057\u307E\u3059\n/// @param n 10\u9032\u6570\
    \u306E\u6570\u5024\n/// @return N\u9032\u6570\u306E\u6587\u5B57\ninline char decton(const\
    \ int n) {\n    switch (n) {\n        case 0:\n            return '0';\n     \
    \   case 1:\n            return '1';\n        case 2:\n            return '2';\n\
    \        case 3:\n            return '3';\n        case 4:\n            return\
    \ '4';\n        case 5:\n            return '5';\n        case 6:\n          \
    \  return '6';\n        case 7:\n            return '7';\n        case 8:\n  \
    \          return '8';\n        case 9:\n            return '9';\n        case\
    \ 10:\n            return 'A';\n        case 11:\n            return 'B';\n  \
    \      case 12:\n            return 'C';\n        case 13:\n            return\
    \ 'D';\n        case 14:\n            return 'E';\n        case 15:\n        \
    \    return 'F';\n        case 16:\n            return 'G';\n        case 17:\n\
    \            return 'H';\n        case 18:\n            return 'I';\n        case\
    \ 19:\n            return 'J';\n        case 20:\n            return 'K';\n  \
    \      case 21:\n            return 'L';\n        case 22:\n            return\
    \ 'M';\n        case 23:\n            return 'N';\n        case 24:\n        \
    \    return 'O';\n        case 25:\n            return 'P';\n        case 26:\n\
    \            return 'Q';\n        case 27:\n            return 'R';\n        case\
    \ 28:\n            return 'S';\n        case 29:\n            return 'T';\n  \
    \      case 30:\n            return 'U';\n        case 31:\n            return\
    \ 'V';\n        case 32:\n            return 'W';\n        case 33:\n        \
    \    return 'X';\n        case 34:\n            return 'W';\n        case 35:\n\
    \            return 'Z';\n        default:\n            return '\\0';\n    }\n\
    }\n\n/// @brief N\u9032\u6570\u306E\u6587\u5B57\u5217\u3092M\u9032\u6570\u306B\
    \u76F4\u3057\u3066\u51FA\u529B\u3057\u307E\u3059\u3002\n/// @param str N\u9032\
    \u6570\u306E\u6587\u5B57\n/// @param n \u6587\u5B57\u306E\u9032\u6570\n/// @param\
    \ m \u51FA\u529B\u306E\u9032\u6570\n/// @return M\u9032\u6570\u306E\u6587\u5B57\
    \ninline string n_ary(const string& str, const int n, const int m) {\n    unsigned\
    \ long tmp = 0;\n    string ret;\n\n    for (unsigned long long i = 0; i < str.length();\
    \ i++) {\n        tmp += (unsigned long)ntodec(str[str.length() - 1 - i]) * pow_ll(n,\
    \ i);\n    }\n\n    if (tmp == 0)\n        return \"0\";\n    while (tmp != 0)\
    \ {\n        ret = decton(tmp % m) + ret;\n        tmp /= m;\n    }\n    return\
    \ ret;\n}\n\n/// @brief\n/// @tparam T n\u306E\u578B\n/// @param n \u7D20\u56E0\
    \u6570\u5206\u89E3\u3059\u308B\u6570\n/// @return \u4E0D\u660E\ntemplate <typename\
    \ T>\ninline map<T, T> prime_factor_map(T n) {\n    map<T, T> ret;\n    for (T\
    \ i = 2; i * i <= n; i++) {\n        T tmp = 0;\n        while (n % i == 0) {\n\
    \            tmp++;\n            n /= i;\n        }\n        ret[i] = tmp;\n \
    \   }\n    if (n != 1)\n        ret[n] = 1;\n    return ret;\n}\n\n// \u7D20\u56E0\
    \u6570\u5206\u89E3\n// O(sqrt(N))\nvector<pair<ll, ll>> prime_factor(ll N) {\n\
    \    vector<pair<ll, ll>> res;\n\n    for (ll p = 2; p * p <= N; ++p) {\n    \
    \    if (N % p != 0) {\n            continue;\n        }\n\n        int e = 0;\n\
    \        while (N % p == 0) {\n            ++e;\n            N /= p;\n       \
    \ }\n\n        res.emplace_back(p, e);\n    }\n\n    if (N != 1) {\n        res.emplace_back(N,\
    \ 1);\n    }\n    return res;\n}\n\n// \u7D04\u6570\u306E\u500B\u6570\n// O(sqrt(N))\n\
    inline ull divisor_num(const ll N) {\n    map<ll, ll> pf = prime_factor_map(N);\n\
    \    ull ret = 1;\n    for (auto p : pf) {\n        ret *= (p.second + 1);\n \
    \   }\n    return ret;\n}\n\n/// @brief n\u306E\u7D04\u6570\u3092\u5168\u5217\u6319\
    \u3057\u307E\u3059\u3002(\u8A08\u7B97\u91CF: O(sqrt(N)))\n/// @param n \u5168\u5217\
    \u6319\u3059\u308B\u7D04\u6570\n/// @return n\u306E\u7D04\u6570\ninline vll divisor(const\
    \ ll n) {\n    vll ret;\n    for (ll i = 1; i * i <= n; i++) {\n        if (n\
    \ % i == 0) {\n            ret.push_back(i);\n            if (i * i != n)\n  \
    \              ret.push_back(n / i);\n        }\n    }\n    sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n\n/// @brief \u6587\u5B57\u5217\u304C\u6570\
    \u5B57\u306E\u307F\u304B\u5224\u5B9A\u3057\u307E\u3059 O(|S|)\n/// @param s \u5224\
    \u5B9A\u3059\u308B\u6587\u5B57\u5217\n/// @return \u6570\u5024\u3067\u3067\u304D\
    \u305F\u6587\u5B57\u5217\u304B\u3069\u3046\u304B\ninline bool isint(const string&\
    \ s) noexcept {\n    rep(i, s.size()) {\n        if (!isdigit(s[i])) {\n     \
    \       return false;\n        }\n    }\n\n    return true;\n}\n\n/// @brief \u4E8C\
    \u6B21\u5143\u914D\u5217\u309290\u5EA6\u6642\u8A08\u56DE\u308A\u306B\u56DE\u8EE2\
    \u3059\u308B\n/// @tparam T \u914D\u5217\u306E\u578B(vector<vector<T>>)\n/// @param\
    \ arr \u4E8C\u6B21\u5143\u914D\u5217\n/// @return \u8FD4\u308A\u5024\ntemplate\
    \ <typename T>\n[[nodiscard]] inline vector<vector<T>> rot90(const vector<vector<T>>&\
    \ A) {\n    ll N = A.size(), M = A[0].size();\n    vector<vector<T>> ret(M, vector<T>(N));\n\
    \n    ll _i = 0, _j = 0;\n\n    rep(j, M) {\n        for (ll i = N - 1; i >= 0;\
    \ i--) {\n            ret[_i][_j] = A[i][j];\n            _j++;\n        }\n \
    \       _j = 0;\n        _i++;\n    }\n\n    return ret;\n}\n\n/// @brief \u56DE\
    \u6587\u304B\u3069\u3046\u304B\u5224\u5B9A\n/// @param str \u6587\u5B57\u5217\n\
    /// @return \u56DE\u6587\u304B\u3069\u3046\u304B\ninline bool ispalind(const string&\
    \ str) noexcept {\n    ull n = str.length();\n    for (ull i = 0; i < n / 2; i++)\
    \ {\n        if (str[i] != str[n - i - 1]) {\n            return false;\n    \
    \    }\n    }\n    return true;\n}\n\ninline bool ispalind(const string& str,\
    \ ull x, ull n) {\n    assert(x < str.size());\n    assert(x + n <= str.size());\n\
    \n    for (ull i = 0; i < n / 2; i++) {\n        if (str[x + i] != str[(x + n)\
    \ - i - 1]) {\n            return false;\n        }\n    }\n    return true;\n\
    }\n\n/// @brief 10\u9032\u6CD5\u3067\u8868\u3057\u305F\u6642\u306E\u5404\u6841\
    \u306E\u548C\u3092\u6C42\u3081\u307E\u3059\n/// @param s 10\u9032\u6CD5\u3067\u8868\
    \u3057\u305F\u6587\u5B57\u5217\n/// @return \u5404\u6841\u306E\u548C\ninline ll\
    \ csum(const string& s) noexcept {\n    ll ret = 0;\n    rep(i, s.size()) {\n\
    \        ret += ctoi(s[i]);\n    }\n\n    return ret;\n}\n\n/// @brief csum\u306E\
    \u6570\u5024\u7528\u306E\u88DC\u5B8C\u95A2\u6570\n/// @param n \u6570\u5024\n\
    /// @return \u5404\u6841\u306E\u548C\ninline ll csum(const ll n) noexcept {\n\
    \    return csum(to_string(n));\n}\n\n/// @brief \u4E00\u6B21\u5143\u306E\u7D2F\
    \u7A4D\u548C\u3092\u8FD4\u3057\u307E\u3059\n/// @tparam T vector\u306E\u578B\n\
    /// @param v \u52A0\u5DE5\u3059\u308B\u524D\u306E\u914D\u5217\n/// @return \u52A0\
    \u5DE5\u5F8C\u306E\u914D\u5217(\u9577\u3055\u306F |v|+1 \u3068\u306A\u308A\u307E\
    \u3059\u3002)\ntemplate <typename T>\ninline vector<T> cum(const vector<T>& v)\
    \ noexcept {\n    vector<T> ans(v.size() + 1);\n    ans[0] = 0;\n    for (ull\
    \ i = 1; i <= v.size(); i++) {\n        ans[i] = ans[i - 1] + v[i - 1];\n    }\n\
    \    return ans;\n}\n\n/// @brief \u4E8C\u6B21\u5143\u306E\u7D2F\u7A4D\u548C\u3092\
    \u8FD4\u3057\u307E\u3059\n/// @tparam T vector<vector<>>\u306E\u578B\n/// @param\
    \ v \u52A0\u5DE5\u524D\u306E\u914D\u5217\n/// @return \u52A0\u5DE5\u5F8C\u306E\
    \u914D\u5217(\u9577\u3055\u306F\u305D\u308C\u305E\u308C+1\u306B\u306A\u308A\u307E\
    \u3059)\ntemplate <typename T>\ninline vec2<T> cum(const vec2<T>& v) {\n    assert(v.size()\
    \ > 0);\n    ull H = v.size(), W = v[0].size();\n    auto ret = make_vec2<T>(H\
    \ + 1, W + 1, 0);\n    for (ull i = 1; i <= H; i++) {\n        for (ull j = 1;\
    \ j <= W; j++) {\n            ret[i][j] = ret[i][j - 1] + v[i - 1][j - 1];\n \
    \       }\n    }\n\n    for (ull j = 1; j <= W; j++) {\n        for (ull i = 1;\
    \ i <= H; i++) {\n            ret[i][j] += ret[i - 1][j];\n        }\n    }\n\n\
    \    return ret;\n}\n\ntemplate <typename T>\ninline vec3<T> cum(const vec3<T>&\
    \ v) {\n    assert(v.size() > 0 && v[0].size() > 0);\n    ll x = v.size();\n \
    \   ll y = v[0].size();\n    ll z = v[0][0].size();\n    auto ret = make_vec3<T>(x\
    \ + 1, y + 1, z + 1, 0);\n\n    for (ll i = 0; i < x; ++i) {\n        for (ll\
    \ j = 0; j < y; ++j) {\n            for (ll k = 0; k < z; ++k) {\n           \
    \     ret[i + 1][j + 1][k + 1] =\n                    ret[i][j + 1][k + 1] + ret[i\
    \ + 1][j][k + 1] +\n                    ret[i + 1][j + 1][k] - ret[i][j][k + 1]\
    \ - ret[i][j + 1][k] -\n                    ret[i + 1][j][k] + ret[i][j][k] +\
    \ v[i][j][k];\n            }\n        }\n    }\n\n    return ret;\n}\n\n// 0-indexed\n\
    template <typename T>\ninline ll cumcnt(const vec2<T>& z, ll lx, ll ly, ll rx,\
    \ ll ry) {\n    lx++;\n    ly++;\n    rx++;\n    ry++;\n    return z[rx][ry] +\
    \ z[lx - 1][ly - 1] - z[lx - 1][ry] - z[rx][ly - 1];\n}\n\ntemplate <typename\
    \ T>\ninline ll cumcnt(const vec3<T>& z, ll lx, ll ly, ll lz, ll rx, ll ry, ll\
    \ rz) {\n    lx++;\n    ly++;\n    lz++;\n    rx++;\n    ry++;\n    rz++;\n  \
    \  return z[rx][ry][rz] - z[lx - 1][ry][rz] - z[rx][ly - 1][rz] - z[rx][ry][lz\
    \ - 1] + z[lx - 1][ly - 1][rz] + z[lx - 1][ry][lz - 1] + z[rx][ly - 1][lz - 1]\
    \ - z[lx - 1][ly - 1][lz - 1];\n}\n\n#ifdef cpp20\ntemplate <integral T>\n#else\n\
    template <typename T>\n#endif\ninline vector<T> cumxor(const vector<T>& x) {\n\
    \    vector<T> ans(x.size() + 1);\n    ans[0] = 0;\n    irep(i, x.size()) {\n\
    \        ans[i] = ans[i - 1] ^ x[i - 1];\n    }\n\n    return ans;\n}\n\n/// @brief\
    \ \u30E9\u30F3\u30C0\u30E0\u306A\u6570\u5024\u3092\u8FD4\u3059\n/// @param l \u6700\
    \u5C0F\u5024\n/// @param r \u6700\u5927\u5024\n/// @return\ninline ll randint(const\
    \ ll l, const ll r) noexcept {\n    if (l == r)\n        return l;\n    return\
    \ l + (rng() % (r - l + 1));\n}\n\n/// @brief \u9AD8\u901F\u5168\u63A2\u7D22 O(log\
    \ N)\n/// @tparam T \u914D\u5217\u306E\u578B\n/// @param v \u914D\u5217\n/// @param\
    \ x \u63A2\u7D22\u3059\u308B\u3084\u3064\n/// @return \u6570\ntemplate <typename\
    \ T>\ninline long long bound_count(const vector<T>& v, const T& x) noexcept {\n\
    \    auto l = lower_bound(v.begin(), v.end(), x);\n    auto u = upper_bound(v.begin(),\
    \ v.end(), x);\n\n    if (*l != x) {\n        return 0;\n    }\n\n    if (u ==\
    \ v.end()) {\n        return v.size() - (l - v.begin());\n    } else {\n     \
    \   return (u - v.begin()) - (l - v.begin());\n    }\n}\n\n/// @brief \u914D\u5217\
    \u306E\u6700\u8FD1\u5024\u3092\u6C42\u3081\u308B\n/// @tparam T \u914D\u5217\u306E\
    \u578B\n/// @param v \u914D\u5217\n/// @param x \u6700\u8FD1\u5024\u3092\u6C42\
    \u3081\u308B\u5024\n/// @return x\u306E\u6700\u8FD1\u5024\ntemplate <typename\
    \ T>\ninline T recent(const vector<T>& v, const T& x) noexcept {\n    auto it\
    \ = lower_bound(all(v), x);\n\n    if (it == v.end())\n        return *prev(v.end(),\
    \ 1);\n    else {\n        if (it == v.begin())\n            return *v.begin();\n\
    \        else {\n            if (abs(*it - x) < abs(*prev(it, 1) - x))\n     \
    \           return *it;\n            else\n                return *prev(it, 1);\n\
    \        }\n    }\n}\n\n/// @brief \u6587\u5B57\u5217\u5727\u7E2E\n/// @param\
    \ str \u5727\u7E2E\u3059\u308B\u6587\u5B57\u5217\n/// @return \u5727\u7E2E\u5F8C\
    \ninline vector<pair<char, ull>> rlencode(const string& str) noexcept {\n    ull\
    \ n = (ull)str.size();\n    vector<pair<char, ull>> ret;\n    for (ull l = 0;\
    \ l < n;) {\n        ull r = l + 1;\n        for (; r < n && str[l] == str[r];\
    \ r++) {\n        };\n        ret.push_back({str[l], r - l});\n        l = r;\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T>\ninline vector<pair<T, ull>>\
    \ rlencode(const vector<T>& v) noexcept {\n    ull n = (ull)v.size();\n    vector<pair<T,\
    \ ull>> ret;\n    for (ull l = 0; l < n;) {\n        ull r = l + 1;\n        for\
    \ (; r < n && v[l] == v[r]; r++) {\n        };\n        ret.push_back({v[l], r\
    \ - l});\n        l = r;\n    }\n    return ret;\n}\n\ntemplate <typename T>\n\
    inline map<T, ll> counter(const vector<T>& v) noexcept {\n    map<T, ll> dat;\n\
    \    rep(i, v.size()) {\n        dat[v[i]]++;\n    }\n\n    return dat;\n}\n\n\
    inline map<char, ll> counter(const string& s) noexcept {\n    map<char, ll> dat;\n\
    \    rep(i, s.size()) {\n        dat[s[i]]++;\n    }\n\n    return dat;\n}\n\n\
    /// @brief \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u8DDD\u96E2\n/// @param x1\n///\
    \ @param y1\n/// @param x2\n/// @param y2\n/// @return\ninline ld euclidean(const\
    \ ld x1, const ld y1, const ld x2, const ld y2) noexcept {\n    ld dx = x2 - x1;\n\
    \    ld dy = y2 - y1;\n\n    ld distance = sqrt(dx * dx + dy * dy);\n\n    return\
    \ distance;\n}\n\n/// @brief \u914D\u5217\u306E\u7BC4\u56F2(\u9589\u533A\u9593\
    )\u306B\u5C5E\u3059\u308B\u5024\u306E\u500B\u6570\u3092\u8A08\u7B97\n/// @tparam\
    \ T \u914D\u5217\u306E\u5024\u578B\n/// @param v \u914D\u5217\n/// @param l \u5DE6\
    \u7AEF\n/// @param r \u53F3\u7AEF\n/// @return\ntemplate <typename T>\ninline\
    \ ll lencnt(const vector<T>& v, const T& l, const T& r) noexcept {\n    return\
    \ upper_bound(all(v), r) - lower_bound(all(v), l);\n}\n\nusing GraphKey = ll;\n\
    \nstruct CostEdge {\n    GraphKey to;\n    ll cost;\n\n#if __cplusplus >= 202002L\n\
    \    auto operator<=>(const CostEdge& e) const {\n        return this->cost <=>\
    \ e.cost;\n    }\n#endif\n\n    bool operator==(const CostEdge& e) const {\n \
    \       return this->cost == e.cost;\n    }\n};\n\nstruct FromCostEdge : CostEdge\
    \ {\n    GraphKey from;\n};\n\nostream& operator<<(ostream& os, const CostEdge&\
    \ cost) {\n    os << \"{ to: \" << cost.to << \", cost: \" << cost.cost << \"\
    \ }\";\n\n    return os;\n}\n\nusing Edge = GraphKey;\n\nusing Graph = vector<vector<Edge>>;\n\
    using CostGraph = vector<vector<CostEdge>>;\n\ninline CostEdge make_cost(const\
    \ GraphKey to, const ll cost) noexcept {\n    return CostEdge{to, cost};\n}\n\n\
    inline CostGraph to_costgraph(const Graph& g) noexcept {\n    CostGraph ans(g.size());\n\
    \    rep(i, g.size()) {\n        rep(j, g[i].size()) {\n            ans[i].emplace_back(CostEdge{g[i][j],\
    \ 1});\n        }\n    }\n\n    return ans;\n}\n\ninline pair<GraphKey, ll> __tree_diamiter_dfs(const\
    \ CostGraph& G, ll u, ll par) {  // \u6700\u9060\u70B9\u9593\u8DDD\u96E2\u3068\
    \u6700\u9060\u70B9\u3092\u6C42\u3081\u308B\n    pair<GraphKey, ll> ret = make_pair((GraphKey)0,\
    \ u);\n    for (auto e : G[u]) {\n        if (e.to == par)\n            continue;\n\
    \        auto next = __tree_diamiter_dfs(G, e.to, u);\n        next.first += e.cost;\n\
    \        ret = max(ret, next);\n    }\n    return ret;\n}\n\n// \u6728\u306E\u76F4\
    \u5F84\ninline GraphKey tree_diamiter(const CostGraph& G) {\n    pair<GraphKey,\
    \ ll> p = __tree_diamiter_dfs(G, 0LL, -1LL);\n    pair<GraphKey, ll> q = __tree_diamiter_dfs(G,\
    \ p.second, -1LL);\n    return q.first;\n}\n\n// \u6728\u306E\u76F4\u5F84\n//\
    \ O(V)\ninline GraphKey tree_diamiter(const Graph& G) {\n    return tree_diamiter(to_costgraph(G));\n\
    }\n\ninline vector<ll> dijkstra(const CostGraph& G, ll start = 0, ll init = 0)\
    \ {\n    ll n = G.size();\n    assert(0 <= start && start < n);\n    vector<bool>\
    \ kakutei(n, false);\n    vll cur(n, INFLL);\n\n    reverse_queue<pll> q;\n  \
    \  cur[start] = init;\n    q.push(make_pair(cur[start], start));\n\n    while\
    \ (!q.empty()) {\n        ll pos = q.top().second;\n        q.pop();\n\n     \
    \   if (kakutei[pos])\n            continue;\n\n        kakutei[pos] = true;\n\
    \        rep(i, G[pos].size()) {\n            ll nex = G[pos][i].to;\n       \
    \     ll cost = G[pos][i].cost;\n            if (cur[nex] > cur[pos] + cost) {\n\
    \                cur[nex] = cur[pos] + cost;\n                q.push(make_pair(cur[nex],\
    \ nex));\n            }\n        }\n    }\n\n    return cur;\n}\n\ninline vector<ll>\
    \ dijkstra(const CostGraph& G, vll& prv, ll start = 0, ll init = 0) {\n    ll\
    \ n = G.size();\n    assert(0 <= start && start < n);\n    vector<bool> kakutei(n,\
    \ false);\n    vll cur(n, INFLL);\n    prv.resize(G.size(), -1);\n\n    reverse_queue<pll>\
    \ q;\n    cur[start] = init;\n    q.push(make_pair(cur[start], start));\n\n  \
    \  while (!q.empty()) {\n        ll pos = q.top().second;\n        q.pop();\n\n\
    \        if (kakutei[pos])\n            continue;\n\n        kakutei[pos] = true;\n\
    \        rep(i, G[pos].size()) {\n            ll nex = G[pos][i].to;\n       \
    \     ll cost = G[pos][i].cost;\n            if (cur[nex] > cur[pos] + cost) {\n\
    \                cur[nex] = cur[pos] + cost;\n                prv[nex] = pos;\n\
    \                q.push(make_pair(cur[nex], nex));\n            }\n        }\n\
    \    }\n\n    return cur;\n}\n\ninline vector<ll> get_path(const vector<ll>& prev,\
    \ ll t) {\n    vector<ll> path;\n    for (ll cur = t; cur != -1; cur = prev[cur])\
    \ {\n        path.push_back(cur);\n    }\n    reverse(path.begin(), path.end());\
    \  // \u9006\u9806\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\u3059\n   \
    \ return path;\n}\n\ninline vector<ll> dijkstra(const Graph& G, ll start = 0,\
    \ ll init = 0) {\n    return dijkstra(to_costgraph(G), start, init);\n}\n\ninline\
    \ vector<ll> dijkstra(const Graph& G, vll& prv, ll start = 0, ll init = 0) {\n\
    \    return dijkstra(to_costgraph(G), prv, start, init);\n}\n\ninline vector<vector<ll>>\
    \ warshall_floyd(const CostGraph& G) {\n    ll n = G.size();\n    vvll d = make_vec2<ll>(n,\
    \ n, INFLL);\n\n    rep(i, n) {\n        d[i][i] = 0;\n    }\n\n    rep(i, n)\
    \ {\n        rep(j, G[i].size()) {\n            d[i][G[i][j].to] = G[i][j].cost;\n\
    \        }\n    }\n\n    rep(k, n) {\n        rep(i, n) {\n            rep(j,\
    \ n) {\n                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n         \
    \   }\n        }\n    }\n\n    return d;\n}\n\ninline vector<vector<ll>> warshall_floyd(const\
    \ Graph& G) {\n    return warshall_floyd(to_costgraph(G));\n}\n\ntemplate <ull\
    \ bit, ull n>\nclass CustomBit {\n   public:\n    explicit CustomBit(ull val =\
    \ 0) {\n        this->__val = val;\n        this->__max_val = pow_ll(bit, n) -\
    \ 1;\n        this->__reload();\n    }\n\n    ull to_ull() const {\n        return\
    \ this->__val;\n    }\n\n    // O(1)\n    ull max_val() const {\n        return\
    \ this->__max_val;\n    }\n\n    // O(1)\n    array<ull, n> get_all() const {\n\
    \        return this->__dat;\n    }\n\n    // O(1)\n    ull get(ull x) const {\n\
    \        assert(x < n);\n\n        return this->__dat[x];\n    }\n\n    // O(1)\n\
    \    constexpr ull size() const {\n        return n;\n    }\n\n    constexpr void\
    \ set(ull x, ull val) {\n        assert(val < bit);\n        this->__dat[x] =\
    \ val;\n\n        this->__reload_val();\n    }\n\n    CustomBit& operator++(int)\
    \ {\n        this->__val++;\n        this->__reload();\n\n        return *this;\n\
    \    }\n\n    CustomBit& operator++() {\n        auto tmp = *this;\n        ++this->__val;\n\
    \n        this->__reload();\n\n        return tmp;\n    }\n\n   private:\n   \
    \ ull __val;\n    array<ull, n> __dat;\n    ull __max_val;\n\n    void __reload()\
    \ {\n        assert(0 <= this->__val && this->__val <= this->__max_val);\n   \
    \     auto tmp = this->__val;\n        for (ll i = 0; i < n; ++i) {\n        \
    \    this->__dat[i] = tmp % bit;\n            tmp /= bit;\n        }\n    }\n\n\
    \    void __reload_val() {\n        this->__val = 0;\n        ull a = 1;\n   \
    \     for (ll i = 0; i < n; ++i) {\n            this->__val += a * this->__dat[i];\n\
    \            a *= bit;\n        }\n    }\n};\n\ntemplate <ull bit, ull n>\nostream&\
    \ operator<<(ostream& os, const CustomBit<bit, n>& bits) {\n    os << \"[\";\n\
    \    for (ll i = 0; i < n; ++i) {\n        os << bits.get(i) << (i != n - 1 ?\
    \ \", \" : \"\");\n    }\n    os << \"](bit: \" << bit << \")\";\n\n    return\
    \ os;\n}\n\n/// @brief Union-Find \u6728\n/// @note 1.4 \u9AD8\u901F\u5316 + \u7701\
    \u30E1\u30E2\u30EA\u5316\n/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/union-find\n\
    class UnionFind {\n   public:\n    UnionFind() = default;\n\n    /// @brief Union-Find\
    \ \u6728\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\n    /// @param n \u8981\u7D20\
    \u6570\n    explicit UnionFind(size_t n)\n        : m_parentsOrSize(n, -1) {}\n\
    \n    /// @brief \u9802\u70B9 i \u306E root \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param i \u8ABF\u3079\u308B\
    \u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @return \u9802\
    \u70B9 i \u306E root \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    ll find(ll\
    \ i) {\n        if (m_parentsOrSize[i] < 0) {\n            return i;\n       \
    \ }\n\n        // \u7D4C\u8DEF\u5727\u7E2E\n        return (m_parentsOrSize[i]\
    \ = find(m_parentsOrSize[i]));\n    }\n\n    /// @brief a \u306E\u30B0\u30EB\u30FC\
    \u30D7\u3068 b \u306E\u30B0\u30EB\u30FC\u30D7\u3092\u7D71\u5408\u3057\u307E\u3059\
    \u3002\n    /// @param a \u4E00\u65B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n    /// @param b \u4ED6\u65B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  \
    \  void merge(ll a, ll b) {\n        a = find(a);\n        b = find(b);\n\n  \
    \      if (a != b) {\n            // union by size (\u5C0F\u3055\u3044\u307B\u3046\
    \u304C\u5B50\u306B\u306A\u308B\uFF09\n            if (-m_parentsOrSize[a] < -m_parentsOrSize[b])\
    \ {\n                std::swap(a, b);\n            }\n\n            m_parentsOrSize[a]\
    \ += m_parentsOrSize[b];\n            m_parentsOrSize[b] = a;\n        }\n   \
    \ }\n\n    /// @brief a \u3068 b \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5C5E\u3059\u304B\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param a \u4E00\
    \u65B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @param b \u4ED6\u65B9\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @return a \u3068 b \u304C\u540C\
    \u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u5834\u5408 true, \u305D\u308C\
    \u4EE5\u5916\u306E\u5834\u5408\u306F false\n    bool connected(ll a, ll b) {\n\
    \        return (find(a) == find(b));\n    }\n\n    /// @brief i \u304C\u5C5E\u3059\
    \u308B\u30B0\u30EB\u30FC\u30D7\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3057\u307E\
    \u3059\u3002\n    /// @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @return\
    \ i \u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u8981\u7D20\u6570\n\
    \    ll size(ll i) {\n        return -m_parentsOrSize[find(i)];\n    }\n\n   private:\n\
    \    // m_parentsOrSize[i] \u306F i \u306E \u89AA,\n    // \u305F\u3060\u3057\
    \ root \u306E\u5834\u5408\u306F (-1 * \u305D\u306E\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5C5E\u3059\u308B\u8981\u7D20\u6570)\n    std::vector<ll> m_parentsOrSize;\n\
    };\n\ninline vector<FromCostEdge> to_fromcostedges(const CostGraph& g) {\n   \
    \ vector<FromCostEdge> dat;\n    rep(i, g.size()) {\n        rep(j, g[i].size())\
    \ {\n            dat.emplace_back(FromCostEdge{{g[i][j].to, g[i][j].cost}, i});\n\
    \        }\n    }\n\n    return dat;\n}\n\n/// @brief \u6700\u5C0F\u30FB\u6700\
    \u5927\u5168\u57DF\u6728\n/// @param e \u8FBA(\u30BD\u30FC\u30C8\u6E08\u307F)\n\
    /// @param v \u9802\u70B9\u6570\n/// @return\n/// @see https://x.gd/7JLRg\ninline\
    \ ll get_mst(const vector<FromCostEdge>& edges, ll v) {\n    UnionFind uf(v);\n\
    \    ll sum = 0;\n\n    for (const auto& edge : edges) {\n        if (!uf.connected(edge.from,\
    \ edge.to)) {\n            uf.merge(edge.from, edge.to);\n            sum += edge.cost;\n\
    \        }\n    }\n\n    return sum;\n}\n\ntemplate <typename T>\ninline T sum(const\
    \ vector<T>& v) {\n    T ans = 0;\n    rep(i, v.size()) ans += v[i];\n\n    return\
    \ ans;\n}\n\n#ifdef cpp20\ntemplate <number T>\n#else\ntemplate <typename T>\n\
    #endif\ninline vector<T> zaatsu(const vector<T>& A) {\n    vector<T> B = A;\n\n\
    \    // B \u3092\u5C0F\u3055\u3044\u9806\u306B\u30BD\u30FC\u30C8\n    sort(B.begin(),\
    \ B.end());\n\n    // B \u304B\u3089\u91CD\u8907\u3092\u9664\u53BB\u3059\u308B\
    \n    B.erase(unique(B.begin(), B.end()), B.end());\n\n    // \u5EA7\u6A19\u5727\
    \u7E2E\u3057\u305F\u7D50\u679C\u3092\u6C42\u3081\u308B\n    vector<T> res(A.size());\n\
    \    for (ull i = 0; i < A.size(); ++i) {\n        res[i] = lower_bound(B.begin(),\
    \ B.end(), A[i]) - B.begin();\n    }\n\n    return res;\n}\n\n#ifdef cpp20\n//\
    \ https://x.gd/yonBS\nclass Doubling {\n   public:\n    explicit Doubling(const\
    \ vll& x, ull max_k) {\n        k = bit_width(max_k);\n        n = x.size();\n\
    \        dp = make_vec2<ll>(k + 1, n);\n        this->max_k = max_k;\n\n     \
    \   rep(j, n) dp[0][j] = x[j];\n\n        irep(i, k) {\n            rep(j, n)\
    \ {\n                dp[i][j] = dp[i - 1][dp[i - 1][j]];\n            }\n    \
    \    }\n    }\n\n    ull to(ull pos, ull k) const {\n        assert(k <= max_k);\n\
    \        ll now = pos;\n        for (ull i = 0; k > 0; ++i) {\n            if\
    \ (k & 1) now = dp[i][now];\n\n            k >>= 1;\n        }\n\n        return\
    \ now;\n    }\n\n   private:\n    ull n;\n    ull k;\n    ull max_k;\n    vvll\
    \ dp;\n};\n\ninline void gmerge(Graph& g, ull a, ull b) {\n    assert(a < g.size());\n\
    \    assert(b < g.size());\n    g[a].emplace_back(b);\n    g[b].emplace_back(a);\n\
    }\n\ninline void gmerge(CostGraph& g, ull a, ull b, ll c) {\n    assert(a < g.size());\n\
    \    assert(b < g.size());\n    g[a].emplace_back(make_cost(b, c));\n    g[b].emplace_back(make_cost(a,\
    \ c));\n}\n\n// Hash\nconstexpr ll HMOD = (1LL << 61LL) - 1LL;\nll HB = 0;\nvll\
    \ HPOW;\nbool inited_hpow = false;\n\ninline void fastio() noexcept {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  rng = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    HB = randint(150, HMOD - 10);\n}\n\ninline vll str_to_vec(const string& s)\
    \ {\n    vll ans(s.size());\n    rep(i, s.size()) {\n        ans[i] = s[i];\n\
    \    }\n\n    return ans;\n}\n\ninline ll hmod_mul(ll x, ll y) {\n    int128_t\
    \ t = int128_t(x) * int128_t(y);\n    t = (t >> 61) + (t & HMOD);\n\n    if (t\
    \ >= HMOD) return t - HMOD;\n    return ll(t);\n}\n\ninline void init_hash(ll\
    \ n) {\n    HPOW.resize(n + 1);\n    HPOW[0] = 1;\n    irep(i, n) HPOW[i] = hmod_mul(HPOW[i\
    \ - 1], HB);\n\n    inited_hpow = true;\n}\n\ninline vll rolling_hash(const vll&\
    \ a) {\n    assert(inited_hpow);\n\n    vll h(a.size() + 1);\n    h[0] = 0;\n\
    \    irep(i, a.size()) h[i] = (hmod_mul(h[i - 1], HB) + (a[i - 1] % HMOD)) % HMOD;\n\
    \n    return h;\n}\n\ninline vll rolling_hash(const string& s) {\n    return rolling_hash(str_to_vec(s));\n\
    }\n\ninline ll get_hash(const vll& h, ll l, ll r) {\n    ll val = h[r + 1] - hmod_mul(h[l],\
    \ HPOW[r - l + 1]);\n    if (val < 0) val += HMOD;\n\n    return val;\n}\n\nstruct\
    \ TopologicalResult {\n    vector<int> sort;\n    bool just_one;\n};\n\ninline\
    \ TopologicalResult topological_sort(const Graph& graph) noexcept {\n    // \u5404\
    \u9802\u70B9\u306E\u5165\u6B21\u6570\u3092\u7BA1\u7406\u3059\u308B\u914D\u5217\
    \n    std::vector<int> indegrees(graph.size());\n\n    // \u5165\u6B21\u6570\u3092\
    \u8A08\u7B97\u3059\u308B\n    for (const auto& v : graph) {\n        for (const\
    \ auto& to : v) {\n            ++indegrees[to];\n        }\n    }\n\n    // \u5165\
    \u6B21\u6570\u304C 0 \u306E\u9802\u70B9\u3092\u7BA1\u7406\u3059\u308B\u30AD\u30E5\
    \u30FC\uFF08\u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u7D50\u679C\u3092\u5F97\u308B\
    \u305F\u3081\u3001\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\u3092\u4F7F\
    \u7528\u3059\u308B\uFF09\n    std::priority_queue<int, std::vector<int>, std::greater<>>\
    \ q;\n\n    // \u73FE\u6642\u70B9\u3067\u5165\u6B21\u6570\u304C 0 \u306E\u9802\
    \u70B9\u3092\u3059\u3079\u3066\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\
    \n    for (int i = 0; i < static_cast<int>(graph.size()); ++i) {\n        if (indegrees[i]\
    \ == 0) {\n            q.push(i);\n        }\n    }\n\n    // \u7D50\u679C\uFF08\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\uFF09\u3092\u683C\u7D0D\u3059\
    \u308B\u914D\u5217\n    std::vector<int> result;\n\n    bool one = true;\n\n \
    \   while (!q.empty()) {\n        if (1 < q.size()) {\n            one = false;\n\
    \        }\n\n        // \u5165\u6B21\u6570\u304C 0 \u306E\u9802\u70B9\u306E\u3046\
    \u3061\u3001\u9802\u70B9\u756A\u53F7\u304C\u5C0F\u3055\u3044\u3082\u306E\u304B\
    \u3089\u53D6\u308A\u51FA\u3059\n        const int from = q.top();\n        q.pop();\n\
    \n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306B\u8FFD\u52A0\
    \u3059\u308B\n        result.push_back(from);\n\n        // \u305D\u306E\u9802\
    \u70B9\u304B\u3089\u51FA\u308B\u5404\u8FBA\u306B\u3064\u3044\u3066\n        for\
    \ (const auto& to : graph[from]) {\n            // \u305D\u306E\u5148\u306E\u9802\
    \u70B9\u306E\u5165\u6B21\u6570\u3092\u6E1B\u3089\u3057\u3001\u65B0\u305F\u306B\
    \ 0 \u306B\u306A\u3063\u305F\u3089\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\
    \n            if (--indegrees[to] == 0) {\n                q.push(to);\n     \
    \       }\n        }\n    }\n\n    // \u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\
    \uFF08\u9802\u70B9\u3092\u3059\u3079\u3066\u51E6\u7406\u3067\u304D\u3066\u3044\
    \u306A\u3044\uFF09\u5834\u5408\n    if (result.size() < graph.size()) {\n    \
    \    // \u7A7A\u306E\u914D\u5217\u3092\u8FD4\u3059\n        return {{}, false};\n\
    \    }\n\n    return {result, one};\n}\n\n// \u5171\u901A\u90E8\u5206\u3082\u3063\
    \u3066\u308B?\ninline bool has_kyotsu(pll l, pll r) noexcept {\n    if (l.first\
    \ <= r.first && r.second <= l.second) return true;\n    if (r.first <= l.first\
    \ && l.second <= r.second) return true;\n    if (r.first <= l.first && l.first\
    \ <= r.second && r.second <= l.second) return true;\n    if (l.first <= r.first\
    \ && r.first <= l.second && l.second <= r.second) return true;\n\n    return false;\n\
    }\n\n// \u5171\u901A\u90E8\u5206\u53D6\u5F97\ninline pll get_kyotu(pll l, pll\
    \ r) noexcept {\n    assert(has_kyotsu(l, r));\n    return {max(l.first, r.first),\
    \ min(l.second, r.second)};\n}\n\n// nCk\ntemplate <typename mint>\nclass Combination\
    \ {\n   private:\n    static const int MAX = 510000;\n    mint fac[MAX], finv[MAX],\
    \ inv[MAX];\n\n   public:\n    // \u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u308B\u524D\
    \u51E6\u7406\n    Combination() {\n        const int MOD = mint::mod();\n    \
    \    fac[0] = fac[1] = 1;\n        finv[0] = finv[1] = 1;\n        inv[1] = 1;\n\
    \        for (int i = 2; i < MAX; i++) {\n            fac[i] = fac[i - 1] * i;\n\
    \            inv[i] = MOD - inv[MOD % i] * (MOD / i);\n            finv[i] = finv[i\
    \ - 1] * inv[i];\n        }\n    }\n\n    // \u4E8C\u9805\u4FC2\u6570\u8A08\u7B97\
    \n    mint COM(int n, int k) const {\n        if (n < k) return 0;\n        if\
    \ (n < 0 || k < 0) return 0;\n        return fac[n] * finv[k] * finv[n - k];\n\
    \    }\n};\n\nclass imos {\n   private:\n    vll dat;\n\n   public:\n    imos(ll\
    \ n, ll init = 0) : dat(n + 1, 0) {\n        add(0, n, init);\n    }\n\n    //\
    \ [l, r) \u306B x \u3092\u52A0\u3048\u308B\n    // O(1)\n    void add(ull l, ull\
    \ r, ll x) {\n        assert(l <= r && r <= dat.size());\n        dat[l] += x;\n\
    \        dat[r] -= x;\n    }\n\n    // O(n)\n    vll get() const {\n        vll\
    \ res(dat.size() - 1);\n        res[0] = dat[0];\n        arep(i, 1, res.size())\
    \ res[i] = res[i - 1] + dat[i];\n\n        return res;\n    }\n};\n\ntemplate\
    \ <integral T>\nstruct PrimeFact {\n    vector<T> spf;\n\n    // O(N log log N)\n\
    \    PrimeFact(T N) { init(N); }\n\n    void init(T N) {\n        spf.assign(N\
    \ + 1, 0);\n        for (T i = 0; i <= N; i++) spf[i] = i;\n        for (T i =\
    \ 2; i * i <= N; i++) {\n            if (spf[i] == i) {\n                for (T\
    \ j = i * i; j <= N; j += i) {\n                    if (spf[j] == j) {\n     \
    \                   spf[j] = i;\n                    }\n                }\n  \
    \          }\n        }\n    }\n\n    // O(log N)\n    map<T, T> get(T n) {\n\
    \        assert(1 <= n && n < spf.size());\n        map<T, T> m;\n        while\
    \ (n != 1) {\n            m[spf[n]]++;\n            n /= spf[n];\n        }\n\
    \        return m;\n    }\n};\n\n#endif\n\n/* #endregion */\n\n/* Variables */\n\
    \n#ifndef LIBTEST\n\nll N, M, K, Q;\nll H, W;\nstring S = \"\";\nstring dump =\
    \ \"\";\nll codeforces_t = -1;\n\n/* Main Function */\n\nint main() {\n    return\
    \ 0;\n}\n\n#endif\n\n/* \u6587\u5B57\u5316\u3051\u6CE8\u610F */\n"
  code: "/*------------------------------------------------------------\n\n\n    \
    \           Welcome to my program!\n               @x__0 / @e6nlaq\n\n       \
    \     \u3000\u3000\u2227\uFF3F\u2227        AtCoder / Codeforces  etc...\n   \
    \         \u3000 ( \u3000\uFF65\u03C9\uFF65)\n            \uFF3F(__\u3064/\uFFE3\
    \uFFE3\uFFE3 /\n            \u3000\u3000\uFF3C/\u3000\u3000\u3000\u3000 /  C++\
    \ GCC 14.2.0\n            \u3000\u3000\u3000\u3000\uFFE3\uFFE3\uFFE3\uFFE3\uFFE3\
    \n                               Let's write Codes!\n\n\n------------------------------------------------------------*/\n\
    \n/* #region AtCoder Template */\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// \u578B\u7701\u7565\nusing uint = unsigned;\nusing ll = long long;\n\
    // using ll = __int128_t;\nusing ull = unsigned long long;\nusing ld = long double;\n\
    using pll = pair<ll, ll>;\nusing vll = vector<ll>;\nusing vb = vector<bool>;\n\
    using vc = vector<char>;\nusing vs = vector<string>;\nusing vd = vector<double>;\n\
    using vld = vector<ld>;\nusing vull = vector<ull>;\nusing vpll = vector<pll>;\n\
    using pdd = pair<ld, ld>;\nusing psl = pair<string, ll>;\nusing pcl = pair<char,\
    \ ll>;\nusing vvll = vector<vll>;\nusing vvvll = vector<vvll>;\nusing vvc = vector<vc>;\n\
    using vvs = vector<vs>;\nusing vvb = vector<vb>;\nusing vvld = vector<vld>;\n\
    using vvd = vector<vd>;\nusing mll = map<ll, ll>;\nusing mcl = map<char, ll>;\n\
    using msl = map<string, ll>;\nusing sll = set<ll>;\nusing spll = set<pair<ll,\
    \ ll>>;\nusing spdd = set<pair<ld, ld>>;\nusing stll = stack<ll>;\nusing qll =\
    \ queue<ll>;\nusing qd = queue<ld>;\nusing qs = queue<string>;\nusing qc = queue<char>;\n\
    using int128_t = __int128_t;\n\ntemplate <typename Tp1, typename Tp2>\nusing unmap\
    \ = unordered_map<Tp1, Tp2>;\n\ntemplate <typename Tp>\nusing unset = unordered_set<Tp>;\n\
    \ntemplate <typename Tp>\nusing reverse_queue = priority_queue<Tp, vector<Tp>,\
    \ greater<Tp>>;\n\ntemplate <typename T>\nusing vec2 = vector<vector<T>>;\n\n\
    template <typename T>\nusing vec3 = vector<vector<vector<T>>>;\n\n#if __cplusplus\
    \ >= 202002L\n#define cpp20\n\ntemplate <typename T>\nconcept number = integral<T>\
    \ || floating_point<T>;\n\n#endif\n\n// \u30DE\u30AF\u30ED\n#define rep(i, n)\
    \ for (ll i = 0; i < (ll)(n); i++)\n#define rrep(i, n) for (ll i = (n) - 1; i\
    \ >= 0; i--)\n#define irep(i, n) for (ll i = 1; i <= (ll)(n); i++)\n#define arep(i,\
    \ a, n) for (ll i = (a); i < (ll)(n); i++)\n#define adrep(i, a, d, n) for (ll\
    \ i = (a); i < (ll)(n); i += d)\n#define until(b) while (!(b))\n\n// \u7701\u7565\
    define\n#define all(x) (x).begin(), (x).end()\n#define rall(x) (x).rbegin(), (x).rend()\n\
    #define elif else if\n\n#define exit exit(0)\n\n// \u5B9A\u6570\n\nconst string\
    \ sl = \"\";\nconstexpr char cl = '\\0';\nconstexpr ll nl = 0LL;\nconstexpr ll\
    \ INFINT = 2047483647;\nconstexpr ll INFLL = (1LL << 61);  // \u3060\u3044\u305F\
    \u3044\nconst ll mod1 = pow(10, 9) + 1;\nconstexpr char sp = ' ';\nconst ll j2_32\
    \ = pow(2, 32);\nconst ll j2_m32 = pow(2, -32);\nconst ll j2_10 = pow(2, 10);\n\
    const vector<int> dx = {0, 0, 1, -1};\nconst vector<int> dy = {1, -1, 0, 0};\n\
    const vector<int> ex = {-1, -1, -1, 0, 0, 1, 1, 1};\nconst vector<int> ey = {-1,\
    \ 0, 1, -1, 1, -1, 0, 1};\nconst string spa = \" \";\nconstexpr bool except =\
    \ true;\n\nmt19937_64 rng;\n\n// \u8272\u3005\u306A\u30C6\u30F3\u30D7\u30EC(\u5B8C\
    \u5168\u30B3\u30D4\u30DA)\n\ntemplate <class T>\nsize_t HashCombine(const size_t\
    \ seed, const T& v) {\n    return seed ^ (std::hash<T>()(v) + 0x9e3779b9 + (seed\
    \ << 6) + (seed >> 2));\n}\n/* pair\u7528 */\ntemplate <class T, class S>\nstruct\
    \ std::hash<std::pair<T, S>> {\n    size_t operator()(const std::pair<T, S>& keyval)\
    \ const noexcept {\n        return HashCombine(std::hash<T>()(keyval.first), keyval.second);\n\
    \    }\n};\n/* vector\u7528 */\ntemplate <class T>\nstruct std::hash<std::vector<T>>\
    \ {\n    size_t operator()(const std::vector<T>& keyval) const noexcept {\n  \
    \      size_t s = 0;\n        for (auto&& v : keyval)\n            s = HashCombine(s,\
    \ v);\n        return s;\n    }\n};\n/* tuple\u7528 */\ntemplate <int N>\nstruct\
    \ HashTupleCore {\n    template <class Tuple>\n    size_t operator()(const Tuple&\
    \ keyval) const noexcept {\n        size_t s = HashTupleCore<N - 1>()(keyval);\n\
    \        return HashCombine(s, std::get<N - 1>(keyval));\n    }\n};\ntemplate\
    \ <>\nstruct HashTupleCore<0> {\n    template <class Tuple>\n    size_t operator()(const\
    \ Tuple& keyval) const noexcept { return 0; }\n};\ntemplate <class... Args>\n\
    struct std::hash<std::tuple<Args...>> {\n    size_t operator()(const tuple<Args...>&\
    \ keyval) const noexcept {\n        return HashTupleCore<tuple_size<tuple<Args...>>::value>()(keyval);\n\
    \    }\n};\n\nstd::string\noperator\"\"_s(char const* str, std::size_t) {\n  \
    \  return str;\n}\n\nstd::string\noperator*(std::string const& str, int n) {\n\
    \    if (n < 1)\n        return \"\";\n    std::string result;\n    result.reserve(str.length()\
    \ * n);\n    for (int i = 0; i < n; ++i) {\n        result += str;\n    }\n  \
    \  return result;\n}\n\n// \u95A2\u6570\u985E\n\n// O(\u221AN)\ninline bool isprime(const\
    \ ull num) noexcept {\n    if (num < 2)\n        return false;\n    else if (num\
    \ == 2)\n        return true;\n    else if (num % 2 == 0)\n        return false;\n\
    \n    for (ull i = 3; i * i <= num; i += 2) {\n        if (num % i == 0) {\n \
    \           return false;\n        }\n    }\n    return true;\n}\n\n// O(1)\n\
    inline int ctoi(const char c) noexcept {\n    if (c >= '0' && c <= '9')\n    \
    \    return c - '0';\n    return 0;\n}\n\n// \u6570\u50240\u57CB\u3081\n// O(N)\n\
    inline string zerou(const ull i, string s) noexcept {\n    while (s.size() !=\
    \ i)\n        s = '0' + s;\n    return s;\n}\n\ninline string zerou(const ull\
    \ i, const ull n) noexcept {\n    return zerou(i, to_string(n));\n}\n\n/**\n *\
    \ @brief T\u578B\u3092char\u578B\u306B\u5909\u63DB\u3057\u307E\u3059\n *\n * @tparam\
    \ T \u5909\u63DB\u3059\u308B\u578B\n * @param i \u5909\u63DB\u3059\u308B\u6570\
    \u5024\n * @return char \u5909\u63DB\u5F8C\u306E\u6587\u5B57\n */\ninline char\
    \ to_char(const ull i) {\n    assert(i <= 9);\n    return '0' + i;\n}\n\ntemplate\
    \ <typename T1, typename T2>\n    requires totally_ordered_with<T1, T2> && assignable_from<T1&,\
    \ T2>\ninline bool chmax(T1& i, const T2 j) noexcept {\n    if (i < j) {\n   \
    \     i = j;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T1, typename T2>\n    requires totally_ordered_with<T1, T2> && assignable_from<T1&,\
    \ T2>\ninline bool chmin(T1& i, const T2 j) noexcept {\n    if (i > j) {\n   \
    \     i = j;\n        return true;\n    }\n    return false;\n}\n\n/**\n * @brief\
    \ \u914D\u5217\u5185\u306E\u5168\u8981\u7D20\u3092\u51FA\u529B\u3057\u307E\u3059\
    \n *\n * @tparam T \u914D\u5217\u306E\u578B(vector<T>)\n * @param v \u914D\u5217\
    \n * @param s \u533A\u5207\u308A\u6587\u5B57(\u898F\u5B9A\u3067\u306F\u30B9\u30DA\
    \u30FC\u30B9)\n * @author https://zenn.dev/antyuntyun\n */\ntemplate <typename\
    \ T>\ninline void print(const vector<T>& v, const string& s = \" \") noexcept\
    \ {\n    rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : \"\\n\"\
    );\n}\n\ntemplate <typename A, typename B>\ninline void print(const vector<pair<A,\
    \ B>>& v, const string& s = \"\\n\") noexcept {\n    rep(i, v.size()) cout <<\
    \ v[i].first << \" \" << v[i].second << s;\n}\n\n/// @brief \u4E8C\u6B21\u5143\
    \u914D\u5217\u306E\u5168\u8981\u7D20\u3092\u51FA\u529B\u3057\u307E\u3059\n///\
    \ @tparam T \u914D\u5217\u306E\u578B(vector<vector<T>>)\n/// @param v \u4E8C\u6B21\
    \u5143\u914D\u5217\n/// @param s \u533A\u5207\u308A\u6587\u5B57\ntemplate <typename\
    \ T>\ninline void print(const vector<vector<T>>& v, string const& s = \" \") noexcept(except)\
    \ {\n    rep(i, v.size()) {\n        rep(j, v[i].size()) cout << v[i][j] << (j\
    \ != (ll)v[i].size() - 1 ? s : \"\\n\");\n    }\n}\n\n/**\n * @brief \u6587\u5B57\
    \u5217\u3092\u53CD\u8EE2\u3057\u305F\u6587\u5B57\u5217\u3092\u8FD4\u3057\u307E\
    \u3059\n *\n * @param s \u53CD\u8EE2\u3059\u308B\u6587\u5B57\u5217\n * @return\
    \ string \u53CD\u8EE2\u5F8C\u306E\u6587\u5B57\u5217\n */\ninline string srev(string\
    \ s) noexcept {\n    reverse(all(s));\n    return s;\n}\n\ntemplate <typename\
    \ T>\ninline vector<vector<T>> make_vec2(const ull H, const ull W, const T& init)\
    \ {\n    return vector<vector<T>>(H, vector<T>(W, init));\n}\n\ntemplate <typename\
    \ T>\ninline vector<vector<T>> make_vec2(const ull H, const ull W) {\n    return\
    \ vector<vector<T>>(H, vector<T>(W));\n}\n\ntemplate <typename T>\ninline vector<vector<vector<T>>>\
    \ make_vec3(const ull X, const ull Y, const ull Z, const T& init) {\n    return\
    \ vector<vector<vector<T>>>(X, make_vec2<T>(Y, Z, init));\n}\n\ntemplate <typename\
    \ T>\ninline vector<vector<vector<T>>> make_vec3(const ull X, const ull Y, const\
    \ ull Z) {\n    return vector<vector<vector<T>>>(X, make_vec2<T>(Y, Z));\n}\n\n\
    /// @brief N\u9032\u6570\u306E\u6587\u5B57\u304B\u308910\u9032\u6570\u306E\u6570\
    \u5024\u306B\u5909\u63DB\u3057\u307E\u3059\n/// @param c N\u9032\u6570\u306E\u6587\
    \u5B57\n/// @return \u5909\u63DB\u3057\u305F10\u9032\u6570\u306E\u6570\u5024\n\
    inline int ntodec(const char c) {\n    switch (c) {\n        case '0':\n     \
    \       return 0;\n        case '1':\n            return 1;\n        case '2':\n\
    \            return 2;\n        case '3':\n            return 3;\n        case\
    \ '4':\n            return 4;\n        case '5':\n            return 5;\n    \
    \    case '6':\n            return 6;\n        case '7':\n            return 7;\n\
    \        case '8':\n            return 8;\n        case '9':\n            return\
    \ 9;\n        case 'A':\n            return 10;\n        case 'B':\n         \
    \   return 11;\n        case 'C':\n            return 12;\n        case 'D':\n\
    \            return 13;\n        case 'E':\n            return 14;\n        case\
    \ 'F':\n            return 15;\n        case 'G':\n            return 16;\n  \
    \      case 'H':\n            return 17;\n        case 'I':\n            return\
    \ 18;\n        case 'J':\n            return 19;\n        case 'K':\n        \
    \    return 20;\n        case 'L':\n            return 21;\n        case 'M':\n\
    \            return 22;\n        case 'N':\n            return 23;\n        case\
    \ 'O':\n            return 24;\n        case 'P':\n            return 25;\n  \
    \      case 'Q':\n            return 26;\n        case 'R':\n            return\
    \ 27;\n        case 'S':\n            return 28;\n        case 'T':\n        \
    \    return 29;\n        case 'U':\n            return 30;\n        case 'V':\n\
    \            return 31;\n        case 'W':\n            return 32;\n        case\
    \ 'X':\n            return 33;\n        case 'Y':\n            return 34;\n  \
    \      case 'Z':\n            return 35;\n        default:\n            return\
    \ -1;\n    }\n}\n\n/// @brief 10\u9032\u6570\u306E\u6570\u5024\u3092N\u9032\u6570\
    \u306E\u6587\u5B57\u306B\u5909\u63DB\u3057\u307E\u3059\n/// @param n 10\u9032\u6570\
    \u306E\u6570\u5024\n/// @return N\u9032\u6570\u306E\u6587\u5B57\ninline char decton(const\
    \ int n) {\n    switch (n) {\n        case 0:\n            return '0';\n     \
    \   case 1:\n            return '1';\n        case 2:\n            return '2';\n\
    \        case 3:\n            return '3';\n        case 4:\n            return\
    \ '4';\n        case 5:\n            return '5';\n        case 6:\n          \
    \  return '6';\n        case 7:\n            return '7';\n        case 8:\n  \
    \          return '8';\n        case 9:\n            return '9';\n        case\
    \ 10:\n            return 'A';\n        case 11:\n            return 'B';\n  \
    \      case 12:\n            return 'C';\n        case 13:\n            return\
    \ 'D';\n        case 14:\n            return 'E';\n        case 15:\n        \
    \    return 'F';\n        case 16:\n            return 'G';\n        case 17:\n\
    \            return 'H';\n        case 18:\n            return 'I';\n        case\
    \ 19:\n            return 'J';\n        case 20:\n            return 'K';\n  \
    \      case 21:\n            return 'L';\n        case 22:\n            return\
    \ 'M';\n        case 23:\n            return 'N';\n        case 24:\n        \
    \    return 'O';\n        case 25:\n            return 'P';\n        case 26:\n\
    \            return 'Q';\n        case 27:\n            return 'R';\n        case\
    \ 28:\n            return 'S';\n        case 29:\n            return 'T';\n  \
    \      case 30:\n            return 'U';\n        case 31:\n            return\
    \ 'V';\n        case 32:\n            return 'W';\n        case 33:\n        \
    \    return 'X';\n        case 34:\n            return 'W';\n        case 35:\n\
    \            return 'Z';\n        default:\n            return '\\0';\n    }\n\
    }\n\n/// @brief N\u9032\u6570\u306E\u6587\u5B57\u5217\u3092M\u9032\u6570\u306B\
    \u76F4\u3057\u3066\u51FA\u529B\u3057\u307E\u3059\u3002\n/// @param str N\u9032\
    \u6570\u306E\u6587\u5B57\n/// @param n \u6587\u5B57\u306E\u9032\u6570\n/// @param\
    \ m \u51FA\u529B\u306E\u9032\u6570\n/// @return M\u9032\u6570\u306E\u6587\u5B57\
    \ninline string n_ary(const string& str, const int n, const int m) {\n    unsigned\
    \ long tmp = 0;\n    string ret;\n\n    for (unsigned long long i = 0; i < str.length();\
    \ i++) {\n        tmp += (unsigned long)ntodec(str[str.length() - 1 - i]) * pow_ll(n,\
    \ i);\n    }\n\n    if (tmp == 0)\n        return \"0\";\n    while (tmp != 0)\
    \ {\n        ret = decton(tmp % m) + ret;\n        tmp /= m;\n    }\n    return\
    \ ret;\n}\n\n/// @brief\n/// @tparam T n\u306E\u578B\n/// @param n \u7D20\u56E0\
    \u6570\u5206\u89E3\u3059\u308B\u6570\n/// @return \u4E0D\u660E\ntemplate <typename\
    \ T>\ninline map<T, T> prime_factor_map(T n) {\n    map<T, T> ret;\n    for (T\
    \ i = 2; i * i <= n; i++) {\n        T tmp = 0;\n        while (n % i == 0) {\n\
    \            tmp++;\n            n /= i;\n        }\n        ret[i] = tmp;\n \
    \   }\n    if (n != 1)\n        ret[n] = 1;\n    return ret;\n}\n\n// \u7D20\u56E0\
    \u6570\u5206\u89E3\n// O(sqrt(N))\nvector<pair<ll, ll>> prime_factor(ll N) {\n\
    \    vector<pair<ll, ll>> res;\n\n    for (ll p = 2; p * p <= N; ++p) {\n    \
    \    if (N % p != 0) {\n            continue;\n        }\n\n        int e = 0;\n\
    \        while (N % p == 0) {\n            ++e;\n            N /= p;\n       \
    \ }\n\n        res.emplace_back(p, e);\n    }\n\n    if (N != 1) {\n        res.emplace_back(N,\
    \ 1);\n    }\n    return res;\n}\n\n// \u7D04\u6570\u306E\u500B\u6570\n// O(sqrt(N))\n\
    inline ull divisor_num(const ll N) {\n    map<ll, ll> pf = prime_factor_map(N);\n\
    \    ull ret = 1;\n    for (auto p : pf) {\n        ret *= (p.second + 1);\n \
    \   }\n    return ret;\n}\n\n/// @brief n\u306E\u7D04\u6570\u3092\u5168\u5217\u6319\
    \u3057\u307E\u3059\u3002(\u8A08\u7B97\u91CF: O(sqrt(N)))\n/// @param n \u5168\u5217\
    \u6319\u3059\u308B\u7D04\u6570\n/// @return n\u306E\u7D04\u6570\ninline vll divisor(const\
    \ ll n) {\n    vll ret;\n    for (ll i = 1; i * i <= n; i++) {\n        if (n\
    \ % i == 0) {\n            ret.push_back(i);\n            if (i * i != n)\n  \
    \              ret.push_back(n / i);\n        }\n    }\n    sort(ret.begin(),\
    \ ret.end());\n    return ret;\n}\n\n/// @brief \u6587\u5B57\u5217\u304C\u6570\
    \u5B57\u306E\u307F\u304B\u5224\u5B9A\u3057\u307E\u3059 O(|S|)\n/// @param s \u5224\
    \u5B9A\u3059\u308B\u6587\u5B57\u5217\n/// @return \u6570\u5024\u3067\u3067\u304D\
    \u305F\u6587\u5B57\u5217\u304B\u3069\u3046\u304B\ninline bool isint(const string&\
    \ s) noexcept {\n    rep(i, s.size()) {\n        if (!isdigit(s[i])) {\n     \
    \       return false;\n        }\n    }\n\n    return true;\n}\n\n/// @brief \u4E8C\
    \u6B21\u5143\u914D\u5217\u309290\u5EA6\u6642\u8A08\u56DE\u308A\u306B\u56DE\u8EE2\
    \u3059\u308B\n/// @tparam T \u914D\u5217\u306E\u578B(vector<vector<T>>)\n/// @param\
    \ arr \u4E8C\u6B21\u5143\u914D\u5217\n/// @return \u8FD4\u308A\u5024\ntemplate\
    \ <typename T>\n[[nodiscard]] inline vector<vector<T>> rot90(const vector<vector<T>>&\
    \ A) {\n    ll N = A.size(), M = A[0].size();\n    vector<vector<T>> ret(M, vector<T>(N));\n\
    \n    ll _i = 0, _j = 0;\n\n    rep(j, M) {\n        for (ll i = N - 1; i >= 0;\
    \ i--) {\n            ret[_i][_j] = A[i][j];\n            _j++;\n        }\n \
    \       _j = 0;\n        _i++;\n    }\n\n    return ret;\n}\n\n/// @brief \u56DE\
    \u6587\u304B\u3069\u3046\u304B\u5224\u5B9A\n/// @param str \u6587\u5B57\u5217\n\
    /// @return \u56DE\u6587\u304B\u3069\u3046\u304B\ninline bool ispalind(const string&\
    \ str) noexcept {\n    ull n = str.length();\n    for (ull i = 0; i < n / 2; i++)\
    \ {\n        if (str[i] != str[n - i - 1]) {\n            return false;\n    \
    \    }\n    }\n    return true;\n}\n\ninline bool ispalind(const string& str,\
    \ ull x, ull n) {\n    assert(x < str.size());\n    assert(x + n <= str.size());\n\
    \n    for (ull i = 0; i < n / 2; i++) {\n        if (str[x + i] != str[(x + n)\
    \ - i - 1]) {\n            return false;\n        }\n    }\n    return true;\n\
    }\n\n/// @brief 10\u9032\u6CD5\u3067\u8868\u3057\u305F\u6642\u306E\u5404\u6841\
    \u306E\u548C\u3092\u6C42\u3081\u307E\u3059\n/// @param s 10\u9032\u6CD5\u3067\u8868\
    \u3057\u305F\u6587\u5B57\u5217\n/// @return \u5404\u6841\u306E\u548C\ninline ll\
    \ csum(const string& s) noexcept {\n    ll ret = 0;\n    rep(i, s.size()) {\n\
    \        ret += ctoi(s[i]);\n    }\n\n    return ret;\n}\n\n/// @brief csum\u306E\
    \u6570\u5024\u7528\u306E\u88DC\u5B8C\u95A2\u6570\n/// @param n \u6570\u5024\n\
    /// @return \u5404\u6841\u306E\u548C\ninline ll csum(const ll n) noexcept {\n\
    \    return csum(to_string(n));\n}\n\n/// @brief \u4E00\u6B21\u5143\u306E\u7D2F\
    \u7A4D\u548C\u3092\u8FD4\u3057\u307E\u3059\n/// @tparam T vector\u306E\u578B\n\
    /// @param v \u52A0\u5DE5\u3059\u308B\u524D\u306E\u914D\u5217\n/// @return \u52A0\
    \u5DE5\u5F8C\u306E\u914D\u5217(\u9577\u3055\u306F |v|+1 \u3068\u306A\u308A\u307E\
    \u3059\u3002)\ntemplate <typename T>\ninline vector<T> cum(const vector<T>& v)\
    \ noexcept {\n    vector<T> ans(v.size() + 1);\n    ans[0] = 0;\n    for (ull\
    \ i = 1; i <= v.size(); i++) {\n        ans[i] = ans[i - 1] + v[i - 1];\n    }\n\
    \    return ans;\n}\n\n/// @brief \u4E8C\u6B21\u5143\u306E\u7D2F\u7A4D\u548C\u3092\
    \u8FD4\u3057\u307E\u3059\n/// @tparam T vector<vector<>>\u306E\u578B\n/// @param\
    \ v \u52A0\u5DE5\u524D\u306E\u914D\u5217\n/// @return \u52A0\u5DE5\u5F8C\u306E\
    \u914D\u5217(\u9577\u3055\u306F\u305D\u308C\u305E\u308C+1\u306B\u306A\u308A\u307E\
    \u3059)\ntemplate <typename T>\ninline vec2<T> cum(const vec2<T>& v) {\n    assert(v.size()\
    \ > 0);\n    ull H = v.size(), W = v[0].size();\n    auto ret = make_vec2<T>(H\
    \ + 1, W + 1, 0);\n    for (ull i = 1; i <= H; i++) {\n        for (ull j = 1;\
    \ j <= W; j++) {\n            ret[i][j] = ret[i][j - 1] + v[i - 1][j - 1];\n \
    \       }\n    }\n\n    for (ull j = 1; j <= W; j++) {\n        for (ull i = 1;\
    \ i <= H; i++) {\n            ret[i][j] += ret[i - 1][j];\n        }\n    }\n\n\
    \    return ret;\n}\n\ntemplate <typename T>\ninline vec3<T> cum(const vec3<T>&\
    \ v) {\n    assert(v.size() > 0 && v[0].size() > 0);\n    ll x = v.size();\n \
    \   ll y = v[0].size();\n    ll z = v[0][0].size();\n    auto ret = make_vec3<T>(x\
    \ + 1, y + 1, z + 1, 0);\n\n    for (ll i = 0; i < x; ++i) {\n        for (ll\
    \ j = 0; j < y; ++j) {\n            for (ll k = 0; k < z; ++k) {\n           \
    \     ret[i + 1][j + 1][k + 1] =\n                    ret[i][j + 1][k + 1] + ret[i\
    \ + 1][j][k + 1] +\n                    ret[i + 1][j + 1][k] - ret[i][j][k + 1]\
    \ - ret[i][j + 1][k] -\n                    ret[i + 1][j][k] + ret[i][j][k] +\
    \ v[i][j][k];\n            }\n        }\n    }\n\n    return ret;\n}\n\n// 0-indexed\n\
    template <typename T>\ninline ll cumcnt(const vec2<T>& z, ll lx, ll ly, ll rx,\
    \ ll ry) {\n    lx++;\n    ly++;\n    rx++;\n    ry++;\n    return z[rx][ry] +\
    \ z[lx - 1][ly - 1] - z[lx - 1][ry] - z[rx][ly - 1];\n}\n\ntemplate <typename\
    \ T>\ninline ll cumcnt(const vec3<T>& z, ll lx, ll ly, ll lz, ll rx, ll ry, ll\
    \ rz) {\n    lx++;\n    ly++;\n    lz++;\n    rx++;\n    ry++;\n    rz++;\n  \
    \  return z[rx][ry][rz] - z[lx - 1][ry][rz] - z[rx][ly - 1][rz] - z[rx][ry][lz\
    \ - 1] + z[lx - 1][ly - 1][rz] + z[lx - 1][ry][lz - 1] + z[rx][ly - 1][lz - 1]\
    \ - z[lx - 1][ly - 1][lz - 1];\n}\n\n#ifdef cpp20\ntemplate <integral T>\n#else\n\
    template <typename T>\n#endif\ninline vector<T> cumxor(const vector<T>& x) {\n\
    \    vector<T> ans(x.size() + 1);\n    ans[0] = 0;\n    irep(i, x.size()) {\n\
    \        ans[i] = ans[i - 1] ^ x[i - 1];\n    }\n\n    return ans;\n}\n\n/// @brief\
    \ \u30E9\u30F3\u30C0\u30E0\u306A\u6570\u5024\u3092\u8FD4\u3059\n/// @param l \u6700\
    \u5C0F\u5024\n/// @param r \u6700\u5927\u5024\n/// @return\ninline ll randint(const\
    \ ll l, const ll r) noexcept {\n    if (l == r)\n        return l;\n    return\
    \ l + (rng() % (r - l + 1));\n}\n\n/// @brief \u9AD8\u901F\u5168\u63A2\u7D22 O(log\
    \ N)\n/// @tparam T \u914D\u5217\u306E\u578B\n/// @param v \u914D\u5217\n/// @param\
    \ x \u63A2\u7D22\u3059\u308B\u3084\u3064\n/// @return \u6570\ntemplate <typename\
    \ T>\ninline long long bound_count(const vector<T>& v, const T& x) noexcept {\n\
    \    auto l = lower_bound(v.begin(), v.end(), x);\n    auto u = upper_bound(v.begin(),\
    \ v.end(), x);\n\n    if (*l != x) {\n        return 0;\n    }\n\n    if (u ==\
    \ v.end()) {\n        return v.size() - (l - v.begin());\n    } else {\n     \
    \   return (u - v.begin()) - (l - v.begin());\n    }\n}\n\n/// @brief \u914D\u5217\
    \u306E\u6700\u8FD1\u5024\u3092\u6C42\u3081\u308B\n/// @tparam T \u914D\u5217\u306E\
    \u578B\n/// @param v \u914D\u5217\n/// @param x \u6700\u8FD1\u5024\u3092\u6C42\
    \u3081\u308B\u5024\n/// @return x\u306E\u6700\u8FD1\u5024\ntemplate <typename\
    \ T>\ninline T recent(const vector<T>& v, const T& x) noexcept {\n    auto it\
    \ = lower_bound(all(v), x);\n\n    if (it == v.end())\n        return *prev(v.end(),\
    \ 1);\n    else {\n        if (it == v.begin())\n            return *v.begin();\n\
    \        else {\n            if (abs(*it - x) < abs(*prev(it, 1) - x))\n     \
    \           return *it;\n            else\n                return *prev(it, 1);\n\
    \        }\n    }\n}\n\n/// @brief \u6587\u5B57\u5217\u5727\u7E2E\n/// @param\
    \ str \u5727\u7E2E\u3059\u308B\u6587\u5B57\u5217\n/// @return \u5727\u7E2E\u5F8C\
    \ninline vector<pair<char, ull>> rlencode(const string& str) noexcept {\n    ull\
    \ n = (ull)str.size();\n    vector<pair<char, ull>> ret;\n    for (ull l = 0;\
    \ l < n;) {\n        ull r = l + 1;\n        for (; r < n && str[l] == str[r];\
    \ r++) {\n        };\n        ret.push_back({str[l], r - l});\n        l = r;\n\
    \    }\n    return ret;\n}\n\ntemplate <typename T>\ninline vector<pair<T, ull>>\
    \ rlencode(const vector<T>& v) noexcept {\n    ull n = (ull)v.size();\n    vector<pair<T,\
    \ ull>> ret;\n    for (ull l = 0; l < n;) {\n        ull r = l + 1;\n        for\
    \ (; r < n && v[l] == v[r]; r++) {\n        };\n        ret.push_back({v[l], r\
    \ - l});\n        l = r;\n    }\n    return ret;\n}\n\ntemplate <typename T>\n\
    inline map<T, ll> counter(const vector<T>& v) noexcept {\n    map<T, ll> dat;\n\
    \    rep(i, v.size()) {\n        dat[v[i]]++;\n    }\n\n    return dat;\n}\n\n\
    inline map<char, ll> counter(const string& s) noexcept {\n    map<char, ll> dat;\n\
    \    rep(i, s.size()) {\n        dat[s[i]]++;\n    }\n\n    return dat;\n}\n\n\
    /// @brief \u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u8DDD\u96E2\n/// @param x1\n///\
    \ @param y1\n/// @param x2\n/// @param y2\n/// @return\ninline ld euclidean(const\
    \ ld x1, const ld y1, const ld x2, const ld y2) noexcept {\n    ld dx = x2 - x1;\n\
    \    ld dy = y2 - y1;\n\n    ld distance = sqrt(dx * dx + dy * dy);\n\n    return\
    \ distance;\n}\n\n/// @brief \u914D\u5217\u306E\u7BC4\u56F2(\u9589\u533A\u9593\
    )\u306B\u5C5E\u3059\u308B\u5024\u306E\u500B\u6570\u3092\u8A08\u7B97\n/// @tparam\
    \ T \u914D\u5217\u306E\u5024\u578B\n/// @param v \u914D\u5217\n/// @param l \u5DE6\
    \u7AEF\n/// @param r \u53F3\u7AEF\n/// @return\ntemplate <typename T>\ninline\
    \ ll lencnt(const vector<T>& v, const T& l, const T& r) noexcept {\n    return\
    \ upper_bound(all(v), r) - lower_bound(all(v), l);\n}\n\nusing GraphKey = ll;\n\
    \nstruct CostEdge {\n    GraphKey to;\n    ll cost;\n\n#if __cplusplus >= 202002L\n\
    \    auto operator<=>(const CostEdge& e) const {\n        return this->cost <=>\
    \ e.cost;\n    }\n#endif\n\n    bool operator==(const CostEdge& e) const {\n \
    \       return this->cost == e.cost;\n    }\n};\n\nstruct FromCostEdge : CostEdge\
    \ {\n    GraphKey from;\n};\n\nostream& operator<<(ostream& os, const CostEdge&\
    \ cost) {\n    os << \"{ to: \" << cost.to << \", cost: \" << cost.cost << \"\
    \ }\";\n\n    return os;\n}\n\nusing Edge = GraphKey;\n\nusing Graph = vector<vector<Edge>>;\n\
    using CostGraph = vector<vector<CostEdge>>;\n\ninline CostEdge make_cost(const\
    \ GraphKey to, const ll cost) noexcept {\n    return CostEdge{to, cost};\n}\n\n\
    inline CostGraph to_costgraph(const Graph& g) noexcept {\n    CostGraph ans(g.size());\n\
    \    rep(i, g.size()) {\n        rep(j, g[i].size()) {\n            ans[i].emplace_back(CostEdge{g[i][j],\
    \ 1});\n        }\n    }\n\n    return ans;\n}\n\ninline pair<GraphKey, ll> __tree_diamiter_dfs(const\
    \ CostGraph& G, ll u, ll par) {  // \u6700\u9060\u70B9\u9593\u8DDD\u96E2\u3068\
    \u6700\u9060\u70B9\u3092\u6C42\u3081\u308B\n    pair<GraphKey, ll> ret = make_pair((GraphKey)0,\
    \ u);\n    for (auto e : G[u]) {\n        if (e.to == par)\n            continue;\n\
    \        auto next = __tree_diamiter_dfs(G, e.to, u);\n        next.first += e.cost;\n\
    \        ret = max(ret, next);\n    }\n    return ret;\n}\n\n// \u6728\u306E\u76F4\
    \u5F84\ninline GraphKey tree_diamiter(const CostGraph& G) {\n    pair<GraphKey,\
    \ ll> p = __tree_diamiter_dfs(G, 0LL, -1LL);\n    pair<GraphKey, ll> q = __tree_diamiter_dfs(G,\
    \ p.second, -1LL);\n    return q.first;\n}\n\n// \u6728\u306E\u76F4\u5F84\n//\
    \ O(V)\ninline GraphKey tree_diamiter(const Graph& G) {\n    return tree_diamiter(to_costgraph(G));\n\
    }\n\ninline vector<ll> dijkstra(const CostGraph& G, ll start = 0, ll init = 0)\
    \ {\n    ll n = G.size();\n    assert(0 <= start && start < n);\n    vector<bool>\
    \ kakutei(n, false);\n    vll cur(n, INFLL);\n\n    reverse_queue<pll> q;\n  \
    \  cur[start] = init;\n    q.push(make_pair(cur[start], start));\n\n    while\
    \ (!q.empty()) {\n        ll pos = q.top().second;\n        q.pop();\n\n     \
    \   if (kakutei[pos])\n            continue;\n\n        kakutei[pos] = true;\n\
    \        rep(i, G[pos].size()) {\n            ll nex = G[pos][i].to;\n       \
    \     ll cost = G[pos][i].cost;\n            if (cur[nex] > cur[pos] + cost) {\n\
    \                cur[nex] = cur[pos] + cost;\n                q.push(make_pair(cur[nex],\
    \ nex));\n            }\n        }\n    }\n\n    return cur;\n}\n\ninline vector<ll>\
    \ dijkstra(const CostGraph& G, vll& prv, ll start = 0, ll init = 0) {\n    ll\
    \ n = G.size();\n    assert(0 <= start && start < n);\n    vector<bool> kakutei(n,\
    \ false);\n    vll cur(n, INFLL);\n    prv.resize(G.size(), -1);\n\n    reverse_queue<pll>\
    \ q;\n    cur[start] = init;\n    q.push(make_pair(cur[start], start));\n\n  \
    \  while (!q.empty()) {\n        ll pos = q.top().second;\n        q.pop();\n\n\
    \        if (kakutei[pos])\n            continue;\n\n        kakutei[pos] = true;\n\
    \        rep(i, G[pos].size()) {\n            ll nex = G[pos][i].to;\n       \
    \     ll cost = G[pos][i].cost;\n            if (cur[nex] > cur[pos] + cost) {\n\
    \                cur[nex] = cur[pos] + cost;\n                prv[nex] = pos;\n\
    \                q.push(make_pair(cur[nex], nex));\n            }\n        }\n\
    \    }\n\n    return cur;\n}\n\ninline vector<ll> get_path(const vector<ll>& prev,\
    \ ll t) {\n    vector<ll> path;\n    for (ll cur = t; cur != -1; cur = prev[cur])\
    \ {\n        path.push_back(cur);\n    }\n    reverse(path.begin(), path.end());\
    \  // \u9006\u9806\u306A\u306E\u3067\u3072\u3063\u304F\u308A\u8FD4\u3059\n   \
    \ return path;\n}\n\ninline vector<ll> dijkstra(const Graph& G, ll start = 0,\
    \ ll init = 0) {\n    return dijkstra(to_costgraph(G), start, init);\n}\n\ninline\
    \ vector<ll> dijkstra(const Graph& G, vll& prv, ll start = 0, ll init = 0) {\n\
    \    return dijkstra(to_costgraph(G), prv, start, init);\n}\n\ninline vector<vector<ll>>\
    \ warshall_floyd(const CostGraph& G) {\n    ll n = G.size();\n    vvll d = make_vec2<ll>(n,\
    \ n, INFLL);\n\n    rep(i, n) {\n        d[i][i] = 0;\n    }\n\n    rep(i, n)\
    \ {\n        rep(j, G[i].size()) {\n            d[i][G[i][j].to] = G[i][j].cost;\n\
    \        }\n    }\n\n    rep(k, n) {\n        rep(i, n) {\n            rep(j,\
    \ n) {\n                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\n         \
    \   }\n        }\n    }\n\n    return d;\n}\n\ninline vector<vector<ll>> warshall_floyd(const\
    \ Graph& G) {\n    return warshall_floyd(to_costgraph(G));\n}\n\ntemplate <ull\
    \ bit, ull n>\nclass CustomBit {\n   public:\n    explicit CustomBit(ull val =\
    \ 0) {\n        this->__val = val;\n        this->__max_val = pow_ll(bit, n) -\
    \ 1;\n        this->__reload();\n    }\n\n    ull to_ull() const {\n        return\
    \ this->__val;\n    }\n\n    // O(1)\n    ull max_val() const {\n        return\
    \ this->__max_val;\n    }\n\n    // O(1)\n    array<ull, n> get_all() const {\n\
    \        return this->__dat;\n    }\n\n    // O(1)\n    ull get(ull x) const {\n\
    \        assert(x < n);\n\n        return this->__dat[x];\n    }\n\n    // O(1)\n\
    \    constexpr ull size() const {\n        return n;\n    }\n\n    constexpr void\
    \ set(ull x, ull val) {\n        assert(val < bit);\n        this->__dat[x] =\
    \ val;\n\n        this->__reload_val();\n    }\n\n    CustomBit& operator++(int)\
    \ {\n        this->__val++;\n        this->__reload();\n\n        return *this;\n\
    \    }\n\n    CustomBit& operator++() {\n        auto tmp = *this;\n        ++this->__val;\n\
    \n        this->__reload();\n\n        return tmp;\n    }\n\n   private:\n   \
    \ ull __val;\n    array<ull, n> __dat;\n    ull __max_val;\n\n    void __reload()\
    \ {\n        assert(0 <= this->__val && this->__val <= this->__max_val);\n   \
    \     auto tmp = this->__val;\n        for (ll i = 0; i < n; ++i) {\n        \
    \    this->__dat[i] = tmp % bit;\n            tmp /= bit;\n        }\n    }\n\n\
    \    void __reload_val() {\n        this->__val = 0;\n        ull a = 1;\n   \
    \     for (ll i = 0; i < n; ++i) {\n            this->__val += a * this->__dat[i];\n\
    \            a *= bit;\n        }\n    }\n};\n\ntemplate <ull bit, ull n>\nostream&\
    \ operator<<(ostream& os, const CustomBit<bit, n>& bits) {\n    os << \"[\";\n\
    \    for (ll i = 0; i < n; ++i) {\n        os << bits.get(i) << (i != n - 1 ?\
    \ \", \" : \"\");\n    }\n    os << \"](bit: \" << bit << \")\";\n\n    return\
    \ os;\n}\n\n/// @brief Union-Find \u6728\n/// @note 1.4 \u9AD8\u901F\u5316 + \u7701\
    \u30E1\u30E2\u30EA\u5316\n/// @see https://zenn.dev/reputeless/books/standard-cpp-for-competitive-programming/viewer/union-find\n\
    class UnionFind {\n   public:\n    UnionFind() = default;\n\n    /// @brief Union-Find\
    \ \u6728\u3092\u69CB\u7BC9\u3057\u307E\u3059\u3002\n    /// @param n \u8981\u7D20\
    \u6570\n    explicit UnionFind(size_t n)\n        : m_parentsOrSize(n, -1) {}\n\
    \n    /// @brief \u9802\u70B9 i \u306E root \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param i \u8ABF\u3079\u308B\
    \u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @return \u9802\
    \u70B9 i \u306E root \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    ll find(ll\
    \ i) {\n        if (m_parentsOrSize[i] < 0) {\n            return i;\n       \
    \ }\n\n        // \u7D4C\u8DEF\u5727\u7E2E\n        return (m_parentsOrSize[i]\
    \ = find(m_parentsOrSize[i]));\n    }\n\n    /// @brief a \u306E\u30B0\u30EB\u30FC\
    \u30D7\u3068 b \u306E\u30B0\u30EB\u30FC\u30D7\u3092\u7D71\u5408\u3057\u307E\u3059\
    \u3002\n    /// @param a \u4E00\u65B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n    /// @param b \u4ED6\u65B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  \
    \  void merge(ll a, ll b) {\n        a = find(a);\n        b = find(b);\n\n  \
    \      if (a != b) {\n            // union by size (\u5C0F\u3055\u3044\u307B\u3046\
    \u304C\u5B50\u306B\u306A\u308B\uFF09\n            if (-m_parentsOrSize[a] < -m_parentsOrSize[b])\
    \ {\n                std::swap(a, b);\n            }\n\n            m_parentsOrSize[a]\
    \ += m_parentsOrSize[b];\n            m_parentsOrSize[b] = a;\n        }\n   \
    \ }\n\n    /// @brief a \u3068 b \u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5C5E\u3059\u304B\u3092\u8FD4\u3057\u307E\u3059\u3002\n    /// @param a \u4E00\
    \u65B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @param b \u4ED6\u65B9\
    \u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @return a \u3068 b \u304C\u540C\
    \u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u5834\u5408 true, \u305D\u308C\
    \u4EE5\u5916\u306E\u5834\u5408\u306F false\n    bool connected(ll a, ll b) {\n\
    \        return (find(a) == find(b));\n    }\n\n    /// @brief i \u304C\u5C5E\u3059\
    \u308B\u30B0\u30EB\u30FC\u30D7\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3057\u307E\
    \u3059\u3002\n    /// @param i \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n    /// @return\
    \ i \u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u8981\u7D20\u6570\n\
    \    ll size(ll i) {\n        return -m_parentsOrSize[find(i)];\n    }\n\n   private:\n\
    \    // m_parentsOrSize[i] \u306F i \u306E \u89AA,\n    // \u305F\u3060\u3057\
    \ root \u306E\u5834\u5408\u306F (-1 * \u305D\u306E\u30B0\u30EB\u30FC\u30D7\u306B\
    \u5C5E\u3059\u308B\u8981\u7D20\u6570)\n    std::vector<ll> m_parentsOrSize;\n\
    };\n\ninline vector<FromCostEdge> to_fromcostedges(const CostGraph& g) {\n   \
    \ vector<FromCostEdge> dat;\n    rep(i, g.size()) {\n        rep(j, g[i].size())\
    \ {\n            dat.emplace_back(FromCostEdge{{g[i][j].to, g[i][j].cost}, i});\n\
    \        }\n    }\n\n    return dat;\n}\n\n/// @brief \u6700\u5C0F\u30FB\u6700\
    \u5927\u5168\u57DF\u6728\n/// @param e \u8FBA(\u30BD\u30FC\u30C8\u6E08\u307F)\n\
    /// @param v \u9802\u70B9\u6570\n/// @return\n/// @see https://x.gd/7JLRg\ninline\
    \ ll get_mst(const vector<FromCostEdge>& edges, ll v) {\n    UnionFind uf(v);\n\
    \    ll sum = 0;\n\n    for (const auto& edge : edges) {\n        if (!uf.connected(edge.from,\
    \ edge.to)) {\n            uf.merge(edge.from, edge.to);\n            sum += edge.cost;\n\
    \        }\n    }\n\n    return sum;\n}\n\ntemplate <typename T>\ninline T sum(const\
    \ vector<T>& v) {\n    T ans = 0;\n    rep(i, v.size()) ans += v[i];\n\n    return\
    \ ans;\n}\n\n#ifdef cpp20\ntemplate <number T>\n#else\ntemplate <typename T>\n\
    #endif\ninline vector<T> zaatsu(const vector<T>& A) {\n    vector<T> B = A;\n\n\
    \    // B \u3092\u5C0F\u3055\u3044\u9806\u306B\u30BD\u30FC\u30C8\n    sort(B.begin(),\
    \ B.end());\n\n    // B \u304B\u3089\u91CD\u8907\u3092\u9664\u53BB\u3059\u308B\
    \n    B.erase(unique(B.begin(), B.end()), B.end());\n\n    // \u5EA7\u6A19\u5727\
    \u7E2E\u3057\u305F\u7D50\u679C\u3092\u6C42\u3081\u308B\n    vector<T> res(A.size());\n\
    \    for (ull i = 0; i < A.size(); ++i) {\n        res[i] = lower_bound(B.begin(),\
    \ B.end(), A[i]) - B.begin();\n    }\n\n    return res;\n}\n\n#ifdef cpp20\n//\
    \ https://x.gd/yonBS\nclass Doubling {\n   public:\n    explicit Doubling(const\
    \ vll& x, ull max_k) {\n        k = bit_width(max_k);\n        n = x.size();\n\
    \        dp = make_vec2<ll>(k + 1, n);\n        this->max_k = max_k;\n\n     \
    \   rep(j, n) dp[0][j] = x[j];\n\n        irep(i, k) {\n            rep(j, n)\
    \ {\n                dp[i][j] = dp[i - 1][dp[i - 1][j]];\n            }\n    \
    \    }\n    }\n\n    ull to(ull pos, ull k) const {\n        assert(k <= max_k);\n\
    \        ll now = pos;\n        for (ull i = 0; k > 0; ++i) {\n            if\
    \ (k & 1) now = dp[i][now];\n\n            k >>= 1;\n        }\n\n        return\
    \ now;\n    }\n\n   private:\n    ull n;\n    ull k;\n    ull max_k;\n    vvll\
    \ dp;\n};\n\ninline void gmerge(Graph& g, ull a, ull b) {\n    assert(a < g.size());\n\
    \    assert(b < g.size());\n    g[a].emplace_back(b);\n    g[b].emplace_back(a);\n\
    }\n\ninline void gmerge(CostGraph& g, ull a, ull b, ll c) {\n    assert(a < g.size());\n\
    \    assert(b < g.size());\n    g[a].emplace_back(make_cost(b, c));\n    g[b].emplace_back(make_cost(a,\
    \ c));\n}\n\n// Hash\nconstexpr ll HMOD = (1LL << 61LL) - 1LL;\nll HB = 0;\nvll\
    \ HPOW;\nbool inited_hpow = false;\n\ninline void fastio() noexcept {\n    cin.tie(nullptr);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(15);\n  \
    \  rng = mt19937_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \    HB = randint(150, HMOD - 10);\n}\n\ninline vll str_to_vec(const string& s)\
    \ {\n    vll ans(s.size());\n    rep(i, s.size()) {\n        ans[i] = s[i];\n\
    \    }\n\n    return ans;\n}\n\ninline ll hmod_mul(ll x, ll y) {\n    int128_t\
    \ t = int128_t(x) * int128_t(y);\n    t = (t >> 61) + (t & HMOD);\n\n    if (t\
    \ >= HMOD) return t - HMOD;\n    return ll(t);\n}\n\ninline void init_hash(ll\
    \ n) {\n    HPOW.resize(n + 1);\n    HPOW[0] = 1;\n    irep(i, n) HPOW[i] = hmod_mul(HPOW[i\
    \ - 1], HB);\n\n    inited_hpow = true;\n}\n\ninline vll rolling_hash(const vll&\
    \ a) {\n    assert(inited_hpow);\n\n    vll h(a.size() + 1);\n    h[0] = 0;\n\
    \    irep(i, a.size()) h[i] = (hmod_mul(h[i - 1], HB) + (a[i - 1] % HMOD)) % HMOD;\n\
    \n    return h;\n}\n\ninline vll rolling_hash(const string& s) {\n    return rolling_hash(str_to_vec(s));\n\
    }\n\ninline ll get_hash(const vll& h, ll l, ll r) {\n    ll val = h[r + 1] - hmod_mul(h[l],\
    \ HPOW[r - l + 1]);\n    if (val < 0) val += HMOD;\n\n    return val;\n}\n\nstruct\
    \ TopologicalResult {\n    vector<int> sort;\n    bool just_one;\n};\n\ninline\
    \ TopologicalResult topological_sort(const Graph& graph) noexcept {\n    // \u5404\
    \u9802\u70B9\u306E\u5165\u6B21\u6570\u3092\u7BA1\u7406\u3059\u308B\u914D\u5217\
    \n    std::vector<int> indegrees(graph.size());\n\n    // \u5165\u6B21\u6570\u3092\
    \u8A08\u7B97\u3059\u308B\n    for (const auto& v : graph) {\n        for (const\
    \ auto& to : v) {\n            ++indegrees[to];\n        }\n    }\n\n    // \u5165\
    \u6B21\u6570\u304C 0 \u306E\u9802\u70B9\u3092\u7BA1\u7406\u3059\u308B\u30AD\u30E5\
    \u30FC\uFF08\u8F9E\u66F8\u9806\u6700\u5C0F\u306E\u7D50\u679C\u3092\u5F97\u308B\
    \u305F\u3081\u3001\u512A\u5148\u5EA6\u4ED8\u304D\u30AD\u30E5\u30FC\u3092\u4F7F\
    \u7528\u3059\u308B\uFF09\n    std::priority_queue<int, std::vector<int>, std::greater<>>\
    \ q;\n\n    // \u73FE\u6642\u70B9\u3067\u5165\u6B21\u6570\u304C 0 \u306E\u9802\
    \u70B9\u3092\u3059\u3079\u3066\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\
    \n    for (int i = 0; i < static_cast<int>(graph.size()); ++i) {\n        if (indegrees[i]\
    \ == 0) {\n            q.push(i);\n        }\n    }\n\n    // \u7D50\u679C\uFF08\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\uFF09\u3092\u683C\u7D0D\u3059\
    \u308B\u914D\u5217\n    std::vector<int> result;\n\n    bool one = true;\n\n \
    \   while (!q.empty()) {\n        if (1 < q.size()) {\n            one = false;\n\
    \        }\n\n        // \u5165\u6B21\u6570\u304C 0 \u306E\u9802\u70B9\u306E\u3046\
    \u3061\u3001\u9802\u70B9\u756A\u53F7\u304C\u5C0F\u3055\u3044\u3082\u306E\u304B\
    \u3089\u53D6\u308A\u51FA\u3059\n        const int from = q.top();\n        q.pop();\n\
    \n        // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u306B\u8FFD\u52A0\
    \u3059\u308B\n        result.push_back(from);\n\n        // \u305D\u306E\u9802\
    \u70B9\u304B\u3089\u51FA\u308B\u5404\u8FBA\u306B\u3064\u3044\u3066\n        for\
    \ (const auto& to : graph[from]) {\n            // \u305D\u306E\u5148\u306E\u9802\
    \u70B9\u306E\u5165\u6B21\u6570\u3092\u6E1B\u3089\u3057\u3001\u65B0\u305F\u306B\
    \ 0 \u306B\u306A\u3063\u305F\u3089\u30AD\u30E5\u30FC\u306B\u8FFD\u52A0\u3059\u308B\
    \n            if (--indegrees[to] == 0) {\n                q.push(to);\n     \
    \       }\n        }\n    }\n\n    // \u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\
    \uFF08\u9802\u70B9\u3092\u3059\u3079\u3066\u51E6\u7406\u3067\u304D\u3066\u3044\
    \u306A\u3044\uFF09\u5834\u5408\n    if (result.size() < graph.size()) {\n    \
    \    // \u7A7A\u306E\u914D\u5217\u3092\u8FD4\u3059\n        return {{}, false};\n\
    \    }\n\n    return {result, one};\n}\n\n// \u5171\u901A\u90E8\u5206\u3082\u3063\
    \u3066\u308B?\ninline bool has_kyotsu(pll l, pll r) noexcept {\n    if (l.first\
    \ <= r.first && r.second <= l.second) return true;\n    if (r.first <= l.first\
    \ && l.second <= r.second) return true;\n    if (r.first <= l.first && l.first\
    \ <= r.second && r.second <= l.second) return true;\n    if (l.first <= r.first\
    \ && r.first <= l.second && l.second <= r.second) return true;\n\n    return false;\n\
    }\n\n// \u5171\u901A\u90E8\u5206\u53D6\u5F97\ninline pll get_kyotu(pll l, pll\
    \ r) noexcept {\n    assert(has_kyotsu(l, r));\n    return {max(l.first, r.first),\
    \ min(l.second, r.second)};\n}\n\n// nCk\ntemplate <typename mint>\nclass Combination\
    \ {\n   private:\n    static const int MAX = 510000;\n    mint fac[MAX], finv[MAX],\
    \ inv[MAX];\n\n   public:\n    // \u30C6\u30FC\u30D6\u30EB\u3092\u4F5C\u308B\u524D\
    \u51E6\u7406\n    Combination() {\n        const int MOD = mint::mod();\n    \
    \    fac[0] = fac[1] = 1;\n        finv[0] = finv[1] = 1;\n        inv[1] = 1;\n\
    \        for (int i = 2; i < MAX; i++) {\n            fac[i] = fac[i - 1] * i;\n\
    \            inv[i] = MOD - inv[MOD % i] * (MOD / i);\n            finv[i] = finv[i\
    \ - 1] * inv[i];\n        }\n    }\n\n    // \u4E8C\u9805\u4FC2\u6570\u8A08\u7B97\
    \n    mint COM(int n, int k) const {\n        if (n < k) return 0;\n        if\
    \ (n < 0 || k < 0) return 0;\n        return fac[n] * finv[k] * finv[n - k];\n\
    \    }\n};\n\nclass imos {\n   private:\n    vll dat;\n\n   public:\n    imos(ll\
    \ n, ll init = 0) : dat(n + 1, 0) {\n        add(0, n, init);\n    }\n\n    //\
    \ [l, r) \u306B x \u3092\u52A0\u3048\u308B\n    // O(1)\n    void add(ull l, ull\
    \ r, ll x) {\n        assert(l <= r && r <= dat.size());\n        dat[l] += x;\n\
    \        dat[r] -= x;\n    }\n\n    // O(n)\n    vll get() const {\n        vll\
    \ res(dat.size() - 1);\n        res[0] = dat[0];\n        arep(i, 1, res.size())\
    \ res[i] = res[i - 1] + dat[i];\n\n        return res;\n    }\n};\n\ntemplate\
    \ <integral T>\nstruct PrimeFact {\n    vector<T> spf;\n\n    // O(N log log N)\n\
    \    PrimeFact(T N) { init(N); }\n\n    void init(T N) {\n        spf.assign(N\
    \ + 1, 0);\n        for (T i = 0; i <= N; i++) spf[i] = i;\n        for (T i =\
    \ 2; i * i <= N; i++) {\n            if (spf[i] == i) {\n                for (T\
    \ j = i * i; j <= N; j += i) {\n                    if (spf[j] == j) {\n     \
    \                   spf[j] = i;\n                    }\n                }\n  \
    \          }\n        }\n    }\n\n    // O(log N)\n    map<T, T> get(T n) {\n\
    \        assert(1 <= n && n < spf.size());\n        map<T, T> m;\n        while\
    \ (n != 1) {\n            m[spf[n]]++;\n            n /= spf[n];\n        }\n\
    \        return m;\n    }\n};\n\n#endif\n\n/* #endregion */\n\n/* Variables */\n\
    \n#ifndef LIBTEST\n\nll N, M, K, Q;\nll H, W;\nstring S = \"\";\nstring dump =\
    \ \"\";\nll codeforces_t = -1;\n\n/* Main Function */\n\nint main() {\n    return\
    \ 0;\n}\n\n#endif\n\n/* \u6587\u5B57\u5316\u3051\u6CE8\u610F */\n"
  dependsOn: []
  isVerificationFile: false
  path: template.cpp
  requiredBy: []
  timestamp: '2025-12-11 00:03:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: template.cpp
layout: document
redirect_from:
- /library/template.cpp
- /library/template.cpp.html
title: "T\u578B\u3092char\u578B\u306B\u5909\u63DB\u3057\u307E\u3059"
---
