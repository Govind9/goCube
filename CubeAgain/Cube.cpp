#include "Cube.h"

using namespace std;

move_fn funcs[] = {
    R, Ri, R2, U, Ui, U2, F, Fi, F2,
    L, Li, L2, D, Di, D2, B, Bi, B2
};


Cube::Cube() {
    Cubie cubie;
    cubie.x = r;
    cubie.y = b;
    cubie.z = yy;
    pos[0] = cubie;

    cubie.x = n;
    cubie.y = b;
    cubie.z = yy;
    pos[1] = cubie;

    cubie.x = o;
    cubie.y = b;
    cubie.z = yy;
    pos[2] = cubie;

    cubie.x = o;
    cubie.y = n;
    cubie.z = yy;
    pos[3] = cubie;

    cubie.x = o;
    cubie.y = g;
    cubie.z = yy;
    pos[4] = cubie;

    cubie.x = n;
    cubie.y = g;
    cubie.z = yy;
    pos[5] = cubie;

    cubie.x = r;
    cubie.y = g;
    cubie.z = yy;
    pos[6] = cubie;

    cubie.x = r;
    cubie.y = n;
    cubie.z = yy;
    pos[7] = cubie;

    cubie.x = r;
    cubie.y = b;
    cubie.z = n;
    pos[8] = cubie;

    cubie.x = o;
    cubie.y = b;
    cubie.z = n;
    pos[9] = cubie;

    cubie.x = o;
    cubie.y = g;
    cubie.z = n;
    pos[10] = cubie;

    cubie.x = r;
    cubie.y = g;
    cubie.z = n;
    pos[11] = cubie;

    cubie.x = r;
    cubie.y = b;
    cubie.z = w;
    pos[12] = cubie;

    cubie.x = n;
    cubie.y = b;
    cubie.z = w;
    pos[13] = cubie;

    cubie.x = o;
    cubie.y = b;
    cubie.z = w;
    pos[14] = cubie;

    cubie.x = o;
    cubie.y = n;
    cubie.z = w;
    pos[15] = cubie;

    cubie.x = o;
    cubie.y = g;
    cubie.z = w;
    pos[16] = cubie;

    cubie.x = n;
    cubie.y = g;
    cubie.z = w;
    pos[17] = cubie;

    cubie.x = r;
    cubie.y = g;
    cubie.z = w;
    pos[18] = cubie;

    cubie.x = r;
    cubie.y = n;
    cubie.z = w;
    pos[19] = cubie;
}

string color(int c) {
    if (c == yy)
        return YELLOW;
    if (c == g)
        return GREEN;
    if (c == w)
        return WHITE;
    if (c == b)
        return BLUE;
    if (c == o)
        return ORANGE;
    if (c == r)
        return RED;
}

void Cube::paint() {
    string text = "";
    text += "      ";
    text += color(pos[0].z);
    text += color(pos[1].z);
    text += color(pos[2].z);
    text += "      \n";

    text += "      ";
    text += color(pos[7].z);
    text += color(yy);
    text += color(pos[3].z);
    text += "      \n";

    text += "      ";
    text += color(pos[6].z);
    text += color(pos[5].z);
    text += color(pos[4].z);
    text += "      \n";

    text += color(pos[0].x);
    text += color(pos[7].x);
    text += color(pos[6].x);
    text += color(pos[6].y);
    text += color(pos[5].y);
    text += color(pos[4].y);
    text += color(pos[4].x);
    text += color(pos[3].x);
    text += color(pos[2].x);
    text += "\n";

    text += color(pos[8].x);
    text += color(r);
    text += color(pos[11].x);
    text += color(pos[11].y);
    text += color(g);
    text += color(pos[10].y);
    text += color(pos[10].x);
    text += color(o);
    text += color(pos[9].x);
    text += "\n";

    text += color(pos[12].x);
    text += color(pos[19].x);
    text += color(pos[18].x);
    text += color(pos[18].y);
    text += color(pos[17].y);
    text += color(pos[16].y);
    text += color(pos[16].x);
    text += color(pos[15].x);
    text += color(pos[14].x);
    text += "\n";

    text += "      ";
    text += color(pos[18].z);
    text += color(pos[17].z);
    text += color(pos[16].z);
    text += "      \n";

    text += "      ";
    text += color(pos[19].z);
    text += color(w);
    text += color(pos[15].z);
    text += "      \n";

    text += "      ";
    text += color(pos[12].z);
    text += color(pos[13].z);
    text += color(pos[14].z);
    text += "      \n";

    text += "      ";
    text += color(pos[12].y);
    text += color(pos[13].y);
    text += color(pos[14].y);
    text += "      \n";

    text += "      ";
    text += color(pos[8].y);
    text += color(b);
    text += color(pos[9].y);
    text += "      \n";

    text += "      ";
    text += color(pos[0].y);
    text += color(pos[1].y);
    text += color(pos[2].y);
    text += "      \n";

    cout << text << END_COLOR;
}

void Cube::print(int index) {
    cout << "x: " << pos[index].x << " ";
    cout << "y: " << pos[index].y << " ";
    cout << "z: " << pos[index].z << endl;
}

void solve(Cube cube, check_fn cfn) {
    queue <Cube> Q;
    set <unsigned long long> corners, edges;
    int level = 0, new_level = 0;
    Cube n_cube, cur;
    unsigned long long code1, code2;

    cube.trail.clear();
    Q.push(cube);
    tie(code1, code2) = gen_code(cube);
    corners.insert(code1);
    edges.insert(code2);

    while (!Q.empty()) {
        cur = Q.front();
		Q.pop();
		new_level = cur.trail.size();
        if (new_level > level) {
            level = new_level;
            cout << "Entered level: " << level << "QSize: " << Q.size() << endl;
        }

        for (int i=0; i<18; i++) {
            n_cube = funcs[i](cur);
            if (cfn(n_cube)) {
                give_solution(cube, n_cube);
                return;
            }
            tie(code1, code2) = gen_code(n_cube);
            if (
                (corners.find(code1) == corners.end()) ||
                (edges.find(code2) == edges.end())
            ) {
                Q.push(n_cube);
                corners.insert(code1);
                edges.insert(code2);
            }
        }
    }
}

Cube solve2(Cube cube, gen_fn gfn, check_cd cfn) {
    queue <Cube> Q;
    set <unsigned long long> code_set;
    int level = 0, new_level = 0;
    Cube n_cube, cur;
    unsigned long long code;

    cube.trail.clear();
    Q.push(cube);
    code = gfn(cube);
    code_set.insert(code);

    while (!Q.empty()) {
        cur = Q.front();
		Q.pop();
		new_level = cur.trail.size();
        if (new_level > level) {
            level = new_level;
            cout << "Entered level: " << level << "QSize: " << Q.size() << endl;
        }

        for (int i=0; i<18; i++) {
            n_cube = funcs[i](cur);
            code = gfn(n_cube);
            if (cfn(code)) {
                give_solution(cube, n_cube);
                return n_cube;
            }
            if (code_set.find(code) == code_set.end()) {
                Q.push(n_cube);
                code_set.insert(code);
            }
        }
    }
}

void give_solution(Cube cube, Cube n_cube) {
    string moves[18] = {
        "R", "Ri", "R2", "U", "Ui", "U2",
        "F", "Fi", "F2", "L", "Li", "L2",
        "D", "Di", "D2", "B", "Bi", "B2"
    };
    cube.paint();
    cout << "To the above cube apply: ";
    for (int m : n_cube.trail) {
        cout << moves[m] << " ";
    }
    cout << "to obtain:" << endl;
    n_cube.paint();
}

bool is_cross(Cube cube) {
    return (
        cube.pos[13].z == w &&
        cube.pos[15].z == w &&
        cube.pos[17].z == w &&
        cube.pos[19].z == w &&
        cube.pos[13].y == b &&
        cube.pos[15].x == o &&
        cube.pos[17].y == g &&
        cube.pos[19].x == r
    );
}

bool is_cross_code(unsigned long long code) {
    return code == 20021085001341;
}

bool is_f2l_og (unsigned long long code) {
    return code == 20021255008341;
}

tuple<unsigned long long, unsigned long long> gen_code(Cube cube) {
    unsigned long long code[2] = {0, 0};
    int group[12];

    group[0] = cube.pos[0].z +
        cube.pos[2].z +
        cube.pos[4].z +
        cube.pos[6].z;
    group[1] = cube.pos[6].y +
        cube.pos[4].y +
        cube.pos[16].y +
        cube.pos[18].y;
    group[2] = cube.pos[12].z +
        cube.pos[14].z +
        cube.pos[16].z +
        cube.pos[18].z;
    group[3] = cube.pos[12].y +
        cube.pos[14].y +
        cube.pos[0].y +
        cube.pos[2].y;
    group[4] = cube.pos[16].x +
        cube.pos[14].x +
        cube.pos[4].x +
        cube.pos[2].x;
    group[5] = cube.pos[12].x +
        cube.pos[18].x +
        cube.pos[0].x +
        cube.pos[6].x;
    group[6] = cube.pos[1].z +
        cube.pos[3].z +
        cube.pos[5].z +
        cube.pos[7].z;
    group[7] = cube.pos[5].y +
        cube.pos[10].y +
        cube.pos[11].y +
        cube.pos[17].y;
    group[8] = cube.pos[13].z +
        cube.pos[15].z +
        cube.pos[17].z +
        cube.pos[19].z;
    group[9] = cube.pos[13].y +
        cube.pos[8].y +
        cube.pos[1].y +
        cube.pos[9].y;
    group[10] = cube.pos[3].x +
        cube.pos[9].x +
        cube.pos[10].x +
        cube.pos[15].x;
    group[11] = cube.pos[7].x +
        cube.pos[8].x +
        cube.pos[11].x +
        cube.pos[19].x;

    sort(group, group + 6);
    sort(group + 6, group + 12);

    for (int i=0; i<6; i++) {
        code[0] *= 1000;
        code[0] += group[i];
    }
    for (int i=6; i<12; i++) {
        code[1] *= 1000;
        code[1] += group[i];
    }

    return {code[0], code[1]};
}

unsigned long long gen_code_cross(Cube cube) {
    unsigned long long code = 0;
    int group[5];

    group[0] = cube.pos[13].z +
        cube.pos[15].z +
        cube.pos[17].z +
        cube.pos[19].z;
    group[1] = cube.pos[13].y;
    group[2] = cube.pos[15].x;
    group[3] = cube.pos[17].y;
    group[4] = cube.pos[19].x;

    for (int i=0; i<5; i++) {
        code *= 1000;
        code += group[i];
    }

    return code;
}

unsigned long long gen_f2l_og(Cube cube) {
    unsigned long long code = 0;
    int group[5];

    group[0] = cube.pos[13].z +
        cube.pos[15].z +
        cube.pos[17].z +
        cube.pos[19].z;
    group[1] = cube.pos[13].y;
    group[2] = cube.pos[15].x +
        cube.pos[10].x +
        cube.pos[16].x;
    group[3] = cube.pos[17].y +
        cube.pos[10].y +
        cube.pos[16].y +
        cube.pos[16].z;
    group[4] = cube.pos[19].x;

    for (int i=0; i<5; i++) {
        code *= 1000;
        code += group[i];
    }

    return code;
}

Cube apply (Cube cube, string seq) {
    int i = 0;
    string m = "";
    while (i < seq.length()) {
        if (seq[i] == ' ')
            continue;
        m = seq[i];
        i++;
        if (i < seq.length()) {
            if (seq[i] == 'i' || seq[i] == '\'') {
                m += 'i';
                i++;
            }
            else if (seq[i] == '2') {
                m += '2';
                i++;
            }
        }
        if (m == "R")  cube = R (cube);
        if (m == "Ri") cube = Ri(cube);
        if (m == "R2") cube = R2(cube);
        if (m == "U")  cube = U (cube);
        if (m == "Ui") cube = Ui(cube);
        if (m == "U2") cube = U2(cube);
        if (m == "F")  cube = F (cube);
        if (m == "Fi") cube = Fi(cube);
        if (m == "F2") cube = F2(cube);
        if (m == "L")  cube = L (cube);
        if (m == "Li") cube = Li(cube);
        if (m == "L2") cube = L2(cube);
        if (m == "D")  cube = D (cube);
        if (m == "Di") cube = Di(cube);
        if (m == "D2") cube = D2(cube);
        if (m == "B")  cube = B (cube);
        if (m == "Bi") cube = Bi(cube);
        if (m == "B2") cube = B2(cube);
    }
    return cube;
}

Cube apply_wg (Cube cube, string seq) {
    int i = 0;
    string m = "";
    while (i < seq.length()) {
        if (seq[i] == ' ')
            continue;
        m = seq[i];
        i++;
        if (i < seq.length()) {
            if (seq[i] == 'i' || seq[i] == '\'') {
                m += 'i';
                i++;
            }
            else if (seq[i] == '2') {
                m += '2';
                i++;
            }
        }
        if (m == "R")  cube = L (cube);
        if (m == "Ri") cube = Li(cube);
        if (m == "R2") cube = L2(cube);
        if (m == "U")  cube = D (cube);
        if (m == "Ui") cube = Di(cube);
        if (m == "U2") cube = D2(cube);
        if (m == "F")  cube = F (cube);
        if (m == "Fi") cube = Fi(cube);
        if (m == "F2") cube = F2(cube);
        if (m == "L")  cube = R (cube);
        if (m == "Li") cube = Ri(cube);
        if (m == "L2") cube = R2(cube);
        if (m == "D")  cube = U (cube);
        if (m == "Di") cube = Ui(cube);
        if (m == "D2") cube = U2(cube);
        if (m == "B")  cube = B (cube);
        if (m == "Bi") cube = Bi(cube);
        if (m == "B2") cube = B2(cube);
    }
    return cube;
}

Cube R (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[2];
    cube.pos[2] = cube.pos[4];
    cube.pos[4] = cube.pos[16];
    cube.pos[16] = cube.pos[14];
    cube.pos[14] = temp;

    temp = cube.pos[3];
    cube.pos[3] = cube.pos[10];
    cube.pos[10] = cube.pos[15];
    cube.pos[15] = cube.pos[9];
    cube.pos[9] = temp;

    c = cube.pos[2].y;
    cube.pos[2].y = cube.pos[2].z;
    cube.pos[2].z = c;

    c = cube.pos[4].y;
    cube.pos[4].y = cube.pos[4].z;
    cube.pos[4].z = c;

    c = cube.pos[16].y;
    cube.pos[16].y = cube.pos[16].z;
    cube.pos[16].z = c;

    c = cube.pos[14].y;
    cube.pos[14].y = cube.pos[14].z;
    cube.pos[14].z = c;

    c = cube.pos[10].y;
    cube.pos[10].y = cube.pos[10].z;
    cube.pos[10].z = c;

    c = cube.pos[15].y;
    cube.pos[15].y = cube.pos[15].z;
    cube.pos[15].z = c;

    c = cube.pos[3].y;
    cube.pos[3].y = cube.pos[3].z;
    cube.pos[3].z = c;

    c = cube.pos[9].y;
    cube.pos[9].y = cube.pos[9].z;
    cube.pos[9].z = c;

    cube.trail.push_back(0);

    return cube;
}

Cube Ri (Cube cube) {
    Cubie temp;
    int c;

    temp = cube.pos[4];
    cube.pos[4] = cube.pos[2];
    cube.pos[2] = cube.pos[14];
    cube.pos[14] = cube.pos[16];
    cube.pos[16] = temp;

    temp = cube.pos[10];
    cube.pos[10] = cube.pos[3];
    cube.pos[3] = cube.pos[9];
    cube.pos[9] = cube.pos[15];
    cube.pos[15] = temp;

    c = cube.pos[2].y;
    cube.pos[2].y = cube.pos[2].z;
    cube.pos[2].z = c;

    c = cube.pos[4].y;
    cube.pos[4].y = cube.pos[4].z;
    cube.pos[4].z = c;

    c = cube.pos[16].y;
    cube.pos[16].y = cube.pos[16].z;
    cube.pos[16].z = c;

    c = cube.pos[14].y;
    cube.pos[14].y = cube.pos[14].z;
    cube.pos[14].z = c;

    c = cube.pos[10].y;
    cube.pos[10].y = cube.pos[10].z;
    cube.pos[10].z = c;

    c = cube.pos[15].y;
    cube.pos[15].y = cube.pos[15].z;
    cube.pos[15].z = c;

    c = cube.pos[3].y;
    cube.pos[3].y = cube.pos[3].z;
    cube.pos[3].z = c;

    c = cube.pos[9].y;
    cube.pos[9].y = cube.pos[9].z;
    cube.pos[9].z = c;

    cube.trail.push_back(1);

    return cube;
}

Cube R2 (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[2];
    cube.pos[2] = cube.pos[16];
    cube.pos[16] = temp;
    temp = cube.pos[4];
    cube.pos[4] = cube.pos[14];
    cube.pos[14] = temp;

    temp = cube.pos[3];
    cube.pos[3] = cube.pos[15];
    cube.pos[15] = temp;
    temp = cube.pos[10];
    cube.pos[10] = cube.pos[9];
    cube.pos[9] = temp;

    cube.trail.push_back(2);

    return cube;
}

Cube U (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[6];
    cube.pos[6] = cube.pos[4];
    cube.pos[4] = cube.pos[2];
    cube.pos[2] = temp;

    temp = cube.pos[1];
    cube.pos[1] = cube.pos[7];
    cube.pos[7] = cube.pos[5];
    cube.pos[5] = cube.pos[3];
    cube.pos[3] = temp;

    c = cube.pos[0].y;
    cube.pos[0].y = cube.pos[0].x;
    cube.pos[0].x = c;

    c = cube.pos[1].y;
    cube.pos[1].y = cube.pos[1].x;
    cube.pos[1].x = c;

    c = cube.pos[2].y;
    cube.pos[2].y = cube.pos[2].x;
    cube.pos[2].x = c;

    c = cube.pos[3].y;
    cube.pos[3].y = cube.pos[3].x;
    cube.pos[3].x = c;

    c = cube.pos[4].y;
    cube.pos[4].y = cube.pos[4].x;
    cube.pos[4].x = c;

    c = cube.pos[5].y;
    cube.pos[5].y = cube.pos[5].x;
    cube.pos[5].x = c;

    c = cube.pos[6].y;
    cube.pos[6].y = cube.pos[6].x;
    cube.pos[6].x = c;

    c = cube.pos[7].y;
    cube.pos[7].y = cube.pos[7].x;
    cube.pos[7].x = c;

    cube.trail.push_back(3);

    return cube;
}

Cube Ui (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[2];
    cube.pos[2] = cube.pos[4];
    cube.pos[4] = cube.pos[6];
    cube.pos[6] = temp;

    temp = cube.pos[1];
    cube.pos[1] = cube.pos[3];
    cube.pos[3] = cube.pos[5];
    cube.pos[5] = cube.pos[7];
    cube.pos[7] = temp;

    c = cube.pos[0].y;
    cube.pos[0].y = cube.pos[0].x;
    cube.pos[0].x = c;

    c = cube.pos[1].y;
    cube.pos[1].y = cube.pos[1].x;
    cube.pos[1].x = c;

    c = cube.pos[2].y;
    cube.pos[2].y = cube.pos[2].x;
    cube.pos[2].x = c;

    c = cube.pos[3].y;
    cube.pos[3].y = cube.pos[3].x;
    cube.pos[3].x = c;

    c = cube.pos[4].y;
    cube.pos[4].y = cube.pos[4].x;
    cube.pos[4].x = c;

    c = cube.pos[5].y;
    cube.pos[5].y = cube.pos[5].x;
    cube.pos[5].x = c;

    c = cube.pos[6].y;
    cube.pos[6].y = cube.pos[6].x;
    cube.pos[6].x = c;

    c = cube.pos[7].y;
    cube.pos[7].y = cube.pos[7].x;
    cube.pos[7].x = c;

    cube.trail.push_back(4);

    return cube;
}

Cube U2 (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[4];
    cube.pos[4] = temp;
    temp = cube.pos[2];
    cube.pos[2] = cube.pos[6];
    cube.pos[6] = temp;

    temp = cube.pos[1];
    cube.pos[1] = cube.pos[5];
    cube.pos[5] = temp;
    temp = cube.pos[3];
    cube.pos[3] = cube.pos[7];
    cube.pos[7] = temp;

    cube.trail.push_back(5);

    return cube;
}

Cube F (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[6];
    cube.pos[6] = cube.pos[18];
    cube.pos[18] = cube.pos[16];
    cube.pos[16] = cube.pos[4];
    cube.pos[4] = temp;

    temp = cube.pos[5];
    cube.pos[5] = cube.pos[11];
    cube.pos[11] = cube.pos[17];
    cube.pos[17] = cube.pos[10];
    cube.pos[10] = temp;

    c = cube.pos[6].z;
    cube.pos[6].z = cube.pos[6].x;
    cube.pos[6].x = c;

    c = cube.pos[18].z;
    cube.pos[18].z = cube.pos[18].x;
    cube.pos[18].x = c;

    c = cube.pos[16].z;
    cube.pos[16].z = cube.pos[16].x;
    cube.pos[16].x = c;

    c = cube.pos[4].z;
    cube.pos[4].z = cube.pos[4].x;
    cube.pos[4].x = c;

    c = cube.pos[11].z;
    cube.pos[11].z = cube.pos[11].x;
    cube.pos[11].x = c;

    c = cube.pos[5].z;
    cube.pos[5].z = cube.pos[5].x;
    cube.pos[5].x = c;

    c = cube.pos[17].z;
    cube.pos[17].z = cube.pos[17].x;
    cube.pos[17].x = c;

    c = cube.pos[10].z;
    cube.pos[10].z = cube.pos[10].x;
    cube.pos[10].x = c;

    cube.trail.push_back(6);

    return cube;
}

Cube Fi (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[6];
    cube.pos[6] = cube.pos[4];
    cube.pos[4] = cube.pos[16];
    cube.pos[16] = cube.pos[18];
    cube.pos[18] = temp;

    temp = cube.pos[5];
    cube.pos[5] = cube.pos[10];
    cube.pos[10] = cube.pos[17];
    cube.pos[17] = cube.pos[11];
    cube.pos[11] = temp;

    c = cube.pos[6].z;
    cube.pos[6].z = cube.pos[6].x;
    cube.pos[6].x = c;

    c = cube.pos[18].z;
    cube.pos[18].z = cube.pos[18].x;
    cube.pos[18].x = c;

    c = cube.pos[16].z;
    cube.pos[16].z = cube.pos[16].x;
    cube.pos[16].x = c;

    c = cube.pos[4].z;
    cube.pos[4].z = cube.pos[4].x;
    cube.pos[4].x = c;

    c = cube.pos[11].z;
    cube.pos[11].z = cube.pos[11].x;
    cube.pos[11].x = c;

    c = cube.pos[5].z;
    cube.pos[5].z = cube.pos[5].x;
    cube.pos[5].x = c;

    c = cube.pos[17].z;
    cube.pos[17].z = cube.pos[17].x;
    cube.pos[17].x = c;

    c = cube.pos[10].z;
    cube.pos[10].z = cube.pos[10].x;
    cube.pos[10].x = c;

    cube.trail.push_back(7);

    return cube;
}

Cube F2 (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[6];
    cube.pos[6] = cube.pos[16];
    cube.pos[16] = temp;
    temp = cube.pos[4];
    cube.pos[4] = cube.pos[18];
    cube.pos[18] = temp;

    temp = cube.pos[5];
    cube.pos[5] = cube.pos[17];
    cube.pos[17] = temp;
    temp = cube.pos[10];
    cube.pos[10] = cube.pos[11];
    cube.pos[11] = temp;

    cube.trail.push_back(8);

    return cube;
}

Cube L (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[12];
    cube.pos[12] = cube.pos[18];
    cube.pos[18] = cube.pos[6];
    cube.pos[6] = temp;

    temp = cube.pos[7];
    cube.pos[7] = cube.pos[8];
    cube.pos[8] = cube.pos[19];
    cube.pos[19] = cube.pos[11];
    cube.pos[11] = temp;

    c = cube.pos[7].y;
    cube.pos[7].y = cube.pos[7].z;
    cube.pos[7].z = c;

    c = cube.pos[8].y;
    cube.pos[8].y = cube.pos[8].z;
    cube.pos[8].z = c;

    c = cube.pos[19].y;
    cube.pos[19].y = cube.pos[19].z;
    cube.pos[19].z = c;

    c = cube.pos[11].y;
    cube.pos[11].y = cube.pos[11].z;
    cube.pos[11].z = c;

    c = cube.pos[6].y;
    cube.pos[6].y = cube.pos[6].z;
    cube.pos[6].z = c;

    c = cube.pos[0].y;
    cube.pos[0].y = cube.pos[0].z;
    cube.pos[0].z = c;

    c = cube.pos[12].y;
    cube.pos[12].y = cube.pos[12].z;
    cube.pos[12].z = c;

    c = cube.pos[18].y;
    cube.pos[18].y = cube.pos[18].z;
    cube.pos[18].z = c;

    cube.trail.push_back(9);

    return cube;
}

Cube Li (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[6];
    cube.pos[6] = cube.pos[18];
    cube.pos[18] = cube.pos[12];
    cube.pos[12] = cube.pos[0];
    cube.pos[0] = temp;

    temp = cube.pos[7];
    cube.pos[7] = cube.pos[11];
    cube.pos[11] = cube.pos[19];
    cube.pos[19] = cube.pos[8];
    cube.pos[8] = temp;

    c = cube.pos[7].y;
    cube.pos[7].y = cube.pos[7].z;
    cube.pos[7].z = c;

    c = cube.pos[8].y;
    cube.pos[8].y = cube.pos[8].z;
    cube.pos[8].z = c;

    c = cube.pos[19].y;
    cube.pos[19].y = cube.pos[19].z;
    cube.pos[19].z = c;

    c = cube.pos[11].y;
    cube.pos[11].y = cube.pos[11].z;
    cube.pos[11].z = c;

    c = cube.pos[6].y;
    cube.pos[6].y = cube.pos[6].z;
    cube.pos[6].z = c;

    c = cube.pos[0].y;
    cube.pos[0].y = cube.pos[0].z;
    cube.pos[0].z = c;

    c = cube.pos[12].y;
    cube.pos[12].y = cube.pos[12].z;
    cube.pos[12].z = c;

    c = cube.pos[18].y;
    cube.pos[18].y = cube.pos[18].z;
    cube.pos[18].z = c;

    cube.trail.push_back(10);

    return cube;
}

Cube L2 (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[6];
    cube.pos[6] = cube.pos[12];
    cube.pos[12] = temp;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[18];
    cube.pos[18] = temp;

    temp = cube.pos[7];
    cube.pos[7] = cube.pos[19];
    cube.pos[19] = temp;
    temp = cube.pos[8];
    cube.pos[8] = cube.pos[11];
    cube.pos[11] = temp;

    cube.trail.push_back(11);

    return cube;
}

Cube D (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[12];
    cube.pos[12] = cube.pos[14];
    cube.pos[14] = cube.pos[16];
    cube.pos[16] = cube.pos[18];
    cube.pos[18] = temp;

    temp = cube.pos[13];
    cube.pos[13] = cube.pos[15];
    cube.pos[15] = cube.pos[17];
    cube.pos[17] = cube.pos[19];
    cube.pos[19] = temp;

    c = cube.pos[12].y;
    cube.pos[12].y = cube.pos[12].x;
    cube.pos[12].x = c;

    c = cube.pos[13].y;
    cube.pos[13].y = cube.pos[13].x;
    cube.pos[13].x = c;

    c = cube.pos[14].y;
    cube.pos[14].y = cube.pos[14].x;
    cube.pos[14].x = c;

    c = cube.pos[15].y;
    cube.pos[15].y = cube.pos[15].x;
    cube.pos[15].x = c;

    c = cube.pos[16].y;
    cube.pos[16].y = cube.pos[16].x;
    cube.pos[16].x = c;

    c = cube.pos[17].y;
    cube.pos[17].y = cube.pos[17].x;
    cube.pos[17].x = c;

    c = cube.pos[18].y;
    cube.pos[18].y = cube.pos[18].x;
    cube.pos[18].x = c;

    c = cube.pos[19].y;
    cube.pos[19].y = cube.pos[19].x;
    cube.pos[19].x = c;

    cube.trail.push_back(12);

    return cube;
}

Cube Di (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[12];
    cube.pos[12] = cube.pos[18];
    cube.pos[18] = cube.pos[16];
    cube.pos[16] = cube.pos[14];
    cube.pos[14] = temp;

    temp = cube.pos[13];
    cube.pos[13] = cube.pos[19];
    cube.pos[19] = cube.pos[17];
    cube.pos[17] = cube.pos[15];
    cube.pos[15] = temp;

    c = cube.pos[12].y;
    cube.pos[12].y = cube.pos[12].x;
    cube.pos[12].x = c;

    c = cube.pos[13].y;
    cube.pos[13].y = cube.pos[13].x;
    cube.pos[13].x = c;

    c = cube.pos[14].y;
    cube.pos[14].y = cube.pos[14].x;
    cube.pos[14].x = c;

    c = cube.pos[15].y;
    cube.pos[15].y = cube.pos[15].x;
    cube.pos[15].x = c;

    c = cube.pos[16].y;
    cube.pos[16].y = cube.pos[16].x;
    cube.pos[16].x = c;

    c = cube.pos[17].y;
    cube.pos[17].y = cube.pos[17].x;
    cube.pos[17].x = c;

    c = cube.pos[18].y;
    cube.pos[18].y = cube.pos[18].x;
    cube.pos[18].x = c;

    c = cube.pos[19].y;
    cube.pos[19].y = cube.pos[19].x;
    cube.pos[19].x = c;

    cube.trail.push_back(13);

    return cube;
}

Cube D2 (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[12];
    cube.pos[12] = cube.pos[16];
    cube.pos[16] = temp;
    temp = cube.pos[18];
    cube.pos[18] = cube.pos[14];
    cube.pos[14] = temp;

    temp = cube.pos[19];
    cube.pos[19] = cube.pos[15];
    cube.pos[15] = temp;
    temp = cube.pos[13];
    cube.pos[13] = cube.pos[17];
    cube.pos[17] = temp;

    cube.trail.push_back(14);

    return cube;
}

Cube B (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[2];
    cube.pos[2] = cube.pos[14];
    cube.pos[14] = cube.pos[12];
    cube.pos[12] = temp;

    temp = cube.pos[1];
    cube.pos[1] = cube.pos[9];
    cube.pos[9] = cube.pos[13];
    cube.pos[13] = cube.pos[8];
    cube.pos[8] = temp;

    c = cube.pos[0].z;
    cube.pos[0].z = cube.pos[0].x;
    cube.pos[0].x = c;

    c = cube.pos[14].z;
    cube.pos[14].z = cube.pos[14].x;
    cube.pos[14].x = c;

    c = cube.pos[2].z;
    cube.pos[2].z = cube.pos[2].x;
    cube.pos[2].x = c;

    c = cube.pos[12].z;
    cube.pos[12].z = cube.pos[12].x;
    cube.pos[12].x = c;

    c = cube.pos[1].z;
    cube.pos[1].z = cube.pos[1].x;
    cube.pos[1].x = c;

    c = cube.pos[9].z;
    cube.pos[9].z = cube.pos[9].x;
    cube.pos[9].x = c;

    c = cube.pos[13].z;
    cube.pos[13].z = cube.pos[13].x;
    cube.pos[13].x = c;

    c = cube.pos[8].z;
    cube.pos[8].z = cube.pos[8].x;
    cube.pos[8].x = c;

    cube.trail.push_back(15);

    return cube;
}

Cube Bi (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[12];
    cube.pos[12] = cube.pos[14];
    cube.pos[14] = cube.pos[2];
    cube.pos[2] = temp;

    temp = cube.pos[1];
    cube.pos[1] = cube.pos[8];
    cube.pos[8] = cube.pos[13];
    cube.pos[13] = cube.pos[9];
    cube.pos[9] = temp;

    c = cube.pos[0].z;
    cube.pos[0].z = cube.pos[0].x;
    cube.pos[0].x = c;

    c = cube.pos[14].z;
    cube.pos[14].z = cube.pos[14].x;
    cube.pos[14].x = c;

    c = cube.pos[2].z;
    cube.pos[2].z = cube.pos[2].x;
    cube.pos[2].x = c;

    c = cube.pos[12].z;
    cube.pos[12].z = cube.pos[12].x;
    cube.pos[12].x = c;

    c = cube.pos[1].z;
    cube.pos[1].z = cube.pos[1].x;
    cube.pos[1].x = c;

    c = cube.pos[9].z;
    cube.pos[9].z = cube.pos[9].x;
    cube.pos[9].x = c;

    c = cube.pos[13].z;
    cube.pos[13].z = cube.pos[13].x;
    cube.pos[13].x = c;

    c = cube.pos[8].z;
    cube.pos[8].z = cube.pos[8].x;
    cube.pos[8].x = c;

    cube.trail.push_back(16);

    return cube;
}

Cube B2 (Cube cube) {
    Cubie temp;
    int c;
    temp = cube.pos[0];
    cube.pos[0] = cube.pos[14];
    cube.pos[14] = temp;
    temp = cube.pos[2];
    cube.pos[2] = cube.pos[12];
    cube.pos[12] = temp;

    temp = cube.pos[1];
    cube.pos[1] = cube.pos[13];
    cube.pos[13] = temp;
    temp = cube.pos[8];
    cube.pos[8] = cube.pos[9];
    cube.pos[9] = temp;

    cube.trail.push_back(17);

    return cube;
}
