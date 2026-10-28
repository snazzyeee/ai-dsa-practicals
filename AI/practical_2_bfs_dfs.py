# Title: Implementing AI Search Algorithms (BFS and DFS) - Maze Solver
#
# Problem statement:
# Implement a maze solver in Python using Breadth-First Search (BFS) and Depth-First Search (DFS).
# Find a path from the start to the goal while avoiding walls, and compare the traversal paths and
# efficiency of both algorithms.

from collections import deque

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
    row, col = position  # Split the current position into row and column.
    for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):  # Try four directions.
        next_row, next_col = row + dr, col + dc  # Calculate the next position.
        if (0 <= next_row < len(maze) and
                0 <= next_col < len(maze[next_row]) and
                maze[next_row][next_col] == 0):  # Keep only valid, open cells.
            yield (next_row, next_col)  # Return one valid neighbor.


def bfs(maze, start, goal):
    queue = deque([start])  # Put the start cell into the BFS queue.
    parent = {start: None}  # Store the previous cell for path reconstruction.
    expanded = 0  # Count cells removed from the queue.

    while queue:  # Continue until there are no cells left to visit.
        current = queue.popleft()  # BFS removes the oldest cell first.
        expanded += 1  # Record this explored cell.
        if current == goal:  # Stop immediately when the goal is reached.
            return build_path(parent, goal), expanded  # Return the shortest path.
        for position in neighbors(maze, current):  # Check every reachable neighbor.
            if position not in parent:  # A parent entry also means "already visited".
                parent[position] = current  # Remember how this cell was reached.
                queue.append(position)  # Add it at the back of the queue.
    return [], expanded  # Return an empty path when the goal cannot be reached.


def dfs(maze, start, goal):
    stack = [start]  # Put the start cell into the DFS stack.
    parent = {start: None}  # Store previous cells for the final path.
    expanded = 0  # Count cells removed from the stack.

    while stack:  # Continue while a path still needs exploring.
        current = stack.pop()  # DFS removes the newest cell first.
        expanded += 1  # Record this explored cell.
        if current == goal:  # Stop when the goal is found.
            return build_path(parent, goal), expanded  # Rebuild and return the path.
        for position in neighbors(maze, current):  # Check every reachable neighbor.
            if position not in parent:  # Do not visit a cell twice.
                parent[position] = current  # Store the route to this cell.
                stack.append(position)  # Put it on top of the stack.
    return [], expanded  # Return an empty path when no route exists.


def build_path(parent, goal):
    path = []  # Start with an empty path.
    current = goal  # Begin backtracking at the goal.
    while current is not None:  # Stop after reaching the start's None parent.
        path.append(current)  # Add the current cell to the reverse path.
        current = parent[current]  # Move to its previous cell.
    return path[::-1]  # Reverse the path so it starts at the start cell.


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


if __name__ == "__main__":  # Run the menu only when this file is run directly.
    main()
