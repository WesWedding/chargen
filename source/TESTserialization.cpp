/*
 * TESTserialization.cpp
 *
 *  Created on: Jan 3, 2010
 *      Author: Weston Wedding
 */

#include <iostream>
#include <fstream>
#include "datatypes.h"
#include "Character.h"

using namespace std;

int main(int argc, char* argv[])
{
    ofstream ostr;
    ifstream istr;

    /* BEGIN DICE TEST
     * Testing out Dice serialization
     * Currently requires the data members to be exposed(public)
     * because there weren't member accessor functions or
     * a toString() or operator<< when this was typed up

    Dice* diceTest = new Dice(9000,8000);
    Dice* diceTest2 = new Dice(1,2);
    ostr.open("outtest.tst",fstream::binary | fstream::trunc);
    diceTest->serialize(ostr);
    ostr.close();

    cout << "---------Before file read-----------" << endl;
    cout << "diceSides: " << diceTest->diceSides << "  diceNumber : " << diceTest->diceNumber << endl;

    delete diceTest;

    istr.open("outtest.tst", fstream::binary);

    diceTest2->unserialize(istr);

    istr.close();

    cout << "---------After file read-----------" << endl;
    cout << "diceSides: " << diceTest2->diceSides << "  diceNumber : " << diceTest2->diceNumber << endl;
    delete diceTest2;

    // END DICE TEST  */

    return 0;


}
