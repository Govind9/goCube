import sys

ref_syn = "cube.pos"
obj_name = ref_syn.split('.')[0]
tab = "    "
config = {
    "R": {
        "face": [i for i in range(32, 40)],
        "layer": [2, 3, 4, 10, 11, 12, 18, 19, 20, 26, 27, 28]
    },
    "U": {
        "face": [i for i in range(0, 8)],
        "layer": [40, 41, 42, 8, 9, 10,  32, 33, 34, 28, 29, 30]
    },
    "F": {
        "face": [i for i in range(8, 16)],
        "layer": [4, 5, 6, 42, 43, 44, 16, 17, 18, 38, 39, 32]
    },
    "L": {
        "face": [i for i in range(40, 48)],
        "layer": [6, 7, 0, 30, 31, 24, 22, 23, 16, 14, 15, 8]
    },
    "D": {
        "face": [i for i in range(16, 24)],
        "layer": [36, 37, 38, 12, 13, 14, 44, 45, 46, 24, 25, 26]
    },
    "B": {
        "face": [i for i in range(24, 32)],
        "layer": [0, 1, 2, 34, 35, 36, 20, 21, 22, 46, 47, 40]
    }
}

def cycle_through(cycle, swap=False):
    if swap:
        code  = f"temp.set(0, {ref_syn}[{cycle[0]*3+0}]);\n{tab}"
        code += f"temp.set(1, {ref_syn}[{cycle[0]*3+1}]);\n{tab}"
        code += f"temp.set(2, {ref_syn}[{cycle[0]*3+2}]);\n{tab}"
        
        code += f"{ref_syn}.set({cycle[0]*3+0}, cube.pos[{cycle[2]*3+0}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[0]*3+1}, cube.pos[{cycle[2]*3+1}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[0]*3+2}, cube.pos[{cycle[2]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[2]*3+0}, temp[0]);\n{tab}"
        code += f"{ref_syn}.set({cycle[2]*3+1}, temp[1]);\n{tab}"
        code += f"{ref_syn}.set({cycle[2]*3+2}, temp[2]);\n{tab}"

        code += f"temp.set(0, {ref_syn}[{cycle[1]*3+0}]);\n{tab}"
        code += f"temp.set(1, {ref_syn}[{cycle[1]*3+1}]);\n{tab}"
        code += f"temp.set(2, {ref_syn}[{cycle[1]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[1]*3+0}, cube.pos[{cycle[3]*3+0}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[1]*3+1}, cube.pos[{cycle[3]*3+1}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[1]*3+2}, cube.pos[{cycle[3]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[3]*3+0}, temp[0]);\n{tab}"
        code += f"{ref_syn}.set({cycle[3]*3+1}, temp[1]);\n{tab}"
        code += f"{ref_syn}.set({cycle[3]*3+2}, temp[2]);\n{tab}\n{tab}"
    else:
        code  = f"temp.set(0, {ref_syn}[{cycle[0]*3+0}]);\n{tab}"
        code += f"temp.set(1, {ref_syn}[{cycle[0]*3+1}]);\n{tab}"
        code += f"temp.set(2, {ref_syn}[{cycle[0]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[0]*3+0}, cube.pos[{cycle[1]*3+0}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[0]*3+1}, cube.pos[{cycle[1]*3+1}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[0]*3+2}, cube.pos[{cycle[1]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[1]*3+0}, cube.pos[{cycle[2]*3+0}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[1]*3+1}, cube.pos[{cycle[2]*3+1}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[1]*3+2}, cube.pos[{cycle[2]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[2]*3+0}, cube.pos[{cycle[3]*3+0}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[2]*3+1}, cube.pos[{cycle[3]*3+1}]);\n{tab}"
        code += f"{ref_syn}.set({cycle[2]*3+2}, cube.pos[{cycle[3]*3+2}]);\n{tab}"

        code += f"{ref_syn}.set({cycle[3]*3+0}, temp[0]);\n{tab}"
        code += f"{ref_syn}.set({cycle[3]*3+1}, temp[1]);\n{tab}"
        code += f"{ref_syn}.set({cycle[3]*3+2}, temp[2]);\n{tab}\n{tab}"
    return code

def gen_move(move):
    # cycles for side
    side_cycles = []
    for i in range(2):
        side_cycles.append([config[move[0]]["face"][n] for n in range(i, i + 7, 2)])
    # cycles for layer
    layer_cycles = []
    for i in range(3):
        layer_cycles.append([config[move[0]]["layer"][n] for n in range(i, i + 11, 3)])
    
    code = f"Cube {move} (Cube {obj_name})" + "{" + f"\n{tab}"
    code += f"bitset<3> temp;\n{tab}"
    if move[1:] == "":
        code += cycle_through(side_cycles[0][::-1])
        code += cycle_through(side_cycles[1][::-1])
        code += cycle_through(layer_cycles[0])
        code += cycle_through(layer_cycles[1])
        code += cycle_through(layer_cycles[2])
    elif move[1:]== "i":
        code += cycle_through(side_cycles[0])
        code += cycle_through(side_cycles[1])
        code += cycle_through(layer_cycles[0][::-1])
        code += cycle_through(layer_cycles[1][::-1])
        code += cycle_through(layer_cycles[2][::-1])
    elif move[1:] == "2":
        code += cycle_through(side_cycles[0], swap=True)
        code += cycle_through(side_cycles[1], swap=True)
        code += cycle_through(layer_cycles[0], swap=True)
        code += cycle_through(layer_cycles[1], swap=True)
        code += cycle_through(layer_cycles[2], swap=True)
    code += f"return {obj_name};" + "\n}\n\n"
    return code

def gen_code():
    code = ""
    for move in config.keys():
        code += gen_move(move)
        code += gen_move(move+"i")
        code += gen_move(move+"2")
    with open("temp.py", "w") as file:
        file.write(code)

gen_code()