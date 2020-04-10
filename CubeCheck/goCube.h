#include <iostream>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <set>

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

using namespace std;

class Cube {
    public:

        bitset <144> pos;
        vector <char> trail;

        //This is constructure for initializing a cube state
        Cube();

        // Prints the configuration in which cube is
        void print();

        // Paints the configuration in which cube is
        void paint();
};

string color (Cube *cube, int index);

void solve (Cube);

bool is_cross (Cube);
Cube K (Cube);
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
