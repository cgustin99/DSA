#Depth First Search Algorithm written in Python

from helper_fcts import get_path, offsets, is_legal_pos
import get_maze
from stack import Stack

#Our stack contains positions as (row, col) tuples

def dfs(maze, start, goal):
    stack = Stack()
    stack.push(start)
    predecessors = {start: None}

    while not stack.is_empty():
        current_cell = stack.pop()
        if current_cell == goal:
            return get_path(predecessors, start, goal)
        for direction in ["up", "right", "down", "left"]:
            row_offset, col_offset = offsets[direction]
            neighbor = (current_cell[0] + row_offset, current_cell[1] + col_offset)
            if is_legal_pos(maze, neighbor) and neighbor not in predecessors:
                stack.push(neighbor)
                predecessors[neighbor] = current_cell
    return None
