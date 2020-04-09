cpdef Cube R (Cube cube):
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

