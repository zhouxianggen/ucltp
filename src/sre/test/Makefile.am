AM_CPPFLAGS = -I$(top_srcdir)/gtest/include -I$(top_srcdir)/util -I../
AM_LDFLAGS = -L$(top_srcdir)/gtest
check_PROGRAMS = test_sre
test_sre_SOURCES = test_sre.cpp
test_sre_LDADD = -lsre -lgtest -lpthread
test_sre_LDFLAGS = -L../.libs
TESTS = $(check_PROGRAMS)
