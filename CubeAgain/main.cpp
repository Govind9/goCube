#include <iostream>
#include "Cube.h"

using namespace std;

void encode(string s) {
    long rand = 100;
    for (int i=0; i<s.size(); i++) {
        rand += s[i];
    }
    rand *= 3.1415;
    rand += s.size() * (int)s[0];
    rand *= (int)s[s.size()-1];
    cout << s << " " << rand << endl;
}

int main()
{
    unsigned long long code;
    Cube cube;
    cout << gen_f2l_og(cube) << endl;
    //cube = apply_wg(cube, "F2LD2LiR2U2B2RiU2F2RiDB2RF2BiLFUDi");
    //cube = apply(cube, "RLFiBiR2LiDiF");
    cube = apply(cube, "RUiRi");
    cout << gen_f2l_og(cube) << endl;
    cube = apply(cube, "R");
    cout << gen_f2l_og(cube) << endl;
    cube = apply(cube, "U");
    cout << gen_f2l_og(cube) << endl;
    cube = apply(cube, "Ui");
    cout << gen_f2l_og(cube) << endl;
    //cube = solve2(cube, gen_f2l_og, is_f2l_og);

    //cube = solve2(cube, gen_code_cross, is_cross_code);
    return 0;
}
