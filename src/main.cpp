#include <iostream>
#include <bot.h>
#include <iostream>

int main()
{

    Bot bot;

    while (true){
        std::string input = "";
        getline(std::cin, input);

        bot.ask_question(input += " ");
        std::cout << std::endl;
    }
    
    return 0;
}
