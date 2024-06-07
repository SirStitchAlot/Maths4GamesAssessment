#pragma once
#include <cstdint>

namespace MathClasses
{

  using Byte = unsigned char;

  struct Colour{
        // Add the struct data fields and methods, as per the tutorials and exercises, here...
        // ...
    /*==================================^^todo^^=================================================================*/
 



      std::uint32_t colour = 0;                              



    /*=======================================^^properties^^==================================================================*/


        Colour(){
        
            colour = (255);

        }

        Colour(Byte red, Byte green, Byte blue, Byte alpha) {
        
            colour = (red << 24) + (green << 16) + (blue << 8) + (alpha);



        }

        ~Colour() {};


    /*==========================================^^Structors^^=======================================================================*/

        //unsigned char is a 1 byte number that stores a value from 0 to 255, perfect for colours!

        //also remember 1 byte = 8 bits
        unsigned char GetRed() const {
            return colour >> 24;
        }

        unsigned char GetGreen() const {
            return colour >> 16;
        }

        unsigned char GetBlue() const {
            return colour >> 8;
        }

        unsigned char GetAlpha() const {
            return colour >> 0;
        }

        void SetRed(Byte red) {
            //Slide the red bits into the correct position;
            unsigned int v = (unsigned int)red << 24;
            //Clear the current red values
            colour = colour & 0x00ffffff;
            //Put the new red values into place.
            colour = colour | v;
        }

        void SetGreen(Byte green) {
            //Slide the grenn bits into the correct position;
            unsigned int v = (unsigned int)green << 16;        
            //Clear the current green values
            colour = colour & 0xFF00FFFF; 
            //Put the new green values into place.
            colour = colour | v;                       
        }

        void SetBlue(Byte blue) {
            //Slide the blue bits into the correct position;
            unsigned int v = (unsigned int)blue << 8;
            //Clear the current blue values
            colour = colour & 0xFFFF00FF;
            //Put the new blue values into place.
            colour = colour | v;
        }

        void SetAlpha(Byte alpha) {
            //Slide the alpha bits into the correct position;
            unsigned int v = (unsigned int)alpha;
            //Clear the current alpha values
            colour = colour & 0xFFFFFF00;
            //Put the new alpha values into place.
            colour = colour | v;
        }



    /*============================================^^Methods^^======================================================================================*/

        bool operator == (const Colour rhs) {

            return colour == rhs.colour;





        }


   /*=======================================^^^overloads/casting^^^======================================================================*/

    };
}