#include <math.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
#define LEFT      8  // Number of units before "" in si[]
#define RIGHT     8  // Number of units after "" in si[]
#define START     8  // Starts at "" prefix
string si[] = { "Yocto", "Zepto", "Atto", "Femto", "Pico", "Nano", "Micro", "Milli", "", 
"Kilo", "Mega", "Giga", "Tera", "Peta", "Exa", "Zetta", "Yotta" };

string suffixWithUnit(double number) {
    int i = 0;
    double absNumber = fabs(number);
    while (absNumber >= 1000 && i < RIGHT) {
        absNumber /= 1000;
        i++;
    }
    while (absNumber < 1 && i > LEFT) {
        absNumber *= 1000;
        i--;
    }
    char buffer[100];
    sprintf(buffer, "%.6f %s", absNumber, si[i + START].c_str());
    return buffer;
}

int main(int argc, char **argv) {
    double test;
    cout<<"Input a number: "<<endl;
    cin>>test;
    cout << test << " = " << suffixWithUnit(test) << endl;
    return 0;
}