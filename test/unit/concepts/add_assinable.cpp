#include <string>
#include <vector>

#include "e6nlaq/concepts.hpp"

class A {
   public:
    A operator+=(const A& _) const { return A(); }

    A() {}
};

class B {
   public:
    B() {}
};

static_assert(e6nlaq::add_assignable<int>);
static_assert(e6nlaq::add_assignable<double>);
static_assert(e6nlaq::add_assignable<std::string>);

static_assert(!e6nlaq::add_assignable<std::vector<int>>);

static_assert(e6nlaq::add_assignable<A>);
static_assert(!e6nlaq::add_assignable<B>);

int main() {
    return 0;
}