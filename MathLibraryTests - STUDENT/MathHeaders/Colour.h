#pragma once
#include <cstdint>

namespace MathClasses
{
    struct Colour
    {
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
    /*==================================^^todo^^=================================================================*/




        std::uint32_t colour;



    /*=======================================^^properties^^==================================================================*/





    /*==========================================^^Structors^^=======================================================================*/

        //unsigned char is a 1 byte number that stores a value from 0 to 255, perfect for colours!
        unsigned char GetRed() const {
            return colour >> 24;
        }

    /*============================================^^Methods^^======================================================================================*/






    };
}