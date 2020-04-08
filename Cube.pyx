from copy import deepcopy
from colors import white, red, green, blue
from colorama import init

cdef class Cube:
    cpdef public int [48] pos
    cpdef public int cc
    def __init__(self):
        self.pos[:] = [
            0, 0, 0, 0, 0, 0, 0, 0,
            1, 1, 1, 1, 1, 1, 1, 1,
            2, 2, 2, 2, 2, 2, 2, 2,
            3, 3, 3, 3, 3, 3, 3, 3,
            4, 4, 4, 4, 4, 4, 4, 4,
            5, 5, 5, 5, 5, 5, 5, 5
        ]
        self.cc = 99999999
    
    def __str__(self):
        return str(self.pos)

cpdef Cube change(Cube cube, int n):
    cube.pos[n] = 99
    return cube

cpdef bint is_solved(Cube cube):
    cdef int i
    cdef int j
    for i in range(5):
        for j in range(6):
            if cube.pos[8*i+j] != i:
                return False
    return True

def orange (text):
    return f'\x1b[95m{text}\x1b[0m'

def yellow (text):
    return f'\x1b[93m{text}\x1b[0m'

def blank (text):
    return " "

def paint (cube):
    init(convert=True)
    colors = [yellow, green, white, blue, orange, red, blank]
    block = u"\u25A0"
    board = [[], [], [], [], [], [], [], [], [], [], [], []]
    board[0] = [6] * 3 + cube.pos[0:3] + [6] * 3
    board[1] = [6] * 3 + [cube.pos[7]] + [0] + [cube.pos[3]] + [6] * 3
    board[2] = [6] * 3 + cube.pos[4:7][::-1] + [6] * 3
    board[3] = cube.pos[40:43] + cube.pos[8:11] + cube.pos[32:35]
    board[4] = [cube.pos[47]] + [5] + [cube.pos[43]] + [cube.pos[15]] + [1]
    board[4] += [cube.pos[11]] + [cube.pos[39]] + [4] + [cube.pos[35]]
    board[5] = cube.pos[44:47][::-1] + cube.pos[12:15][::-1] + cube.pos[36:39][::-1]
    board[6] = [6] * 3 + cube.pos[16:19] + [6] * 3
    board[7] = [6] * 3 + [cube.pos[23]] + [2] + [cube.pos[19]] + [6] * 3
    board[8] = [6] * 3 + cube.pos[20:23][::-1] + [6] * 3
    board[9] = [6] * 3 + cube.pos[24:27] + [6] * 3
    board[10] = [6] * 3 + [cube.pos[31]] + [3] + [cube.pos[27]] + [6] * 3
    board[11] = [6] * 3 + cube.pos[28:31][::-1] + [6] * 3
    text = ""
    for i in range(len(board)):
        for j in range(len(board[i])):
            text += colors[board[i][j]](block) + " "
        text += "\n"
    print (text[:-1])