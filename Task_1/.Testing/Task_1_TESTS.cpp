#include <gtest/gtest.h>

#include "Task_1.h"

TEST(InversionTest, AllInversions) {
  double array[] = {5, 4, 3, 2, 1};
  ASSERT_EQ(findInversions(array, 4), 10);
}

TEST(InversionTest, ReverseInversions) {
  double array[] = {1, 2, 3, 4, 5};
  ASSERT_EQ(findInversions(array, 4), 0);
}

TEST(InversionTest, SymmetricalNumInversions) {
  double array[] = {1, 2, 3, 2, 1};
  ASSERT_EQ(findInversions(array, 4), 4);
}

TEST(InversionTest, NotIntInversions) {
  double array[] = {5.5, 4.4, 3.3, 2.2, 1.1};
  ASSERT_EQ(findInversions(array, 4), 10);
}

TEST(InversionTest, ArrayOfOneNumber) {
  double array[] = {5.99};
  ASSERT_EQ(findInversions(array, 0), 0);
}

TEST(InversionTest, ArrayOfSimilarNumbers) {
  double array[] = {5.99, 5.99, 5.99, 5.99, 5.99};
  ASSERT_EQ(findInversions(array, 4), 0);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}
