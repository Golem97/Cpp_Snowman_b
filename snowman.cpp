/*
===============================================================
>Submission 1.1 CPP_CS_Ariel University 2021 Year_2 Semester_2 
>Author <Nathanael Benichou>
>snowman-a  
>Snowman Structur :

 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)

ARGS STRUCTUR : HNLRXYTB
================================================================
*/
#include "snowman.hpp"
#include <iostream>
#include <array>
#include <string>
#include <exception>
using namespace std;

namespace ariel
{

    string snowman(int input)
    {

        //Check if input is good 
        if (input < MINIMUM || input > MAXIMUM)
        {
            __throw_invalid_argument("Error! Not a valid input");
        }
        else
        {

            int *arr = new int[SIZE];
            //Checks for each digit if its correct
            for (int i = 0; i < SIZE; i++)
            {
                if (input % BASE > 4 || input % BASE < 1)
                {
                    __throw_invalid_argument("Error! Not a valid input");
                }
                arr[LAST_INDEX - i] = input % BASE;
                input /= BASE;
            }

            //Creat array For each parts of : HNLRXYTB

            //Empty, Straw hat, Mexican Hat,  Fez, Russian Hat
            const array<string, FIVE> hats = {"", "_===_\n", " ___ \n .....\n", "  _  \n  /_\\ \n", " ___ \n (_*_)\n"};

            //Empty, Normal, Dot, Line, None
            const array<string, FIVE> noses = {"", ",", ".", "_", " "};

            //Empty, Dot ,Bigger Dot, Biggest Dot, Closed
            const array<string, FIVE> right_Eye = {"", ".", "o", "O", "-"};

            //Empty, Dot ,Bigger Dot, Biggest Dot, Closed
            const array<string, FIVE> left_Eye = {"", ".", "o", "O", "-"};

            
            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None
            const array<string, FIVE> high_Left = {"", " ", "\\", " ", " "};

            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None
            const array<string, FIVE> low_Left = {"", "<", " ", "/", " "};
           
            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None
            const array<string, FIVE> low_Right = {"", ">", " ", "\\", " "};

            //Empty,Buttons, vest, Inwards Arms, None
            const array<string, FIVE> torso = {"", " : ", "] [", "> <", "   "};

            //Empty,  Normal Arm,  Upwards Arm, Downwards Arm, None 
            const array<string, FIVE> high_Right = {"", " ", "/", " ", " "};

            //Empty, Buttons, feet, Flat, None
            const array<string, FIVE> base = {"", " : ", "\" \"", "___", "   "};

            //Constuction of the return ans with peek each value in corresponding index of is array.

            string snw = " " + hats[arr[ZERO]] +
                         high_Left[arr[FOUR]] + "(" + left_Eye[arr[TWO]] + noses[arr[ONE]] + right_Eye[arr[THREE]] + ")" + high_Right[arr[FIVE]] + "\n" +
                         low_Left[arr[FOUR]] + "(" + torso[arr[SIX]]+")" + low_Right[arr[FIVE]] + "\n (" +
                         base[arr[LAST_INDEX]] + ")";
            return snw;
        }
    }
}


