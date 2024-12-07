#pragma once

#include "curPipe_config.hpp"
#include "curPipe_callBack.hpp"
#include <fstream>

// criar uma POO o mais rápido que conseguir : )



namespace curPipe {

    void payloader(std::string site, std::string nameOfTheFileDownloaded);

    void openFiles(std::string nameOfFiles);

    void MensageFromSite(std::string site);
    
    std::string readFiles(std::string fileLocate);
    
}