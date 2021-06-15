def get_maze(file_name):
    try:
        with open(file_name) as fh:
            maze = [[char for char in line.strip('\n')]
                    for line in fh]
            for row in maze:
                if len(row) != len(maze[0]):
                    print("Maze is not rectangular")
                    raise SystemExit
            return maze
    except OSError:
        print("A problem has arisen")
        raise SystemExit
