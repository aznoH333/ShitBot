#ifndef BOT
#define BOT

#include <iostream>
#include <vector>
#include <map>



enum KEY_WORD{
    WHERE = 5,
    HOW = 3,
    RANDOM = 7,
    NAME = 11,
    IS = 1,
    COMPLIMENT = 2,
    INSULT = 9,
    INTRO = 8,
    GREET = 10,
    FAIL = 0,
    WHO = 4,
    MAMA = -1,
    WHY = 6,
};

class Bot{
    private:
        std::map<std::string, KEY_WORD> key_words;
        std::map<KEY_WORD, std::vector<std::string>> responses;



        
        std::vector<KEY_WORD> analyze_input(std::string input);
        KEY_WORD guess_meaning(std::vector<KEY_WORD> key_words);
        void respond(KEY_WORD task);

    public:
        Bot();

        void ask_question(std::string input);
};

#endif