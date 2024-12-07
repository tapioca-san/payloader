#pragma once

#include "curPipe_config.hpp"

namespace curPipe {

    size_t CookieCallback(void* contents, size_t size, size_t nmemb, void* userp);

    size_t filewriteCallback(void* ptr, size_t size, size_t nmemb, void* userdata);

    size_t mensageWriteCallback(void *contents, size_t size, size_t nmemb, std::string *buffer);

}




