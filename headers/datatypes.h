/*
 * datatypes.h
 *
 *  Created on: Jun 26, 2009
 *      Author: Weston Wedding
 */

#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef short int idNumber;

//Buff, debuff types  TODO: Put in more appropriate spot
enum Nature {
        NATURAL,
        SUPERNATURAL,
        ANIMAL
};

enum Type {
        PSIONIC,
        CURSE,
        MAGIC,
        INJURY,
        GM_MOD,
        POISON,
        TOXIN,
        STAT_MOD,
        SKILL_MOD
};

struct Modifier {
    private:
        int modifier;
        int duration;
        Type modType;
};

#include "Stat.h"
#include "OCC.h"
#include "Dice.h"
#include "Skill.h"
#include "Race.h"

#endif /* DATATYPES_H_ */
