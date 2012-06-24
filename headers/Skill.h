/*
 * Skill.h
 *
 *  Created on: Dec 18, 2009
 *      Author: Weston Wedding
 */

#ifndef SKILL_H_
#define SKILL_H_

#include <iostream>
#include <string>
#include "datatypes.h"

class Skill{
    public:
        void serialize(std::ostream& ostr);
    private:
        idNumber skillID;
        std::string description;
};


#endif /* SKILL_H_ */
