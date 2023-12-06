#include <iostream>
#include "UrlParser.h"

void testParseUrl() {
    UrlParser parser("http://example.com/path?query#fragment");

    // Тесты для функции getScheme 
    if (parser.getScheme() == "http") {
        std::cout << "Test 1 Passed: getScheme() http = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() http = " << parser.getScheme() << std::endl;
    }

    // Тесты для функции getHost
    if (parser.getHost() == "example.com") {
        std::cout << "Test 2 Passed: getHost() example.com = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getHost() example.com = " << parser.getHost() << std::endl;
    }

    // Тесты для функции getPath
    if (parser.getPath() == "/path") {
        std::cout << "Test 3 Passed: getPath() /path = " << parser.getPath() << std::endl;
    } else {
        std::cout << "Test 3 Failed: getPath() /path = " << parser.getPath() << std::endl;
    }

}

void testParseUrlFull() {
    UrlParser parser("https://login:password@example.com:8080/path?query=123#fragment");

    // Тесты для функции getScheme
    if (parser.getScheme() == "https") {
        std::cout << "Test 1 Passed: getScheme() https = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() https = " << parser.getScheme() << std::endl;
    }

    // Тесты для функции getLogin
    if (parser.getUser() == "login") {
        std::cout << "Test 2 Passed: getUser() login = " << parser.getUser() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getUser() login = " << parser.getUser() << std::endl;
    }

    // Тесты для функции getPassword
    if (parser.getPassword() == "password") {
        std::cout << "Test 3 Passed: getPassword() password = " << parser.getPassword() << std::endl;
    } else {
        std::cout << "Test 3 Failed: getPassword() password = " << parser.getPassword() << std::endl;
    }

    // Тесты для функции getHost
    if (parser.getHost() == "example.com") {
        std::cout << "Test 4 Passed: getHost() example.com = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 4 Failed: getHost() example.com = " << parser.getHost() << std::endl;
    }

    // Тесты для функции getPort
    if (parser.getPort() == "8080") {
        std::cout << "Test 5 Passed: getPort() 8080 = " << parser.getPort() << std::endl;
    } else {
        std::cout << "Test 5 Failed: getPort() 8080 = " << parser.getPort() << std::endl;
    }

    // Тесты для функции getPath
    if (parser.getPath() == "/path") {
        std::cout << "Test 6 Passed: getPath() /path = " << parser.getPath() << std::endl;
    } else {
        std::cout << "Test 6 Failed: getPath() /path = " << parser.getPath() << std::endl;
    }

    // Тесты для функции getQuery
    if (parser.getQuery() == "query=123") {
        std::cout << "Test 7 Passed: getQuery() query=123 = " << parser.getQuery() << std::endl;
    } else {
        std::cout << "Test 7 Failed: getQuery() query=123 = " << parser.getQuery() << std::endl;
    }

    // Тесты для функции getFragment
    if (parser.getFragment() == "fragment") {
        std::cout << "Test 8 Passed: getFragment() fragment = " << parser.getFragment() << std::endl;
    } else {
        std::cout << "Test 8 Failed: getFragment() fragment = " << parser.getFragment() << std::endl;
    }
}

void testParseUrlQuery(){
    UrlParser parser("https://login:password@example.com:8080/path?query=123");

    // Тесты для функции getQuery
    if (parser.getQuery() == "query=123") {
        std::cout << "Test 1 Passed: getQuery() query=123 = " << parser.getQuery() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getQuery() query=123 = " << parser.getQuery() << std::endl;
    }

    std::cout<< parser.getQuery() << " | " << parser.getFragment() << std::endl;
}

void testParseUrlWiki(){
    UrlParser parser("https://ru.wikipedia.org/wiki/URL");
    if (parser.getScheme() == "https") {
        std::cout << "Test 1 Passed: getScheme() https = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() https = " << parser.getScheme() << std::endl;
    }

    if (parser.getHost() == "ru.wikipedia.org"){
        std::cout << "Test 2 Passed: getHost() ru.wikipedia.org = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getHost() ru.wikipedia.org = " << parser.getHost() << std::endl;
    }

    if (parser.getPath() == "/wiki/URL"){
        std::cout << "Test 3 Passed: getPath() /wiki/URL = " << parser.getPath() << std::endl;
    } else {
        std::cout << "Test 3 Failed: getPath() /wiki/URL = " << parser.getPath() << std::endl;
    }
}

void testParseUrlEmptyScheme(){
    UrlParser parser("example.com/path?query#fragment");

    // Тесты для функции getScheme
    if (parser.getScheme() == "") {
        std::cout << "Test 1 Passed: getScheme() http = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() http = " << parser.getScheme() << std::endl;
    }

    // Тесты для функции getHost
    if (parser.getHost() == "example.com") {
        std::cout << "Test 2 Passed: getHost() example.com = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getHost() example.com = " << parser.getHost() << std::endl;
    }

    // Тесты для функции getPath
    if (parser.getPath() == "/path") {
        std::cout << "Test 3 Passed: getPath() /path = " << parser.getPath() << std::endl;
    } else {
        std::cout << "Test 3 Failed: getPath() /path = " << parser.getPath() << std::endl;
    }
}

void testParseUrlEmptyHost(){
    UrlParser parser("http://");

    // Тесты для функции getScheme
    if (parser.getScheme() == "http") {
        std::cout << "Test 1 Passed: getScheme() http = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() http = " << parser.getScheme() << std::endl;
    }

    // Тесты для функции getHost
    if (parser.getHost() == "") {
        std::cout << "Test 2 Passed: getHost() example.com = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getHost() example.com = " << parser.getHost() << std::endl;
    }

}

void testParseEmptyUrl(){
    UrlParser parser("https://ya.ru");

    // Тесты для функции getScheme
    if (parser.getScheme() == "https") {
        std::cout << "Test 1 Passed: getScheme() https = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() https = " << parser.getScheme() << std::endl;
    }

    // Тесты для функции getHost
    if (parser.getHost() == "ya.ru") {
        std::cout << "Test 2 Passed: getHost() ya.ru = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getHost() ya.ru = " << parser.getHost() << std::endl;
    }

    // Тесты для функции getPath
    if (parser.getPath() == "") {
        std::cout << "Test 3 Passed: getPath() '' =:" << parser.getPath() << std::endl;
    } else {
        std::cout << "Test 3 Failed: getPath() '' =:" << parser.getPath() << std::endl;
    }
}

void testParseUrlInvalidPort(){
    UrlParser parser("http://example.com:loBo/path?query#fragment");

    // Тесты для функции getScheme
    if (parser.getScheme() == "http") {
        std::cout << "Test 1 Passed: getScheme() http = " << parser.getScheme() << std::endl;
    } else {
        std::cout << "Test 1 Failed: getScheme() http = " << parser.getScheme() << std::endl;
    }

    // Тесты для функции getHost
    if (parser.getHost() == "example.com") {
        std::cout << "Test 2 Passed: getHost() example.com = " << parser.getHost() << std::endl;
    } else {
        std::cout << "Test 2 Failed: getHost() example.com = " << parser.getHost() << std::endl;
    }

    // Тесты для функции getPort
    if (parser.getPort() == "loBo") {
        std::cout << "Test 5 Passed: getPort() loBo = " << parser.getPort() << std::endl;
    } else {
        std::cout << "Test 5 Failed: getPort() loBo = " << parser.getPort() << std::endl;
    }

    // Тесты для функции getPath
    if (parser.getPath() == "/path") {
        std::cout << "Test 3 Passed: getPath() /path = " << parser.getPath() << std::endl;
    } else {
        std::cout << "Test 3 Failed: getPath() /path = " << parser.getPath() << std::endl;
    }
}

int main() {
    // std::cout << "Start Test testParseUrl:" << std::endl;
    // testParseUrl();
    // std::cout << std::endl << "Start Test testParseUrlFull:" << std::endl;
    // testParseUrlFull();
    // std::cout << std::endl << "Start Test testParseUrlQuery:" << std::endl;
    // testParseUrlQuery();
    // std::cout << std::endl << "Start Test testParseUrlWiki:" << std::endl;
    // testParseUrlWiki();
    // // std::cout << std::endl << "Start Test testParseUrlEmptyScheme:" << std::endl;
    // // testParseUrlEmptyScheme();
    // // std::cout << std::endl << "Start Test testParseUrlEmptyHost:" << std::endl;
    // // testParseUrlEmptyHost();
    // std::cout << std::endl << "Start Test testParseEmptyUrl:" << std::endl;
    // testParseEmptyUrl();
    // std::cout << std::endl << "Start Test testParseUrlInvalidPort:" << std::endl;
    // testParseUrlInvalidPort();
    // std::cout << std::endl << "Exit." << std::endl;

    std::string scheme_chek = "Ht1-3t.p3+2.4s";
    int i = 0;
    for (char c : scheme_chek) {
        // Проверяем, является ли символ английской буквой, точкой, плюсом или тире
        if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '.' || c == '+' || c == '-')) {
            std::cout << c << " " << i++ << std::endl;
        }
    }

    i = 0;
    std::string prot_chek = "t:8080/";
    size_t colon_pos = prot_chek.find(':');
    size_t slash_pos = prot_chek.find('/');
    if (colon_pos != std::string::npos) {
        std::string host = prot_chek.substr(0, colon_pos);
        std::cout << host << std::endl;
        if (colon_pos + 1 < prot_chek.size()) {
            std::string port = prot_chek.substr(colon_pos + 1, slash_pos - colon_pos - 1);
            std::cout << port << std::endl;
            for (char c : port) {
                if (!isdigit(c)) {
                    std::cout << c << " " << i++ << std::endl;
                }
            }
        }
    }
    return 0;
}
// http://www.example.com:8080/path/to/page?query=123#fragment;
// https://ru.wikipedia.org/wiki/URL
// https://marketplace.visualstudio.com/items?itemName=twxs.cmake