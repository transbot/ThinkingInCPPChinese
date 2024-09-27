# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C0B
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ../$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe


Borland:  \
	Dummy.exe

Microsoft:  \
	Dummy.exe

g++:  \
	Dummy.exe

edg:  \
	Dummy.exe

Metrowerks:  \
	Dummy.exe

DigitalMars:  \
	Dummy.exe

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


Dummy.exe: Dummy.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

