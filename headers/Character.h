/*
 * Character.h
 *
 *  Created on: Mar 23, 2009
 *      Author: Weston Wedding
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "datatypes.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#ifndef NO_STAT_CHANGE
#define NO_STAT_CHANGE  -1
#endif /* NO_STAT_CHANGE */

const short int endianCheck = 1; //Used during serialization and de-serialization

struct CharacterAttributes {
        int IQ;
        int ME;
        int MA;
        int PS;
        int PP;
        int PE;
        int PB;
        int spd;

        CharacterAttributes(): IQ(NO_STAT_CHANGE),
                                ME(NO_STAT_CHANGE),
                                MA(NO_STAT_CHANGE),
                                PS(NO_STAT_CHANGE),
                                PP(NO_STAT_CHANGE),
                                PE(NO_STAT_CHANGE),
                                PB(NO_STAT_CHANGE),
                                spd(NO_STAT_CHANGE)
                                {}
};


struct SecondaryAttributes
{
        Stat hitPoints;
        Stat ISP;
        Stat PPE;
        Stat SDC;
        Stat naturalAR;
        Stat horrorFactor;
        Nature characterNature;
        short int actionsPerMelee;
        short int attacksPerMelee;
};


class Character {
public:

	Character();
	Character(int ID, std::string& trueName);
	bool setAttributes(CharacterAttributes const& AttributeStruct);
	bool setSecondaryAttribs(SecondaryAttributes const& SecondaryAttribs);
	void setBonuses();
	void setOCC();
	void setRace();
	void setGainsPerLevel();
	void setTrueName();
	void setGivenName();
	void addSkill();

	void serialize(std::ostream&);
	void unserialize(std::istream&);


private:

	//Name data for character sheet
	std::string givenName;
	std::string trueName;

	//Primary Attributes as defined by Palladium Games; different sourcebooks
	// Source used is Palladium Fantasy RPG

	Stat IQ;
	Stat ME;
    Stat MA;
    Stat PS;
    Stat PP;
    Stat PE;
    Stat PB;
    Stat spd;  //End primary
    //Secondary Attributes.  Dervied by OOC, Race, Stats
	Stat hitPoints;
	Stat ISP;
	Stat PPE;
	Stat SDC;
	Stat naturalAR;
	Stat horrorFactor;
	Nature characterNature;
	short int actionsPerMelee;
	short int attacksPerMelee;  //End secondary
	Stat bonusVsPsionic;
	Stat bonusVsInsanity;
	Stat bonusVsComa;
	Stat bonusVsDeath;
	Stat bonusVsMagic;
	Stat bonusVsPoison;
	Stat bonusVsHorrorFactor;
	Stat bonusToSpellStrength;
	Stat bonusToPsionicStrength;
	Stat bonusToInitiative;
	Stat bonusVsDrugs;
	Stat bonusVsToxins;
	Stat bonusVsPossession;
	Stat bonusVsCircles;
	Stat bonusVsFumes;
	Stat bonusVsRitual;
	Stat bonusVsWard;
	Stat bonusVsFaerieMagic;
	OCC characterOCC;
	Race characterRace;
	Dice gainSDCPerLevel;
	Dice gainHPPerLevel;
	Dice gainPPEPerLevel;
	Dice gainISPPerLevel;
	std::list<Skill> skills;

};



#endif  /* _CHARACTER_H */

