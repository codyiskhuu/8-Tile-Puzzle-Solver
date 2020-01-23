# 8-Tile-Puzzle-Solver

This is an 8 tile puzzle solver. Using C++ I've created a program that solves a mixed up 8 title puzzle if it is possible to solve.
If the puzzle is solvable, then it will proceed to solve it. 
If the puzzle is impossible: 
e.g physically swapping two tiles so that it will appear as

1 2 3

4 5 6

8 7 *

Then the solver will do every possible move and tell the user that the puzzle is unsolvable
There are different heuristics that are used within solving the tile puzzle which change the speed of solving the puzzle.
Uniform Cost Search: (Variant of Dijikstra’s) Where it checks if a node is in a priority queue and insert one by one when needed, trying to find the best case scenario to the final product.
A-Star & Misplaced Tile: A star is a best-first search algorithm that aims to find a path with the smallest cost, while Misplaced Tile is calculating the cost of each tile by how much distance it is away from it’s original spot.
A-Star & Manhattan Distance: Manhattan Distance is calculating the distance of how many spaces is it until the correct spot.
