#include <iostream>
#include "UrlParser.h"

UrlParser::UrlParser(const std::string& url){
    parse(url);
}

void UrlParser::parse(const std::string& url) {
    
    // Поиск пробела и проверка на его наличие в строке
    size_t pos = url.find(" ");
    if (pos != std::string::npos) {
        throw std::invalid_argument("Invalid URL: Space in URL string");
    }

    // Поиск протокола
    pos = url.find("://");
    if (pos != std::string::npos) {
        scheme = url.substr(0, pos);
        pos += 3;  // Пропускаем "://"
        if (scheme.empty()){
            throw std::invalid_argument("Invalid URL: Missing scheme");
        }

        //Проверка на корректность протокола
        for (char c : scheme) {
        // Проверяем, является ли символ английской буквой, точкой, плюсом или тире
            if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.' || c == '+' || c == '-')) {
                throw std::invalid_argument("Invalid URL: Invalid scheme");
            }
        }

    } else {
        // Проверка на отсутствие протокола
        throw std::invalid_argument("Invalid URL: Missing scheme");
    }

    // Поиск логина и пароля
    size_t at_pos = url.find('@', pos);
    size_t slash_pos = url.find('/', pos);
    if (at_pos != std::string::npos && (slash_pos == std::string::npos || at_pos < slash_pos)) {
        // Если "@" найдено и перед "/" или отсутствует "/", то это логин и пароль
        std::string login_password = url.substr(pos, at_pos - pos);
        size_t colon_pos = login_password.find(':');
        if (colon_pos != std::string::npos) {
            // Если ":" найдено, то есть логин и пароль разделены
            user = login_password.substr(0, colon_pos);
            
            //Проверка на корректность имени пользователя
            for (char c : user) {
                if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '$' || c == '-' || c == '_' || c == '~' || c == '.')) {
                    throw std::invalid_argument("Invalid URL: Invalid user");
                }
            }

            password = login_password.substr(colon_pos + 1);

            //Проверка на корректность пароля пользователя
            for (char c : password) {
                if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '$' || c == '-' || c == '_' || c == '~' || c == '.')) {
                    throw std::invalid_argument("Invalid URL: Invalid password");
                }
            }

        } else {
            
            //Иначе это только имя пользователя, пароль отсутствует
            user = login_password;

            //Проверка на корректность имени пользователя
            for (char c : user) {
                if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '$' || c == '-' || c == '_' || c == '~' || c == '.')) {
                    throw std::invalid_argument("Invalid URL: Invalid user");
                }
            }
            password = "";
        }
        pos = at_pos + 1;  // Продвигаем указатель за символ '@'
    } else {
        // Иначе логин и пароль отсутствуют
        user = "";
        password = "";
    }

    // Поиск хоста и порта
    size_t colon_pos = url.find(':', pos);
    if (colon_pos != std::string::npos && (slash_pos == std::string::npos || colon_pos < slash_pos)) {
        host = url.substr(pos, colon_pos - pos);
        
        if (colon_pos + 1 < url.size()) {
            port = url.substr(colon_pos + 1, slash_pos - colon_pos - 1);

            // Проверка на число

            //try {
                // size_t symbol_pos = 0;
                // std::stoi(port, &symbol_pos);
                // symbol_pos = port.size();

                for (char c : port) {
                     if (!isdigit(c)) {
                        throw std::invalid_argument("Invalid URL: Invalid port");
                    }
                }

            // } catch (const std::invalid_argument&) {
            //     throw std::invalid_argument("Invalid URL: Invalid port");
            // }

        } else {
            throw std::invalid_argument("Invalid URL: Missing port");
        }
    } else {
    
        // Иначе это только хост
        if (slash_pos != std::string::npos) {
            host = url.substr(pos, slash_pos - pos);
        } else {
            host = url.substr(pos);

            // Проверка на наличие хоста или пути
            if (host.empty()) {
                throw std::invalid_argument("Invalid URL: Missing host");
            }
            else {
                throw std::invalid_argument("Invalid URL: Missing path");
            }
        }
        port = "";  // Порт не указан
    }

    // Проверка на корректность хоста
    for (char c : host) {
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.')) {
            throw std::invalid_argument("Invalid URL: Invalid host");
        }
    }

    // Поиск пути
    pos = slash_pos;
    slash_pos = url.find('?', pos);
    if (slash_pos != std::string::npos) {
        path = url.substr(pos, slash_pos - pos);
        pos = slash_pos;
    } else {
        path = url.substr(pos);
        pos = url.size() - 1;
    }

    // Проверка на корректность пути
    for (char c : path) {
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '/' || c == '-' || c == '_' || c == '~' || c == '.')) {
            throw std::invalid_argument("Invalid URL: Invalid path");
        }
    }

    // Поиск строки запроса
    slash_pos = url.find('#', pos);
    if (slash_pos != std::string::npos) {
        query = url.substr(pos + 1, slash_pos - pos - 1);
        pos = slash_pos;
    } else {
        query = url.substr(pos + 1);
        pos = url.size();
    }

    // Поиск фрагмента
    if (pos < url.size()) {
        fragment = url.substr(pos + 1);
    } else {
        fragment = "";
    }
}

std::string UrlParser::getScheme() const {
    return scheme;
}

std::string UrlParser::getHost() const {
    return host;
}

std::string UrlParser::getPath() const {
    return path;
}

std::string UrlParser::getQuery() const {
    return query;
}

std::string UrlParser::getFragment() const {
    return fragment;
}

std::string UrlParser::getPort() const {
    return port;
}

std::string UrlParser::getUser() const{
    return user;
}

std::string UrlParser::getPassword() const{
    return password;
}