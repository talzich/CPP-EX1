/*
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
 * X - Left arm - Will be split to upper arm (UX) and lower arm (LX)
 * Y - Right arm - Will be split to upper arm (UY) and lower arm (LY)
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

using namespace ariel;
using namespace std;

#define CHECK_THROWS DOCTEST_CHECK_THROWS

enum bad_inputs{ too_long, too_short, too_high, too_low};

const int LONG_INPUT_LENGTH = 10;
const int SHORT_INPUT_LENGTH = 5;
const int GOOD_INPUT_LENGTH = 8;
const int NUM_OF_TESTS = 25;

// The next 4 methods produce bad inputs of different types
int produce_long_input(){
    int c;
    string input = "";
    for (int i = 0; i < LONG_INPUT_LENGTH; i++){
                c = 1 + (rand() % 4); // Generating a random digit between 1 and 4 
                input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);
}

int produce_short_input(){
    int c;
    string input = "";
    for (int i = 0; i < SHORT_INPUT_LENGTH; i++){
                c = 1 + (rand() % 4); // Generating a random digit between 1 and 4 
                input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);
}

int produce_high_input(){

    int c;
    string input = "";
    for (int i = 0; i < GOOD_INPUT_LENGTH; i++){
        c = 5 + (rand() % 5); // Generating a random digit between 5 and 9 
        input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);

}

int produce_low_input(){

    int c;
    string input = "";
    for (int i = 0; i < GOOD_INPUT_LENGTH; i++){
        c = (-1)*(rand() % 9); // Generating a random digit between 0 and -9 
        input += to_string(c);; // Converting the random digit to a char and concatinating it to the string 
    }
    return stoi(input);

}

/* This method will produce a random valid input for the snowman method */
int produce_valid_input(){
    int c;
    string input = "";
    for (int i = 0; i < GOOD_INPUT_LENGTH; i++){
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
    string str = "";// We will use that string to concatenate numbers 

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

/*
    This method takes output from ariel::snowman() and the parts corresponding
    with input in the shape of an array named broken. 
    The method iterates through the output, char by char, and compares to 
    the corresponding chars in the 'broken' array, taking in to consideration 
    the proper format of a snowman (properly placed parenthesis, '\n' and spaces)

*/
bool check_snowman(string output, string *broken){

    cout << "### Now checking the following snowman ###\n" << output << endl;
    int index; // Will iterate through the output

    // Length of possible hats is not constant
    // We have the correct hat in broken[0]. So, we will iterate through the 
    // first chars of output and compare, char by char, to broken[0].
    for(index = 0; index < broken[HAT].size(); index++){
        if(broken[HAT].at(index) != output.at(index)) return false;
    }
    if(output.at(index++) != '\n') return false; //Getting past '\n'

    // Comparing upper left arm
    if(output.at(index++) != broken[LEFT_ARM].at(UP)) return false;

    // Comparing the face
    int first_char = 0;
    if(output.at(index++) != '(') return false;
    if(output.at(index++) != broken[LEFT_EYE].at(first_char)) return false;
    if(output.at(index++) != broken[NOSE].at(first_char)) return false;
    if(output.at(index++) != broken[RIGHT_EYE].at(first_char)) return false;
    if(output.at(index++) != ')') return false; // Getting past ')'

    // Comparing upper right arm
    if(output.at(index++) != broken[RIGHT_ARM].at(UP)) return false;
    if(output.at(index++) != '\n') return false; //Getting past '\n'

    // Comparing lower left arm
    if(output.at(index++) != broken[LEFT_ARM].at(DOWN)) return false;

    // Comparing torso
    int torso_iter = 0;
    if(output.at(index++) != '(') return false; //Getting past '('
    while(torso_iter < 3){
        if(output.at(index++) != broken[TORSO].at(torso_iter++)) return false;
    }
    if(output.at(index++) != ')') return false; //Getting past ')'

    // Comparing lower right arm
    if(output.at(index++) != broken[RIGHT_ARM].at(DOWN)) return false;
    if(output.at(index++) != '\n') return false; //Getting past '\n'
    if(output.at(index++) != WS.at(first_char)) return false; //Getting past one white space preceding to base

    // Comparing base
    int base_iterator = 0;
    if(output.at(index++) != '(') return false; //Getting past '('
    while(base_iterator < 3){
        if(output.at(index++) != broken[BASE].at(base_iterator++)) return false;
    }
    if(output.at(index++) != ')') return false; //Getting past ')'
    
    cout << "### Passed comparison ###\n" << endl;
    return true;
}

TEST_CASE("Good snowman code") {
    
    string *broken = fetch_parts(11114411);
    CHECK(check_snowman(snowman(11114411), broken));

    broken = fetch_parts(33232124);
    CHECK(check_snowman(snowman(33232124), broken));
    
    int input;
    for(int i = 0; i < NUM_OF_TESTS; i++){
        input = produce_valid_input();
        broken = fetch_parts(input);
        CHECK(check_snowman(snowman(input), broken));
    }
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

    for(int i = 0; i < NUM_OF_TESTS; i++){
        CHECK_THROWS(snowman(produce_short_input()));
    }

    // Too long of an expression
    CHECK_THROWS(snowman(123412341234));

    for(int i = 0; i < NUM_OF_TESTS; i++){
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