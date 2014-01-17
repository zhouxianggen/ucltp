AM_CPPFLAGS = -I$(top_srcdir)/gtest/include -I$(top_srcdir)/util -I../ -I../../
AM_LDFLAGS = -L$(top_srcdir)/gtest
check_PROGRAMS = test_date
test_date_SOURCES = test_date.cpp
test_date_LDADD = -ldate -lgtest -lpthread
test_date_LDFLAGS = -L../.libs
TESTS = $(check_PROGRAMS)
