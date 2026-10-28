# Title: Implementation of the A* Algorithm
#
# Problem statement:
# Implement the A* search algorithm in Python to solve a pathfinding problem in a maze or grid-
# based environment, using the cost from the start and a heuristic estimate to the goal.

import heapq

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
        next_row, next_col = row + dr, col + dc  # Calculate a neighboring cell.
        if (0 <= next_row < len(maze) and
                0 <= next_col < len(maze[next_row]) and
                maze[next_row][next_col] == 0):
            yield (next_row, next_col)  # Return an open cell inside the maze.


def heuristic(position, goal):
    return abs(position[0] - goal[0]) + abs(position[1] - goal[1])  # Estimate steps left.


def a_star(maze, start, goal):
    frontier = [(heuristic(start, goal), 0, start)]  # Heap entries are (f, g, cell).
    cost = {start: 0}  # Store the cheapest known cost to every visited cell.
    parent = {start: None}  # Store the previous cell for rebuilding the path.
    expanded = 0  # Count cells actually explored.

    while frontier:  # Continue while cells remain in the priority queue.
        _, distance, current = heapq.heappop(frontier)  # Choose the lowest estimated cost.
        if distance != cost[current]:  # Ignore an older, more expensive heap entry.
            continue
        expanded += 1  # Record this explored cell.
        if current == goal:  # Stop when the goal is reached.
            path = []  # Start a reverse path at the goal.
            while current is not None:  # Follow parent links back to the start.
                path.append(current)  # Add the current cell.
                current = parent[current]  # Move to its parent.
            return path[::-1], expanded  # Reverse the path before returning it.

        for position in neighbors(maze, current):  # Check each possible next cell.
            new_cost = distance + 1  # Every grid move costs one step.
            if position not in cost or new_cost < cost[position]:  # Keep only a better route.
                cost[position] = new_cost  # Save the improved cost.
                parent[position] = current  # Save how the cell was reached.
                priority = new_cost + heuristic(position, goal)  # Calculate f = g + h.
                heapq.heappush(frontier, (priority, new_cost, position))  # Queue the cell.
    return [], expanded  # No route exists when the heap becomes empty.


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

    path, expanded = a_star(MAZE, START, GOAL)  # Find the route with A*.

    if path:
        print("\nPath:", path)
        print("Steps:", len(path) - 1)
        show_maze(MAZE, path, START, GOAL)
    else:
        print("\nNo path found.")
    print("Positions explored:", expanded)


if __name__ == "__main__":  # Run main only when this file is run directly.
    main()
