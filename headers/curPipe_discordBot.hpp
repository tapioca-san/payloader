#include "curPipe_config.hpp"


namespace curPipe {


    class MyBot {
    public:
        dpp::cluster bot;

        MyBot(const std::string &token);
    };

}