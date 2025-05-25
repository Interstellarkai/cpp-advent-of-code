#include <filesystem>
#include <iostream>
#include <vector>

#include "day01.hpp"

using namespace advent_of_code::year2016::day01;

auto main() noexcept -> int
{
  // Try multiple possible locations for the input file
  const std::vector<std::filesystem::path> possible_paths = {
    "input.txt",                               // For make run (executable in build/bin/Debug)
    "src/advent_of_code/2016/day01/input.txt"  // For direct execution from project root
  };

  const std::vector<std::pair<DIRECTION, int>> input = Solution::parse_input(possible_paths);

  // Solve both parts
  const int part1_result = Solution::solve_part1(input);
  const int part2_result = Solution::solve_part2(input);

  // Print results
  std::cout << "Part 1: " << part1_result << '\n';
  std::cout << "Part 2: " << part2_result << '\n';

  return 0;
}