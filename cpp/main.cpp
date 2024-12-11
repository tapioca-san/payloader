#include "../headers/curPipe_engine.hpp"
#include <dpp/cluster.h>

#define token "your discord bot's token here"

int main(){


curPipe::netWork rede(token);
	rede.readCommandsOnChat();
	rede.perfomBot();
	

}
