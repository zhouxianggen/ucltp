AM_CPPFLAGS = -I$(top_srcdir)/gtest/include -I$(top_srcdir)/util -I../
AM_LDFLAGS = -L$(top_srcdir)/gtest
check_PROGRAMS = test_dat
test_dat_SOURCES = test_dat.cpp
test_dat_LDADD = -ldat -lgtest -lpthread
test_dat_LDFLAGS = -L../.libs
TESTS = $(check_PROGRAMS)
