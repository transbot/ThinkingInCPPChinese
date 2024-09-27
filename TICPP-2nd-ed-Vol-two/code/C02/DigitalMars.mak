# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http:\\www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C02
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ..\$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe


Borland:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT) \
	TESTHEADER_Date1.exe \
	TESTHEADER_DateTest.exe \
	TESTHEADER_MemCheck.exe \
	TESTHEADER_Rational.exe \
	TESTHEADER_Date.exe

Microsoft:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT) \
	TESTHEADER_Date1.exe \
	TESTHEADER_DateTest.exe \
	TESTHEADER_MemCheck.exe \
	TESTHEADER_Rational.exe \
	TESTHEADER_Date.exe

g++:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT) \
	TESTHEADER_Date1.exe \
	TESTHEADER_DateTest.exe \
	TESTHEADER_MemCheck.exe \
	TESTHEADER_Rational.exe \
	TESTHEADER_Date.exe

edg:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT) \
	TESTHEADER_Date1.exe \
	TESTHEADER_DateTest.exe \
	TESTHEADER_MemCheck.exe \
	TESTHEADER_Rational.exe \
	TESTHEADER_Date.exe

Metrowerks:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT) \
	TESTHEADER_Date1.exe \
	TESTHEADER_DateTest.exe \
	TESTHEADER_MemCheck.exe \
	TESTHEADER_Rational.exe \
	TESTHEADER_Date.exe

DigitalMars:  \
	HiLo.exe \
	SimpleDateTest.exe \
	SimpleDateTest2.exe \
	DateTest.exe \
	MemCheck.$(OBJEXT) \
	MemTest.exe \
	Date.$(OBJEXT) \
	TESTHEADER_Date1.exe \
	TESTHEADER_DateTest.exe \
	TESTHEADER_MemCheck.exe \
	TESTHEADER_Rational.exe \
	TESTHEADER_Date.exe

CodeWizard:
	CodeWizard *.cpp

clean:
ifeq ($(notdir $(SHELL)),COMMAND.COM)
	del *.o
	del *.obj
	del *.exe
	del *.tds
	del *.map
else
	rm -f *.o *.obj *.exe *.tds *.map
endif


HiLo.exe: HiLo.cpp


SimpleDateTest.exe: Date.$(OBJEXT) SimpleDateTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

SimpleDateTest.$(OBJEXT): SimpleDateTest.cpp

SimpleDateTest2.exe: Date.$(OBJEXT) SimpleDateTest2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

SimpleDateTest2.$(OBJEXT): SimpleDateTest2.cpp

DateTest.exe: Date.$(OBJEXT) ..\TestSuite\Test.$(OBJEXT) DateTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

DateTest.$(OBJEXT): DateTest.cpp

MemCheck.$(OBJEXT): MemCheck.cpp


MemTest.exe: MemCheck.$(OBJEXT) MemTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

MemTest.$(OBJEXT): MemTest.cpp

Date.$(OBJEXT): Date.cpp


TESTHEADER_Date1.exe: TESTHEADER_Date1.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_DateTest.exe: TESTHEADER_DateTest.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_MemCheck.exe: TESTHEADER_MemCheck.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_Rational.exe: TESTHEADER_Rational.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_Date.exe: TESTHEADER_Date.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

