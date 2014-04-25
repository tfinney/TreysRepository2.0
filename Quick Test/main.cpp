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
    cout << "Pizza 1" << endl
         << "Coke 2" << endl
         << "Pepsi 3";
    cin >> var1;
    if(var1 == 1)
        cout << "PIZZA PARTY!!!";
    else if(var1 == 2)
        cout << "Coke Party!";
    else if(var1 == 3)
        cout << "Pepsi is nasty!";
    else if(var1 <=0 or var1 >=3)
        cout << "Please try again";
    else if(var1 != )
        cout << "Please enter a 1, 2, or 3";
    
    return 0;
}

