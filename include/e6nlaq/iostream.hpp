#ifndef E6NLAQ_IOSTREAM_HPP
#define E6NLAQ_IOSTREAM_HPP 1

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

namespace e6nlaq {

#ifdef __GNUC__
namespace {
__int128_t parse(const std::string& s) {
    __int128_t ret = 0;
    for (const char c : s) {
        if ('0' <= c && c <= '9') {
            ret = 10 * ret + (c - '0');
        }
    }

    if (!s.empty() && s[0] == '-') {
        ret = -ret;
    }

    return ret;
}
}  // namespace

// https://kenkoooo.hatenablog.com/entry/2016/11/30/163533
inline std::ostream& operator<<(std::ostream& dest, __int128_t value) {
    std::ostream::sentry s(dest);
    if (s) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[128];
        char* d = std::end(buffer);
        do {
            --d;
            *d = "0123456789"[tmp % 10];
            tmp /= 10;
        } while (tmp != 0);
        if (value < 0) {
            --d;
            *d = '-';
        }
        int len = std::end(buffer) - d;
        if (dest.rdbuf()->sputn(d, len) != len) {
            dest.setstate(std::ios_base::badbit);
        }
    }
    return dest;
}

inline std::istream& operator>>(std::istream& is, __int128_t& value) {
    std::string tmp;
    is >> tmp;

    value = parse(tmp);

    return is;
}
#endif  // __GNUC__

template <typename T>
inline std::istream& operator>>(std::istream& is, std::vector<T>& v) {
#if defined(LOCAL) && !defined(ALLOW_ZERO_VEC_CIN)
    assert(v.size() != 0);
#endif
    for (auto& elem : v) {
        is >> elem;
    }

    return is;
}

}  // namespace e6nlaq

#endif  // E6NLAQ_IOSTREAM_HPP
