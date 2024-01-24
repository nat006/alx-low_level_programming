#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in a grid.

    Args:
    - grid: a list of lists of integers representing the land and water zones

    Returns:
    - the perimeter of the island

    Assumptions:
    - 0 represents a water zone
    - 1 represents a land zone
    - One cell is a square with side length 1
    - Grid cells are connected horizontally/vertically (not diagonally)
    - Grid is rectangular, width and height don’t exceed 100
    - Grid is completely surrounded by water, and there is one island (or nothing)
    - The island doesn’t have “lakes” (water inside that isn’t connected to the water around the island)
    """
    if not grid:
        return 0
    
    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0
    
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                perimeter += 4  # each land cell contributes 4 to the perimeter

                # check the neighbors to subtract the shared sides
                if i > 0 and grid[i-1][j] == 1:
                    perimeter -= 2
                if j > 0 and grid[i][j-1] == 1:
                    perimeter -= 2

    return perimeter
