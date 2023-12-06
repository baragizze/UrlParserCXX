#include <iostream>
#include "UrlParser.h"
#include "gtest/gtest.h"

TEST(UrlParserTest, ParseUrl) {
    UrlParser parser("http://example.com/path?query#fragment");

    EXPECT_EQ(parser.getScheme(), "http");
    EXPECT_EQ(parser.getUser(), "");
    EXPECT_EQ(parser.getPassword(), "");
    EXPECT_EQ(parser.getHost(), "example.com");
    EXPECT_EQ(parser.getPort(), "");
    EXPECT_EQ(parser.getPath(), "/path");
    EXPECT_EQ(parser.getQuery(), "query");
    EXPECT_EQ(parser.getFragment(), "fragment");
}

TEST(UrlParserTest, ParseUrlStrangeScheme) {
    UrlParser parser("Ht1-0t.p3+2.4s://example.com/path?query#fragment");

    EXPECT_EQ(parser.getScheme(), "Ht1-0t.p3+2.4s");
    EXPECT_EQ(parser.getUser(), "");
    EXPECT_EQ(parser.getPassword(), "");
    EXPECT_EQ(parser.getHost(), "example.com");
    EXPECT_EQ(parser.getPort(), "");
    EXPECT_EQ(parser.getPath(), "/path");
    EXPECT_EQ(parser.getQuery(), "query");
    EXPECT_EQ(parser.getFragment(), "fragment");
}

TEST(UrlParserTest, ParseUrlBadScheme) {
    try {
        UrlParser parser("ht,tp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("ht tp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Space in URL string"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("%http://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("htt(p://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("http:://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("ht}tp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("ht*tp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("h^ttp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("http&://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("ht#tp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("h@ttp://example.com/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlWithPort) {
    UrlParser parser("http://example.com:8080/path?query#fragment");

    EXPECT_EQ(parser.getScheme(), "http");
    EXPECT_EQ(parser.getUser(), "");
    EXPECT_EQ(parser.getPassword(), "");
    EXPECT_EQ(parser.getHost(), "example.com");
    EXPECT_EQ(parser.getPort(), "8080");
    EXPECT_EQ(parser.getPath(), "/path");
    EXPECT_EQ(parser.getQuery(), "query");
    EXPECT_EQ(parser.getFragment(), "fragment");
}

TEST(UrlParserTest, ParseUrl_Wiki) {
    UrlParser parser("https://ru.wikipedia.org/wiki/URL");

    EXPECT_EQ(parser.getScheme(), "https");
    EXPECT_EQ(parser.getUser(), "");
    EXPECT_EQ(parser.getPassword(), "");
    EXPECT_EQ(parser.getHost(), "ru.wikipedia.org");
    EXPECT_EQ(parser.getPort(), "");
    EXPECT_EQ(parser.getPath(), "/wiki/URL");
    EXPECT_EQ(parser.getQuery(), "");
    EXPECT_EQ(parser.getFragment(), "");
}

TEST(UrlParserTest, ParseUrlFull) {
    UrlParser parser("http://log_in:pa$$word@example.com:8080/pa_th1?query=123#fragment");

    EXPECT_EQ(parser.getScheme(), "http");
    EXPECT_EQ(parser.getUser(), "log_in");
    EXPECT_EQ(parser.getPassword(), "pa$$word");
    EXPECT_EQ(parser.getHost(), "example.com");
    EXPECT_EQ(parser.getPort(), "8080");
    EXPECT_EQ(parser.getPath(), "/pa_th1");
    EXPECT_EQ(parser.getQuery(), "query=123");
    EXPECT_EQ(parser.getFragment(), "fragment");
}

TEST(UrlParserTest, ParseUrlSomeSite) {
    UrlParser parser("https://marketplace.visualstudio.com/items?itemName=twxs.cmake");

    EXPECT_EQ(parser.getScheme(), "https");
    EXPECT_EQ(parser.getUser(), "");
    EXPECT_EQ(parser.getPassword(), "");
    EXPECT_EQ(parser.getHost(), "marketplace.visualstudio.com");
    EXPECT_EQ(parser.getPort(), "");
    EXPECT_EQ(parser.getPath(), "/items");
    EXPECT_EQ(parser.getQuery(), "itemName=twxs.cmake");
    EXPECT_EQ(parser.getFragment(), "");
}

TEST(UrlParserTest, ParseUrlEmptyScheme) {
    try {
        UrlParser parser("://login:password@example.com:8080/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Missing scheme"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlSpaceInPort) {
    try {
        UrlParser parser("https://login:password@example.com:80 80/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Space in URL string"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlSymbolInPort) {
    try {
        UrlParser parser("https://login:password@example.com:8t80/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid port"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }

    try {
        UrlParser parser("https://login:password@example.com:8]80/path?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid port"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlSpaceInPath) {
    try {
        UrlParser parser("https://login:password@example.com:8080/pa th?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Space in URL string"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlYandexSlash) {
    UrlParser parser("https://ya.ru/");

    EXPECT_EQ(parser.getScheme(), "https");
    EXPECT_EQ(parser.getHost(), "ya.ru");
    EXPECT_EQ(parser.getPath(), "/");
}

TEST(UrlParserTest, ParseUrlYandexSpace) {
    try {
        UrlParser parser("https:// y a.r u/");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Space in URL string"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlYandex) {
    try {
        UrlParser parser("https://ya.ru");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Missing path"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlOnlyScheme) {
    try {
        UrlParser parser("https://");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Missing host"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlInvalidPath) {
    try {
        UrlParser parser("https://login:password@example.com:8080/pa`th?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid path"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlInvalidUser) {
    try {
        UrlParser parser("https://log|in:password@example.com:8080/pa`th?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid user"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlInvalidPassword) {
    try {
        UrlParser parser("https://login:pass!word@example.com:8080/pa`th?query#fragment");
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        EXPECT_EQ(err.what(),std::string("Invalid URL: Invalid password"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(UrlParserTest, ParseUrlLoginOnly) {
    UrlParser parser("ftp://login@example.com:8080/path?query#fragment");

    EXPECT_EQ(parser.getUser(), "login");
}