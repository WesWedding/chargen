/*
 * Stat.cpp
 *
 *  Created on: Jun 27, 2009
 *      Author: Weston Wedding
 */
#include "Stat.h"

Stat::Stat() :  statName("NoID"),
                statBase(-1),
                registeredModifiers(),
                modifiers()  //list constructors are
                             // fine for registeredModifiers and modifiers
{}
Stat Stat::operator=(int const rightSide)
{
    if (rightSide == NO_STAT_CHANGE)
        return *this;
    else {
        this->statBase = rightSide;
        return *this;
    }
}

void Stat::serialize(std::ostream& ostr)
{
}


