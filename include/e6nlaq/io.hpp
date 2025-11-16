// @e6nlaq/library / (C) 2025 e6nlaq

#ifndef E6NLAQ_IO_HPP
#define E6NLAQ_IO_HPP 1

#include <concepts>
#include <iostream>

namespace e6nlaq {
/**
 * @brief 改行を出力する
 */
inline void co() {
#ifdef USE_ENDL
    std::cout << std::endl;
#else
    std::cout << "\n";
#endif
}

/**
 * @brief 可変長引数で与えられた値を空白区切りで出力し、最後に改行する
 * @tparam Head 最初の引数の型
 * @tparam Tail 残りの引数の型パック
 * @param head 最初の引数
 * @param tail 残りの引数
 */
template <typename Head, typename... Tail>
inline void co(Head head, Tail... tail) {
    std::cout << head;

    if constexpr (sizeof...(tail) > 0) {
        std::cout << " ";
    }

    co(tail...);
}

/**
 * @brief 真偽値に応じて "YES" または "NO" を大文字で出力する
 * @tparam T boolに変換可能な型
 * @param b 真偽値
 */
template <typename T>
    requires std::convertible_to<T, bool>
inline void YESNO(T b) {
    std::cout << (b ? "YES" : "NO") << std::endl;
}

/**
 * @brief 真偽値に応じて "yes" または "no" を小文字で出力する
 * @tparam T boolに変換可能な型
 * @param b 真偽値
 */
template <typename T>
    requires std::convertible_to<T, bool>
inline void yesno(T b) {
    std::cout << (b ? "yes" : "no") << std::endl;
}

/**
 * @brief 真偽値に応じて "Yes" または "No" を先頭大文字で出力する
 * @tparam T boolに変換可能な型
 * @param b 真偽値
 */
template <typename T>
    requires std::convertible_to<T, bool>
inline void YesNo(T b) {
    std::cout << (b ? "Yes" : "No") << std::endl;
}

/**
 * @brief 条件に応じて異なるメッセージを出力する
 * @tparam T boolに変換可能な型
 * @tparam tr 真の場合に出力する値の型
 * @tparam fal 偽の場合に出力する値の型
 * @param b 条件
 * @param tru 真の場合に出力する値
 * @param fals 偽の場合に出力する値
 */
template <typename T, typename tr, typename fal>
    requires std::convertible_to<T, bool>
inline void outif(T b, tr tru, fal fals) {
    if (b) {
        std::cout << tru << std::endl;
    } else {
        std::cout << fals << std::endl;
    }
}

/**
 * @brief 標準入出力の高速化を行う
 * @note C++の標準入出力を高速化するための設定を行う
 */
inline void fastio() noexcept {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
}

}  // namespace e6nlaq

#endif  // E6NLAQ_IO_HPP
