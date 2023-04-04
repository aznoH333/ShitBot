#include <bot.h>
#include <string>
#include <vector>
#include <random>


Bot::Bot(){
    // load keywords
    key_words.insert(std::pair("kde", WHERE));

    key_words.insert(std::pair("jak", HOW));
    key_words.insert(std::pair("kolik", HOW));

    key_words.insert(std::pair("neco", RANDOM));
    key_words.insert(std::pair("nahodneho", RANDOM));
    key_words.insert(std::pair("nahodny", RANDOM));

    key_words.insert(std::pair("jmenuje", NAME));
    key_words.insert(std::pair("nazyva", NAME));
    key_words.insert(std::pair("rika", NAME));
    key_words.insert(std::pair("oslovuje", NAME));

    key_words.insert(std::pair("nadavka", INSULT));
    key_words.insert(std::pair("nadavku", INSULT));
    key_words.insert(std::pair("picovinu", INSULT));
    key_words.insert(std::pair("sracku", INSULT));
    key_words.insert(std::pair("kokot", INSULT));
    key_words.insert(std::pair("penis", INSULT));
    key_words.insert(std::pair("debil", INSULT));
    key_words.insert(std::pair("kreten", INSULT));
    key_words.insert(std::pair("picus", INSULT));


    key_words.insert(std::pair("hezkeho", COMPLIMENT));
    key_words.insert(std::pair("dobreho", COMPLIMENT));
    key_words.insert(std::pair("prijemneho", COMPLIMENT));
    key_words.insert(std::pair("pekneho", COMPLIMENT));
    key_words.insert(std::pair("lichothneho", COMPLIMENT));

    key_words.insert(std::pair("je", IS));
    key_words.insert(std::pair("existuje", IS));
    key_words.insert(std::pair("umi", IS));
    key_words.insert(std::pair("dokaze", IS));

    key_words.insert(std::pair("jsi", INTRO));
    key_words.insert(std::pair("jmenujes", INTRO));


    key_words.insert(std::pair("ahoj", GREET));
    key_words.insert(std::pair("zdravim", GREET));
    key_words.insert(std::pair("cus", GREET));
    key_words.insert(std::pair("cauves", GREET));
    key_words.insert(std::pair("ahojda", GREET));
    key_words.insert(std::pair("oi", GREET));
    key_words.insert(std::pair("oy", GREET));
    key_words.insert(std::pair("oj", GREET));

    key_words.insert(std::pair("kdo", WHO));
    
    key_words.insert(std::pair("mama", MAMA));
    key_words.insert(std::pair("mame", MAMA));
    key_words.insert(std::pair("matka", MAMA));
    key_words.insert(std::pair("macecha", MAMA));
    key_words.insert(std::pair("maminka", MAMA));
    key_words.insert(std::pair("maticka", MAMA));

    key_words.insert(std::pair("proc", WHY));


    // load responses
    responses[GREET].push_back("Zdravim, pojdme diskutovat tvoji mamu.");
    responses[GREET].push_back("Ahoj, pojdme si povidat o tvoji mame.");
    responses[GREET].push_back("Zdar. Chci se bavit o tvoji mame.");

    responses[INTRO].push_back("Moje jmeno je CBT bot a nehodlam mluvit o nicem jinem nez tvoji mame.");
    responses[INTRO].push_back("Jsem CBT bot. Umim konverzovat jen o tvoji mame.");

    responses[IS].push_back("Je to mozne.");
    responses[IS].push_back("Rozhodne ano.");
    responses[IS].push_back("Nepochybne.");
    responses[IS].push_back("To neni pravda.");
    responses[IS].push_back("To je nepravdepodobne.");

    responses[INSULT].push_back("Ne, tvoje mama.");
    responses[INSULT].push_back("Tvoje mama je pica.");



    responses[NAME].push_back("Tvoje mama nema jmeno.");
    responses[NAME].push_back("Jmeno tvoji matky bylo zapomenuto.");
    responses[NAME].push_back("Ani buh nevi jak se jmenuje tovje mama.");

    responses[WHERE].push_back("Nekde.");
    responses[WHERE].push_back("6 metru v podzemi.");
    responses[WHERE].push_back("V moji posteli.");
    responses[WHERE].push_back("Na onem svete.");
    responses[WHERE].push_back("V nemeckem fekal pornu");

    responses[FAIL].push_back("Nehodlam mluvit o nicem jine nez o tvoji mame");
    responses[FAIL].push_back("Nevidim jak to navazuje na tvoji mamu");
    responses[FAIL].push_back("Nerozumim zeptej se me na tvoji mamu");

    responses[RANDOM].push_back("Tvoje mama nikdy nebyla na mesici");
    responses[RANDOM].push_back("Tvoje mama neni az tak tlusta.");
    responses[RANDOM].push_back("Tvoje mama je jenom trochu stara.");
    responses[RANDOM].push_back("Tvoje mama stara.");
    responses[RANDOM].push_back("Tvoje mama umrela v roce 2005.");
    responses[RANDOM].push_back("Tvoje mama si predobjednala bibli.");
    responses[RANDOM].push_back("Ani Chuck Noris neuzvedne tvoji mamu.");

    responses[WHO].push_back("Tvoje mama.");

    responses[HOW].push_back("Tvoje mama je az moc stara");
    responses[HOW].push_back("Tvoje mama je starsi nez buh");
    responses[HOW].push_back("Tvoje mama zazila dinosaury");

    responses[WHY].push_back("Ja nevim.");
    responses[WHY].push_back("Protoze tvoje mama je tlusta.");
    responses[WHY].push_back("Protoze tvoje mama je stara.");
    responses[WHY].push_back("Protoze tvoje mama je skareda.");



}


void Bot::ask_question(std::string input){
    respond(guess_meaning(analyze_input(input)));
}


std::vector<KEY_WORD> Bot::analyze_input(std::string input){
    std::vector<KEY_WORD> output;
    std::string word = "";

    for (char c : input){
        if (c != ' '){
            word += c;
        }else {
            // evaluate word
            if (key_words.find(word) != key_words.end()){
                output.push_back(key_words[word]);
            }

            word = "";
        }


    }

    return output;
}

KEY_WORD Bot::guess_meaning(std::vector<KEY_WORD> key_words){
    std::map<KEY_WORD, int> values;

    for (KEY_WORD k : key_words){
        if (values.find(k) == values.end()){
            values[k] = k;
        }else{
            values[k] *= k;
        }
    }

    // get the highest result
    std::pair<KEY_WORD, int> best_match = std::pair(FAIL, 0); 
    bool is_related_to_your_mother = false;
    for (std::pair p : values){
        if (p.second == MAMA) is_related_to_your_mother = true;
        if (p.second > best_match.second){
            best_match = p;
        }
    }

    if (!is_related_to_your_mother
    && best_match.second != INSULT 
    && best_match.second != GREET 
    && best_match.second != RANDOM
    && best_match.second != INTRO){
        return FAIL;
    }

    return best_match.first;
}

void Bot::respond(KEY_WORD task){

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,responses[task].size()-1);

    std::cout << responses[task][dist(rng)] << std::endl;
}