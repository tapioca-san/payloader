#pragma once

#include "curPipe_config.hpp"
#include "curPipe_callBack.hpp"
#include "curPipe_functions.hpp"
#include "curPipe_textFunction.hpp"
#include <dpp/cluster.h>


namespace curPipe {

    class netWork{

        private:

        bool deBugger;
        std::string cleanedMensage;
        dpp::cluster bot;

        public:

            netWork(std::string token);
            ~netWork();

            void readCommandsOnChat();

            void perfomBot();

    };


}