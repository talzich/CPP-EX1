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
#include <iostream>

using namespace ariel;
using namespace std;

#define CHECK_THROWS DOCTEST_CHECK_THROWS

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
                        {straw_hat, mexican_hat, fez, russian_hat}, // Hats
                        {",", ".", "_", " "}, // Noses
                        {".", "o", "0", "-"}, // Left eye
                        {".", "o", "0", "-"}, // Right eye
                        {normal_left, up_left, down_left, none_arm}, // Left arms
                        {normal_right, up_right, down_right, none_arm}, // Right arms
                        {buttons, vest, inward_arms, none}, // Torsos
                        {buttons, feet, flat, none}}; // Bases


enum bad_inputs{ too_long, too_short, too_high, too_low};

int produce_long_input(){
    int c;
    string input = "";
    for (int i = 0; i < 10; i++){
                c = 1 + (rand() % 4); // Generating a random digit between 1 and 4 
                input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);
}

int produce_short_input(){
    int c;
    string input = "";
    for (int i = 0; i < 5; i++){
                c = 1 + (rand() % 4); // Generating a random digit between 1 and 4 
                input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);
}

int produce_high_input(){

    int c;
    string input = "";
    for (int i = 0; i < 8; i++){
        c = 5 + (rand() % 5); // Generating a random digit between 5 and 9 
        input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);

}

int produce_low_input(){

    int c;
    string input = "";
    for (int i = 0; i < 8; i++){
        c = (-1)*(rand() % 9); // Generating a random digit between 0 and -9 
        input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);

}

/* This method will produce a random valid input for the snowman method */
int produce_valid_input(){

    int c;
    string input = "";
    for (int i = 0; i < 8; i++){
        c = 1 + (rand() % 4); // Generating a random digit between 1 and 4 
        input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);

}

/* 
    This method will produce an invalid random invalid input for the snowman method. 
    The input could be too long, too short or digits not in the correct range. 
    The type of bad input is also set randomly
*/
int produce_invalid_input(){
    
    int type, input; // type will be the type of invalid input
    string str = "";// We will use that string to concatinate numbers 

    type = rand() % 4;
    switch (type){
        case too_long:
            return produce_long_input();
        case too_short:
            return produce_short_input();
        case too_high:
            return produce_high_input();
        case too_low:
            return produce_low_input();

    }
    return 0;
}

/* This method takes the input ariel::snowman was given and produces a broken up snowman so we could
   later compare the parts to the actual output ariel::snowman provided*/ 

string* break_snowman(const int input){
 
    string *broken = new string[8];
    string str_input = to_string(input);

    for(int i = 0; i < str_input.size(); i++){
        int j = (str_input.at(i) - '0');
        broken[i] = parts[i][j];
    }

    return broken;
}

/*  This method takes the acutual output ariel::snowman produced and compares it to the broken snowman
    we produced earlier */
int compare_snowmans(string output, string *broken){}

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

    for(int i = 0; i < 25; i++){
        CHECK_THROWS(snowman(produce_short_input()));
    }

    // Too long of an expression
    CHECK_THROWS(snowman(123412341234));

    for(int i = 0; i < 25; i++){
        CHECK_THROWS(snowman(produce_long_input()));
    }
    
    // Input numbers not in range
    CHECK_THROWS(snowman(5));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(-1));
    for(int i = 0; i < 25; i++){
        CHECK_THROWS(snowman(produce_low_input()));
        CHECK_THROWS(snowman(produce_high_input()));
    }

    // Check for general bad input
    for(int i = 0; i < 1000; i++){
        CHECK_THROWS(snowman(produce_invalid_input()));
    }
}
