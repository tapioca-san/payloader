#include "../headers/curPipe_callBack.hpp"

namespace curPipe {

    size_t CookieCallback(void* contents, size_t size, size_t nmemb, void* userp){
    std::string* cookies = static_cast<std::string*>(userp);
    cookies->append(static_cast<char*>(contents), size * nmemb);
    return size * nmemb;
    };

    size_t filewriteCallback(void* ptr, size_t size, size_t nmemb, void* userdata) {
        std::ofstream* outStream = static_cast<std::ofstream*>(userdata);
        size_t totalSize = size * nmemb;
        if (outStream->is_open()) {
            outStream->write(static_cast<char*>(ptr), totalSize);
        }
        return totalSize;
    };


    size_t mensageWriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer) {
        size_t totalSize = size * nmemb;
        buffer->append(static_cast<char*>(contents), totalSize);
        return totalSize;
    }

}