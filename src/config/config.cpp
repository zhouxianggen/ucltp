
#include <iostream>
#include <fstream>
using std::ifstream;
#include "util.h"
#include "config.h"

namespace ucltp {

void Config::release()
{
  map<string, Config*>::iterator mi;
  for (mi=_sections.begin(); mi!=_sections.end(); mi++)
    delete mi->second;
  _sections.clear();
  _values.clear();
}

int Config::parse(const char* conf)
{
  ifstream fi(conf);
  string line;
  vector<string> parts;
  vector<seq_t> seqs;
  map<string, string> defines;

  if (!fi) return -1;
  
  while (getline(fi, line)) {
    seq_t s;
    
    split(line, parts);

    if (parts.size() == 1) {
      int front=0, back=parts[0].length()-1, lev2=0;
      
      for (; front<back && parts[0][front]=='[' && parts[0][back]==']'; front+=1,back-=1)
        lev2 += 1;

      if (front < back) {
        s.lev = lev2;
        s.section = parts[0].substr(front, back + 1 - front);
        seqs.push_back(s);
      }
    }
    else if (parts.size() == 3) {
      if (parts[1] == "=") {
        if (parts[0][0] == '$') {
          string define = parts[0].substr(1, parts[0].length() - 1);
          if (define.length() > 0)
            defines[define] = parts[2];
        }
        else {
          s.key = parts[0];
          s.value = replace(defines, parts[2]);
          seqs.push_back(s);
        }
      }
    }
    else continue;
  }
 
  return parse(seqs, 0, seqs.size());
}

int Config::parse(const vector<seq_t>& seqs, int begin, int end)
{
  if (begin >= end) return 0;
  
  for (; begin<end && seqs[begin].lev==0; begin+=1)
    _values[seqs[begin].key] = seqs[begin].value;
  
  while (begin < end) {
    int i = begin + 1;
    
    for (; i<end; i+=1) {
      int lev = seqs[i].lev;
      if (lev == 0 || lev-1 == seqs[begin].lev) continue;
      if (lev == seqs[begin].lev) break;
      return -1;
    }
    Config* cfg = new Config;
    cfg->parse(seqs, begin+1, i);
    _sections[seqs[begin].section] = cfg;
    begin = i;
  }
  return 0;
}

string Config::replace(const map<string, string>& defines, string str)
{
  int i=0, len=str.length();
  map<string, string>::const_iterator mi;

  for (; i < len; i += 1) {
    if (str[i] == '$') {
      for (mi=defines.begin(); mi!=defines.end(); mi++) {
        if (str.substr(i, mi->first.length()) == mi->first) {
          str.replace(i, mi->first.length(), mi->second);
          len = str.length();
          i += mi->second.length() - 1;
          break;
        }
      }
    }
  }

  return str;
}

void Config::show(int lev)
{
  string tab;
  for (int i=0; i<lev; i+=1)
    tab += "  ";
  
  for (map<string, string>::iterator mi=_values.begin(); mi!=_values.end(); mi++)
    std::cout<<tab<<mi->first<<" = "<<mi->second<<std::endl;
  for (map<string, Config*>::iterator mi=_sections.begin(); mi!=_sections.end(); mi++) {
    std::cout<<tab<<"["<<mi->first<<"]"<<std::endl;
    mi->second->show(lev + 1);
  }
}

} // end namespace 
