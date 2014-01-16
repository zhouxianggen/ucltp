/**
 * unitest for sre
 * zhouxg@ucweb.com
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include "util.h"
#include "../sre.h"
using ucltp::Sre;

class TestSre : public testing::Test {
protected:
  Sre *_re;
	virtual void SetUp(){
    _re = new Sre;
	}
	virtual void TearDown(){
    delete _re;
	}
};

TEST_F (TestSre, test_all)
{
  int r = _re->build("regexp");
  ASSERT_EQ(r, 0);

  char str[] = "一千三百零二万亿零四百八十万三千二百零一";
  vector<ucltp::char_t> chars;
  ucltp::read_utf8_text(str, chars);
  
  ucltp::match_result_t mr = _re->match(chars, 0);
  printf("chars.size = %d\n", chars.size());
  ASSERT_EQ(mr.len, chars.size());
  
  mr = _re->match(chars, 1);
  ASSERT_EQ(mr.len, 2);
  
  mr = _re->match(chars, 2);
  ASSERT_EQ(mr.len, chars.size()-2);
}

int main(int argc, char **argv)
{
	::testing::FLAGS_gtest_output = "xml:test_sre_result.xml";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

