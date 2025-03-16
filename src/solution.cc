#include "solution.hpp"

#include <iostream>

using namespace std;

std::vector<std::pair<unsigned int, unsigned int>> SolveMaze(
    const std::vector<std::vector<char>>& maze,
    unsigned int start_x,
    unsigned int start_y) {
  std::vector<std::pair<unsigned int, unsigned int>> path;
  std::vector<std::vector<bool>> visited(maze.size(),
                                         vector<bool>(maze[0].size(), false));

  SolveMazeRecursive(maze, start_x, start_y, path, visited);

  return path;
}

bool SolveMazeRecursive(
    const std::vector<std::vector<char>>& maze,
    unsigned int x,
    unsigned int y,
    std::vector<std::pair<unsigned int, unsigned int>>& path,
    std::vector<std::vector<bool>>& visited) {
  char cell = maze[x][y];
  if (cell == 'X') {
    path.push_back(pair<unsigned int, unsigned int>{x, y});
    visited[x][y] = true;
    return true;
  }
  if (cell != '#' && x < maze.size() && y < maze[0].size() && !visited[x][y]) {
    visited[x][y] = true;
    path.push_back(pair<unsigned int, unsigned int>{x, y});
    if (SolveMazeRecursive(maze, x + 1, y, path, visited) ||
        SolveMazeRecursive(maze, x - 1, y, path, visited) ||
        SolveMazeRecursive(maze, x, y + 1, path, visited) ||
        SolveMazeRecursive(maze, x, y - 1, path, visited)) {
      return true;
    }
    path.pop_back();
  }
  return false;
}