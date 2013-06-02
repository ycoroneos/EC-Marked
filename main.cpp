#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <algorithm>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "Prefix.h"
using namespace std;

void generate(map<Prefix, vector<string> > dict, int amnt);

int main()
{
    int psize=1;
    string file="output";
    map<Prefix,vector<string> > dictionary;
    ifstream infile;
    infile.open(file.c_str());
    string input[psize+1];
    for (int i=0; i<psize+1; ++i)
    {
        infile >> input[i];
    }
    while (infile.good())
    {
        Prefix ptemp=Prefix(psize, input);
        map<Prefix,vector<string> >::iterator iter;
        iter=dictionary.find(ptemp);
        if (iter!=dictionary.end())
        {
          iter->second.push_back(input[psize]);
        }
        else
        {
          dictionary[Prefix(psize, input)].push_back(input[psize]);
        }
        for (int i=1; i<psize+1; ++i)
        {
            input[i-1]=input[i];
        }
        infile >> input[psize];
    }
    cout << "finished reading file\n";
    //std::cout << "mymap contains:";
    //for ( map<Prefix, vector<string> >::iterator  it = dictionary.begin(); it != dictionary.end(); ++it )
     //   std::cout << " " << it->first.getAllPrefix() << ":" << it->second[0];
    //std::cout << std::endl;
    generate(dictionary, 1000);
    return 0;
}

void generate(map<Prefix, vector<string> > dict, int amnt)
{
    srand(time(NULL));
    int randint=rand() % (dict.size()-1) + 0;
    //cout << "dict size: " << dict.size() << " randint: " << randint << endl;
    map<Prefix, vector<string> >::iterator  it=dict.begin();
    while (randint>0)
    {
        ++it;
        --randint;
    }
    vector<string> chain=it->first.print();
    if (it->second.size()==0)
    {
      return;
    }
    randint=(rand() % (it->second.size()) + 1)-1;
    chain.push_back(it->second[randint]);
    for (int i=0; i<chain.size()-1; ++i)
    {
        //cout << chain[i] << " ";
    }
    while (amnt>=0)
    {
        cout << chain.back() + " ";
        /*for (int i=0; i<chain.size(); ++i)
        {
          cout << chain[i] << " ";
        }
        cout << "\n****************************\n";
        */
        for (int i=0; i<chain.size()-1; ++i)
        {
            chain[i]=chain[i+1];
        }
        chain.pop_back();
        Prefix ptemp=Prefix(chain.size(), &chain[0]);
        map<Prefix,vector<string> >::iterator iter;
        iter=dict.find(ptemp);
        if (iter!=dict.end())
        {
          vector<string> suffixes=iter->second;
          chain.push_back(suffixes[rand() % (suffixes.size())]);
        }
        else
        {
          //cout << "\n\nfound nothing\n";
          break;
        }
        --amnt;
    }
    cout << endl;
}




