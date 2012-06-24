//A quick test of pseudo random number generation methods.
// Looking for an even distribution of numbers to represent good dice of varying
// side count.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>


using namespace std;
int random(int sides);

int main(int argc, char* argv[])
{

    srand(time(NULL));
    int max = 9000;
    int i = 0;
    int result = 0;
    float totalCount = 0;
    stringstream pattern;

        #define SIDES 20
        pattern.clear();
        float percentage[SIDES];
        for (i = 0; i < SIDES; i++)
            percentage[i] = 0;
        int sides[SIDES];
        for (i = 0; i < SIDES; i++)
            sides[i] = 0;
        for (i = 0; i < max; i++)
        {
            result = random(SIDES);
            sides[result] = sides[result] + 1;
            pattern << result;
        }
        for (i = 0; i < SIDES; i++)  //cal totalCount
            totalCount += sides[i];
        for (i = 0; i < SIDES; i++)
            percentage[i] = sides[i]/totalCount;  //calc percentages

        std::cout << "Results for SIDES sides" << endl;
        std::cout << "-----------------------" << endl;
        for(i=0;i<SIDES;i++)
            cout << "Side " << i << "   ";
        cout << endl;
        for(i=0;i<SIDES;i++)
            cout << sides[i] << "   ";
        cout << endl;
        for(i=0;i<SIDES;i++)
            cout << percentage[i] << "   ";
        cout << endl;
        cout << "Total : " << totalCount << endl << endl;

        //Testing 6 sides

        //cout << pattern.str(); */




    return 0;
}


int random(int sides)  //Simple rand() and seeding with time()
{
    int val = 0;
    val = rand() % sides;

    return val;

}
