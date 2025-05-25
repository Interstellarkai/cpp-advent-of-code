#pragma once

#include <cstdint>
#include <filesystem>
#include <vector>

namespace advent_of_code::year2016::day01
{
  enum class DIRECTION : std::uint8_t
  {
    NORTH,
    EAST,
    SOUTH,
    WEST,
  };

  class Solution
  {
   public:
    static auto solve_part1(const std::vector<std::pair<DIRECTION, int>>& input) -> int;
    static auto solve_part2(const std::vector<std::pair<DIRECTION, int>>& input) -> int;
    static auto parse_input(const std::vector<std::filesystem::path>& possible_paths) -> std::vector<std::pair<DIRECTION, int>>;

   private:
    static auto update_position(std::pair<int, int>& current_position, const DIRECTION& new_direction, const int& new_steps) -> void;
  };

}  // namespace advent_of_code::year2016::day01