/*
 * Character.cpp
 *
 *  Created on: Mar 23, 2009
 *      Author: Weston Wedding
 */
#include "Character.h"
#include "datatypes.h"
#include <list>
#include <iterator>


Character::Character()
{
}

Character::Character(int ID, std::string& trueName)
{
}

bool Character::setAttributes(CharacterAttributes const& attributeStruct)
{
    IQ = attributeStruct.IQ;
    ME = attributeStruct.ME;
    MA = attributeStruct.MA;
    PS = attributeStruct.PS;
    PP = attributeStruct.PP;
    PE = attributeStruct.PE;
    PB = attributeStruct.PB;
    spd = attributeStruct.spd;
    return true;
}

bool Character::setSecondaryAttribs(SecondaryAttributes const& secondaries)
{
    return true;
}

void Character::setBonuses()
{

}


void Character::setOCC()
{

}

void Character::setRace()
{

}

void Character::setGainsPerLevel()
{

}

void Character::setTrueName()
{

}

void Character::setGivenName()
{

}

void Character::addSkill()
{

}

// IMPORTANT: .  File usage or internet communication
// between two different architectures will most likely not work.
void Character::serialize(std::ostream& ostr)
{
    ostr.write(givenName.c_str(), givenName.size());
    ostr.write(trueName.c_str(), trueName.size());

    IQ.serialize(ostr);
    ME.serialize(ostr);
    MA.serialize(ostr);
    PS.serialize(ostr);
    PP.serialize(ostr);
    PE.serialize(ostr);
    PB.serialize(ostr);
    spd.serialize(ostr);

    hitPoints.serialize(ostr);
    ISP.serialize(ostr);
    PPE.serialize(ostr);
    SDC.serialize(ostr);
    naturalAR.serialize(ostr);
    horrorFactor.serialize(ostr);
    ostr.write((char*)&characterNature, sizeof(Nature));
    ostr.write((char*)&actionsPerMelee, sizeof(short int));
    ostr.write((char*)&attacksPerMelee, sizeof(short int));
    bonusVsPsionic.serialize(ostr);
    bonusVsInsanity.serialize(ostr);
    bonusVsComa.serialize(ostr);
    bonusVsDeath.serialize(ostr);
    bonusVsMagic.serialize(ostr);
    bonusVsPoison.serialize(ostr);
    bonusVsHorrorFactor.serialize(ostr);
    bonusToSpellStrength.serialize(ostr);
    bonusToPsionicStrength.serialize(ostr);
    bonusToInitiative.serialize(ostr);
    bonusVsDrugs.serialize(ostr);
    bonusVsToxins.serialize(ostr);
    bonusVsPossession.serialize(ostr);
    bonusVsCircles.serialize(ostr);
    bonusVsFumes.serialize(ostr);
    bonusVsRitual.serialize(ostr);
    bonusVsWard.serialize(ostr);
    bonusVsFaerieMagic.serialize(ostr);
    characterOCC.serialize(ostr);
    characterRace.serialize(ostr);
    gainSDCPerLevel.serialize(ostr);
    gainHPPerLevel.serialize(ostr);
    gainPPEPerLevel.serialize(ostr);
    gainISPPerLevel.serialize(ostr);

    std::list<Skill>::iterator it;
    std::list<Skill>::iterator itEnd;
    it = skills.begin();
    itEnd = skills.end();
    while (!(it == itEnd))
    {
        (*it).serialize(ostr);
        it++;
    }


     return;
}


void Character::unserialize(std::istream& istr)
{
    // IMPORTANT: Endianness is not addressed but it IS checked.  File usage or internet communication
    // between two different architectures will most likely not work.
    return;
}
