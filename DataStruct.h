#ifndef TECPROG2_DATASTRUCT_H
#define TECPROG2_DATASTRUCT_H

#include <string>
#include <utility>

#include "Exeptons.h"

struct DataStruct
{
    double key1;
    unsigned long long key2;
    std::string key3;

    DataStruct() :
            key1(0.0),
            key2(0.0)
    {}

    DataStruct(const double a,const unsigned long long b, std::string  c) :
            key1(a),
            key2(b),
            key3(std::move(c))
    {}

    DataStruct& operator=(const DataStruct &otherArr) noexcept
    {
        if (this != &otherArr)
        {
            key1 = otherArr.key1;
            key2 = otherArr.key2;
            key3 = otherArr.key3;
        }
        return *this;
    }

    bool operator==(DataStruct &data) const {
        if (key1 == data.key1 && key2 == data.key2 && key3 == data.key3) { return true; }
        else { return false; }
    }

    bool operator!=(DataStruct &data) const {
        return !(operator==(data));
    }

    bool operator<(DataStruct &data) const {
        if (key1 < data.key1) {
            return true;
        }
        else if (key1 == data.key1 && key2 < data.key2) {
            return true;
        }
        else if (key1 == data.key1 && key2 == data.key2 && key3 < data.key3) {
            return true;
        }
        return false;
    }

    friend std::istream& operator>>(std::istream &in, DataStruct& var) {
        std::string str;
        std::string keyNum;
        std::string buffer;
        double bufKey1 = 0.0;
        unsigned long long bufKey2 = 0.0;
        std::string bufKey3;

        try {
            getline(std::cin, str);

            if (*(str.begin()) != '(') {
                throw ErrorBadInput();
            }

            if (*(str.end() - 1) != ')') {
                throw ErrorBadInput();
            }

            str.erase(str.begin(), str.begin() + 1);
            str.erase(str.end() - 2, str.end());

            while (!str.empty()) {
                keyNum = *(str.begin() + 4);

                if (keyNum == "1") {
                    str.erase(str.begin(), str.begin() + 6);

                    while (!str.empty() && *str.begin() != ':') {
                        buffer.push_back(*str.begin());
                        str.erase(str.begin(), str.begin() + 1);
                    }

                    if (*(--buffer.end()) != 'd') {
                        throw ErrorBadInput();
                    }

                    if(std::atof(buffer.c_str())){
                        bufKey1 = std::atof(buffer.c_str());
                        buffer.clear();
                    }
                    else{
                        throw WrongDoubleInput();
                    }
                }
                else if (keyNum == "2") {
                    str.erase(str.begin(), str.begin() + 6);

                    while (!str.empty() && *str.begin() != ':') {
                        buffer.push_back(*str.begin());
                        str.erase(str.begin(), str.begin() + 1);
                    }

                    if ((*(--buffer.end()) != 'l' && *(buffer.end() - 2) != 'l' && *(buffer.end() - 3) != 'u')) {
                        if ((*(--buffer.end()) != 'L' && *(buffer.end() - 2) != 'L' && *(buffer.end() - 3) != 'U')) {
                            throw ErrorBadInput();
                        }
                    }
                    else if (*buffer.begin() == '-') {
                        throw WrongUnsignedLongLongInput();
                    }

                    if(std::stoul(buffer.c_str())){
                        bufKey2 = std::stoul(buffer.c_str());
                        buffer.clear();
                    }
                    else{
                        throw WrongUnsignedLongLongInput();
                    }
                }
                else if (keyNum == "3") {
                    str.erase(str.begin(), str.begin() + 6);

                    while (!str.empty() && *str.begin() != ':') {
                        buffer.push_back(*str.begin());
                        str.erase(str.begin(), str.begin() + 1);
                    }

                    bufKey3 = buffer;
                    buffer.clear();
                }
                else {
                    throw ErrorBadInput();
                }
            }
        }
        catch(std::exception &exception) {
        in.clear();
        std::cerr << std::endl << exception.what() << std::endl;
        }

        var.key1 = bufKey1;
        var.key2 = bufKey2;
        var.key3 = bufKey3;
        in.clear();

        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const DataStruct& var){
        if(var.key3 != "" && var.key2 != 0 && var.key1 != 0) {
            out << "(:key1 " << var.key1 << "d" << ":key2 " << var.key2 << "ull" << ":key3 "
                << var.key3 << ":)" << std::endl;
        }
        return out;
    }
};


#endif //TECPROG2_DATASTRUCT_H
