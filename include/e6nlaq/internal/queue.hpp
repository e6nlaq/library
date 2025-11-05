// @e6nlaq/library / (C) 2025 e6nlaq
// This file is a fork of AtCoder Library.

#ifndef E6NLAQ_INTERNAL_QUEUE_HPP
#define E6NLAQ_INTERNAL_QUEUE_HPP 1

#include <vector>

namespace e6nlaq {

namespace internal {

template <class T>
struct simple_queue {
    std::vector<T> payload;
    int pos = 0;
    void reserve(int n) { payload.reserve(n); }
    int size() const { return int(payload.size()) - pos; }
    bool empty() const { return pos == int(payload.size()); }
    void push(const T& t) { payload.push_back(t); }
    T& front() { return payload[pos]; }
    void clear() {
        payload.clear();
        pos = 0;
    }
    void pop() { pos++; }
};

}  // namespace internal

}  // namespace e6nlaq

#endif  // E6NLAQ_INTERNAL_QUEUE_HPP
