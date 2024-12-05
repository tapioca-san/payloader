#include "../headers/curPipe_functions.hpp"

namespace curPipe {

    void payloader(std::string site, std::string nameOfTheFileDownloaded){
    
        CURLcode res = curl_global_init(CURL_GLOBAL_ALL);
        if (res != CURLE_OK) {
            std::cerr << "Erro ao iniciar a configuração global do libcurl. \n";
            
        }

        CURL* handle = curl_easy_init();
        if (!handle) {
            std::cerr << "Erro ao inicializar o libcurl. \n";
            curl_global_cleanup();
            
        }
        std::ofstream outfile(nameOfTheFileDownloaded, std::ios::binary);
            if (!outfile){
                std::cerr << "erro ao criar o arquivo de saida \n";
                curl_easy_cleanup(handle); 
            }
        

        res = curl_easy_setopt(handle, CURLOPT_URL, site.c_str());
        if (res != CURLE_OK) {
            std::cerr << "Erro ao configurar a URL. \n";
            curl_easy_cleanup(handle);
            curl_global_cleanup();
            
        }

        res = curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, curPipe::writeCallback);
        if (res != CURLE_OK) {
            std::cerr << "Erro ao configurar a função de callback. \n";
            curl_easy_cleanup(handle);
            curl_global_cleanup();
            
        }

        res = curl_easy_setopt(handle, CURLOPT_WRITEDATA, &outfile);
        if (res != CURLE_OK) {
            std::cerr << "Erro ao configurar o destino dos dados recebidos. \n";
            curl_easy_cleanup(handle);
            curl_global_cleanup();
            
        }

        res = curl_easy_perform(handle);
        if (res != CURLE_OK) {
            std::cerr << "Erro ao realizar a requisição HTTP: " << curl_easy_strerror(res) << "\n";
            curl_easy_cleanup(handle);
            curl_global_cleanup();
            
        }

            outfile.close();
        

            curl_easy_cleanup(handle);
            curl_global_cleanup();
        
    }




    void openFiles(std::string nameOfFiles){

        std::ifstream file;

        file.open(nameOfFiles, std::ios::in | std::ios::binary);

        if (!file.is_open()){
            std::cerr << "erro ao abrir \n";	
        }
    }
}