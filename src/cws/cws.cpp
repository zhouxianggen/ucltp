
#include "config.h"
#include "dat.h"
#include "ner.h"
#include "crfmodel.h"
#include "newword.h"
#include "cws.h"

namespace ucltp {

int Cws::init(const char *config)
{
    release();

    Config cfg;
    cfg.parse(config);

    return init(cfg);
}

int Cws::init(const Config& cfg)
{
  _granularity = cfg.getint("option", "granularity");
  _without_stopwords = cfg.getint("option", "without-stopwords");
  
  _dict = new Dat;
  if (!_dict || _dict->init(cfg.get("dict")) != 0) return -1;

  _new = new Ner;
  if (!_ner || _ner->init(cfg.get("ner")) != 0) return -2;

  _sm = new CrfModel;
  if (!_sm || _sm->init(cfg.get("stat")) != 0) return -3;

  _nw = new NewWord;
  if (!_nw || _nw->init(cfg.get("newword")) != 0) return -4;

  return 0;
}

int Cws::seg(const char* text, vector<word_t>& words)
{
  vector<char_t> chars;

  read_utf8_text(text, chars);
  
  rule_seg(chars);
  dict_seg(chars);
  ner_seg(chars);
  stat_seg(chars);
  newword_seg(chars);

  make_words(chars, words);

  return 0;
}

void Cws::rule_seg(const vector<char_t>& chars)
{
}

void Cws::dict_seg(const vector<char_t>& chars)
{
}

void Cws::ner_seg(const vector<char_t>& chars)
{
}

void Cws::stat_seg(const vector<char_t>& chars)
{
}

void Cws::newword_seg(const vector<char_t>& chars)
{
}

} // namepsace

