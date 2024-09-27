# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http:\\www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C04
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ..\$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe


Borland:  \
	FileClass.$(OBJEXT) \
	FileClassTest.exe \
	Iosexamp.exe \
	Strfile.exe \
	Stype.exe \
	Sbufget.exe \
	Seeking.exe \
	Iofile.exe \
	Istring.exe \
	DateIOTest.exe \
	Ostring.exe \
	HTMLStripper2.exe \
	Unitbuf.exe \
	Format.exe \
	Manips.exe \
	InputWidth.exe \
	nl.exe \
	Effector.exe \
	Cppcheck.exe \
	Showerr.exe \
	DataLogger.$(OBJEXT) \
	Datagen.exe \
	Datascan.exe \
	Exercise14.exe \
	TESTHEADER_FileClass.exe \
	TESTHEADER_Fullwrap.exe \
	TESTHEADER_DataLogger.exe

Microsoft:  \
	FileClass.$(OBJEXT) \
	FileClassTest.exe \
	Iosexamp.exe \
	Strfile.exe \
	Stype.exe \
	Sbufget.exe \
	Seeking.exe \
	Iofile.exe \
	Istring.exe \
	DateIOTest.exe \
	Ostring.exe \
	HTMLStripper2.exe \
	StringSeeking.exe \
	Unitbuf.exe \
	Format.exe \
	Manips.exe \
	InputWidth.exe \
	nl.exe \
	Effector.exe \
	Cppcheck.exe \
	Showerr.exe \
	DataLogger.$(OBJEXT) \
	Datagen.exe \
	Datascan.exe \
	Locale.exe \
	Facets.exe \
	Exercise14.exe \
	TESTHEADER_FileClass.exe \
	TESTHEADER_Fullwrap.exe \
	TESTHEADER_DataLogger.exe

g++:  \
	FileClass.$(OBJEXT) \
	FileClassTest.exe \
	Iosexamp.exe \
	Strfile.exe \
	Stype.exe \
	Sbufget.exe \
	Seeking.exe \
	Iofile.exe \
	Istring.exe \
	DateIOTest.exe \
	Ostring.exe \
	HTMLStripper2.exe \
	StringSeeking.exe \
	Unitbuf.exe \
	Format.exe \
	Manips.exe \
	InputWidth.exe \
	nl.exe \
	Effector.exe \
	Cppcheck.exe \
	Showerr.exe \
	DataLogger.$(OBJEXT) \
	Datagen.exe \
	Datascan.exe \
	Exercise14.exe \
	TESTHEADER_FileClass.exe \
	TESTHEADER_Fullwrap.exe \
	TESTHEADER_DataLogger.exe

edg:  \
	FileClass.$(OBJEXT) \
	FileClassTest.exe \
	Iosexamp.exe \
	Strfile.exe \
	Stype.exe \
	Sbufget.exe \
	Seeking.exe \
	Iofile.exe \
	Istring.exe \
	DateIOTest.exe \
	Ostring.exe \
	HTMLStripper2.exe \
	StringSeeking.exe \
	Unitbuf.exe \
	Format.exe \
	Manips.exe \
	InputWidth.exe \
	nl.exe \
	Effector.exe \
	Cppcheck.exe \
	Showerr.exe \
	DataLogger.$(OBJEXT) \
	Datagen.exe \
	Datascan.exe \
	Exercise14.exe \
	TESTHEADER_FileClass.exe \
	TESTHEADER_Fullwrap.exe \
	TESTHEADER_DataLogger.exe

Metrowerks:  \
	FileClass.$(OBJEXT) \
	FileClassTest.exe \
	Iosexamp.exe \
	Strfile.exe \
	Stype.exe \
	Sbufget.exe \
	Seeking.exe \
	Iofile.exe \
	Istring.exe \
	DateIOTest.exe \
	Ostring.exe \
	HTMLStripper2.exe \
	StringSeeking.exe \
	Unitbuf.exe \
	Format.exe \
	Manips.exe \
	InputWidth.exe \
	nl.exe \
	Effector.exe \
	Cppcheck.exe \
	Showerr.exe \
	DataLogger.$(OBJEXT) \
	Datagen.exe \
	Datascan.exe \
	Locale.exe \
	Exercise14.exe \
	TESTHEADER_FileClass.exe \
	TESTHEADER_Fullwrap.exe \
	TESTHEADER_DataLogger.exe

DigitalMars:  \
	FileClass.$(OBJEXT) \
	FileClassTest.exe \
	Iosexamp.exe \
	Strfile.exe \
	Stype.exe \
	Sbufget.exe \
	Seeking.exe \
	Iofile.exe \
	Istring.exe \
	DateIOTest.exe \
	Ostring.exe \
	HTMLStripper2.exe \
	Unitbuf.exe \
	Format.exe \
	Manips.exe \
	InputWidth.exe \
	nl.exe \
	Effector.exe \
	Cppcheck.exe \
	Showerr.exe \
	DataLogger.$(OBJEXT) \
	Datagen.exe \
	Datascan.exe \
	Locale.exe \
	Facets.exe \
	Exercise14.exe \
	TESTHEADER_FileClass.exe \
	TESTHEADER_Fullwrap.exe \
	TESTHEADER_DataLogger.exe

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


FileClass.$(OBJEXT): FileClass.cpp


FileClassTest.exe: FileClass.$(OBJEXT) FileClassTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

FileClassTest.$(OBJEXT): FileClassTest.cpp

Iosexamp.exe: Iosexamp.cpp


Strfile.exe: Strfile.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Stype.exe: Stype.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Sbufget.exe: Sbufget.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Seeking.exe: Seeking.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Iofile.exe: Iofile.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Istring.exe: Istring.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

DateIOTest.exe: ..\C02\Date.$(OBJEXT) DateIOTest.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

DateIOTest.$(OBJEXT): DateIOTest.cpp

Ostring.exe: Ostring.cpp


HTMLStripper2.exe: ..\C03\ReplaceAll.$(OBJEXT) HTMLStripper2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^

HTMLStripper2.$(OBJEXT): HTMLStripper2.cpp

StringSeeking.exe: StringSeeking.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Unitbuf.exe: Unitbuf.cpp


Format.exe: Format.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Manips.exe: Manips.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

InputWidth.exe: InputWidth.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

nl.exe: nl.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Effector.exe: Effector.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Cppcheck.exe: Cppcheck.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Showerr.exe: Showerr.cpp


DataLogger.$(OBJEXT): DataLogger.cpp


Datagen.exe: DataLogger.$(OBJEXT) Datagen.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Datagen.$(OBJEXT): Datagen.cpp

Datascan.exe: DataLogger.$(OBJEXT) Datascan.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Datascan.$(OBJEXT): Datascan.cpp

Locale.exe: Locale.cpp


Facets.exe: Facets.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Exercise14.exe: Exercise14.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_FileClass.exe: TESTHEADER_FileClass.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_Fullwrap.exe: TESTHEADER_Fullwrap.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_DataLogger.exe: TESTHEADER_DataLogger.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

