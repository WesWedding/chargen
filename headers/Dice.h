/*
 * Dice.h
 *
 *  Created on: Dec 18, 2009
 *      Author: Weston Wedding
 */

#ifndef DICE_H_
#define DICE_H_

#include <iostream>

class Dice{
    public:
        Dice();
        Dice(int quantity, int sides);
        int RollDice(int quantity, int sides);
        void serialize(std::ostream& ostr);
        void unserialize(std::istream& ostr);

    private:
        int diceNumber;
        int diceSides;
};

#endif /* DICE_H_ */
