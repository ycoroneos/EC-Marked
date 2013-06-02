#include "Prefix.h"
#include <vector>
using namespace std;

Prefix::Prefix(int num, string input[])
{
    size=num;
    for (int i=0; i<size; ++i)
    {
      members.push_back(input[i]);
    }
}

Prefix::~Prefix()
{
  members.clear();
}

string Prefix::getElem(int index) const
{
    if (index<=size)
    {
        return members[index];
    }
    return "INDEX_OUT_OF_RANGE";
}

string Prefix::getAllPrefix() const
{
    string out="";
    for (unsigned int i=0; i<size; ++i)
    {
        out+=members[i];
    }
    return out;
}

vector<string> Prefix::print() const
{
  return members;
}

bool Prefix::operator==(const Prefix& comparator) const
{
  return (this->getAllPrefix() == comparator.getAllPrefix());
}

bool Prefix::operator<(const Prefix& comparator) const
{
  return (this->getAllPrefix() < comparator.getAllPrefix());
}
