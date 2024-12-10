#include "../headers/curPipe_engine.hpp"
#include <dpp/cluster.h>

#define token "MTIyOTkxNDg4OTgxNzAzNDg1Ng.GrceOq.u3rTxynFv8Pli9AO5nQHBScGhNCrwCQ8-TaQAY"

int main(){


curPipe::netWork rede(token);
	rede.readCommandsOnChat();
	rede.perfomBot();
	

}
