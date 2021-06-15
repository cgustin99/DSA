'''
Use a priority queue containing f-values and (i, j) tuples along with dictionaries
for predecessors and g-values
'''

from helper_fcts import get_path, offsets, is_legal_pos
import get_maze
from priority_queue import PriorityQueue

def heuristic(a, b):
    x1, y1 = a
    x2, y2 = b
    return abs(x1 - x2) + abs(y1 - y2)

def a_star(maze, start, goal):
    pq = PriorityQueue()
    pq.put(start, 0)
    predecessors = {start: None}
    g_values = {start: 0}

    while not pq.is_empty():
        current_cell = pq.get()
        if current_cell == goal:
            return get_path(predecessors, start, goal)
        for direction in ["up", "right", "down", "left"]:
            row_offset, col_offset = offsets[direction]
            neighbor = (current_cell[0] + row_offset, current_cell[1] + col_offset)
            if is_legal_pos(maze, neighbor) and neighbor not in g_values:
                new_cost = g_values[current_cell] + 1
                g_values[neighbor] = new_cost
                f_value = new_cost + heuristic(goal, neighbor)
                pq.put(neighbor, f_value)
                predecessors[neighbor] = current_cell
    return None
