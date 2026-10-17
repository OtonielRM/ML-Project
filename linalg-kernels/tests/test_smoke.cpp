#include <gtest/gtest.h>

#include "linalg/version.hpp"

// Smoke test: proves the library builds, links, and that CMake wiring reaches the code.
TEST(Smoke, VersionMatchesCMakeProject) {
    const auto v = linalg::version();
    EXPECT_EQ(v.major, 0);
    EXPECT_EQ(v.minor, 0);
    EXPECT_EQ(v.patch, 1);
}
