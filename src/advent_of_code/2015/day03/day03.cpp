#include "day03.hpp"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

namespace advent_of_code::year2015::day03
{
  auto Solution::solve_part1(const std::vector<char>& input) -> int
  {
    std::unordered_set<std::string> visited;

    std::pair<int, int> currentPosition {0, 0};
    visited.insert("0,0");

    for (const auto& ch : input) {
        switch (ch) {
            case '^':
                ++currentPosition.second;
                break;
            case 'v':
                --currentPosition.second;
                break;
            case '<':
                --currentPosition.first;
                break;
            case '>':
                ++currentPosition.first;
                break;
            default:
                std::cerr << "Error handling: '" << ch << "'\n";
                break;
        }
        visited.insert(std::to_string(currentPosition.first) + "," + std::to_string(currentPosition.second));
    }
    
    return static_cast<int>(visited.size());
  }

  auto Solution::solve_part2(const std::vector<char>& input) -> int
  {
    std::unordered_set<std::string> visited;

    std::pair<int, int> currentPosition_santa {0, 0};
    std::pair<int, int> currentPosition_elf {0, 0};
    visited.insert("0,0");

    bool santa_turn = true;
    for (const auto& ch : input) {
        auto& currentPosition = santa_turn ? currentPosition_santa : currentPosition_elf;
        switch (ch) {
            case '^':
                ++currentPosition.second;
                break;
            case 'v':
                --currentPosition.second;
                break;
            case '<':
                --currentPosition.first;
                break;
            case '>':
                ++currentPosition.first;
                break;
            default:
                std::cerr << "Error handling: '" << ch << "'\n";
                break;
        }
        visited.insert(std::to_string(currentPosition.first) + "," + std::to_string(currentPosition.second));
        santa_turn = !santa_turn;
    }
    
    return static_cast<int>(visited.size());
  }

  auto Solution::parse_input(const std::vector<std::filesystem::path>& possible_paths) -> std::vector<char>
  {
    std::vector<char> result;

    std::ifstream inputFile;
    for (const auto& path : possible_paths)
    {
      inputFile.open(path);
      if (inputFile.is_open())
      {
        std::string line;
        while (std::getline(inputFile, line))
        {  // 1 line
          for (const auto& ch : line)
          {
            result.emplace_back(ch);
          }
        }
        inputFile.close();
        break;
      }
    }

    if (result.empty())
    {
      std::cerr << "Error: parsing the file" << '\n';
    }

    return result;
  }
};  // namespace advent_of_code::year2015::day03
