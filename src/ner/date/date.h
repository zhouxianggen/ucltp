// date entity

#ifndef UCLTP_NER_DATE_H_
#define UCLTP_NER_DATE_H_

#include "entity.h"

namespace ucltp {

class Dat; // double array trie dict
class Sre; // simple regular expression engin

class Date : public Entity {
public:
  int load_dict(const char* fdict);
  int load_regexp(const char* fre);
  void seg(vector<char_t>& chars);

  Date() : _dict(0), _re(0) {}
  ~Date() { release(); }
private:
  Dat *_dict;
  Sre *_re;

  void release();
};

}
#endif
