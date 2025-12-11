#include <string>
#include <vector>

#include "e6nlaq/concepts.hpp"

class A {
   public:
    A operator-=(const A& _) const { return A(); }

    A() {}
};

class B {
   public:
    B operator-(const B& _) const { return B(); }

    B() {}
};

static_assert(e6nlaq::subtract_assignable<int>);
static_assert(e6nlaq::subtract_assignable<double>);
static_assert(!e6nlaq::subtract_assignable<std::string>);

static_assert(!e6nlaq::subtract_assignable<std::vector<int>>);

static_assert(e6nlaq::subtract_assignable<A>);
static_assert(!e6nlaq::subtract_assignable<B>);

int main() {
    return 0;
}
