# distutils: language = c++

from copy import deepcopy
from colors import white, red, green, blue
from colorama import init
from libcpp.set cimport set
from libcpp.vector cimport vector
import queue

cpdef enum:
    y = 0
    g = 1
    w = 2
    b = 3
    o = 4
    r = 5

move_map = {
    'R': R, 'Ri': Ri, 'R2': R2,
    'U': U, 'Ui': Ui, 'U2': U2,
    'F': F, 'Fi': Fi, 'F2': F2,
    'L': L, 'Li': Li, 'L2': L2,
    'D': D, 'Di': Di, 'D2': D2,
    'B': B, 'Bi': Bi, 'B2': B2
}
cdef list moves = list(move_map.keys())

cdef class Cube:
    cdef public int [48] pos
    cdef public vector[char] trail
    def __init__(self):
        self.pos[:] = [
            y, y, y, y, y, y, y, y,
            g, g, g, g, g, g, g, g,
            w, w, w, w, w, w, w, w,
            b, b, b, b, b, b, b, b,
            o, o, o, o, o, o, o, o,
            r, r, r, r, r, r, r, r
        ]
    
    def __str__(self):
        return str(self.pos)

cdef class Code:
    cdef public long long first
    cdef public long long second
    cdef public char third

    def __init__(self, Cube cube):
        cdef int i
        self.first = 0
        for i in range(19):
            self.first *= 10
            self.first += cube.pos[i]+1
        self.second = 0
        for i in range(19, 38):
            self.second *= 10
            self.second += cube.pos[i]+1
        self.third = 0
        for i in range(38, 40):
            self.third *= 10
            self.third += cube.pos[i]+1
    
    def __str__(self):
        return f"{self.first}, {self.second}, {self.third}"

cdef class CodeSet:
    cdef public set[long long] first
    cdef public set[long long] second
    cdef public set[char] third

    def insert(self, Code code):
        self.first.insert(code.first)
        self.second.insert(code.second)
        self.third.insert(code.third)
    
    def __contains__(self, code):
        return (
            self.first.find(code.first) != self.first.end() and
            self.second.find(code.second) != self.second.end() and
            self.third.find(code.third) != self.third.end() 
        )

cpdef solve(Cube cube, verbose=False):
    code_set = CodeSet()
    code = Code(cube)
    code_set.insert(code)
    Q = queue.Queue()
    cdef int i
    cdef int level = 0
    Q.put(cube)

    while (not Q.empty()):
        cur = Q.get()
        if len(cur.trail) > level:
            level = len(cur.trail)
            print (f"Entered level: {level} Size: {Q.qsize()}")
        if verbose:
            print ("#"*50)
            paint (cur)
        '''
        for i in range(len(moves)):
            n_cube = apply(cur, moves[i])
            #if verbose:
            #    print (moves[i])
            #    paint (n_cube)
            n_cube.trail.push_back(i)
            #if is_cross(n_cube):
            #    paint (n_cube)
            #    give_solution(n_cube)
            #    return
            n_code = Code(n_cube)
            if n_code not in code_set:
                Q.put(n_cube)
                code_set.insert(n_code)
        '''
        n_cube = R(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = Ri(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = R2(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = U(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = Ui(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = U2(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = F(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = Fi(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = F2(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = L(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = Li(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = L2(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = D(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = Di(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = D2(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = B(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = Bi(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)
        n_cube = B2(cur)
        if is_cross(n_cube):
            give_solution(n_cube)
            return
        n_code = Code(n_cube)
        if n_code not in code_set:
            Q.put(n_cube)
            code_set.insert(n_code)

cpdef give_solution(Cube cube):
    cdef int i
    text = ""
    for i in cube.trail:
        text += moves[i] + " "
    print ("$"*10)
    print (text)
    print ("$"*10)
    paint (cube)

cpdef Cube apply(Cube cube, seq):
    n_cube = deepcopy(cube)
    i = 0
    while i < len(seq):
        if seq[i] == " ":
            continue
        move = seq[i].upper()
        i += 1
        if i < len(seq):
            if seq[i] in ["i", "'"]:
                move += 'i'
                i += 1
            elif seq[i] == '2':
                move += seq[i]
                i += 1
        func = move_map.get(move)
        if func:
            n_cube = func(n_cube)
    return n_cube

cpdef bint is_solved(Cube cube):
    cdef int i
    cdef int j
    for i in range(5):
        for j in range(6):
            if cube.pos[8*i+j] != i:
                return False
    return True

cpdef bint is_cross(Cube cube):
    return (
        cube.pos[17] == w and
        cube.pos[19] == w and
        cube.pos[21] == w and
        cube.pos[23] == w and
        cube.pos[13] == g and
        cube.pos[37] == o and
        cube.pos[45] == r and
        cube.pos[25] == b and
        False
    )

cpdef bint is_f2l_og(Cube cube):
    return (
        is_cross(cube) and
        cube.pos[11] == g and
        cube.pos[12] == g and
        cube.pos[38] == o and
        cube.pos[39] == o and
        cube.pos[18] == w
    )

cpdef bint is_f2l_rg(Cube cube):
    return (
        is_f2l_og(cube) and
        cube.pos[14] == g and
        cube.pos[15] == g and
        cube.pos[43] == r and
        cube.pos[44] == r and
        cube.pos[16] == w
    )

cpdef bint is_f2l_ob(Cube cube):
    return (
        is_f2l_rg(cube) and
        cube.pos[35] == o and
        cube.pos[36] == o and
        cube.pos[26] == b and
        cube.pos[27] == b and
        cube.pos[20] == w
    )

cpdef bint is_f2l_rb(Cube cube):
    return (
        is_f2l_ob(cube) and
        cube.pos[46] == r and
        cube.pos[47] == r and
        cube.pos[24] == b and
        cube.pos[31] == b and
        cube.pos[22] == w
    )

cpdef bint is_oll(Cube cube):
    return (
        is_f2l_rb(cube) and
        cube.pos[0] == y and
        cube.pos[1] == y and
        cube.pos[2] == y and
        cube.pos[3] == y and
        cube.pos[4] == y and
        cube.pos[5] == y and
        cube.pos[6] == y and
        cube.pos[7] == y
    )

cpdef bint is_pll(Cube cube):
    return (
        is_oll(cube) and
        cube.pos[8] == g and
        cube.pos[9] == g and
        cube.pos[10] == g and
        cube.pos[32] == o and
        cube.pos[33] == o and
        cube.pos[34] == o and
        cube.pos[28] == b and
        cube.pos[29] == b and
        cube.pos[30] == b and
        cube.pos[40] == r and
        cube.pos[41] == r and
        cube.pos[42] == r
    )

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

cpdef Cube R (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(0)
    cdef int temp
    temp = cube.pos[38]
    cube.pos[38] = cube.pos[36]
    cube.pos[36] = cube.pos[34]
    cube.pos[34] = cube.pos[32]
    cube.pos[32] = temp
    
    temp = cube.pos[39]
    cube.pos[39] = cube.pos[37]
    cube.pos[37] = cube.pos[35]
    cube.pos[35] = cube.pos[33]
    cube.pos[33] = temp
    
    temp = cube.pos[2]
    cube.pos[2] = cube.pos[10]
    cube.pos[10] = cube.pos[18]
    cube.pos[18] = cube.pos[26]
    cube.pos[26] = temp
    
    temp = cube.pos[3]
    cube.pos[3] = cube.pos[11]
    cube.pos[11] = cube.pos[19]
    cube.pos[19] = cube.pos[27]
    cube.pos[27] = temp
    
    temp = cube.pos[4]
    cube.pos[4] = cube.pos[12]
    cube.pos[12] = cube.pos[20]
    cube.pos[20] = cube.pos[28]
    cube.pos[28] = temp
    
    return cube

cpdef Cube Ri (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(1)
    cdef int temp
    temp = cube.pos[32]
    cube.pos[32] = cube.pos[34]
    cube.pos[34] = cube.pos[36]
    cube.pos[36] = cube.pos[38]
    cube.pos[38] = temp
    
    temp = cube.pos[33]
    cube.pos[33] = cube.pos[35]
    cube.pos[35] = cube.pos[37]
    cube.pos[37] = cube.pos[39]
    cube.pos[39] = temp
    
    temp = cube.pos[26]
    cube.pos[26] = cube.pos[18]
    cube.pos[18] = cube.pos[10]
    cube.pos[10] = cube.pos[2]
    cube.pos[2] = temp
    
    temp = cube.pos[27]
    cube.pos[27] = cube.pos[19]
    cube.pos[19] = cube.pos[11]
    cube.pos[11] = cube.pos[3]
    cube.pos[3] = temp
    
    temp = cube.pos[28]
    cube.pos[28] = cube.pos[20]
    cube.pos[20] = cube.pos[12]
    cube.pos[12] = cube.pos[4]
    cube.pos[4] = temp
    
    return cube

cpdef Cube R2 (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(2)
    cdef int temp
    temp = cube.pos[32]
    cube.pos[32] = cube.pos[36]
    cube.pos[36] = temp
    temp = cube.pos[34]
    cube.pos[34] = cube.pos[38]
    cube.pos[38] = temp
    
    temp = cube.pos[33]
    cube.pos[33] = cube.pos[37]
    cube.pos[37] = temp
    temp = cube.pos[35]
    cube.pos[35] = cube.pos[39]
    cube.pos[39] = temp
    
    temp = cube.pos[2]
    cube.pos[2] = cube.pos[18]
    cube.pos[18] = temp
    temp = cube.pos[10]
    cube.pos[10] = cube.pos[26]
    cube.pos[26] = temp
    
    temp = cube.pos[3]
    cube.pos[3] = cube.pos[19]
    cube.pos[19] = temp
    temp = cube.pos[11]
    cube.pos[11] = cube.pos[27]
    cube.pos[27] = temp
    
    temp = cube.pos[4]
    cube.pos[4] = cube.pos[20]
    cube.pos[20] = temp
    temp = cube.pos[12]
    cube.pos[12] = cube.pos[28]
    cube.pos[28] = temp
    
    return cube

cpdef Cube U (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(3)
    cdef int temp
    temp = cube.pos[6]
    cube.pos[6] = cube.pos[4]
    cube.pos[4] = cube.pos[2]
    cube.pos[2] = cube.pos[0]
    cube.pos[0] = temp
    
    temp = cube.pos[7]
    cube.pos[7] = cube.pos[5]
    cube.pos[5] = cube.pos[3]
    cube.pos[3] = cube.pos[1]
    cube.pos[1] = temp
    
    temp = cube.pos[40]
    cube.pos[40] = cube.pos[8]
    cube.pos[8] = cube.pos[32]
    cube.pos[32] = cube.pos[28]
    cube.pos[28] = temp
    
    temp = cube.pos[41]
    cube.pos[41] = cube.pos[9]
    cube.pos[9] = cube.pos[33]
    cube.pos[33] = cube.pos[29]
    cube.pos[29] = temp
    
    temp = cube.pos[42]
    cube.pos[42] = cube.pos[10]
    cube.pos[10] = cube.pos[34]
    cube.pos[34] = cube.pos[30]
    cube.pos[30] = temp
    
    return cube

cpdef Cube Ui (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(4)
    cdef int temp
    temp = cube.pos[0]
    cube.pos[0] = cube.pos[2]
    cube.pos[2] = cube.pos[4]
    cube.pos[4] = cube.pos[6]
    cube.pos[6] = temp
    
    temp = cube.pos[1]
    cube.pos[1] = cube.pos[3]
    cube.pos[3] = cube.pos[5]
    cube.pos[5] = cube.pos[7]
    cube.pos[7] = temp
    
    temp = cube.pos[28]
    cube.pos[28] = cube.pos[32]
    cube.pos[32] = cube.pos[8]
    cube.pos[8] = cube.pos[40]
    cube.pos[40] = temp
    
    temp = cube.pos[29]
    cube.pos[29] = cube.pos[33]
    cube.pos[33] = cube.pos[9]
    cube.pos[9] = cube.pos[41]
    cube.pos[41] = temp
    
    temp = cube.pos[30]
    cube.pos[30] = cube.pos[34]
    cube.pos[34] = cube.pos[10]
    cube.pos[10] = cube.pos[42]
    cube.pos[42] = temp
    
    return cube

cpdef Cube U2 (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(5)
    cdef int temp
    temp = cube.pos[0]
    cube.pos[0] = cube.pos[4]
    cube.pos[4] = temp
    temp = cube.pos[2]
    cube.pos[2] = cube.pos[6]
    cube.pos[6] = temp
    
    temp = cube.pos[1]
    cube.pos[1] = cube.pos[5]
    cube.pos[5] = temp
    temp = cube.pos[3]
    cube.pos[3] = cube.pos[7]
    cube.pos[7] = temp
    
    temp = cube.pos[40]
    cube.pos[40] = cube.pos[32]
    cube.pos[32] = temp
    temp = cube.pos[8]
    cube.pos[8] = cube.pos[28]
    cube.pos[28] = temp
    
    temp = cube.pos[41]
    cube.pos[41] = cube.pos[33]
    cube.pos[33] = temp
    temp = cube.pos[9]
    cube.pos[9] = cube.pos[29]
    cube.pos[29] = temp
    
    temp = cube.pos[42]
    cube.pos[42] = cube.pos[34]
    cube.pos[34] = temp
    temp = cube.pos[10]
    cube.pos[10] = cube.pos[30]
    cube.pos[30] = temp
    
    return cube

cpdef Cube F (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(6)
    cdef int temp
    temp = cube.pos[14]
    cube.pos[14] = cube.pos[12]
    cube.pos[12] = cube.pos[10]
    cube.pos[10] = cube.pos[8]
    cube.pos[8] = temp
    
    temp = cube.pos[15]
    cube.pos[15] = cube.pos[13]
    cube.pos[13] = cube.pos[11]
    cube.pos[11] = cube.pos[9]
    cube.pos[9] = temp
    
    temp = cube.pos[4]
    cube.pos[4] = cube.pos[42]
    cube.pos[42] = cube.pos[16]
    cube.pos[16] = cube.pos[38]
    cube.pos[38] = temp
    
    temp = cube.pos[5]
    cube.pos[5] = cube.pos[43]
    cube.pos[43] = cube.pos[17]
    cube.pos[17] = cube.pos[39]
    cube.pos[39] = temp
    
    temp = cube.pos[6]
    cube.pos[6] = cube.pos[44]
    cube.pos[44] = cube.pos[18]
    cube.pos[18] = cube.pos[32]
    cube.pos[32] = temp
    
    return cube

cpdef Cube Fi (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(7)
    cdef int temp
    temp = cube.pos[8]
    cube.pos[8] = cube.pos[10]
    cube.pos[10] = cube.pos[12]
    cube.pos[12] = cube.pos[14]
    cube.pos[14] = temp
    
    temp = cube.pos[9]
    cube.pos[9] = cube.pos[11]
    cube.pos[11] = cube.pos[13]
    cube.pos[13] = cube.pos[15]
    cube.pos[15] = temp
    
    temp = cube.pos[38]
    cube.pos[38] = cube.pos[16]
    cube.pos[16] = cube.pos[42]
    cube.pos[42] = cube.pos[4]
    cube.pos[4] = temp
    
    temp = cube.pos[39]
    cube.pos[39] = cube.pos[17]
    cube.pos[17] = cube.pos[43]
    cube.pos[43] = cube.pos[5]
    cube.pos[5] = temp
    
    temp = cube.pos[32]
    cube.pos[32] = cube.pos[18]
    cube.pos[18] = cube.pos[44]
    cube.pos[44] = cube.pos[6]
    cube.pos[6] = temp
    
    return cube

cpdef Cube F2 (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(8)
    cdef int temp
    temp = cube.pos[8]
    cube.pos[8] = cube.pos[12]
    cube.pos[12] = temp
    temp = cube.pos[10]
    cube.pos[10] = cube.pos[14]
    cube.pos[14] = temp
    
    temp = cube.pos[9]
    cube.pos[9] = cube.pos[13]
    cube.pos[13] = temp
    temp = cube.pos[11]
    cube.pos[11] = cube.pos[15]
    cube.pos[15] = temp
    
    temp = cube.pos[4]
    cube.pos[4] = cube.pos[16]
    cube.pos[16] = temp
    temp = cube.pos[42]
    cube.pos[42] = cube.pos[38]
    cube.pos[38] = temp
    
    temp = cube.pos[5]
    cube.pos[5] = cube.pos[17]
    cube.pos[17] = temp
    temp = cube.pos[43]
    cube.pos[43] = cube.pos[39]
    cube.pos[39] = temp
    
    temp = cube.pos[6]
    cube.pos[6] = cube.pos[18]
    cube.pos[18] = temp
    temp = cube.pos[44]
    cube.pos[44] = cube.pos[32]
    cube.pos[32] = temp
    
    return cube

cpdef Cube L (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(9)
    cdef int temp
    temp = cube.pos[46]
    cube.pos[46] = cube.pos[44]
    cube.pos[44] = cube.pos[42]
    cube.pos[42] = cube.pos[40]
    cube.pos[40] = temp
    
    temp = cube.pos[47]
    cube.pos[47] = cube.pos[45]
    cube.pos[45] = cube.pos[43]
    cube.pos[43] = cube.pos[41]
    cube.pos[41] = temp
    
    temp = cube.pos[6]
    cube.pos[6] = cube.pos[30]
    cube.pos[30] = cube.pos[22]
    cube.pos[22] = cube.pos[14]
    cube.pos[14] = temp
    
    temp = cube.pos[7]
    cube.pos[7] = cube.pos[31]
    cube.pos[31] = cube.pos[23]
    cube.pos[23] = cube.pos[15]
    cube.pos[15] = temp
    
    temp = cube.pos[0]
    cube.pos[0] = cube.pos[24]
    cube.pos[24] = cube.pos[16]
    cube.pos[16] = cube.pos[8]
    cube.pos[8] = temp
    
    return cube

cpdef Cube Li (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(10)
    cdef int temp
    temp = cube.pos[40]
    cube.pos[40] = cube.pos[42]
    cube.pos[42] = cube.pos[44]
    cube.pos[44] = cube.pos[46]
    cube.pos[46] = temp
    
    temp = cube.pos[41]
    cube.pos[41] = cube.pos[43]
    cube.pos[43] = cube.pos[45]
    cube.pos[45] = cube.pos[47]
    cube.pos[47] = temp
    
    temp = cube.pos[14]
    cube.pos[14] = cube.pos[22]
    cube.pos[22] = cube.pos[30]
    cube.pos[30] = cube.pos[6]
    cube.pos[6] = temp
    
    temp = cube.pos[15]
    cube.pos[15] = cube.pos[23]
    cube.pos[23] = cube.pos[31]
    cube.pos[31] = cube.pos[7]
    cube.pos[7] = temp
    
    temp = cube.pos[8]
    cube.pos[8] = cube.pos[16]
    cube.pos[16] = cube.pos[24]
    cube.pos[24] = cube.pos[0]
    cube.pos[0] = temp
    
    return cube

cpdef Cube L2 (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(11)
    cdef int temp
    temp = cube.pos[40]
    cube.pos[40] = cube.pos[44]
    cube.pos[44] = temp
    temp = cube.pos[42]
    cube.pos[42] = cube.pos[46]
    cube.pos[46] = temp
    
    temp = cube.pos[41]
    cube.pos[41] = cube.pos[45]
    cube.pos[45] = temp
    temp = cube.pos[43]
    cube.pos[43] = cube.pos[47]
    cube.pos[47] = temp
    
    temp = cube.pos[6]
    cube.pos[6] = cube.pos[22]
    cube.pos[22] = temp
    temp = cube.pos[30]
    cube.pos[30] = cube.pos[14]
    cube.pos[14] = temp
    
    temp = cube.pos[7]
    cube.pos[7] = cube.pos[23]
    cube.pos[23] = temp
    temp = cube.pos[31]
    cube.pos[31] = cube.pos[15]
    cube.pos[15] = temp
    
    temp = cube.pos[0]
    cube.pos[0] = cube.pos[16]
    cube.pos[16] = temp
    temp = cube.pos[24]
    cube.pos[24] = cube.pos[8]
    cube.pos[8] = temp
    
    return cube

cpdef Cube D (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(12)
    cdef int temp
    temp = cube.pos[22]
    cube.pos[22] = cube.pos[20]
    cube.pos[20] = cube.pos[18]
    cube.pos[18] = cube.pos[16]
    cube.pos[16] = temp
    
    temp = cube.pos[23]
    cube.pos[23] = cube.pos[21]
    cube.pos[21] = cube.pos[19]
    cube.pos[19] = cube.pos[17]
    cube.pos[17] = temp
    
    temp = cube.pos[36]
    cube.pos[36] = cube.pos[12]
    cube.pos[12] = cube.pos[44]
    cube.pos[44] = cube.pos[24]
    cube.pos[24] = temp
    
    temp = cube.pos[37]
    cube.pos[37] = cube.pos[13]
    cube.pos[13] = cube.pos[45]
    cube.pos[45] = cube.pos[25]
    cube.pos[25] = temp
    
    temp = cube.pos[38]
    cube.pos[38] = cube.pos[14]
    cube.pos[14] = cube.pos[46]
    cube.pos[46] = cube.pos[26]
    cube.pos[26] = temp
    
    return cube

cpdef Cube Di (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(13)
    cdef int temp
    temp = cube.pos[16]
    cube.pos[16] = cube.pos[18]
    cube.pos[18] = cube.pos[20]
    cube.pos[20] = cube.pos[22]
    cube.pos[22] = temp
    
    temp = cube.pos[17]
    cube.pos[17] = cube.pos[19]
    cube.pos[19] = cube.pos[21]
    cube.pos[21] = cube.pos[23]
    cube.pos[23] = temp
    
    temp = cube.pos[24]
    cube.pos[24] = cube.pos[44]
    cube.pos[44] = cube.pos[12]
    cube.pos[12] = cube.pos[36]
    cube.pos[36] = temp
    
    temp = cube.pos[25]
    cube.pos[25] = cube.pos[45]
    cube.pos[45] = cube.pos[13]
    cube.pos[13] = cube.pos[37]
    cube.pos[37] = temp
    
    temp = cube.pos[26]
    cube.pos[26] = cube.pos[46]
    cube.pos[46] = cube.pos[14]
    cube.pos[14] = cube.pos[38]
    cube.pos[38] = temp
    
    return cube

cpdef Cube D2 (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(14)
    cdef int temp
    temp = cube.pos[16]
    cube.pos[16] = cube.pos[20]
    cube.pos[20] = temp
    temp = cube.pos[18]
    cube.pos[18] = cube.pos[22]
    cube.pos[22] = temp
    
    temp = cube.pos[17]
    cube.pos[17] = cube.pos[21]
    cube.pos[21] = temp
    temp = cube.pos[19]
    cube.pos[19] = cube.pos[23]
    cube.pos[23] = temp
    
    temp = cube.pos[36]
    cube.pos[36] = cube.pos[44]
    cube.pos[44] = temp
    temp = cube.pos[12]
    cube.pos[12] = cube.pos[24]
    cube.pos[24] = temp
    
    temp = cube.pos[37]
    cube.pos[37] = cube.pos[45]
    cube.pos[45] = temp
    temp = cube.pos[13]
    cube.pos[13] = cube.pos[25]
    cube.pos[25] = temp
    
    temp = cube.pos[38]
    cube.pos[38] = cube.pos[46]
    cube.pos[46] = temp
    temp = cube.pos[14]
    cube.pos[14] = cube.pos[26]
    cube.pos[26] = temp
    
    return cube

cpdef Cube B (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(15)
    cdef int temp
    temp = cube.pos[30]
    cube.pos[30] = cube.pos[28]
    cube.pos[28] = cube.pos[26]
    cube.pos[26] = cube.pos[24]
    cube.pos[24] = temp
    
    temp = cube.pos[31]
    cube.pos[31] = cube.pos[29]
    cube.pos[29] = cube.pos[27]
    cube.pos[27] = cube.pos[25]
    cube.pos[25] = temp
    
    temp = cube.pos[0]
    cube.pos[0] = cube.pos[34]
    cube.pos[34] = cube.pos[20]
    cube.pos[20] = cube.pos[46]
    cube.pos[46] = temp
    
    temp = cube.pos[1]
    cube.pos[1] = cube.pos[35]
    cube.pos[35] = cube.pos[21]
    cube.pos[21] = cube.pos[47]
    cube.pos[47] = temp
    
    temp = cube.pos[2]
    cube.pos[2] = cube.pos[36]
    cube.pos[36] = cube.pos[22]
    cube.pos[22] = cube.pos[40]
    cube.pos[40] = temp
    
    return cube

cpdef Cube Bi (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(16)
    cdef int temp
    temp = cube.pos[24]
    cube.pos[24] = cube.pos[26]
    cube.pos[26] = cube.pos[28]
    cube.pos[28] = cube.pos[30]
    cube.pos[30] = temp
    
    temp = cube.pos[25]
    cube.pos[25] = cube.pos[27]
    cube.pos[27] = cube.pos[29]
    cube.pos[29] = cube.pos[31]
    cube.pos[31] = temp
    
    temp = cube.pos[46]
    cube.pos[46] = cube.pos[20]
    cube.pos[20] = cube.pos[34]
    cube.pos[34] = cube.pos[0]
    cube.pos[0] = temp
    
    temp = cube.pos[47]
    cube.pos[47] = cube.pos[21]
    cube.pos[21] = cube.pos[35]
    cube.pos[35] = cube.pos[1]
    cube.pos[1] = temp
    
    temp = cube.pos[40]
    cube.pos[40] = cube.pos[22]
    cube.pos[22] = cube.pos[36]
    cube.pos[36] = cube.pos[2]
    cube.pos[2] = temp
    
    return cube

cpdef Cube B2 (Cube cube):
    cube = deepcopy(cube)
    cube.trail.push_back(17)
    cdef int temp
    temp = cube.pos[24]
    cube.pos[24] = cube.pos[28]
    cube.pos[28] = temp
    temp = cube.pos[26]
    cube.pos[26] = cube.pos[30]
    cube.pos[30] = temp
    
    temp = cube.pos[25]
    cube.pos[25] = cube.pos[29]
    cube.pos[29] = temp
    temp = cube.pos[27]
    cube.pos[27] = cube.pos[31]
    cube.pos[31] = temp
    
    temp = cube.pos[0]
    cube.pos[0] = cube.pos[20]
    cube.pos[20] = temp
    temp = cube.pos[34]
    cube.pos[34] = cube.pos[46]
    cube.pos[46] = temp
    
    temp = cube.pos[1]
    cube.pos[1] = cube.pos[21]
    cube.pos[21] = temp
    temp = cube.pos[35]
    cube.pos[35] = cube.pos[47]
    cube.pos[47] = temp
    
    temp = cube.pos[2]
    cube.pos[2] = cube.pos[22]
    cube.pos[22] = temp
    temp = cube.pos[36]
    cube.pos[36] = cube.pos[40]
    cube.pos[40] = temp
    
    return cube
