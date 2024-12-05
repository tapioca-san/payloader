#include "curPipe_config.hpp"
#include <string>

namespace curPipe {

    bool findWordsOnString(std::string mensageContent, std::string phraseToFind);

    std::string cleanWordsOnString(std::string mensageContent, std::string phraseToClean, bool is_url = false);


}