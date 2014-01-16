/**
 * unitest for dat
 * zhouxg@ucweb.com
 * 
 */

#include <gtest/gtest.h>
#include <fstream>
#include "util.h"
#include "../dat.h"
using ucltp::Dat;

class TestDat : public testing::Test {
protected:
  Dat *_dict;
	virtual void SetUp(){
    _dict = new Dat;
	}
	virtual void TearDown(){
    delete _dict;
	}
};

TEST_F (TestDat, test_all)
{
  int r = _dict->build("dict");
  ASSERT_EQ(r, 0);
  
  char str[] = "中国人的中国梦之队";

  vector<ucltp::char_t> chars;
  ucltp::read_utf8_text(str, chars);
  ucltp::match_result_t mr = _dict->match(chars, 0);
  ASSERT_EQ(mr.len, 3);
  
  mr = _dict->match(chars, 1);
  ASSERT_EQ(mr.len, 0);
  
  mr = _dict->match(chars, 4);
  ASSERT_EQ(mr.len, 5);

  r = _dict->save("bin");
  ASSERT_EQ(r, 0);
  r = _dict->load("bin");
  ASSERT_EQ(r, 0);

  mr = _dict->match(chars, 4);
  ASSERT_EQ(mr.len, 5);
}

int main(int argc, char **argv)
{
	::testing::FLAGS_gtest_output = "xml:test_dat_result.xml";
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

