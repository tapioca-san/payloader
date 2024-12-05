#pragma once

#include "curPipe_config.hpp"
#include "curPipe_callBack.hpp"
#include "curPipe_functions.hpp"
#include "curPipe_discordBot.hpp"
#include "curPipe_textFunction.hpp"
#include <dpp/cluster.h>


namespace curPipe {

    class netWork{

        private:

	
        dpp::cluster bot;

        public:

            netWork(std::string token);
            ~netWork();

            void readCommandsOnChat();

            void perfomBot();

    };


}