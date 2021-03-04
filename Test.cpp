/**
 * AUTHORS: Tal Zichlinsky
 * 
 * This file will test a program that takes in an eight character string
 * (via stdin or command line) in the format HNLRXYTB, where each
 * letter is a digit from 1 to 4 that denotes which preset to use for the
 * corresponding section of the snowperson.
 * 
 * H - Hat
 * N - Nose
 * L - Left eye
 * R - Right eye
 * X - Left arm
 * Y - Right arm
 * T - Torso
 * B - Base
 * 
 * Date: 2021-03
 */

#include "doctest.h"
#include "snowman.hpp"
#include <string>

using namespace ariel;
using namespace std;

// Setting up possible hats
string straw_hat = "_==_";
string mexican_hat = " ___ \n.....";
string fez = "  _  \n/_\\";
string russian_hat = "  _  \n/_\\";

// Setting up possible Torsos
string buttons = " : ";
string vest = "] [";
string inward_arms = "> <";
string none = "  ";

// Setting up possible Bases
string feet = "" "";
string flat = "___";

// Setting up possible left arms
string normal_left = "\n<";
string up_left = "\\\n";
string down_left = "\n/";
string none_arm = "\n\n";

// Setting up possible right arms
string normal_right = "\n>";
string up_right = "/\n";
string down_right = "\n\\";

string parts[8][4] = {
                        {straw_hat, mexican_hat, fez, russian_hat},
                        {",", ".", "_", " "},
                        {".", "o", "0", "-"},
                        {".", "o", "0", "-"},
                        {normal_left, up_left, down_left, none_arm},
                        {normal_right, up_right, down_right, none_arm},
                        {buttons, vest, inward_arms, none},
                        {buttons, feet, flat, none}};

TEST_CASE("Good snowman code") {
    CHECK(snowman(11114411) == "_===_\n(.,.)\n( : )\n( : )");
    

    
}

TEST_CASE("Bad snowman code") {
    
    // Too short of an expression
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));

    // Too long of an expression
    CHECK_THROWS(snowman(123412341234));
    
    // Input numbers not in range
    CHECK_THROWS(snowman(5));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(-1));

}


/* Add more test cases here */
