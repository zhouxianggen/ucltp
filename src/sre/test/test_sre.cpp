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

TEST_F (TestSre, test_build)
{
  ASSERT_TRUE(fo);
  int r = _re->build("regexp");
}

TEST_F (TestSre, test_match)
{
  char str[] = "一千三百零二万亿零四百八十万三千二百零一";
  
  match_result_t mr = _re.match(str);
  ASSERT_EQ(mr.len, strlen(str));
  ASSERT_EQ(mr.value, 0);

  vector<char_t> chars;
  ucltp::read_utf8_text(str, chars);
  mr = _re.match(chars, 0);
  ASSERT_EQ(mr.len, chars.size());
  
  mr = _re.match(chars, 1);
  ASSERT_EQ(mr.len, 0);
  
  mr = _re.match(chars, 2);
  ASSERT_EQ(mr.len, chars.size()-2);
}

int main(int argc, char **argv)
{
	::testing::FLAGS_gtest_output = "xml:test_sre_result.xml";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

