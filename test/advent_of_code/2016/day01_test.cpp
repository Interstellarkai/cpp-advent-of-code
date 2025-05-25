#include <gtest/gtest.h>
#include <advent_of_code/2016/day01/day01.hpp>

using namespace advent_of_code::year2016::day01;

TEST(Day03Test, Part1)
{
  EXPECT_EQ(Solution::solve_part1({{DIRECTION::EAST, 2}, {DIRECTION::WEST, 3}}), 5);
  EXPECT_EQ(Solution::solve_part1({{DIRECTION::EAST, 2}, {DIRECTION::EAST, 2}, {DIRECTION::EAST, 2}}), 2);
  EXPECT_EQ(Solution::solve_part1({{DIRECTION::EAST, 5}, {DIRECTION::WEST, 5}, {DIRECTION::EAST, 5}, {DIRECTION::EAST, 3}}), 12);
}

TEST(Day03Test, Part2) {
//   EXPECT_EQ(solve_part2("R2, L3"), 5);
}

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
} 