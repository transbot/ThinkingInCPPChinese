# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http:\\www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\TestSuite
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ..\$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe


Borland:  \
	Test.$(OBJEXT) \
	Suite.$(OBJEXT) \
	TESTHEADER_Test.exe \
	TESTHEADER_Suite.exe

Microsoft:  \
	Test.$(OBJEXT) \
	Suite.$(OBJEXT) \
	TESTHEADER_Test.exe \
	TESTHEADER_Suite.exe

g++:  \
	Test.$(OBJEXT) \
	Suite.$(OBJEXT) \
	TESTHEADER_Test.exe \
	TESTHEADER_Suite.exe

edg:  \
	Test.$(OBJEXT) \
	Suite.$(OBJEXT) \
	TESTHEADER_Test.exe \
	TESTHEADER_Suite.exe

Metrowerks:  \
	Test.$(OBJEXT) \
	Suite.$(OBJEXT) \
	TESTHEADER_Test.exe \
	TESTHEADER_Suite.exe

DigitalMars:  \
	Test.$(OBJEXT) \
	Suite.$(OBJEXT) \
	TESTHEADER_Test.exe \
	TESTHEADER_Suite.exe

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


Test.$(OBJEXT): Test.cpp


Suite.$(OBJEXT): Suite.cpp


TESTHEADER_Test.exe: TESTHEADER_Test.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_Suite.exe: TESTHEADER_Suite.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

