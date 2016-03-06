#include <iostream>
#include "resistor.h"

using namespace std;

/**
 * Ohmikus ellen�ll�st megval�sit� oszt�ly kipr�b�l�sa
 */
int main()
{
    // cporta tesztesetei miatt csak eg�szeket �runk ki. 
    cout.setf(ios::fixed);
    cout.precision(0);

    Resistor r;
    cout << r.getR() << endl;                         // default �rt�k

    cout << Resistor(130).getR() << endl;             // 130
    cout.precision(0);
    Resistor r1(1000), r2(3000), r3(6000);

               // o--[r1]--[r2]--o 
    cout << (r1 + r2).getR() << endl                  // 4000

               //    +--[r1]--+
               // o--+        +---o
               //    +--[r1]--+
         << (r1 % r1).getR() << endl                  //  500

               // o--[r1]--[r1]--o
         << (2 * r1).getR() << endl                   // 2000

               // o--[r1]--[r1]--[r2]--o
         << (2*r1 + r2).getR() << endl                // 5000

               // o--[r1]--[r2]---[r1]--[r2]--o
         << (2 * (r1+r2)).getR() << endl              // 8000

               //    +--[r2]--+   +--[r2]--+
               // o--+        +---+        +---o
               //    +--[r3]--+   +--[r3]--+
         << (2 * (r2%r3)).getR() << endl;             // 4000

    Resistor::setDef(2);	  		      // 2 ohm a default
    Resistor rt[10];			  	      // a t�mb minden eleme 2 ohmos lesz
    cout << rt[5].getR() << endl;                     // 5. elem is 2

    try {
        int n;
        while (cin >> n) {
            cout << (n * r1).getR() << endl;
        }
        cout << "�p�ts�nk �r�kmozg�t!" << endl;
    }
    catch (const char *s) {
        cout << s << endl;                            // saj�t Neptun
    }

    return 0;
}
