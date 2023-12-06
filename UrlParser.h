#ifndef URL_PARSER_HH
#define URL_PARSER_HH

#include <string>

class UrlParser {
    public:
        UrlParser(const std::string& url);
    
        std::string getScheme() const;
        std::string getHost() const;
        std::string getPath() const;
        std::string getQuery() const;
        std::string getFragment() const;
        std::string getPort() const;
        std::string getUser() const;
        std::string getPassword() const;

    private:
        void parse(const std::string& url);

        std::string scheme;
        std::string host;
        std::string path;
        std::string query;
        std::string fragment;
        std::string port;
        std::string user;
        std::string password;
};

#endif