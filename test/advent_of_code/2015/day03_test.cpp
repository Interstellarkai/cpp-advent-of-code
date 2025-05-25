#include "advent_of_code/2015/day03/day03.hpp"
#include "gtest/gtest.h"

using namespace advent_of_code::year2015::day03;

TEST(Day03Test, Part1Example) {
    ASSERT_EQ(Solution::solve_part1({'>'}), 2);
    ASSERT_EQ(Solution::solve_part1({'^', '>', 'v', '<'}), 4);
    ASSERT_EQ(Solution::solve_part1({'^', 'v', '^', 'v', '^', 'v', '^', 'v', '^', 'v'}), 2);
}

TEST(Day03Test, Part2Example) {
    ASSERT_EQ(Solution::solve_part2({'^', 'v'}), 3);
    ASSERT_EQ(Solution::solve_part2({'^', '>', 'v', '<'}), 3);
    ASSERT_EQ(Solution::solve_part2({'^', 'v', '^', 'v', '^', 'v', '^', 'v', '^', 'v'}), 11);
}

auto main(int argc, char** argv) -> int {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}