#include <iostream>
#include "goCube.h"
#include <algorithm>
#include <chrono>
#include <limits.h>

using namespace std;
using namespace std::chrono;

char colorrr[6]={'Y','G','W','B','O','R'};

class Cc {
    public:

        char configuration[24];
        vector<short> parent;

        Cc() {
            for(int i=0, k=0; i<24; i=i+4, k++){
            for(int j=0;j<4;j++)
                configuration[i+j]=colorrr[k]; // assign color to each piece.
            }
        }
};

unsigned long long code_generator(Cc obj){

    int temp[6];

    //Generate code for all cube
    for(int i= 0 ; i<6; i++){
        temp[i]=0;
        int t=0;

        //Generate code for each face which is unique
        for (int j=i*4; j<((i*4)+4); j++){
            switch(obj.configuration[j]){
                case('Y'):
                    t=0;
                    break;
                case('G'):
                    t=1;
                    break;
                case('W'):
                    t=5;
                    break;
                case('B'):
                    t=21;
                    break;
                case('O'):
                    t=85;
                    break;
                case('R'):
                    t=341;
                    break;
            }
            temp[i]=temp[i]+t;
        }
    }

    // sort code for all face
    sort(temp,temp+6);

    //concatenate code for all faces
    unsigned long long code=0;
    for (int i=0; i<6; i++){
        if(i<4)
            code=code*(1000);
        if(i>3)
            code=code*(10000);
        code=code+temp[i];
    }
    return code;
}

Cc H (Cc obj) {
    char temp1, temp2;
    temp1=obj.configuration[14];
    temp2=obj.configuration[15];
    obj.configuration[15]=obj.configuration[22];
    obj.configuration[14]=obj.configuration[21];
    obj.configuration[21]=obj.configuration[4];
    obj.configuration[22]=obj.configuration[5];
    obj.configuration[4]=obj.configuration[19];
    obj.configuration[5]=obj.configuration[16];
    obj.configuration[19]=temp1;
    obj.configuration[16]=temp2;
    temp1=obj.configuration[0];
    obj.configuration[0]=obj.configuration[3];
    obj.configuration[3]=obj.configuration[2];
    obj.configuration[2]=obj.configuration[1];
    obj.configuration[1]=temp1;

    return obj;
}

inline bitset <36> rotate (bitset <36> n, int c, bool clock) {
    if (clock)
        return n << c | n >> (36-c);
    return n >> c | n << (36-c);
}

bitset <36> killer(bitset <36> bs) {
    return rotate(bs, 9, true);
}

int main() {
    string ss = "100111011010110011101101011001110110";
    bitset <36> bs (ss);
    //auto p = rotate(n, 2, true);
    //cout << p << endl;
    //p = rotate(n, 2, false);
    //cout << p;

    Cube a, b;
    int m = 100000;
    string code;
    unsigned long long code2;
    unsigned long long cd;
    auto f = a.pos;
    auto start = high_resolution_clock::now();
    for (int i=0; i<=m; i++) {
        killer(bs);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

    Cc c, d;
    start = high_resolution_clock::now();
    for (int i=0; i<=m; i++) {
        d = H(c);
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

}
