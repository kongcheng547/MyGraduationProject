//
// Created by kongcheng547 on 2022/3/15.
//

#ifndef STEPREADER_UTIL_H
#define STEPREADER_UTIL_H
#include "string"
#include "iostream"
#include "vector"

using namespace std;
class Util {
public:
    // 对字符串根据符号分割
    void split(const string& s, vector<string>& tokens, const char& delim = ' ') {
        tokens.clear();
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
    }

    // 清空字符串所有空格
    std::string& clearAllSpace(std::string &str)
    {
        int index = 0;
        if (!str.empty())
        {
            while ((index = str.find(' ', index)) != std::string::npos)
            {
                str.erase(index, 1);
            }
        }
        return str;
    }
};


#endif //STEPREADER_UTIL_H
