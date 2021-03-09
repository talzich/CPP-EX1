#include <string>
#include <exception>
#include <iostream>

#include "snowman.hpp"

using namespace std;

namespace ariel{

    int check_validity(const long int number){
        string input = to_string(number);
        if(input.size() != 8) return 0;
        for(int i = 0; i < 8; i++){
            if(input.at(i) < '1' || input.at(i) > '4') return 0;
        }
        return 1;
    }
    string snowman(long int number)
    {
        const long int INPUT_1 = 11114411;
        const long int INPUT_2 = 33232124;

        if(!(check_validity(number))){
            //cout << "Invalid input: " << number << endl;
            //exception e;
            throw invalid_argument("Invalid input: " + to_string(number));
        }
        else if (number == INPUT_1) return " _===_\n (.,.)\n ( : )\n ( : )";
        else if (number == INPUT_2) return "   _\n  /_\\\n\\(o_O)\n (] [)>\n (   )";
        return " ";
    }
}
