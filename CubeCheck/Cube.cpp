/*
 * This file contain functions definitions
 * needed to solve 2*2*2 cube with minimum number
 * of moves with maximum 11 moves for
 * any possible configuration
 *
 * author -:
 * Govind Sharma
 */


#include "goCube.h"

using namespace std;


/*
 * This is constructure for initializing
 * a cube state i.e. make cube
 */

Cube::Cube(){
    for (int i=26; i<=47; i+=3)  pos.set(i);
    for (int i=49; i<=70; i+=3)  pos.set(i);
    for (int i=96; i<=137; i+=3) pos.set(i);
    for (int i=73; i<=94; i+=3) {
        pos.set(i);
        pos.set(i+1);
    }
    for (int i=120; i<=141; i+=3) {
        pos.set(i);
        pos.set(i+2);
    }
}

void Cube::print(){
    for (int i=0; i<6; i++) {
        for (int j=0; j<24; j++) {
            cout << pos[24*i + j];
        }
        cout << endl;
    }
}

string color (Cube *cube, int index) {
    string colors[18] = {YELLOW, GREEN, WHITE, BLUE, ORANGE, RED};
    index = index * 3;
    return colors[cube->pos[index]*4 + cube->pos[index+1]*2 + cube->pos[index+2]];
}

void Cube::paint(){
    string text = "";
    text += "      ";
    text += color(this, 0);
    text += color(this, 1);
    text += color(this, 2);
    text += "      \n";

    text += "      ";
    text += color(this, 7);
    text += YELLOW;
    text += color(this, 3);
    text += "      \n";

    text += "      ";
    text += color(this, 6);
    text += color(this, 5);
    text += color(this, 4);
    text += "      \n";

    text += color(this, 40);
    text += color(this, 41);
    text += color(this, 42);
    text += color(this, 8);
    text += color(this, 9);
    text += color(this, 10);
    text += color(this, 32);
    text += color(this, 33);
    text += color(this, 34);
    text += "\n";

    text += color(this, 47);
    text += RED;
    text += color(this, 43);
    text += color(this, 15);
    text += GREEN;
    text += color(this, 11);
    text += color(this, 39);
    text += ORANGE;
    text += color(this, 35);
    text += "\n";

    text += color(this, 46);
    text += color(this, 45);
    text += color(this, 44);
    text += color(this, 14);
    text += color(this, 13);
    text += color(this, 12);
    text += color(this, 38);
    text += color(this, 37);
    text += color(this, 36);
    text += "\n";

    text += "      ";
    text += color(this, 16);
    text += color(this, 17);
    text += color(this, 18);
    text += "      \n";

    text += "      ";
    text += color(this, 23);
    text += WHITE;
    text += color(this, 19);
    text += "      \n";

    text += "      ";
    text += color(this, 22);
    text += color(this, 21);
    text += color(this, 20);
    text += "      \n";

    text += "      ";
    text += color(this, 24);
    text += color(this, 25);
    text += color(this, 26);
    text += "      \n";

    text += "      ";
    text += color(this, 31);
    text += BLUE;
    text += color(this, 27);
    text += "      \n";

    text += "      ";
    text += color(this, 30);
    text += color(this, 29);
    text += color(this, 28);
    text += "      \n\n";

    cout << text << END_COLOR;
}

void solve(Cube cube) {
    queue <Cube> Q;
    set <string> cube_set;
    int level = 0, new_level = 0;
    Cube n_cube, cur;
    string code;

    Q.push(cube);
    cube_set.insert(cube.pos.to_string());

    while (!Q.empty()) {
        cur = Q.front();
		Q.pop();
		new_level = cur.trail.size();
        if (new_level > level) {
            level = new_level;
            cout << "Entered level: " << level << "QSize: " << Q.size() << endl;
        }

        n_cube = R(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }

        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = Ri(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = R2(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = U(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = Ui(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = U2(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = F(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = Fi(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = F2(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = L(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = Li(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = L2(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = B(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = Bi(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = B2(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = D(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = Di(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }

        n_cube = D2(cur);
        if (is_cross(n_cube)) {
            //give_solution(n_cube);
            return;
        }
        code = n_cube.pos.to_string();
        if(cube_set.find(code) == cube_set.end()) {
            cube_set.insert(code);
            Q.push(n_cube);
        }
    }
}

bool is_cross(Cube cube) {
    return false;
}

Cube K (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[114]);
    temp.set(1, cube.pos[115]);
    temp.set(2, cube.pos[116]);
    cube.pos.set(114, cube.pos[108]);
    cube.pos.set(115, cube.pos[109]);
    cube.pos.set(116, cube.pos[110]);
    cube.pos.set(108, cube.pos[102]);
    cube.pos.set(109, cube.pos[103]);
    cube.pos.set(110, cube.pos[104]);
    cube.pos.set(102, cube.pos[96]);
    cube.pos.set(103, cube.pos[97]);
    cube.pos.set(104, cube.pos[98]);
    cube.pos.set(96, temp[0]);
    cube.pos.set(97, temp[1]);
    cube.pos.set(98, temp[2]);
    cube.trail.push_back(0);
    return cube;
}

Cube R (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[114]);
    temp.set(1, cube.pos[115]);
    temp.set(2, cube.pos[116]);
    cube.pos.set(114, cube.pos[108]);
    cube.pos.set(115, cube.pos[109]);
    cube.pos.set(116, cube.pos[110]);
    cube.pos.set(108, cube.pos[102]);
    cube.pos.set(109, cube.pos[103]);
    cube.pos.set(110, cube.pos[104]);
    cube.pos.set(102, cube.pos[96]);
    cube.pos.set(103, cube.pos[97]);
    cube.pos.set(104, cube.pos[98]);
    cube.pos.set(96, temp[0]);
    cube.pos.set(97, temp[1]);
    cube.pos.set(98, temp[2]);

    temp.set(0, cube.pos[117]);
    temp.set(1, cube.pos[118]);
    temp.set(2, cube.pos[119]);
    cube.pos.set(117, cube.pos[111]);
    cube.pos.set(118, cube.pos[112]);
    cube.pos.set(119, cube.pos[113]);
    cube.pos.set(111, cube.pos[105]);
    cube.pos.set(112, cube.pos[106]);
    cube.pos.set(113, cube.pos[107]);
    cube.pos.set(105, cube.pos[99]);
    cube.pos.set(106, cube.pos[100]);
    cube.pos.set(107, cube.pos[101]);
    cube.pos.set(99, temp[0]);
    cube.pos.set(100, temp[1]);
    cube.pos.set(101, temp[2]);

    temp.set(0, cube.pos[6]);
    temp.set(1, cube.pos[7]);
    temp.set(2, cube.pos[8]);
    cube.pos.set(6, cube.pos[30]);
    cube.pos.set(7, cube.pos[31]);
    cube.pos.set(8, cube.pos[32]);
    cube.pos.set(30, cube.pos[54]);
    cube.pos.set(31, cube.pos[55]);
    cube.pos.set(32, cube.pos[56]);
    cube.pos.set(54, cube.pos[78]);
    cube.pos.set(55, cube.pos[79]);
    cube.pos.set(56, cube.pos[80]);
    cube.pos.set(78, temp[0]);
    cube.pos.set(79, temp[1]);
    cube.pos.set(80, temp[2]);

    temp.set(0, cube.pos[9]);
    temp.set(1, cube.pos[10]);
    temp.set(2, cube.pos[11]);
    cube.pos.set(9, cube.pos[33]);
    cube.pos.set(10, cube.pos[34]);
    cube.pos.set(11, cube.pos[35]);
    cube.pos.set(33, cube.pos[57]);
    cube.pos.set(34, cube.pos[58]);
    cube.pos.set(35, cube.pos[59]);
    cube.pos.set(57, cube.pos[81]);
    cube.pos.set(58, cube.pos[82]);
    cube.pos.set(59, cube.pos[83]);
    cube.pos.set(81, temp[0]);
    cube.pos.set(82, temp[1]);
    cube.pos.set(83, temp[2]);

    temp.set(0, cube.pos[12]);
    temp.set(1, cube.pos[13]);
    temp.set(2, cube.pos[14]);
    cube.pos.set(12, cube.pos[36]);
    cube.pos.set(13, cube.pos[37]);
    cube.pos.set(14, cube.pos[38]);
    cube.pos.set(36, cube.pos[60]);
    cube.pos.set(37, cube.pos[61]);
    cube.pos.set(38, cube.pos[62]);
    cube.pos.set(60, cube.pos[84]);
    cube.pos.set(61, cube.pos[85]);
    cube.pos.set(62, cube.pos[86]);
    cube.pos.set(84, temp[0]);
    cube.pos.set(85, temp[1]);
    cube.pos.set(86, temp[2]);

    cube.trail.push_back(0);
    return cube;
}

Cube Ri (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[96]);
    temp.set(1, cube.pos[97]);
    temp.set(2, cube.pos[98]);
    cube.pos.set(96, cube.pos[102]);
    cube.pos.set(97, cube.pos[103]);
    cube.pos.set(98, cube.pos[104]);
    cube.pos.set(102, cube.pos[108]);
    cube.pos.set(103, cube.pos[109]);
    cube.pos.set(104, cube.pos[110]);
    cube.pos.set(108, cube.pos[114]);
    cube.pos.set(109, cube.pos[115]);
    cube.pos.set(110, cube.pos[116]);
    cube.pos.set(114, temp[0]);
    cube.pos.set(115, temp[1]);
    cube.pos.set(116, temp[2]);

    temp.set(0, cube.pos[99]);
    temp.set(1, cube.pos[100]);
    temp.set(2, cube.pos[101]);
    cube.pos.set(99, cube.pos[105]);
    cube.pos.set(100, cube.pos[106]);
    cube.pos.set(101, cube.pos[107]);
    cube.pos.set(105, cube.pos[111]);
    cube.pos.set(106, cube.pos[112]);
    cube.pos.set(107, cube.pos[113]);
    cube.pos.set(111, cube.pos[117]);
    cube.pos.set(112, cube.pos[118]);
    cube.pos.set(113, cube.pos[119]);
    cube.pos.set(117, temp[0]);
    cube.pos.set(118, temp[1]);
    cube.pos.set(119, temp[2]);

    temp.set(0, cube.pos[78]);
    temp.set(1, cube.pos[79]);
    temp.set(2, cube.pos[80]);
    cube.pos.set(78, cube.pos[54]);
    cube.pos.set(79, cube.pos[55]);
    cube.pos.set(80, cube.pos[56]);
    cube.pos.set(54, cube.pos[30]);
    cube.pos.set(55, cube.pos[31]);
    cube.pos.set(56, cube.pos[32]);
    cube.pos.set(30, cube.pos[6]);
    cube.pos.set(31, cube.pos[7]);
    cube.pos.set(32, cube.pos[8]);
    cube.pos.set(6, temp[0]);
    cube.pos.set(7, temp[1]);
    cube.pos.set(8, temp[2]);

    temp.set(0, cube.pos[81]);
    temp.set(1, cube.pos[82]);
    temp.set(2, cube.pos[83]);
    cube.pos.set(81, cube.pos[57]);
    cube.pos.set(82, cube.pos[58]);
    cube.pos.set(83, cube.pos[59]);
    cube.pos.set(57, cube.pos[33]);
    cube.pos.set(58, cube.pos[34]);
    cube.pos.set(59, cube.pos[35]);
    cube.pos.set(33, cube.pos[9]);
    cube.pos.set(34, cube.pos[10]);
    cube.pos.set(35, cube.pos[11]);
    cube.pos.set(9, temp[0]);
    cube.pos.set(10, temp[1]);
    cube.pos.set(11, temp[2]);

    temp.set(0, cube.pos[84]);
    temp.set(1, cube.pos[85]);
    temp.set(2, cube.pos[86]);
    cube.pos.set(84, cube.pos[60]);
    cube.pos.set(85, cube.pos[61]);
    cube.pos.set(86, cube.pos[62]);
    cube.pos.set(60, cube.pos[36]);
    cube.pos.set(61, cube.pos[37]);
    cube.pos.set(62, cube.pos[38]);
    cube.pos.set(36, cube.pos[12]);
    cube.pos.set(37, cube.pos[13]);
    cube.pos.set(38, cube.pos[14]);
    cube.pos.set(12, temp[0]);
    cube.pos.set(13, temp[1]);
    cube.pos.set(14, temp[2]);

    cube.trail.push_back(1);
    return cube;
}

Cube R2 (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[96]);
    temp.set(1, cube.pos[97]);
    temp.set(2, cube.pos[98]);
    cube.pos.set(96, cube.pos[108]);
    cube.pos.set(97, cube.pos[109]);
    cube.pos.set(98, cube.pos[110]);
    cube.pos.set(108, temp[0]);
    cube.pos.set(109, temp[1]);
    cube.pos.set(110, temp[2]);
    temp.set(0, cube.pos[102]);
    temp.set(1, cube.pos[103]);
    temp.set(2, cube.pos[104]);
    cube.pos.set(102, cube.pos[114]);
    cube.pos.set(103, cube.pos[115]);
    cube.pos.set(104, cube.pos[116]);
    cube.pos.set(114, temp[0]);
    cube.pos.set(115, temp[1]);
    cube.pos.set(116, temp[2]);

    temp.set(0, cube.pos[99]);
    temp.set(1, cube.pos[100]);
    temp.set(2, cube.pos[101]);
    cube.pos.set(99, cube.pos[111]);
    cube.pos.set(100, cube.pos[112]);
    cube.pos.set(101, cube.pos[113]);
    cube.pos.set(111, temp[0]);
    cube.pos.set(112, temp[1]);
    cube.pos.set(113, temp[2]);
    temp.set(0, cube.pos[105]);
    temp.set(1, cube.pos[106]);
    temp.set(2, cube.pos[107]);
    cube.pos.set(105, cube.pos[117]);
    cube.pos.set(106, cube.pos[118]);
    cube.pos.set(107, cube.pos[119]);
    cube.pos.set(117, temp[0]);
    cube.pos.set(118, temp[1]);
    cube.pos.set(119, temp[2]);

    temp.set(0, cube.pos[6]);
    temp.set(1, cube.pos[7]);
    temp.set(2, cube.pos[8]);
    cube.pos.set(6, cube.pos[54]);
    cube.pos.set(7, cube.pos[55]);
    cube.pos.set(8, cube.pos[56]);
    cube.pos.set(54, temp[0]);
    cube.pos.set(55, temp[1]);
    cube.pos.set(56, temp[2]);
    temp.set(0, cube.pos[30]);
    temp.set(1, cube.pos[31]);
    temp.set(2, cube.pos[32]);
    cube.pos.set(30, cube.pos[78]);
    cube.pos.set(31, cube.pos[79]);
    cube.pos.set(32, cube.pos[80]);
    cube.pos.set(78, temp[0]);
    cube.pos.set(79, temp[1]);
    cube.pos.set(80, temp[2]);

    temp.set(0, cube.pos[9]);
    temp.set(1, cube.pos[10]);
    temp.set(2, cube.pos[11]);
    cube.pos.set(9, cube.pos[57]);
    cube.pos.set(10, cube.pos[58]);
    cube.pos.set(11, cube.pos[59]);
    cube.pos.set(57, temp[0]);
    cube.pos.set(58, temp[1]);
    cube.pos.set(59, temp[2]);
    temp.set(0, cube.pos[33]);
    temp.set(1, cube.pos[34]);
    temp.set(2, cube.pos[35]);
    cube.pos.set(33, cube.pos[81]);
    cube.pos.set(34, cube.pos[82]);
    cube.pos.set(35, cube.pos[83]);
    cube.pos.set(81, temp[0]);
    cube.pos.set(82, temp[1]);
    cube.pos.set(83, temp[2]);

    temp.set(0, cube.pos[12]);
    temp.set(1, cube.pos[13]);
    temp.set(2, cube.pos[14]);
    cube.pos.set(12, cube.pos[60]);
    cube.pos.set(13, cube.pos[61]);
    cube.pos.set(14, cube.pos[62]);
    cube.pos.set(60, temp[0]);
    cube.pos.set(61, temp[1]);
    cube.pos.set(62, temp[2]);
    temp.set(0, cube.pos[36]);
    temp.set(1, cube.pos[37]);
    temp.set(2, cube.pos[38]);
    cube.pos.set(36, cube.pos[84]);
    cube.pos.set(37, cube.pos[85]);
    cube.pos.set(38, cube.pos[86]);
    cube.pos.set(84, temp[0]);
    cube.pos.set(85, temp[1]);
    cube.pos.set(86, temp[2]);

    cube.trail.push_back(2);
    return cube;
}

Cube U (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[18]);
    temp.set(1, cube.pos[19]);
    temp.set(2, cube.pos[20]);
    cube.pos.set(18, cube.pos[12]);
    cube.pos.set(19, cube.pos[13]);
    cube.pos.set(20, cube.pos[14]);
    cube.pos.set(12, cube.pos[6]);
    cube.pos.set(13, cube.pos[7]);
    cube.pos.set(14, cube.pos[8]);
    cube.pos.set(6, cube.pos[0]);
    cube.pos.set(7, cube.pos[1]);
    cube.pos.set(8, cube.pos[2]);
    cube.pos.set(0, temp[0]);
    cube.pos.set(1, temp[1]);
    cube.pos.set(2, temp[2]);

    temp.set(0, cube.pos[21]);
    temp.set(1, cube.pos[22]);
    temp.set(2, cube.pos[23]);
    cube.pos.set(21, cube.pos[15]);
    cube.pos.set(22, cube.pos[16]);
    cube.pos.set(23, cube.pos[17]);
    cube.pos.set(15, cube.pos[9]);
    cube.pos.set(16, cube.pos[10]);
    cube.pos.set(17, cube.pos[11]);
    cube.pos.set(9, cube.pos[3]);
    cube.pos.set(10, cube.pos[4]);
    cube.pos.set(11, cube.pos[5]);
    cube.pos.set(3, temp[0]);
    cube.pos.set(4, temp[1]);
    cube.pos.set(5, temp[2]);

    temp.set(0, cube.pos[120]);
    temp.set(1, cube.pos[121]);
    temp.set(2, cube.pos[122]);
    cube.pos.set(120, cube.pos[24]);
    cube.pos.set(121, cube.pos[25]);
    cube.pos.set(122, cube.pos[26]);
    cube.pos.set(24, cube.pos[96]);
    cube.pos.set(25, cube.pos[97]);
    cube.pos.set(26, cube.pos[98]);
    cube.pos.set(96, cube.pos[84]);
    cube.pos.set(97, cube.pos[85]);
    cube.pos.set(98, cube.pos[86]);
    cube.pos.set(84, temp[0]);
    cube.pos.set(85, temp[1]);
    cube.pos.set(86, temp[2]);

    temp.set(0, cube.pos[123]);
    temp.set(1, cube.pos[124]);
    temp.set(2, cube.pos[125]);
    cube.pos.set(123, cube.pos[27]);
    cube.pos.set(124, cube.pos[28]);
    cube.pos.set(125, cube.pos[29]);
    cube.pos.set(27, cube.pos[99]);
    cube.pos.set(28, cube.pos[100]);
    cube.pos.set(29, cube.pos[101]);
    cube.pos.set(99, cube.pos[87]);
    cube.pos.set(100, cube.pos[88]);
    cube.pos.set(101, cube.pos[89]);
    cube.pos.set(87, temp[0]);
    cube.pos.set(88, temp[1]);
    cube.pos.set(89, temp[2]);

    temp.set(0, cube.pos[126]);
    temp.set(1, cube.pos[127]);
    temp.set(2, cube.pos[128]);
    cube.pos.set(126, cube.pos[30]);
    cube.pos.set(127, cube.pos[31]);
    cube.pos.set(128, cube.pos[32]);
    cube.pos.set(30, cube.pos[102]);
    cube.pos.set(31, cube.pos[103]);
    cube.pos.set(32, cube.pos[104]);
    cube.pos.set(102, cube.pos[90]);
    cube.pos.set(103, cube.pos[91]);
    cube.pos.set(104, cube.pos[92]);
    cube.pos.set(90, temp[0]);
    cube.pos.set(91, temp[1]);
    cube.pos.set(92, temp[2]);

    cube.trail.push_back(3);
    return cube;
}

Cube Ui (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[0]);
    temp.set(1, cube.pos[1]);
    temp.set(2, cube.pos[2]);
    cube.pos.set(0, cube.pos[6]);
    cube.pos.set(1, cube.pos[7]);
    cube.pos.set(2, cube.pos[8]);
    cube.pos.set(6, cube.pos[12]);
    cube.pos.set(7, cube.pos[13]);
    cube.pos.set(8, cube.pos[14]);
    cube.pos.set(12, cube.pos[18]);
    cube.pos.set(13, cube.pos[19]);
    cube.pos.set(14, cube.pos[20]);
    cube.pos.set(18, temp[0]);
    cube.pos.set(19, temp[1]);
    cube.pos.set(20, temp[2]);

    temp.set(0, cube.pos[3]);
    temp.set(1, cube.pos[4]);
    temp.set(2, cube.pos[5]);
    cube.pos.set(3, cube.pos[9]);
    cube.pos.set(4, cube.pos[10]);
    cube.pos.set(5, cube.pos[11]);
    cube.pos.set(9, cube.pos[15]);
    cube.pos.set(10, cube.pos[16]);
    cube.pos.set(11, cube.pos[17]);
    cube.pos.set(15, cube.pos[21]);
    cube.pos.set(16, cube.pos[22]);
    cube.pos.set(17, cube.pos[23]);
    cube.pos.set(21, temp[0]);
    cube.pos.set(22, temp[1]);
    cube.pos.set(23, temp[2]);

    temp.set(0, cube.pos[84]);
    temp.set(1, cube.pos[85]);
    temp.set(2, cube.pos[86]);
    cube.pos.set(84, cube.pos[96]);
    cube.pos.set(85, cube.pos[97]);
    cube.pos.set(86, cube.pos[98]);
    cube.pos.set(96, cube.pos[24]);
    cube.pos.set(97, cube.pos[25]);
    cube.pos.set(98, cube.pos[26]);
    cube.pos.set(24, cube.pos[120]);
    cube.pos.set(25, cube.pos[121]);
    cube.pos.set(26, cube.pos[122]);
    cube.pos.set(120, temp[0]);
    cube.pos.set(121, temp[1]);
    cube.pos.set(122, temp[2]);

    temp.set(0, cube.pos[87]);
    temp.set(1, cube.pos[88]);
    temp.set(2, cube.pos[89]);
    cube.pos.set(87, cube.pos[99]);
    cube.pos.set(88, cube.pos[100]);
    cube.pos.set(89, cube.pos[101]);
    cube.pos.set(99, cube.pos[27]);
    cube.pos.set(100, cube.pos[28]);
    cube.pos.set(101, cube.pos[29]);
    cube.pos.set(27, cube.pos[123]);
    cube.pos.set(28, cube.pos[124]);
    cube.pos.set(29, cube.pos[125]);
    cube.pos.set(123, temp[0]);
    cube.pos.set(124, temp[1]);
    cube.pos.set(125, temp[2]);

    temp.set(0, cube.pos[90]);
    temp.set(1, cube.pos[91]);
    temp.set(2, cube.pos[92]);
    cube.pos.set(90, cube.pos[102]);
    cube.pos.set(91, cube.pos[103]);
    cube.pos.set(92, cube.pos[104]);
    cube.pos.set(102, cube.pos[30]);
    cube.pos.set(103, cube.pos[31]);
    cube.pos.set(104, cube.pos[32]);
    cube.pos.set(30, cube.pos[126]);
    cube.pos.set(31, cube.pos[127]);
    cube.pos.set(32, cube.pos[128]);
    cube.pos.set(126, temp[0]);
    cube.pos.set(127, temp[1]);
    cube.pos.set(128, temp[2]);

    cube.trail.push_back(4);
    return cube;
}

Cube U2 (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[0]);
    temp.set(1, cube.pos[1]);
    temp.set(2, cube.pos[2]);
    cube.pos.set(0, cube.pos[12]);
    cube.pos.set(1, cube.pos[13]);
    cube.pos.set(2, cube.pos[14]);
    cube.pos.set(12, temp[0]);
    cube.pos.set(13, temp[1]);
    cube.pos.set(14, temp[2]);
    temp.set(0, cube.pos[6]);
    temp.set(1, cube.pos[7]);
    temp.set(2, cube.pos[8]);
    cube.pos.set(6, cube.pos[18]);
    cube.pos.set(7, cube.pos[19]);
    cube.pos.set(8, cube.pos[20]);
    cube.pos.set(18, temp[0]);
    cube.pos.set(19, temp[1]);
    cube.pos.set(20, temp[2]);

    temp.set(0, cube.pos[3]);
    temp.set(1, cube.pos[4]);
    temp.set(2, cube.pos[5]);
    cube.pos.set(3, cube.pos[15]);
    cube.pos.set(4, cube.pos[16]);
    cube.pos.set(5, cube.pos[17]);
    cube.pos.set(15, temp[0]);
    cube.pos.set(16, temp[1]);
    cube.pos.set(17, temp[2]);
    temp.set(0, cube.pos[9]);
    temp.set(1, cube.pos[10]);
    temp.set(2, cube.pos[11]);
    cube.pos.set(9, cube.pos[21]);
    cube.pos.set(10, cube.pos[22]);
    cube.pos.set(11, cube.pos[23]);
    cube.pos.set(21, temp[0]);
    cube.pos.set(22, temp[1]);
    cube.pos.set(23, temp[2]);

    temp.set(0, cube.pos[120]);
    temp.set(1, cube.pos[121]);
    temp.set(2, cube.pos[122]);
    cube.pos.set(120, cube.pos[96]);
    cube.pos.set(121, cube.pos[97]);
    cube.pos.set(122, cube.pos[98]);
    cube.pos.set(96, temp[0]);
    cube.pos.set(97, temp[1]);
    cube.pos.set(98, temp[2]);
    temp.set(0, cube.pos[24]);
    temp.set(1, cube.pos[25]);
    temp.set(2, cube.pos[26]);
    cube.pos.set(24, cube.pos[84]);
    cube.pos.set(25, cube.pos[85]);
    cube.pos.set(26, cube.pos[86]);
    cube.pos.set(84, temp[0]);
    cube.pos.set(85, temp[1]);
    cube.pos.set(86, temp[2]);

    temp.set(0, cube.pos[123]);
    temp.set(1, cube.pos[124]);
    temp.set(2, cube.pos[125]);
    cube.pos.set(123, cube.pos[99]);
    cube.pos.set(124, cube.pos[100]);
    cube.pos.set(125, cube.pos[101]);
    cube.pos.set(99, temp[0]);
    cube.pos.set(100, temp[1]);
    cube.pos.set(101, temp[2]);
    temp.set(0, cube.pos[27]);
    temp.set(1, cube.pos[28]);
    temp.set(2, cube.pos[29]);
    cube.pos.set(27, cube.pos[87]);
    cube.pos.set(28, cube.pos[88]);
    cube.pos.set(29, cube.pos[89]);
    cube.pos.set(87, temp[0]);
    cube.pos.set(88, temp[1]);
    cube.pos.set(89, temp[2]);

    temp.set(0, cube.pos[126]);
    temp.set(1, cube.pos[127]);
    temp.set(2, cube.pos[128]);
    cube.pos.set(126, cube.pos[102]);
    cube.pos.set(127, cube.pos[103]);
    cube.pos.set(128, cube.pos[104]);
    cube.pos.set(102, temp[0]);
    cube.pos.set(103, temp[1]);
    cube.pos.set(104, temp[2]);
    temp.set(0, cube.pos[30]);
    temp.set(1, cube.pos[31]);
    temp.set(2, cube.pos[32]);
    cube.pos.set(30, cube.pos[90]);
    cube.pos.set(31, cube.pos[91]);
    cube.pos.set(32, cube.pos[92]);
    cube.pos.set(90, temp[0]);
    cube.pos.set(91, temp[1]);
    cube.pos.set(92, temp[2]);

    cube.trail.push_back(5);
    return cube;
}

Cube F (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[42]);
    temp.set(1, cube.pos[43]);
    temp.set(2, cube.pos[44]);
    cube.pos.set(42, cube.pos[36]);
    cube.pos.set(43, cube.pos[37]);
    cube.pos.set(44, cube.pos[38]);
    cube.pos.set(36, cube.pos[30]);
    cube.pos.set(37, cube.pos[31]);
    cube.pos.set(38, cube.pos[32]);
    cube.pos.set(30, cube.pos[24]);
    cube.pos.set(31, cube.pos[25]);
    cube.pos.set(32, cube.pos[26]);
    cube.pos.set(24, temp[0]);
    cube.pos.set(25, temp[1]);
    cube.pos.set(26, temp[2]);

    temp.set(0, cube.pos[45]);
    temp.set(1, cube.pos[46]);
    temp.set(2, cube.pos[47]);
    cube.pos.set(45, cube.pos[39]);
    cube.pos.set(46, cube.pos[40]);
    cube.pos.set(47, cube.pos[41]);
    cube.pos.set(39, cube.pos[33]);
    cube.pos.set(40, cube.pos[34]);
    cube.pos.set(41, cube.pos[35]);
    cube.pos.set(33, cube.pos[27]);
    cube.pos.set(34, cube.pos[28]);
    cube.pos.set(35, cube.pos[29]);
    cube.pos.set(27, temp[0]);
    cube.pos.set(28, temp[1]);
    cube.pos.set(29, temp[2]);

    temp.set(0, cube.pos[12]);
    temp.set(1, cube.pos[13]);
    temp.set(2, cube.pos[14]);
    cube.pos.set(12, cube.pos[126]);
    cube.pos.set(13, cube.pos[127]);
    cube.pos.set(14, cube.pos[128]);
    cube.pos.set(126, cube.pos[48]);
    cube.pos.set(127, cube.pos[49]);
    cube.pos.set(128, cube.pos[50]);
    cube.pos.set(48, cube.pos[114]);
    cube.pos.set(49, cube.pos[115]);
    cube.pos.set(50, cube.pos[116]);
    cube.pos.set(114, temp[0]);
    cube.pos.set(115, temp[1]);
    cube.pos.set(116, temp[2]);

    temp.set(0, cube.pos[15]);
    temp.set(1, cube.pos[16]);
    temp.set(2, cube.pos[17]);
    cube.pos.set(15, cube.pos[129]);
    cube.pos.set(16, cube.pos[130]);
    cube.pos.set(17, cube.pos[131]);
    cube.pos.set(129, cube.pos[51]);
    cube.pos.set(130, cube.pos[52]);
    cube.pos.set(131, cube.pos[53]);
    cube.pos.set(51, cube.pos[117]);
    cube.pos.set(52, cube.pos[118]);
    cube.pos.set(53, cube.pos[119]);
    cube.pos.set(117, temp[0]);
    cube.pos.set(118, temp[1]);
    cube.pos.set(119, temp[2]);

    temp.set(0, cube.pos[18]);
    temp.set(1, cube.pos[19]);
    temp.set(2, cube.pos[20]);
    cube.pos.set(18, cube.pos[132]);
    cube.pos.set(19, cube.pos[133]);
    cube.pos.set(20, cube.pos[134]);
    cube.pos.set(132, cube.pos[54]);
    cube.pos.set(133, cube.pos[55]);
    cube.pos.set(134, cube.pos[56]);
    cube.pos.set(54, cube.pos[96]);
    cube.pos.set(55, cube.pos[97]);
    cube.pos.set(56, cube.pos[98]);
    cube.pos.set(96, temp[0]);
    cube.pos.set(97, temp[1]);
    cube.pos.set(98, temp[2]);

    cube.trail.push_back(6);
    return cube;
}

Cube Fi (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[24]);
    temp.set(1, cube.pos[25]);
    temp.set(2, cube.pos[26]);
    cube.pos.set(24, cube.pos[30]);
    cube.pos.set(25, cube.pos[31]);
    cube.pos.set(26, cube.pos[32]);
    cube.pos.set(30, cube.pos[36]);
    cube.pos.set(31, cube.pos[37]);
    cube.pos.set(32, cube.pos[38]);
    cube.pos.set(36, cube.pos[42]);
    cube.pos.set(37, cube.pos[43]);
    cube.pos.set(38, cube.pos[44]);
    cube.pos.set(42, temp[0]);
    cube.pos.set(43, temp[1]);
    cube.pos.set(44, temp[2]);

    temp.set(0, cube.pos[27]);
    temp.set(1, cube.pos[28]);
    temp.set(2, cube.pos[29]);
    cube.pos.set(27, cube.pos[33]);
    cube.pos.set(28, cube.pos[34]);
    cube.pos.set(29, cube.pos[35]);
    cube.pos.set(33, cube.pos[39]);
    cube.pos.set(34, cube.pos[40]);
    cube.pos.set(35, cube.pos[41]);
    cube.pos.set(39, cube.pos[45]);
    cube.pos.set(40, cube.pos[46]);
    cube.pos.set(41, cube.pos[47]);
    cube.pos.set(45, temp[0]);
    cube.pos.set(46, temp[1]);
    cube.pos.set(47, temp[2]);

    temp.set(0, cube.pos[114]);
    temp.set(1, cube.pos[115]);
    temp.set(2, cube.pos[116]);
    cube.pos.set(114, cube.pos[48]);
    cube.pos.set(115, cube.pos[49]);
    cube.pos.set(116, cube.pos[50]);
    cube.pos.set(48, cube.pos[126]);
    cube.pos.set(49, cube.pos[127]);
    cube.pos.set(50, cube.pos[128]);
    cube.pos.set(126, cube.pos[12]);
    cube.pos.set(127, cube.pos[13]);
    cube.pos.set(128, cube.pos[14]);
    cube.pos.set(12, temp[0]);
    cube.pos.set(13, temp[1]);
    cube.pos.set(14, temp[2]);

    temp.set(0, cube.pos[117]);
    temp.set(1, cube.pos[118]);
    temp.set(2, cube.pos[119]);
    cube.pos.set(117, cube.pos[51]);
    cube.pos.set(118, cube.pos[52]);
    cube.pos.set(119, cube.pos[53]);
    cube.pos.set(51, cube.pos[129]);
    cube.pos.set(52, cube.pos[130]);
    cube.pos.set(53, cube.pos[131]);
    cube.pos.set(129, cube.pos[15]);
    cube.pos.set(130, cube.pos[16]);
    cube.pos.set(131, cube.pos[17]);
    cube.pos.set(15, temp[0]);
    cube.pos.set(16, temp[1]);
    cube.pos.set(17, temp[2]);

    temp.set(0, cube.pos[96]);
    temp.set(1, cube.pos[97]);
    temp.set(2, cube.pos[98]);
    cube.pos.set(96, cube.pos[54]);
    cube.pos.set(97, cube.pos[55]);
    cube.pos.set(98, cube.pos[56]);
    cube.pos.set(54, cube.pos[132]);
    cube.pos.set(55, cube.pos[133]);
    cube.pos.set(56, cube.pos[134]);
    cube.pos.set(132, cube.pos[18]);
    cube.pos.set(133, cube.pos[19]);
    cube.pos.set(134, cube.pos[20]);
    cube.pos.set(18, temp[0]);
    cube.pos.set(19, temp[1]);
    cube.pos.set(20, temp[2]);

    cube.trail.push_back(7);
    return cube;
}

Cube F2 (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[24]);
    temp.set(1, cube.pos[25]);
    temp.set(2, cube.pos[26]);
    cube.pos.set(24, cube.pos[36]);
    cube.pos.set(25, cube.pos[37]);
    cube.pos.set(26, cube.pos[38]);
    cube.pos.set(36, temp[0]);
    cube.pos.set(37, temp[1]);
    cube.pos.set(38, temp[2]);
    temp.set(0, cube.pos[30]);
    temp.set(1, cube.pos[31]);
    temp.set(2, cube.pos[32]);
    cube.pos.set(30, cube.pos[42]);
    cube.pos.set(31, cube.pos[43]);
    cube.pos.set(32, cube.pos[44]);
    cube.pos.set(42, temp[0]);
    cube.pos.set(43, temp[1]);
    cube.pos.set(44, temp[2]);

    temp.set(0, cube.pos[27]);
    temp.set(1, cube.pos[28]);
    temp.set(2, cube.pos[29]);
    cube.pos.set(27, cube.pos[39]);
    cube.pos.set(28, cube.pos[40]);
    cube.pos.set(29, cube.pos[41]);
    cube.pos.set(39, temp[0]);
    cube.pos.set(40, temp[1]);
    cube.pos.set(41, temp[2]);
    temp.set(0, cube.pos[33]);
    temp.set(1, cube.pos[34]);
    temp.set(2, cube.pos[35]);
    cube.pos.set(33, cube.pos[45]);
    cube.pos.set(34, cube.pos[46]);
    cube.pos.set(35, cube.pos[47]);
    cube.pos.set(45, temp[0]);
    cube.pos.set(46, temp[1]);
    cube.pos.set(47, temp[2]);

    temp.set(0, cube.pos[12]);
    temp.set(1, cube.pos[13]);
    temp.set(2, cube.pos[14]);
    cube.pos.set(12, cube.pos[48]);
    cube.pos.set(13, cube.pos[49]);
    cube.pos.set(14, cube.pos[50]);
    cube.pos.set(48, temp[0]);
    cube.pos.set(49, temp[1]);
    cube.pos.set(50, temp[2]);
    temp.set(0, cube.pos[126]);
    temp.set(1, cube.pos[127]);
    temp.set(2, cube.pos[128]);
    cube.pos.set(126, cube.pos[114]);
    cube.pos.set(127, cube.pos[115]);
    cube.pos.set(128, cube.pos[116]);
    cube.pos.set(114, temp[0]);
    cube.pos.set(115, temp[1]);
    cube.pos.set(116, temp[2]);

    temp.set(0, cube.pos[15]);
    temp.set(1, cube.pos[16]);
    temp.set(2, cube.pos[17]);
    cube.pos.set(15, cube.pos[51]);
    cube.pos.set(16, cube.pos[52]);
    cube.pos.set(17, cube.pos[53]);
    cube.pos.set(51, temp[0]);
    cube.pos.set(52, temp[1]);
    cube.pos.set(53, temp[2]);
    temp.set(0, cube.pos[129]);
    temp.set(1, cube.pos[130]);
    temp.set(2, cube.pos[131]);
    cube.pos.set(129, cube.pos[117]);
    cube.pos.set(130, cube.pos[118]);
    cube.pos.set(131, cube.pos[119]);
    cube.pos.set(117, temp[0]);
    cube.pos.set(118, temp[1]);
    cube.pos.set(119, temp[2]);

    temp.set(0, cube.pos[18]);
    temp.set(1, cube.pos[19]);
    temp.set(2, cube.pos[20]);
    cube.pos.set(18, cube.pos[54]);
    cube.pos.set(19, cube.pos[55]);
    cube.pos.set(20, cube.pos[56]);
    cube.pos.set(54, temp[0]);
    cube.pos.set(55, temp[1]);
    cube.pos.set(56, temp[2]);
    temp.set(0, cube.pos[132]);
    temp.set(1, cube.pos[133]);
    temp.set(2, cube.pos[134]);
    cube.pos.set(132, cube.pos[96]);
    cube.pos.set(133, cube.pos[97]);
    cube.pos.set(134, cube.pos[98]);
    cube.pos.set(96, temp[0]);
    cube.pos.set(97, temp[1]);
    cube.pos.set(98, temp[2]);

    cube.trail.push_back(8);
    return cube;
}

Cube L (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[138]);
    temp.set(1, cube.pos[139]);
    temp.set(2, cube.pos[140]);
    cube.pos.set(138, cube.pos[132]);
    cube.pos.set(139, cube.pos[133]);
    cube.pos.set(140, cube.pos[134]);
    cube.pos.set(132, cube.pos[126]);
    cube.pos.set(133, cube.pos[127]);
    cube.pos.set(134, cube.pos[128]);
    cube.pos.set(126, cube.pos[120]);
    cube.pos.set(127, cube.pos[121]);
    cube.pos.set(128, cube.pos[122]);
    cube.pos.set(120, temp[0]);
    cube.pos.set(121, temp[1]);
    cube.pos.set(122, temp[2]);

    temp.set(0, cube.pos[141]);
    temp.set(1, cube.pos[142]);
    temp.set(2, cube.pos[143]);
    cube.pos.set(141, cube.pos[135]);
    cube.pos.set(142, cube.pos[136]);
    cube.pos.set(143, cube.pos[137]);
    cube.pos.set(135, cube.pos[129]);
    cube.pos.set(136, cube.pos[130]);
    cube.pos.set(137, cube.pos[131]);
    cube.pos.set(129, cube.pos[123]);
    cube.pos.set(130, cube.pos[124]);
    cube.pos.set(131, cube.pos[125]);
    cube.pos.set(123, temp[0]);
    cube.pos.set(124, temp[1]);
    cube.pos.set(125, temp[2]);

    temp.set(0, cube.pos[18]);
    temp.set(1, cube.pos[19]);
    temp.set(2, cube.pos[20]);
    cube.pos.set(18, cube.pos[90]);
    cube.pos.set(19, cube.pos[91]);
    cube.pos.set(20, cube.pos[92]);
    cube.pos.set(90, cube.pos[66]);
    cube.pos.set(91, cube.pos[67]);
    cube.pos.set(92, cube.pos[68]);
    cube.pos.set(66, cube.pos[42]);
    cube.pos.set(67, cube.pos[43]);
    cube.pos.set(68, cube.pos[44]);
    cube.pos.set(42, temp[0]);
    cube.pos.set(43, temp[1]);
    cube.pos.set(44, temp[2]);

    temp.set(0, cube.pos[21]);
    temp.set(1, cube.pos[22]);
    temp.set(2, cube.pos[23]);
    cube.pos.set(21, cube.pos[93]);
    cube.pos.set(22, cube.pos[94]);
    cube.pos.set(23, cube.pos[95]);
    cube.pos.set(93, cube.pos[69]);
    cube.pos.set(94, cube.pos[70]);
    cube.pos.set(95, cube.pos[71]);
    cube.pos.set(69, cube.pos[45]);
    cube.pos.set(70, cube.pos[46]);
    cube.pos.set(71, cube.pos[47]);
    cube.pos.set(45, temp[0]);
    cube.pos.set(46, temp[1]);
    cube.pos.set(47, temp[2]);

    temp.set(0, cube.pos[0]);
    temp.set(1, cube.pos[1]);
    temp.set(2, cube.pos[2]);
    cube.pos.set(0, cube.pos[72]);
    cube.pos.set(1, cube.pos[73]);
    cube.pos.set(2, cube.pos[74]);
    cube.pos.set(72, cube.pos[48]);
    cube.pos.set(73, cube.pos[49]);
    cube.pos.set(74, cube.pos[50]);
    cube.pos.set(48, cube.pos[24]);
    cube.pos.set(49, cube.pos[25]);
    cube.pos.set(50, cube.pos[26]);
    cube.pos.set(24, temp[0]);
    cube.pos.set(25, temp[1]);
    cube.pos.set(26, temp[2]);

    cube.trail.push_back(9);
    return cube;
}

Cube Li (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[120]);
    temp.set(1, cube.pos[121]);
    temp.set(2, cube.pos[122]);
    cube.pos.set(120, cube.pos[126]);
    cube.pos.set(121, cube.pos[127]);
    cube.pos.set(122, cube.pos[128]);
    cube.pos.set(126, cube.pos[132]);
    cube.pos.set(127, cube.pos[133]);
    cube.pos.set(128, cube.pos[134]);
    cube.pos.set(132, cube.pos[138]);
    cube.pos.set(133, cube.pos[139]);
    cube.pos.set(134, cube.pos[140]);
    cube.pos.set(138, temp[0]);
    cube.pos.set(139, temp[1]);
    cube.pos.set(140, temp[2]);

    temp.set(0, cube.pos[123]);
    temp.set(1, cube.pos[124]);
    temp.set(2, cube.pos[125]);
    cube.pos.set(123, cube.pos[129]);
    cube.pos.set(124, cube.pos[130]);
    cube.pos.set(125, cube.pos[131]);
    cube.pos.set(129, cube.pos[135]);
    cube.pos.set(130, cube.pos[136]);
    cube.pos.set(131, cube.pos[137]);
    cube.pos.set(135, cube.pos[141]);
    cube.pos.set(136, cube.pos[142]);
    cube.pos.set(137, cube.pos[143]);
    cube.pos.set(141, temp[0]);
    cube.pos.set(142, temp[1]);
    cube.pos.set(143, temp[2]);

    temp.set(0, cube.pos[42]);
    temp.set(1, cube.pos[43]);
    temp.set(2, cube.pos[44]);
    cube.pos.set(42, cube.pos[66]);
    cube.pos.set(43, cube.pos[67]);
    cube.pos.set(44, cube.pos[68]);
    cube.pos.set(66, cube.pos[90]);
    cube.pos.set(67, cube.pos[91]);
    cube.pos.set(68, cube.pos[92]);
    cube.pos.set(90, cube.pos[18]);
    cube.pos.set(91, cube.pos[19]);
    cube.pos.set(92, cube.pos[20]);
    cube.pos.set(18, temp[0]);
    cube.pos.set(19, temp[1]);
    cube.pos.set(20, temp[2]);

    temp.set(0, cube.pos[45]);
    temp.set(1, cube.pos[46]);
    temp.set(2, cube.pos[47]);
    cube.pos.set(45, cube.pos[69]);
    cube.pos.set(46, cube.pos[70]);
    cube.pos.set(47, cube.pos[71]);
    cube.pos.set(69, cube.pos[93]);
    cube.pos.set(70, cube.pos[94]);
    cube.pos.set(71, cube.pos[95]);
    cube.pos.set(93, cube.pos[21]);
    cube.pos.set(94, cube.pos[22]);
    cube.pos.set(95, cube.pos[23]);
    cube.pos.set(21, temp[0]);
    cube.pos.set(22, temp[1]);
    cube.pos.set(23, temp[2]);

    temp.set(0, cube.pos[24]);
    temp.set(1, cube.pos[25]);
    temp.set(2, cube.pos[26]);
    cube.pos.set(24, cube.pos[48]);
    cube.pos.set(25, cube.pos[49]);
    cube.pos.set(26, cube.pos[50]);
    cube.pos.set(48, cube.pos[72]);
    cube.pos.set(49, cube.pos[73]);
    cube.pos.set(50, cube.pos[74]);
    cube.pos.set(72, cube.pos[0]);
    cube.pos.set(73, cube.pos[1]);
    cube.pos.set(74, cube.pos[2]);
    cube.pos.set(0, temp[0]);
    cube.pos.set(1, temp[1]);
    cube.pos.set(2, temp[2]);

    cube.trail.push_back(10);
    return cube;
}

Cube L2 (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[120]);
    temp.set(1, cube.pos[121]);
    temp.set(2, cube.pos[122]);
    cube.pos.set(120, cube.pos[132]);
    cube.pos.set(121, cube.pos[133]);
    cube.pos.set(122, cube.pos[134]);
    cube.pos.set(132, temp[0]);
    cube.pos.set(133, temp[1]);
    cube.pos.set(134, temp[2]);
    temp.set(0, cube.pos[126]);
    temp.set(1, cube.pos[127]);
    temp.set(2, cube.pos[128]);
    cube.pos.set(126, cube.pos[138]);
    cube.pos.set(127, cube.pos[139]);
    cube.pos.set(128, cube.pos[140]);
    cube.pos.set(138, temp[0]);
    cube.pos.set(139, temp[1]);
    cube.pos.set(140, temp[2]);

    temp.set(0, cube.pos[123]);
    temp.set(1, cube.pos[124]);
    temp.set(2, cube.pos[125]);
    cube.pos.set(123, cube.pos[135]);
    cube.pos.set(124, cube.pos[136]);
    cube.pos.set(125, cube.pos[137]);
    cube.pos.set(135, temp[0]);
    cube.pos.set(136, temp[1]);
    cube.pos.set(137, temp[2]);
    temp.set(0, cube.pos[129]);
    temp.set(1, cube.pos[130]);
    temp.set(2, cube.pos[131]);
    cube.pos.set(129, cube.pos[141]);
    cube.pos.set(130, cube.pos[142]);
    cube.pos.set(131, cube.pos[143]);
    cube.pos.set(141, temp[0]);
    cube.pos.set(142, temp[1]);
    cube.pos.set(143, temp[2]);

    temp.set(0, cube.pos[18]);
    temp.set(1, cube.pos[19]);
    temp.set(2, cube.pos[20]);
    cube.pos.set(18, cube.pos[66]);
    cube.pos.set(19, cube.pos[67]);
    cube.pos.set(20, cube.pos[68]);
    cube.pos.set(66, temp[0]);
    cube.pos.set(67, temp[1]);
    cube.pos.set(68, temp[2]);
    temp.set(0, cube.pos[90]);
    temp.set(1, cube.pos[91]);
    temp.set(2, cube.pos[92]);
    cube.pos.set(90, cube.pos[42]);
    cube.pos.set(91, cube.pos[43]);
    cube.pos.set(92, cube.pos[44]);
    cube.pos.set(42, temp[0]);
    cube.pos.set(43, temp[1]);
    cube.pos.set(44, temp[2]);

    temp.set(0, cube.pos[21]);
    temp.set(1, cube.pos[22]);
    temp.set(2, cube.pos[23]);
    cube.pos.set(21, cube.pos[69]);
    cube.pos.set(22, cube.pos[70]);
    cube.pos.set(23, cube.pos[71]);
    cube.pos.set(69, temp[0]);
    cube.pos.set(70, temp[1]);
    cube.pos.set(71, temp[2]);
    temp.set(0, cube.pos[93]);
    temp.set(1, cube.pos[94]);
    temp.set(2, cube.pos[95]);
    cube.pos.set(93, cube.pos[45]);
    cube.pos.set(94, cube.pos[46]);
    cube.pos.set(95, cube.pos[47]);
    cube.pos.set(45, temp[0]);
    cube.pos.set(46, temp[1]);
    cube.pos.set(47, temp[2]);

    temp.set(0, cube.pos[0]);
    temp.set(1, cube.pos[1]);
    temp.set(2, cube.pos[2]);
    cube.pos.set(0, cube.pos[48]);
    cube.pos.set(1, cube.pos[49]);
    cube.pos.set(2, cube.pos[50]);
    cube.pos.set(48, temp[0]);
    cube.pos.set(49, temp[1]);
    cube.pos.set(50, temp[2]);
    temp.set(0, cube.pos[72]);
    temp.set(1, cube.pos[73]);
    temp.set(2, cube.pos[74]);
    cube.pos.set(72, cube.pos[24]);
    cube.pos.set(73, cube.pos[25]);
    cube.pos.set(74, cube.pos[26]);
    cube.pos.set(24, temp[0]);
    cube.pos.set(25, temp[1]);
    cube.pos.set(26, temp[2]);

    cube.trail.push_back(11);
    return cube;
}

Cube D (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[66]);
    temp.set(1, cube.pos[67]);
    temp.set(2, cube.pos[68]);
    cube.pos.set(66, cube.pos[60]);
    cube.pos.set(67, cube.pos[61]);
    cube.pos.set(68, cube.pos[62]);
    cube.pos.set(60, cube.pos[54]);
    cube.pos.set(61, cube.pos[55]);
    cube.pos.set(62, cube.pos[56]);
    cube.pos.set(54, cube.pos[48]);
    cube.pos.set(55, cube.pos[49]);
    cube.pos.set(56, cube.pos[50]);
    cube.pos.set(48, temp[0]);
    cube.pos.set(49, temp[1]);
    cube.pos.set(50, temp[2]);

    temp.set(0, cube.pos[69]);
    temp.set(1, cube.pos[70]);
    temp.set(2, cube.pos[71]);
    cube.pos.set(69, cube.pos[63]);
    cube.pos.set(70, cube.pos[64]);
    cube.pos.set(71, cube.pos[65]);
    cube.pos.set(63, cube.pos[57]);
    cube.pos.set(64, cube.pos[58]);
    cube.pos.set(65, cube.pos[59]);
    cube.pos.set(57, cube.pos[51]);
    cube.pos.set(58, cube.pos[52]);
    cube.pos.set(59, cube.pos[53]);
    cube.pos.set(51, temp[0]);
    cube.pos.set(52, temp[1]);
    cube.pos.set(53, temp[2]);

    temp.set(0, cube.pos[108]);
    temp.set(1, cube.pos[109]);
    temp.set(2, cube.pos[110]);
    cube.pos.set(108, cube.pos[36]);
    cube.pos.set(109, cube.pos[37]);
    cube.pos.set(110, cube.pos[38]);
    cube.pos.set(36, cube.pos[132]);
    cube.pos.set(37, cube.pos[133]);
    cube.pos.set(38, cube.pos[134]);
    cube.pos.set(132, cube.pos[72]);
    cube.pos.set(133, cube.pos[73]);
    cube.pos.set(134, cube.pos[74]);
    cube.pos.set(72, temp[0]);
    cube.pos.set(73, temp[1]);
    cube.pos.set(74, temp[2]);

    temp.set(0, cube.pos[111]);
    temp.set(1, cube.pos[112]);
    temp.set(2, cube.pos[113]);
    cube.pos.set(111, cube.pos[39]);
    cube.pos.set(112, cube.pos[40]);
    cube.pos.set(113, cube.pos[41]);
    cube.pos.set(39, cube.pos[135]);
    cube.pos.set(40, cube.pos[136]);
    cube.pos.set(41, cube.pos[137]);
    cube.pos.set(135, cube.pos[75]);
    cube.pos.set(136, cube.pos[76]);
    cube.pos.set(137, cube.pos[77]);
    cube.pos.set(75, temp[0]);
    cube.pos.set(76, temp[1]);
    cube.pos.set(77, temp[2]);

    temp.set(0, cube.pos[114]);
    temp.set(1, cube.pos[115]);
    temp.set(2, cube.pos[116]);
    cube.pos.set(114, cube.pos[42]);
    cube.pos.set(115, cube.pos[43]);
    cube.pos.set(116, cube.pos[44]);
    cube.pos.set(42, cube.pos[138]);
    cube.pos.set(43, cube.pos[139]);
    cube.pos.set(44, cube.pos[140]);
    cube.pos.set(138, cube.pos[78]);
    cube.pos.set(139, cube.pos[79]);
    cube.pos.set(140, cube.pos[80]);
    cube.pos.set(78, temp[0]);
    cube.pos.set(79, temp[1]);
    cube.pos.set(80, temp[2]);

    cube.trail.push_back(12);
    return cube;
}

Cube Di (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[48]);
    temp.set(1, cube.pos[49]);
    temp.set(2, cube.pos[50]);
    cube.pos.set(48, cube.pos[54]);
    cube.pos.set(49, cube.pos[55]);
    cube.pos.set(50, cube.pos[56]);
    cube.pos.set(54, cube.pos[60]);
    cube.pos.set(55, cube.pos[61]);
    cube.pos.set(56, cube.pos[62]);
    cube.pos.set(60, cube.pos[66]);
    cube.pos.set(61, cube.pos[67]);
    cube.pos.set(62, cube.pos[68]);
    cube.pos.set(66, temp[0]);
    cube.pos.set(67, temp[1]);
    cube.pos.set(68, temp[2]);

    temp.set(0, cube.pos[51]);
    temp.set(1, cube.pos[52]);
    temp.set(2, cube.pos[53]);
    cube.pos.set(51, cube.pos[57]);
    cube.pos.set(52, cube.pos[58]);
    cube.pos.set(53, cube.pos[59]);
    cube.pos.set(57, cube.pos[63]);
    cube.pos.set(58, cube.pos[64]);
    cube.pos.set(59, cube.pos[65]);
    cube.pos.set(63, cube.pos[69]);
    cube.pos.set(64, cube.pos[70]);
    cube.pos.set(65, cube.pos[71]);
    cube.pos.set(69, temp[0]);
    cube.pos.set(70, temp[1]);
    cube.pos.set(71, temp[2]);

    temp.set(0, cube.pos[72]);
    temp.set(1, cube.pos[73]);
    temp.set(2, cube.pos[74]);
    cube.pos.set(72, cube.pos[132]);
    cube.pos.set(73, cube.pos[133]);
    cube.pos.set(74, cube.pos[134]);
    cube.pos.set(132, cube.pos[36]);
    cube.pos.set(133, cube.pos[37]);
    cube.pos.set(134, cube.pos[38]);
    cube.pos.set(36, cube.pos[108]);
    cube.pos.set(37, cube.pos[109]);
    cube.pos.set(38, cube.pos[110]);
    cube.pos.set(108, temp[0]);
    cube.pos.set(109, temp[1]);
    cube.pos.set(110, temp[2]);

    temp.set(0, cube.pos[75]);
    temp.set(1, cube.pos[76]);
    temp.set(2, cube.pos[77]);
    cube.pos.set(75, cube.pos[135]);
    cube.pos.set(76, cube.pos[136]);
    cube.pos.set(77, cube.pos[137]);
    cube.pos.set(135, cube.pos[39]);
    cube.pos.set(136, cube.pos[40]);
    cube.pos.set(137, cube.pos[41]);
    cube.pos.set(39, cube.pos[111]);
    cube.pos.set(40, cube.pos[112]);
    cube.pos.set(41, cube.pos[113]);
    cube.pos.set(111, temp[0]);
    cube.pos.set(112, temp[1]);
    cube.pos.set(113, temp[2]);

    temp.set(0, cube.pos[78]);
    temp.set(1, cube.pos[79]);
    temp.set(2, cube.pos[80]);
    cube.pos.set(78, cube.pos[138]);
    cube.pos.set(79, cube.pos[139]);
    cube.pos.set(80, cube.pos[140]);
    cube.pos.set(138, cube.pos[42]);
    cube.pos.set(139, cube.pos[43]);
    cube.pos.set(140, cube.pos[44]);
    cube.pos.set(42, cube.pos[114]);
    cube.pos.set(43, cube.pos[115]);
    cube.pos.set(44, cube.pos[116]);
    cube.pos.set(114, temp[0]);
    cube.pos.set(115, temp[1]);
    cube.pos.set(116, temp[2]);

    cube.trail.push_back(13);
    return cube;
}

Cube D2 (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[48]);
    temp.set(1, cube.pos[49]);
    temp.set(2, cube.pos[50]);
    cube.pos.set(48, cube.pos[60]);
    cube.pos.set(49, cube.pos[61]);
    cube.pos.set(50, cube.pos[62]);
    cube.pos.set(60, temp[0]);
    cube.pos.set(61, temp[1]);
    cube.pos.set(62, temp[2]);
    temp.set(0, cube.pos[54]);
    temp.set(1, cube.pos[55]);
    temp.set(2, cube.pos[56]);
    cube.pos.set(54, cube.pos[66]);
    cube.pos.set(55, cube.pos[67]);
    cube.pos.set(56, cube.pos[68]);
    cube.pos.set(66, temp[0]);
    cube.pos.set(67, temp[1]);
    cube.pos.set(68, temp[2]);

    temp.set(0, cube.pos[51]);
    temp.set(1, cube.pos[52]);
    temp.set(2, cube.pos[53]);
    cube.pos.set(51, cube.pos[63]);
    cube.pos.set(52, cube.pos[64]);
    cube.pos.set(53, cube.pos[65]);
    cube.pos.set(63, temp[0]);
    cube.pos.set(64, temp[1]);
    cube.pos.set(65, temp[2]);
    temp.set(0, cube.pos[57]);
    temp.set(1, cube.pos[58]);
    temp.set(2, cube.pos[59]);
    cube.pos.set(57, cube.pos[69]);
    cube.pos.set(58, cube.pos[70]);
    cube.pos.set(59, cube.pos[71]);
    cube.pos.set(69, temp[0]);
    cube.pos.set(70, temp[1]);
    cube.pos.set(71, temp[2]);

    temp.set(0, cube.pos[108]);
    temp.set(1, cube.pos[109]);
    temp.set(2, cube.pos[110]);
    cube.pos.set(108, cube.pos[132]);
    cube.pos.set(109, cube.pos[133]);
    cube.pos.set(110, cube.pos[134]);
    cube.pos.set(132, temp[0]);
    cube.pos.set(133, temp[1]);
    cube.pos.set(134, temp[2]);
    temp.set(0, cube.pos[36]);
    temp.set(1, cube.pos[37]);
    temp.set(2, cube.pos[38]);
    cube.pos.set(36, cube.pos[72]);
    cube.pos.set(37, cube.pos[73]);
    cube.pos.set(38, cube.pos[74]);
    cube.pos.set(72, temp[0]);
    cube.pos.set(73, temp[1]);
    cube.pos.set(74, temp[2]);

    temp.set(0, cube.pos[111]);
    temp.set(1, cube.pos[112]);
    temp.set(2, cube.pos[113]);
    cube.pos.set(111, cube.pos[135]);
    cube.pos.set(112, cube.pos[136]);
    cube.pos.set(113, cube.pos[137]);
    cube.pos.set(135, temp[0]);
    cube.pos.set(136, temp[1]);
    cube.pos.set(137, temp[2]);
    temp.set(0, cube.pos[39]);
    temp.set(1, cube.pos[40]);
    temp.set(2, cube.pos[41]);
    cube.pos.set(39, cube.pos[75]);
    cube.pos.set(40, cube.pos[76]);
    cube.pos.set(41, cube.pos[77]);
    cube.pos.set(75, temp[0]);
    cube.pos.set(76, temp[1]);
    cube.pos.set(77, temp[2]);

    temp.set(0, cube.pos[114]);
    temp.set(1, cube.pos[115]);
    temp.set(2, cube.pos[116]);
    cube.pos.set(114, cube.pos[138]);
    cube.pos.set(115, cube.pos[139]);
    cube.pos.set(116, cube.pos[140]);
    cube.pos.set(138, temp[0]);
    cube.pos.set(139, temp[1]);
    cube.pos.set(140, temp[2]);
    temp.set(0, cube.pos[42]);
    temp.set(1, cube.pos[43]);
    temp.set(2, cube.pos[44]);
    cube.pos.set(42, cube.pos[78]);
    cube.pos.set(43, cube.pos[79]);
    cube.pos.set(44, cube.pos[80]);
    cube.pos.set(78, temp[0]);
    cube.pos.set(79, temp[1]);
    cube.pos.set(80, temp[2]);

    cube.trail.push_back(14);
    return cube;
}

Cube B (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[90]);
    temp.set(1, cube.pos[91]);
    temp.set(2, cube.pos[92]);
    cube.pos.set(90, cube.pos[84]);
    cube.pos.set(91, cube.pos[85]);
    cube.pos.set(92, cube.pos[86]);
    cube.pos.set(84, cube.pos[78]);
    cube.pos.set(85, cube.pos[79]);
    cube.pos.set(86, cube.pos[80]);
    cube.pos.set(78, cube.pos[72]);
    cube.pos.set(79, cube.pos[73]);
    cube.pos.set(80, cube.pos[74]);
    cube.pos.set(72, temp[0]);
    cube.pos.set(73, temp[1]);
    cube.pos.set(74, temp[2]);

    temp.set(0, cube.pos[93]);
    temp.set(1, cube.pos[94]);
    temp.set(2, cube.pos[95]);
    cube.pos.set(93, cube.pos[87]);
    cube.pos.set(94, cube.pos[88]);
    cube.pos.set(95, cube.pos[89]);
    cube.pos.set(87, cube.pos[81]);
    cube.pos.set(88, cube.pos[82]);
    cube.pos.set(89, cube.pos[83]);
    cube.pos.set(81, cube.pos[75]);
    cube.pos.set(82, cube.pos[76]);
    cube.pos.set(83, cube.pos[77]);
    cube.pos.set(75, temp[0]);
    cube.pos.set(76, temp[1]);
    cube.pos.set(77, temp[2]);

    temp.set(0, cube.pos[0]);
    temp.set(1, cube.pos[1]);
    temp.set(2, cube.pos[2]);
    cube.pos.set(0, cube.pos[102]);
    cube.pos.set(1, cube.pos[103]);
    cube.pos.set(2, cube.pos[104]);
    cube.pos.set(102, cube.pos[60]);
    cube.pos.set(103, cube.pos[61]);
    cube.pos.set(104, cube.pos[62]);
    cube.pos.set(60, cube.pos[138]);
    cube.pos.set(61, cube.pos[139]);
    cube.pos.set(62, cube.pos[140]);
    cube.pos.set(138, temp[0]);
    cube.pos.set(139, temp[1]);
    cube.pos.set(140, temp[2]);

    temp.set(0, cube.pos[3]);
    temp.set(1, cube.pos[4]);
    temp.set(2, cube.pos[5]);
    cube.pos.set(3, cube.pos[105]);
    cube.pos.set(4, cube.pos[106]);
    cube.pos.set(5, cube.pos[107]);
    cube.pos.set(105, cube.pos[63]);
    cube.pos.set(106, cube.pos[64]);
    cube.pos.set(107, cube.pos[65]);
    cube.pos.set(63, cube.pos[141]);
    cube.pos.set(64, cube.pos[142]);
    cube.pos.set(65, cube.pos[143]);
    cube.pos.set(141, temp[0]);
    cube.pos.set(142, temp[1]);
    cube.pos.set(143, temp[2]);

    temp.set(0, cube.pos[6]);
    temp.set(1, cube.pos[7]);
    temp.set(2, cube.pos[8]);
    cube.pos.set(6, cube.pos[108]);
    cube.pos.set(7, cube.pos[109]);
    cube.pos.set(8, cube.pos[110]);
    cube.pos.set(108, cube.pos[66]);
    cube.pos.set(109, cube.pos[67]);
    cube.pos.set(110, cube.pos[68]);
    cube.pos.set(66, cube.pos[120]);
    cube.pos.set(67, cube.pos[121]);
    cube.pos.set(68, cube.pos[122]);
    cube.pos.set(120, temp[0]);
    cube.pos.set(121, temp[1]);
    cube.pos.set(122, temp[2]);

    cube.trail.push_back(15);
    return cube;
}

Cube Bi (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[72]);
    temp.set(1, cube.pos[73]);
    temp.set(2, cube.pos[74]);
    cube.pos.set(72, cube.pos[78]);
    cube.pos.set(73, cube.pos[79]);
    cube.pos.set(74, cube.pos[80]);
    cube.pos.set(78, cube.pos[84]);
    cube.pos.set(79, cube.pos[85]);
    cube.pos.set(80, cube.pos[86]);
    cube.pos.set(84, cube.pos[90]);
    cube.pos.set(85, cube.pos[91]);
    cube.pos.set(86, cube.pos[92]);
    cube.pos.set(90, temp[0]);
    cube.pos.set(91, temp[1]);
    cube.pos.set(92, temp[2]);

    temp.set(0, cube.pos[75]);
    temp.set(1, cube.pos[76]);
    temp.set(2, cube.pos[77]);
    cube.pos.set(75, cube.pos[81]);
    cube.pos.set(76, cube.pos[82]);
    cube.pos.set(77, cube.pos[83]);
    cube.pos.set(81, cube.pos[87]);
    cube.pos.set(82, cube.pos[88]);
    cube.pos.set(83, cube.pos[89]);
    cube.pos.set(87, cube.pos[93]);
    cube.pos.set(88, cube.pos[94]);
    cube.pos.set(89, cube.pos[95]);
    cube.pos.set(93, temp[0]);
    cube.pos.set(94, temp[1]);
    cube.pos.set(95, temp[2]);

    temp.set(0, cube.pos[138]);
    temp.set(1, cube.pos[139]);
    temp.set(2, cube.pos[140]);
    cube.pos.set(138, cube.pos[60]);
    cube.pos.set(139, cube.pos[61]);
    cube.pos.set(140, cube.pos[62]);
    cube.pos.set(60, cube.pos[102]);
    cube.pos.set(61, cube.pos[103]);
    cube.pos.set(62, cube.pos[104]);
    cube.pos.set(102, cube.pos[0]);
    cube.pos.set(103, cube.pos[1]);
    cube.pos.set(104, cube.pos[2]);
    cube.pos.set(0, temp[0]);
    cube.pos.set(1, temp[1]);
    cube.pos.set(2, temp[2]);

    temp.set(0, cube.pos[141]);
    temp.set(1, cube.pos[142]);
    temp.set(2, cube.pos[143]);
    cube.pos.set(141, cube.pos[63]);
    cube.pos.set(142, cube.pos[64]);
    cube.pos.set(143, cube.pos[65]);
    cube.pos.set(63, cube.pos[105]);
    cube.pos.set(64, cube.pos[106]);
    cube.pos.set(65, cube.pos[107]);
    cube.pos.set(105, cube.pos[3]);
    cube.pos.set(106, cube.pos[4]);
    cube.pos.set(107, cube.pos[5]);
    cube.pos.set(3, temp[0]);
    cube.pos.set(4, temp[1]);
    cube.pos.set(5, temp[2]);

    temp.set(0, cube.pos[120]);
    temp.set(1, cube.pos[121]);
    temp.set(2, cube.pos[122]);
    cube.pos.set(120, cube.pos[66]);
    cube.pos.set(121, cube.pos[67]);
    cube.pos.set(122, cube.pos[68]);
    cube.pos.set(66, cube.pos[108]);
    cube.pos.set(67, cube.pos[109]);
    cube.pos.set(68, cube.pos[110]);
    cube.pos.set(108, cube.pos[6]);
    cube.pos.set(109, cube.pos[7]);
    cube.pos.set(110, cube.pos[8]);
    cube.pos.set(6, temp[0]);
    cube.pos.set(7, temp[1]);
    cube.pos.set(8, temp[2]);

    cube.trail.push_back(16);
    return cube;
}

Cube B2 (Cube cube){
    bitset<3> temp;
    temp.set(0, cube.pos[72]);
    temp.set(1, cube.pos[73]);
    temp.set(2, cube.pos[74]);
    cube.pos.set(72, cube.pos[84]);
    cube.pos.set(73, cube.pos[85]);
    cube.pos.set(74, cube.pos[86]);
    cube.pos.set(84, temp[0]);
    cube.pos.set(85, temp[1]);
    cube.pos.set(86, temp[2]);
    temp.set(0, cube.pos[78]);
    temp.set(1, cube.pos[79]);
    temp.set(2, cube.pos[80]);
    cube.pos.set(78, cube.pos[90]);
    cube.pos.set(79, cube.pos[91]);
    cube.pos.set(80, cube.pos[92]);
    cube.pos.set(90, temp[0]);
    cube.pos.set(91, temp[1]);
    cube.pos.set(92, temp[2]);

    temp.set(0, cube.pos[75]);
    temp.set(1, cube.pos[76]);
    temp.set(2, cube.pos[77]);
    cube.pos.set(75, cube.pos[87]);
    cube.pos.set(76, cube.pos[88]);
    cube.pos.set(77, cube.pos[89]);
    cube.pos.set(87, temp[0]);
    cube.pos.set(88, temp[1]);
    cube.pos.set(89, temp[2]);
    temp.set(0, cube.pos[81]);
    temp.set(1, cube.pos[82]);
    temp.set(2, cube.pos[83]);
    cube.pos.set(81, cube.pos[93]);
    cube.pos.set(82, cube.pos[94]);
    cube.pos.set(83, cube.pos[95]);
    cube.pos.set(93, temp[0]);
    cube.pos.set(94, temp[1]);
    cube.pos.set(95, temp[2]);

    temp.set(0, cube.pos[0]);
    temp.set(1, cube.pos[1]);
    temp.set(2, cube.pos[2]);
    cube.pos.set(0, cube.pos[60]);
    cube.pos.set(1, cube.pos[61]);
    cube.pos.set(2, cube.pos[62]);
    cube.pos.set(60, temp[0]);
    cube.pos.set(61, temp[1]);
    cube.pos.set(62, temp[2]);
    temp.set(0, cube.pos[102]);
    temp.set(1, cube.pos[103]);
    temp.set(2, cube.pos[104]);
    cube.pos.set(102, cube.pos[138]);
    cube.pos.set(103, cube.pos[139]);
    cube.pos.set(104, cube.pos[140]);
    cube.pos.set(138, temp[0]);
    cube.pos.set(139, temp[1]);
    cube.pos.set(140, temp[2]);

    temp.set(0, cube.pos[3]);
    temp.set(1, cube.pos[4]);
    temp.set(2, cube.pos[5]);
    cube.pos.set(3, cube.pos[63]);
    cube.pos.set(4, cube.pos[64]);
    cube.pos.set(5, cube.pos[65]);
    cube.pos.set(63, temp[0]);
    cube.pos.set(64, temp[1]);
    cube.pos.set(65, temp[2]);
    temp.set(0, cube.pos[105]);
    temp.set(1, cube.pos[106]);
    temp.set(2, cube.pos[107]);
    cube.pos.set(105, cube.pos[141]);
    cube.pos.set(106, cube.pos[142]);
    cube.pos.set(107, cube.pos[143]);
    cube.pos.set(141, temp[0]);
    cube.pos.set(142, temp[1]);
    cube.pos.set(143, temp[2]);

    temp.set(0, cube.pos[6]);
    temp.set(1, cube.pos[7]);
    temp.set(2, cube.pos[8]);
    cube.pos.set(6, cube.pos[66]);
    cube.pos.set(7, cube.pos[67]);
    cube.pos.set(8, cube.pos[68]);
    cube.pos.set(66, temp[0]);
    cube.pos.set(67, temp[1]);
    cube.pos.set(68, temp[2]);
    temp.set(0, cube.pos[108]);
    temp.set(1, cube.pos[109]);
    temp.set(2, cube.pos[110]);
    cube.pos.set(108, cube.pos[120]);
    cube.pos.set(109, cube.pos[121]);
    cube.pos.set(110, cube.pos[122]);
    cube.pos.set(120, temp[0]);
    cube.pos.set(121, temp[1]);
    cube.pos.set(122, temp[2]);

    cube.trail.push_back(17);
    return cube;
}


