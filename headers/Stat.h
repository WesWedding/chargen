/*
 * stat.h
 *
 *  Created on: Jun 27, 2009
 *      Author: Weston Wedding
 *
 * Description: Holds numerical character stats with associated IDname strings for resource
 *  and buff/debuff management.
 *
 *  operator= sets statBase, any negative numbers will be discarded and treated as "no change."
 *  The intent is some synergy with structs that are used to change or set new stats.
 *
 *  */

#ifndef STAT_H_
#define STAT_H_

#include <list>
#include <string>
#include "datatypes.h"

#ifndef NO_STAT_CHANGE
#define NO_STAT_CHANGE -1
#endif

class Stat {
    public:
       Stat();
       Stat operator=(int const rightSide);
       void serialize(std::ostream& ostr);
    private:
        std::string statName; //TODO: replace with ID system when resource management implemented
        int statBase;
        std::list<Modifier*> registeredModifiers; //Pointers to mods that effect this stat
        std::list<Modifier> modifiers;  //Extraneous if central mod registration implemented
};


#endif /* STAT_H_ */
