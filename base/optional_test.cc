#include <optional>

#include "base/googletest.h"

GTEST_TEST(OptionalTest, Smoke) {
  std::optional<std::string> maybe_string;
  EXPECT_FALSE(maybe_string);
  maybe_string = "asdf";
  EXPECT_TRUE(maybe_string);
  EXPECT_EQ(maybe_string, "asdf");
}

GTEST_MAIN()
