/**
 * unitest for date
 * zhouxg@ucweb.com
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include "util.h"
#include "../date.h"
using ucltp::Date;
using ucltp::uint64;

class TestDate : public testing::Test {
protected:
  Date *_date;
	virtual void SetUp(){
    _date = new Date;
	}
	virtual void TearDown(){
    delete _date;
	}
};

TEST_F (TestDate, test_all)
{
  int r = _date->load_dict("../../../../data/ner/date/dict");
  ASSERT_EQ(r, 0);
  r = _date->load_regexp("../../../../data/ner/date/regexp"); 
  ASSERT_EQ(r, 0);
  
  char str[] = "乾隆三年到2015.12.10日下午4点";

  vector<ucltp::char_t> chars;
  ucltp::read_utf8_text(str, chars);
  int s = chars.size();
  _date->seg(chars);

  uint64 B = POS_nt;
  uint64 I = POS_nt << 1;
  ASSERT_EQ(chars[0]._tag, B);
  ASSERT_EQ(chars[1]._tag, I);
  ASSERT_EQ(chars[2]._tag, I);
  ASSERT_EQ(chars[3]._tag, I);
  ASSERT_EQ(chars[4]._tag, 0);
  ASSERT_EQ(chars[5]._tag, B);
  ASSERT_EQ(chars[s-1]._tag, I);
}

int main(int argc, char **argv)
{
	::testing::FLAGS_gtest_output = "xml:test_date_result.xml";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

