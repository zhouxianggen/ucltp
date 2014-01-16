AM_CPPFLAGS = -I$(top_srcdir)/gtest/include -I$(top_srcdir)/util -I../ -I../../
AM_LDFLAGS = -L$(top_srcdir)/gtest
check_PROGRAMS = test_number
test_number_SOURCES = test_number.cpp
test_number_LDADD = -lnumber -lgtest -lpthread
test_number_LDFLAGS = -L../.libs
TESTS = $(check_PROGRAMS)
