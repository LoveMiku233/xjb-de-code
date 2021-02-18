#include <iostream>
#include <math.h>
using namespace std;
int main() {
    float meX, meY, drX, drY;
    float chaX, chaY, JD,JDb;
    JDb = 70; 
    meY = 1;
    meX = 1;
    drX = 4;
    drY = 5;
    chaX = meX - drX;
    chaY = meY - drY;
    JD = hypot(chaX, chaY);
    cout << JDb-(atan(chaY / chaX)*180/3.1415) << endl;
    cout << cos(16 * 3.14 / 180) * JD << endl;
    cout << tan(16 * 3.14 / 180) * 4.8 *512<< endl;
    return 0;
}   
