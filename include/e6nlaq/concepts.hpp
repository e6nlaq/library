#pragma once

#define E6NLAQ_CONCEPTS_HPP

namespace e6nlaq {
template <typename T>
concept add_assignable = requires(T a, T b) {
    { a += b };
};

template <typename T>
concept subtract_assignable = requires(T a, T b) {
    { a -= b };
};
}  // namespace e6nlaq