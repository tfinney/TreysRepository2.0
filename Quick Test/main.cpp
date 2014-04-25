/* 
 * File:   main.cpp
 * Author: Trey
 *
 * Created on April 24, 2014, 10:24 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main() {
    //Declare variables
    int var1;
    cout << "Select your perfect party!" << endl;
    cout << "#################" << endl 
         << "# 1.  Pizza" << endl
         << "# 2.  Coke" << endl
         << "# 3.  Pepsi" << endl
         << "#################" << endl;
    cin >> var1;
    if(var1 == 1)
        cout << "PIZZA PARTY!!!";
    else if(var1 == 2)
        cout << "Coke Party!";
    else if(var1 == 3)
        cout << "Pepsi is nasty!";
    else if(var1 <=0 or var1 >=3)
        cout << "Please try again";
    else 
        cout << "Please enter an item off the menu.";
    
    cout << endl << "Have a great day!";
    
    return 0;
}

