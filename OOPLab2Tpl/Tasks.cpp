#include <fstream>
#include <iostream>
#include <clocale>
#include <vector>
#include <string>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    2.1  Data encryption using bitwise operations \n";
    cout << "    3.  Examples of problems using bitwise operations \n";
    cout << "    4.  Exit \n";
}
void task1() {
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations
    setlocale(LC_CTYPE, "ukr");
    cout << "Введiть цiлi числа a, b, c, d:";
    int a, b, c, d, x, y;
    cin >> a >> b >> c >> d;
    x = (((a + a + (a << 4)) + ((d << 8) + (d << 5) + (d << 4) + (d << 3))) >> 9) - ((b << 7) - b - b - b - b - b - b) + ((c << 7) - c - c - c - c - c);
    y = ((18 * a + 312 * d) / 512) - b * 122 + c * 123;
    cout << " x=" << x << " y=" << y << "\n\n";
    cout << " Calculation of expressions using bitwise operations  \n";
}

void task2(char s[16][16], unsigned short rez[256])
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    char ch;
    ifstream ifs("in.lab.txt");
    if (!ifs) {
        cout << "File in.lab not open" << endl; return;
    }

    ofstream ofsb("outb.lab", ios::out | ios::binary);
    unsigned short i, j, l, b, bb, k, t;
    for (i = 0; i < 16; i++) {
        ifs.get(s[i], 5, '\0'); ifs.get(ch);
    }
    j = 0;
    cout << "\n\n";

    for (i = 0; i < 16; i++) {
        cout << s[i] << endl;
    }

    for (int r = 0; r < 16; r++) {
        for (int t = 4; t < 16; t++) {
            s[r][t] = ' ';
        }
    }

    unsigned char c;
    unsigned short r, rW, rw, rp, w, ww, n, p, pp;

    n = 0;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            r = 0;
            rw = 0;
            rW = 0;
            c = s[i][j];
            t = c;
            r |= i; //номер рядка              0000 0000 0000 ____
            rw |= t << 12;     //              ____ 0000 0000 ____
            r |= rw >> 8; // молодша частина   0000 0000 ____ ____
            p = 1;
            b = 0;
            for (short l = 0; l < 7; l++) //обчис біта парності
            {
                if (r & p)
                {
                    if (b == 0) b = 1; else b = 0;
                }
                p <<= 1;
            }
            r |= b << 8; //запис біт панрності  0000 000_ ____ ____
            rW |= t >> 4; // старша частина    (0000 ____) - s
            r |= rW << 9;                  //   000_ ____ ____ ____
            r |= j << 13; //номер букви в рядку 0___ ____ ____ ____
            rp |= r >> 8;                  //  (0___ ____)
            pp = 1;
            bb = 0;
            for (short l = 0; l < 16; l++) //обчис біта парності 2
            {
                if (rp & pp) {
                    if (bb == 0) bb = 1; else bb = 0;
                }
                pp <<= 1;
            }
            r |= bb << 15;                  //  ---- ---- ---- ----
            rez[n] = r;
            n++;
            

        }
    }
    ofsb.write((char*)rez, 256 * sizeof(unsigned short));

    ifs.close();
    ofsb.close();

}

void task2_1()
{
    // Розшифрування даних з використання побітових операцій 
    // Data decryption using bitwise operations
    char ch;
    char so[16][17];
    unsigned short sd2[256], r;
    char st[17];
    ifstream ifs("outb.lab");
    if (!ifs) {
        cout << "File in.dat not open" << endl; return;
    }
    ofstream ofs("outo.lab");
    unsigned short i, j, l, t, w;

    ifs.read((char*)sd2, 256 * sizeof(unsigned short));

    short indi, indj, mp, sp;
    indj = 0;
    for (i = 0; i < 256; i++)
    {
        w = 0;
        r = sd2[i];
        indi = r & 0x000f; // 0000 0000 0000 1111
        mp = r & 0x00f0;   // 0000 0000 1111 0000 v
        mp >>= 4;          // 0000 0000 0000 1111
        w |= mp;           // 0000 1111
        sp = r & 0x1e00;   // 0001 1110 0000 0000
        sp >>= 5;          // 0000 0000 1111 0000
        w |= sp;           // 1111 1111
        //  indj = r & 0x6000;
        //  indj >>= 13;
        ch = w;
        //  cout << hex << mp << ' ';
        //  cout << hex << sp << ' ';
        //  cout << hex << ch << endl;
        //  cout << indi << ' ';
        //  cout << indj << ' ';
        so[indi][indj] = ch;
        //  cout << so[indi][indj] << endl;
        indj++;
        if (indj == 16) indj = 0;
    }


    for (i = 0; i < 16; i++) {
        so[i][16] = '\0';
    }

    for (i = 0; i < 16; i++) {
        ofs.write(so[i], 16) << endl;
    }
    ofs.close();

    for (i = 0; i < 16; i++) {
        cout << hex << so[i] << endl;
    }
    cout << " Data encryption using bitwise operations  \n";
}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}
*/

