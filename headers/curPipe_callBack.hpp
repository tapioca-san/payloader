#pragma once

#include "curPipe_config.hpp"

namespace curPipe {

    size_t CookieCallback(void* contents, size_t size, size_t nmemb, void* userp);

    size_t writeCallback(void* ptr, size_t size, size_t nmemb, void* userdata);
}





/*

refatore e estude |
                  |
                  |
                  V


void getFirefoxCookies(const std::string& firefoxProfilePath) {
    // Caminho para o banco de dados de cookies do Firefox
    std::string dbPath = firefoxProfilePath + "/cookies.sqlite";
    
    sqlite3* db;
    sqlite3_stmt* stmt;
    
    // Abre o banco de dados SQLite
    if (sqlite3_open(dbPath.c_str(), &db)) {
        std::cerr << "Erro ao abrir banco de dados: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Consulta SQL para obter cookies
    const char* query = "SELECT name, value FROM moz_cookies WHERE host LIKE '%roblox.com%'";

    // Prepara a consulta SQL
    if (sqlite3_prepare_v2(db, query, -1, &stmt, 0) != SQLITE_OK) {
        std::cerr << "Erro ao preparar consulta: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Executa a consulta e imprime os cookies
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const char* cookieName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
        const char* cookieValue = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        
        std::cout << "Cookie: " << cookieName << " = " << cookieValue << std::endl;
    }

    // Libera recursos
    sqlite3_finalize(stmt);
    sqlite3_close(db);
}

int main() {
    std::string firefoxProfilePath = "/home/usuario/.mozilla/firefox/[perfil]"; // Substitua pelo seu perfil do Firefox
    getFirefoxCookies(firefoxProfilePath);
    
    return 0;
}

*/