#!/usr/bin/python3
"""
returns the perimeter of the island described in grid.
"""


def island_perimeter(grid):
    """
    returns the perimeter of the island described in grid.
    """
    result = 1
    for i, ver in enumerate(grid):
        for j, hor in enumerate(ver):
            if ver[j] == 1:
                if j > 0:
                    if ver[j - 1] and ver[j + 1] == 1:
                        result *= i * j
                if i > 0:
                    if grid[i - 1][j] and grid[i + 1][j] == 1:
                        result *= i * j
    return result
