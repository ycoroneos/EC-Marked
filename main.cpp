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

int main(int argc, char* argv[])
{
    int psize=1;
    int loops=0;
    int per_loop=0;
    string file;
    if (argc<4)
    {
      cerr << "Usage: " << argv[0] << " prefix_size source_file #loops #iterations_per_loop\n";
    }
    else
    {
      psize=atoi(argv[1]);
      file=argv[2];
      loops=atoi(argv[3]);
      per_loop=atoi(argv[4]);
      srand(time(NULL));
    }
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
    for (int i=0; i<loops; ++i)
    {
      generate(dictionary, per_loop);
      cout << "\n\n";
    }
    return 0;
}

void generate(map<Prefix, vector<string> > dict, int amnt)
{
    int randint=rand() % (dict.size()-1) + 0;
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
    while (amnt>=0)
    {
        cout << chain.back() + " ";
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
          break;
        }
        --amnt;
    }
    cout << endl;
}




