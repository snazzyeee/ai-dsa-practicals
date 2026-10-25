# Title: Implementation of the A* Algorithm
#
# Problem statement:
# Implement the A* search algorithm in Python to solve a pathfinding problem in a maze or grid-
# based environment, using the cost from the start and a heuristic estimate to the goal.

import heapq

PRACTICE_MODE = True  # change to False to use the full-program area at the bottom

# 0 is a path, 1 is a wall; positions are (row, column).
MAZE = [
    [0, 0, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [1, 1, 1, 1, 0],
    [0, 0, 0, 0, 0],
]
START = (0, 0)
GOAL = (4, 4)


def neighbors(maze, position):
    row, col = position
    for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        next_row, next_col = row + dr, col + dc
        if (0 <= next_row < len(maze) and
                0 <= next_col < len(maze[next_row]) and
                maze[next_row][next_col] == 0):
            yield (next_row, next_col)


# PSEUDOCODE: write your A* steps here.
#
#
#
#
#

# PRACTICE: return the Manhattan distance between two positions.
def heuristic(position, goal):
    raise NotImplementedError("TODO: write the heuristic")


# PRACTICE: use heapq for the frontier, with f = g + h.
# Each move costs 1. Return (path, expanded): path is a list of positions
# from start to goal, or [] if there is no path. expanded counts positions
# removed from the heap and explored; don't count stale entries.
def a_star(maze, start, goal):
    raise NotImplementedError("TODO: write A*")


def show_maze(maze, path, start, goal):
    path = set(path)
    for row, cells in enumerate(maze):
        symbols = []
        for col, cell in enumerate(cells):
            position = (row, col)
            if position == start:
                symbols.append("S")
            elif position == goal:
                symbols.append("G")
            elif cell == 1:
                symbols.append("#")
            elif position in path:
                symbols.append("*")
            else:
                symbols.append(".")
        print(" ".join(symbols))


def main():
    print("Maze: S = start, G = goal, # = wall, * = path")
    show_maze(MAZE, [], START, GOAL)

    try:
        path, expanded = a_star(MAZE, START, GOAL)
    except NotImplementedError as error:
        print(error)
        return

    if path:
        print("\nPath:", path)
        print("Steps:", len(path) - 1)
        show_maze(MAZE, path, START, GOAL)
    else:
        print("\nNo path found.")
    print("Positions explored:", expanded)


if __name__ == "__main__" and PRACTICE_MODE:
    main()

# FULL PROGRAM: set PRACTICE_MODE = False and write your whole program below.
