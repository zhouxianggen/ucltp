//
// config parser

#ifndef UCLTP_CONFIG_H_
#define UCLTP_CONFIG_H_

#include <map>
#include <vector>
#include <string>
using std::map;
using std::vector;
using std::string;

namespace ucltp {

class Config {
public:
  int parse(const char* conf);

  const Config* get_section(const string& section) const {
    map<string, Config*>::const_iterator mi = _sections.find(section);
    return (mi != _sections.end())? mi->second : NULL;
  }
  
  const string& get_value(const string& key) const {
    static string empty;
    map<string, string>::const_iterator mi = _values.find(key);
    return (mi != _values.end())? mi->second : empty;
  }
  
  int getint(const string& section, const string& key) const {
    const Config* cfg = get_section(section);
    return cfg? atoi(cfg->get_value(key).c_str()) : 0;
  }

  const string& get(const string& section, const string& key) const {
    static string empty;
    const Config* cfg = get_section(section);
    return cfg? cfg->get_value(key) : empty;
  }
  
  void show(int lev=0);
  ~Config() { release(); }

private:  
  map<string, string> _values;
  map<string, Config*> _sections;

  struct seq_t {
    int lev;
    string section;
    string key;
    string value;

    seq_t() : lev(0) {}
  };

  void release();
  int parse(const vector<seq_t>& seqs, int begin, int end);
  string replace(const map<string, string>& defines, string str);
};

} // end namepace

#endif

