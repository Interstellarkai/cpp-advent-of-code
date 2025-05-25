#pragma once

#include <filesystem>
#include <vector>

namespace advent_of_code::year2015::day03
{

  class Solution
  {
   public:
    // Part 1 solution
    static auto solve_part1(const std::vector<char>& input) -> int;

    // Part 2 solution
    static auto solve_part2(const std::vector<char>& input) -> int;

    // Helper functions
    static auto parse_input(const std::vector<std::filesystem::path>& possible_paths) -> std::vector<char>;

   private:
  };

}  // namespace advent_of_code::year2015::day03
