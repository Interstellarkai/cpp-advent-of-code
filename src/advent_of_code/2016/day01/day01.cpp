#include <advent_of_code/2016/day01/day01.hpp>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

namespace advent_of_code::year2016::day01
{
  auto Solution::update_position(std::pair<int, int>& current_position, const DIRECTION& new_direction, const int& new_steps)
      -> void
  {
    switch (new_direction)
    {
      case DIRECTION::NORTH: current_position.second += new_steps; break;
      case DIRECTION::SOUTH: current_position.second -= new_steps; break;
      case DIRECTION::EAST: current_position.first += new_steps; break;
      case DIRECTION::WEST: current_position.first -= new_steps; break;
    }
  }

  auto Solution::solve_part1(const std::vector<std::pair<DIRECTION, int>>& input) -> int
  {
    std::pair<int, int> current_position = { 0, 0 };  // x, y
    DIRECTION current_direction = DIRECTION::NORTH;

    for (const auto& [turn, steps] : input)
    {
      current_direction = static_cast<DIRECTION>((static_cast<int>(current_direction) + static_cast<int>(turn)) % 4);
      update_position(current_position, current_direction, steps);
    }

    return std::abs(current_position.first) + std::abs(current_position.second);
  }

  auto Solution::solve_part2(const std::vector<std::pair<DIRECTION, int>>& input) -> int
  {
    // HQ: visited twice
    std::unordered_set<std::string> visited_positions;
    std::pair<int, int> current_position = { 0, 0 };
    DIRECTION current_direction = DIRECTION::NORTH;
    for (const auto& [turn, steps] : input)
    {
      current_direction = static_cast<DIRECTION>((static_cast<int>(current_direction) + static_cast<int>(turn)) % 4);

      // walk the steps
      for (int i = 0; i < steps; ++i)
      {
        update_position(current_position, current_direction, 1);
        std::string position_key = std::to_string(current_position.first) + "," + std::to_string(current_position.second);
        if (visited_positions.count(position_key) != 0U)
        {
          return std::abs(current_position.first) + std::abs(current_position.second);
        }
        visited_positions.insert(position_key);
      }
    }
  }

  auto Solution::parse_input(const std::vector<std::filesystem::path>& possible_paths)
      -> std::vector<std::pair<DIRECTION, int>>
  {
    std::vector<std::pair<DIRECTION, int>> result;
    std::ifstream inputFile;
    // check for possible path
    for (const auto& path : possible_paths)
    {
      inputFile.open(path);
      if (inputFile.is_open())
      {
        std::string line;
        while (std::getline(inputFile, line))
        {
          // remove leading and trailing whitespace
          line.erase(remove_if(line.begin(), line.end(), isspace), line.end());

          std::stringstream stream(line);
          std::string token;
          while (std::getline(stream, token, ','))
          {
            // parse the token
            if (token[0] == 'L')
            {
              result.emplace_back(DIRECTION::WEST, std::stoi(token.substr(1)));
            }
            else if (token[0] == 'R')
            {
              result.emplace_back(DIRECTION::EAST, std::stoi(token.substr(1)));
            }
          }
        }
        inputFile.close();
        break;
      }
    }

    return result;
  }

}  // namespace advent_of_code::year2016::day01