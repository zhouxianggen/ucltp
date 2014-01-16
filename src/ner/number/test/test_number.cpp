/**
 * unitest for number
 * zhouxg@ucweb.com
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include "util.h"
#include "../number.h"
using ucltp::Number;
using ucltp::uint64;

class TestNumber : public testing::Test {
protected:
  Number *_number;
	virtual void SetUp(){
    _number = new Number;
	}
	virtual void TearDown(){
    delete _number;
	}
};

TEST_F (TestNumber, test_all)
{
  int r = _number->load_dict("../../../../data/ner/number/dict");
  ASSERT_EQ(r, 0);
  r = _number->load_regexp("../../../../data/ner/number/regexp"); 
  ASSERT_EQ(r, 0);
  
  char str[] = "少量人有6.899万亿(六千八百万亿零三百零一万零五十四)";

  vector<ucltp::char_t> chars;
  ucltp::read_utf8_text(str, chars);
  int s = chars.size();
  _number->seg(chars);

  uint64 B = POS_m;
  uint64 I = POS_m << 1;
  ASSERT_EQ(chars[0]._tag, B);
  ASSERT_EQ(chars[1]._tag, I);
  ASSERT_EQ(chars[2]._tag, 0);
  ASSERT_EQ(chars[3]._tag, 0);
  ASSERT_EQ(chars[4]._tag, B);
  ASSERT_EQ(chars[5]._tag, I);
  ASSERT_EQ(chars[10]._tag, I);
  ASSERT_EQ(chars[11]._tag, 0);
  ASSERT_EQ(chars[12]._tag, B);
  ASSERT_EQ(chars[13]._tag, I);
  ASSERT_EQ(chars[s-2]._tag, I);
  ASSERT_EQ(chars[s-1]._tag, 0);
}

int main(int argc, char **argv)
{
	::testing::FLAGS_gtest_output = "xml:test_number_result.xml";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

