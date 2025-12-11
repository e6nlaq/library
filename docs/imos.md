---
title: imos法
documentation_of: //include/e6nlaq/imos/imos.hpp
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
