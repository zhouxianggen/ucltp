// number entity

#ifndef UCLTP_NER_NUMBER_H_
#define UCLTP_NER_NUMBER_H_

#include "entity.h"

namespace ucltp {

class Dat; // double array trie dict
class Sre; // simple regular expression engin

class Number : public Entity {
public:
  int load_dict(const char* fdict);
  int load_regexp(const char* fre);
  void seg(vector<char_t>& chars);

  Number() : _dict(0), _re(0) {}
  ~Number() { release(); }
private:
  Dat *_dict;
  Sre *_re;

  void release();
};

}
#endif
