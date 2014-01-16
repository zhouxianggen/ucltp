// named entity

#ifndef UCLTP_ENTITY_H_
#define UCLTP_ENTITY_H_

#include "type.h"

namespace ucltp {

class Entity {
public:
  virtual void seg(vector<char_t>& chars) = 0;
};

}
#endif
