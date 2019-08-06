#include "helpMethods.h"

int HelpMethods :: conversionStringToInt( string str){
    int digit;
    digit=atoi(str.c_str());

    return digit;
}

string HelpMethods :: conversionIntToString (int digit){
    ostringstream ss;
    ss << digit;
    string str = ss.str();
    return str;
}
