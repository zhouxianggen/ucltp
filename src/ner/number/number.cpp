
#include "dat.h"
#include "sre.h"
#include "number.h"

namespace ucltp {

void Number::release()
{
  if (_dict) delete _dict;
  _dict = 0;
  if (_re) delete _re;
  _re = 0;
}

int Number::load_dict(const char* fdict)
{
  if (_dict) delete _dict;
  _dict = new Dat;
  return _dict->build(fdict);
}

int Number::load_regexp(const char* fre)
{
  if (_re) delete _re;
  _re = new Sre;
  return _re->build(fre);
}

void Number::seg(vector<char_t>& chars)
{
  for (int i=0,s=chars.size(); i<s; ) {
    match_result_t mr1 = _dict->match(chars, i);
    match_result_t mr2 = _re->match(chars, i);
    //printf("i=%d, mr1.len=%d, mr2.len=%d\n", i, mr1.len, mr2.len);
    int len = max2(mr1.len, mr2.len);
    if (len > 0) {
      chars[i].set_tag(POS_m);
      for (int j=1; j<len; j+=1)
        chars[i+j].set_tag(POS_m, 1);
    }
    i += max2(len, 1);
  }
}

}
