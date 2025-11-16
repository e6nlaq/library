// @e6nlaq/library / (C) 2025 e6nlaq

#ifndef E6NLAQ_IO_HPP
#define E6NLAQ_IO_HPP 1

#include <concepts>
#include <iostream>

namespace e6nlaq {
inline void co() {
#ifdef USE_ENDL
    std::cout << std::endl;
#else
    std::cout << "\n";
#endif
}

template <typename Head, typename... Tail>
inline void co(Head head, Tail... tail) {
    std::cout << head;

    if constexpr (sizeof...(tail) > 0) {
        std::cout << " ";
    }

    co(tail...);
}

template <typename T>
    requires std::convertible_to<T, bool>
inline void YESNO(T b) {
    std::cout << (b ? "YES" : "NO") << std::endl;
}

template <typename T>
    requires std::convertible_to<T, bool>
inline void yesno(T b) {
    std::cout << (b ? "yes" : "no") << std::endl;
}

template <typename T>
    requires std::convertible_to<T, bool>
inline void YesNo(T b) {
    std::cout << (b ? "Yes" : "No") << std::endl;
}

template <typename T, typename tr, typename fal>
    requires std::convertible_to<T, bool>
inline void outif(T b, tr tru, fal fals) {
    if (b) {
        std::cout << tru << std::endl;
    } else {
        std::cout << fals << std::endl;
    }
}

inline void fastio() noexcept {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
}

}  // namespace e6nlaq

#endif  // E6NLAQ_IO_HPP
