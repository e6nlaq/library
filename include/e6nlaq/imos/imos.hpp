#pragma once

#define E6NLAQ_IMOS_IMOS_HPP

#include <stdexcept>
#include <type_traits>
#include <vector>

#include "../concepts.hpp"

namespace e6nlaq {

/**
 * @brief imos法を実装したクラス
 * @tparam T 累積和の型
 */
template <typename T>
    requires add_assignable<T> && subtract_assignable<T>
class imos {
   private:
    std::vector<T> dat;

   public:
    imos() : dat(0) {};

    /**
     * @brief コンストラクタ
     * @param n 配列のサイズ
     * @param init 初期値
     * @param e 単位元
     */
    explicit imos(std::size_t n, const T& init, const T& e) : dat(n + 1, e) {
        add(0, n, init);
    }

    /**
     * @brief コンストラクタ(整数)
     * @param n 配列のサイズ
     * @param init 初期値
     */
    explicit imos(std::size_t n, T init = T(0))
        requires std::is_integral_v<T>
        : imos(n, init, 0) {}

    explicit imos(const std::vector<T>& init)
        requires std::is_integral_v<T>
        : dat(init.size() + 1, 0) {
        for (std::size_t i = 0; i < init.size(); ++i) {
            add(i, i + 1, init[i]);
        }
    }

    explicit imos(const std::vector<T>& init, const T& e) : dat(init.size() + 1, e) {
        for (std::size_t i = 0; i < init.size(); ++i) {
            add(i, i + 1, init[i]);
        }
    }

    /**
     * @brief 区間 [l, r) に x を加える O(1)
     * @param l 区間の左端（含む）
     * @param r 区間の右端（含まない）
     * @param x 加算する値
     * @throw std::out_of_range l > r または r > dat.size() の場合
     */
    void add(std::size_t l, std::size_t r, T x) {
        if (l > r || r > dat.size()) {
            throw std::out_of_range("imos::add: invalid range");
        }
        dat[l] += x;
        dat[r] -= x;
    }

    /**
     * @brief 累積和を計算して返す O(N)
     * @return 累積和の配列
     */
    std::vector<T> get() const {
        std::vector<T> res(dat.size() - 1);
        res[0] = dat[0];
        for (std::size_t i = 1; i < res.size(); i++)
            res[i] = res[i - 1] + dat[i];

        return res;
    }
};

}  // namespace e6nlaq