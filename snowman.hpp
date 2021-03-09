#include <string>
namespace ariel{
    std::string snowman(long int number);

    const short HAT = 0;
    const short NOSE = 1;
    const short LEFT_EYE = 2;
    const short RIGHT_EYE =  3;
    const short UPPER_LEFT = 4;
    const short LOWER_LEFT = 5;
    const short UPPER_RIGHT = 6;
    const short LOWER_RIGHT = 7;
    const short TORSO = 8;
    const short BASE = 9;

    const string WS = " ";

    // Setting up possible hats
    const string straw_hat = WS+"_===_";
    const string mexican_hat = WS+" ___\n .....";
    const string fez = WS+" _\n /_\\";
    const string russian_hat = WS+" ___\n (_*_)";

    // Setting up possible Torsos
    const string buttons = " : ";
    const string vest = "] [";
    const string inward_arms = "> <";
    const string none = "  ";

    // Setting up possible Bases, some are already defined as torsos
    const string feet = "" "";
    const string flat = "___";

    // Hat -> Left arm_1 -> Left eye -> Nose -> Right Eye -> Right_arm_1 -> Left arm 2 -> T1T2T3 -> Right arm 2 -> B1B2B3

    // Setting up possible left arms
    const string normal_left = " <";
    const string up_left = "\\ ";
    const string down_left = " /";
    const string none_left = "  ";



}