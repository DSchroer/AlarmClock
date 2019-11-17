#include "gtest/gtest.h"
#include "utils/vector.hpp"

TEST(VectorTests, CanCreate) {
    Vector<int> a{};

    ASSERT_EQ(0, a.Count);
}

struct Foob { uint8_t val; };
TEST(VectorTests, CanInline) {
    auto a = Foob{1};
    auto b = Foob{2};
    auto c = Foob{3};

    Vector<Foob> vec{a,b,c};

    ASSERT_EQ(3, vec.Count);
    ASSERT_EQ(a.val, vec[0].val);
    ASSERT_EQ(b.val, vec[1].val);
    ASSERT_EQ(c.val, vec[2].val);
}