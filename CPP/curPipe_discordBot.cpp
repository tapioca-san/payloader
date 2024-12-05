#include "../headers/curPipe_discordBot.hpp"

namespace curPipe {

    
    MyBot::MyBot(const std::string &token) : bot(token, 1){
                bot.intents |= dpp::i_message_content;

                bot.on_message_create([this](const dpp::message_create_t &event) {
                    if (event.msg.author.is_bot()) return;
                    std::cout << event.msg.content << std::endl;
                });

                bot.start(dpp::st_wait);
            }
}