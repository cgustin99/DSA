from helper_fcts import get_path, offsets, is_legal_pos
import get_maze
from queue_ds import Queue

#Our stack contains positions as (row, col) tuples

def bfs(maze, start, goal):
    queue = Queue()
    queue.enqueue(start)
    predecessors = {start: None}

    while not queue.is_empty():
        current_cell = queue.dequeue()
        if current_cell == goal:
            return get_path(predecessors, start, goal)
        for direction in ["up", "right", "down", "left"]:
            row_offset, col_offset = offsets[direction]
            neighbor = (current_cell[0] + row_offset, current_cell[1] + col_offset)
            if is_legal_pos(maze, neighbor) and neighbor not in predecessors:
                queue.enqueue(neighbor)
                predecessors[neighbor] = current_cell
    return None
