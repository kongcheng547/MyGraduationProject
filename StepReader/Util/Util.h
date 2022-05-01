//
// Created by kongcheng547 on 2022/3/15.
//

#ifndef STEPREADER_UTIL_H
#define STEPREADER_UTIL_H
#include "string"
#include "iostream"
#include "vector"
#include "sstream"
#include "stack"


using namespace std;
//模板函数：将string类型变量转换为常用的数值类型（此方法具有普遍适用性）
template <class Type>
Type stringToNum(const string& str)
{
    istringstream iss(str);
    Type num;
    iss >> num;
    return num;
}

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

    // 清空字符串所有指定符号
    std::string& clearSelectedChar(std::string &str, char c)
    {
        int index = 0;
        if (!str.empty())
        {
            while ((index = str.find(c, index)) != std::string::npos)
            {
                str.erase(index, 1);
            }
        }
        return str;
    }

    // 处理row里面的double字符串
    double DoubleStringHandle(string doubleString) {
        int removeNum = 0;
        // 如果是最后一个，会带有)
        if (doubleString[doubleString.length() - 1] == ')') {
            removeNum++;
        }
        // 如果是2. 代表是2.0，去掉.
        if (doubleString[doubleString.length() - 1] == '.') {
            removeNum++;
        }
        doubleString = doubleString.substr(0, doubleString.length() - removeNum);
        return stringToNum<double>(doubleString);
    }

    // 找到字符串里面匹配的小括号，返回左括号位置和到右括号的字符数目
    vector<vector<int>> findBracketsVec(string basicString) {
        vector<vector<int>> bracketsMatch;
        stack<int> s;
        int bracketNum = 0;
        for (int i = 0; i < basicString.length(); i++) {
            if (basicString[i] == '(') {
                s.push(bracketNum++);
                vector<int> temp;
                temp.push_back(i);
                bracketsMatch.push_back(temp);
            } else if (basicString[i] == ')') {
                int loc = s.top();
                s.pop();
                bracketsMatch[loc].push_back(i - bracketsMatch[loc][0] + 1);
            }
        }
        return bracketsMatch;
    }

    // 将4,4这样的字符串转为vector存储
    vector<int> handleIntString(string intString) {
        vector<int> intVec;
        vector<string> tempVec;
        this->split(intString, tempVec, ',');
        for (int i = 0; i < tempVec.size(); i++) {
            intVec.push_back(stringToNum<int>(tempVec[i]));
        }
        return intVec;
    }

    // 将4.0,4.1这样的字符串转为vector存储
    vector<double> handleDoubleString(string doubleString) {
        vector<double> doubleVec;
        vector<string> tempVec;
        this->split(doubleString, tempVec, ',');
        for (int i = 0; i < tempVec.size(); i++) {
            doubleVec.push_back(stringToNum<double>(tempVec[i]));
        }
        return doubleVec;
    }
};


#endif //STEPREADER_UTIL_H
