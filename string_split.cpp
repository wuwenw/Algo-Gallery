#include <vector>
#include <string>
#include <regex>
#include <iostream>

using namespace std;
vector<string> regexSplit1(string &s) {
           std::regex words_regex("[^\\s.,:;!?]+");
            auto words_begin = std::sregex_iterator(s.begin(), s.end(), words_regex);
            auto words_end = std::sregex_iterator();
            for(std::sregex_iterator i = words_begin; i != words_end; ++i)
            std::cout << (*i).str() << '\n';

}

vector<string> regexSplit2(string &data) {
        std::regex delim("\\,");
        vector<string> nodes (
            std::sregex_token_iterator(data.begin(), data.end(), delim, -1),
            std::sregex_token_iterator()
        );

}

vector<string> findSplit() {
    // use string view to optimize
    std::string s = "scott>=tiger";
    std::string delim = ">=";

    auto start = 0U;
    auto end = s.find(delim);
    while (end != std::string::npos)
    {
        std::cout << s.substr(start, end - start) << std::endl;
        start = end + delim.length();
        end = s.find(delim, start);
    }

    std::cout << s.substr(start, end);
}


