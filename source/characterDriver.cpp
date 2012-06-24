/*
 * characterDriver.cpp
 *
 *  Created on: Dec 21, 2009
 *      Author: Weston Wedding
 */

#include <iostream>
#include <string>
#include "Character.h"
#include <fstream>

int main(int argc, char argv[])
{
    std::string     name("POOPIEHEADS");
    Character aCharacter(0, name);
    CharacterAttributes attribStruct;
    Character* characterPtr = new Character;

    aCharacter.setAttributes(attribStruct);

    //File I/O testrun
    // Test run result: failure.  Each class needs to have its own .read and .write()
    // member functions.  Pointers need to be dereferenced and the data they point to
    // saved manually.
    std::fstream filestream;
    filestream.open("Poobah.bin", std::ios::binary | std::ios::trunc | std::ios::out);
    if(filestream)
    {
        filestream.write((char*)&aCharacter, sizeof(Character));
        filestream.close();
    }
    filestream.open("Poobah.bin", std::ios::binary | std::ios::out);
    if(filestream)
        {
            filestream.read((char*)characterPtr, sizeof(Character));
            filestream.close();
        }
}
