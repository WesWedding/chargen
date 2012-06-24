/*
 * Dice.cpp
 *
 *  Created on: Dec 18, 2009
 *      Author: Weston Wedding
 */
#include "Dice.h"
#include <iostream>

Dice::Dice()
{

}

Dice::Dice(int quantity, int sides) :   diceNumber(quantity),
                                        diceSides(sides)
{
}

int Dice::RollDice(int quantity, int sides)
{
    return 0;
}

void Dice::serialize(std::ostream& ostr)
{
    ostr.write((char*)&diceNumber, sizeof(int));
    ostr.write((char*)&diceSides, sizeof(int));
}

void Dice::unserialize(std::istream& istr)
{
    istr.read((char*)&diceNumber, sizeof(int));
    istr.read((char*)&diceSides, sizeof(int));
}
