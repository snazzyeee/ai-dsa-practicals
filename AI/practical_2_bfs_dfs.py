# Title: Implementing AI Search Algorithms (BFS and DFS) - Maze Solver
#
# Problem statement:
# Implement a maze solver in Python using Breadth-First Search (BFS) and Depth-First Search (DFS).
# Find a path from the start to the goal while avoiding walls, and compare the traversal paths and
# efficiency of both algorithms.

from collections import deque

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


# The driver supplies valid up, down, left and right neighbors.
def neighbors(maze, position):
    row, col = position
    for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        next_row, next_col = row + dr, col + dc
        if (0 <= next_row < len(maze) and
                0 <= next_col < len(maze[next_row]) and
                maze[next_row][next_col] == 0):
            yield (next_row, next_col)


# PSEUDOCODE: write your BFS and DFS steps here.
#
#
#
#
#

# PRACTICE: use a queue (deque) to explore the maze with BFS.
# Return (path, expanded): path is a list of (row, col) positions from
# start to goal, or [] if there is no path. expanded counts positions removed
# from the queue for exploration.
def bfs(maze, start, goal):
    raise NotImplementedError("TODO: write BFS")


# PRACTICE: use a stack or recursion to explore the maze with DFS.
# Return (path, expanded) using the same rules as BFS. For recursion, count
# positions when first explored.
def dfs(maze, start, goal):
    raise NotImplementedError("TODO: write DFS")


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


def run_search(name, algorithm):
    try:
        path, expanded = algorithm(MAZE, START, GOAL)
    except NotImplementedError as error:
        print(error)
        return

    print(f"\n{name}:")
    if path:
        print("Path:", path)
        print("Steps:", len(path) - 1)
        show_maze(MAZE, path, START, GOAL)
    else:
        print("No path found.")
    print("Positions explored:", expanded)


def main():
    print("Maze: S = start, G = goal, # = wall, * = path")
    show_maze(MAZE, [], START, GOAL)

    while True:
        choice = input("\n1: BFS  2: DFS  3: Both  4: Exit\nChoose: ").strip()
        if choice == "1" or choice == "3":
            run_search("BFS", bfs)
        if choice == "2" or choice == "3":
            run_search("DFS", dfs)
        if choice == "4":
            break
        if choice not in ("1", "2", "3", "4"):
            print("Invalid choice.")


if __name__ == "__main__" and PRACTICE_MODE:
    main()

# FULL PROGRAM: set PRACTICE_MODE = False and write your whole program below.
