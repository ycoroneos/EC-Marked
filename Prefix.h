#pragma once
#include <string>
#include <string.h>
#include <stdio.h>
#include <algorithm>

class Prefix
{
private:
  std::vector<std::string> members;
    int size;
public:
    Prefix(int num, std::string input[]);
    ~Prefix();
    std::string getElem(int index) const;
    std::string getAllPrefix() const;
    std::vector<std::string> print() const;

    bool operator==(const Prefix& comparator) const;
    bool operator<(const Prefix& comparator) const;
};
