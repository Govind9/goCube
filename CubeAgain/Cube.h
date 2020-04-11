#include <iostream>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <tuple>
#include <algorithm>

//Color definitions
#define RED		    "\033[0;31m\u25A0 "
#define GREEN		"\033[0;32m\u25A0 "
#define YELLOW		"\033[0;33m\u25A0 "
#define BLUE		"\033[0;34m\u25A0 "
#define	WHITE		"\033[0;37m\u25A0 "
#define ORANGE      "\033[0;95m\u25A0 "
#define BLANK       "  "
#define END_COLOR	"\033[0m"
#define BLOCK       "\u25A0"
#define yy   0
#define g   1
#define w   5
#define b   21
#define o   85
#define r   341
#define n   342

using namespace std;

class Cubie {
    public:
        short x, y, z;
};

class Cube {
    public:
        Cubie pos[20];
        vector <char> trail;

        //This is constructure for initializing a cube state
        Cube();

        // Prints the configuration in which cube is
        void print(int index);

        // Paints the configuration in which cube is
        void paint();
};

typedef Cube (*move_fn)(Cube);
typedef bool (*check_fn)(Cube);
typedef unsigned long long (*gen_fn)(Cube);
typedef bool (*check_cd)(unsigned long long);

string color(int);

inline int color_code(char);
tuple<unsigned long long, unsigned long long> gen_code(Cube);
unsigned long long gen_code_cross(Cube);
unsigned long long gen_f2l_og(Cube);

void solve(Cube, check_fn);
Cube solve2(Cube, gen_fn, check_cd);

void give_solution(Cube, Cube);

bool is_cross (Cube);
bool is_cross_code (unsigned long long);
bool is_f2l_og (unsigned long long);

Cube apply (Cube, string);
Cube apply_wg (Cube, string);
Cube R (Cube);
Cube Ri(Cube);
Cube R2(Cube);
Cube U (Cube);
Cube Ui(Cube);
Cube U2(Cube);
Cube F (Cube);
Cube Fi(Cube);
Cube F2(Cube);
Cube L (Cube);
Cube Li(Cube);
Cube L2(Cube);
Cube D (Cube);
Cube Di(Cube);
Cube D2(Cube);
Cube B (Cube);
Cube Bi(Cube);
Cube B2(Cube);
