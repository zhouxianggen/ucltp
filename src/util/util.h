// utils

#ifndef UCLTP_UTIL_H_
#define UCLTP_UTIL_H_

#include <fstream>
#include <string>
#include <vector>
using std::ifstream;
using std::string;
using std::vector;
#include "type.h"

namespace ucltp {

// get an utf8 char
bool get_utf8_char(const char *u8text, uint32 &len, uint32 &code);

// read utf8 text to chars
bool read_utf8_text(const char *u8text, vector<char_t>& chars);

// read file to lines
bool read_lines(const char* file, vector<string>& lines);

// split string by space
int split(const string& str, vector<string>& parts);

// show vector<char_t>
void show(const vector<char_t>& chars);

}
#endif 
