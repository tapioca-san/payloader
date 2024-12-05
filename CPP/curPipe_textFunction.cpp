#include "../headers/curPipe_textFunction.hpp"


namespace curPipe {


    

    bool findWordsOnString(std::string mensageContent, std::string phraseToFind){
        std::string lastMensage = mensageContent;
        size_t pos = lastMensage.find(phraseToFind);
        if (pos != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }

    std::string cleanWordsOnString(std::string mensageContent, std::string phraseToClean, bool is_url) {
        std::string lastMensage = mensageContent;

        size_t pos = lastMensage.find(phraseToClean);

        if (pos != std::string::npos) {
            lastMensage = lastMensage.substr(pos + phraseToClean.length() +1);
        }
        if (!is_url){
        return lastMensage;
        }
        else {
        return "https://" + lastMensage;
        }
    }


}