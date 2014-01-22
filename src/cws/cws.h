/*
 * chinese word segment 
 * Copyright (C) 2012-2014 UC
 * Author: zhouxg@ucweb.com
 *
 */
#ifndef	UCLTP_CWS_H_
#define	UCLTP_CWS_H_

#include "type.h"

namespace ucltp {

class Config;
class Dat;
class Ner;
class CrfModel;
class NewWord;

class Cws {
public:
  int init(const char* conf);
  int seg(const char* text, vector<word_t>& words);
  void set_granularity(int lev) { _granularity = lev; }
  void set_without_stopwords(bool b) { _without_stopwords = b; }
  Cws() 
    : _dict(0), _ner(0), _sm(0), _nw(0) {}
  ~Cws() { release(); }
private:
  int init(const Config& cfg);
  void release();
  int rule_seg(vector<char_t>& chars);
  int dict_seg(vector<char_t>& chars);
  int ner_seg(vector<char_t>& chars);
  int stat_seg(vector<char_t>& chars);
  int newword_seg(vector<char_t>& chars);

  int       _granularity;
  bool      _without_stopwords;
  Dat*      _dict;
  Ner*      _ner;
  CrfModel* _sm;
  NewWord*  _nw;
};

}
#endif
