# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http:\\www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Automatically-generated MAKEFILE 
# For examples in directory .\C08
# Invoke with: make compiler-name
# or: make clean

ifneq ($(MAKECMDGOALS),clean)
include ..\$(MAKECMDGOALS).mac
endif

.SUFFIXES : .cpp .$(OBJEXT) .exe


Borland:  \
	CheckedCast.exe \
	CheckedCast2.exe \
	CatchBadCast.exe \
	TypeInfo.exe \
	RTTIandNesting.exe \
	IntermediateCast.exe \
	VoidRTTI.exe \
	ConstructorOrder.exe \
	RTTIandMultipleInheritance.exe \
	Trash.$(OBJEXT) \
	Recycle.exe \
	Recycle2.exe \
	TESTHEADER_Security.exe \
	TESTHEADER_Trash.exe

Microsoft:  \
	CheckedCast.exe \
	CheckedCast2.exe \
	CatchBadCast.exe \
	TypeInfo.exe \
	RTTIandNesting.exe \
	IntermediateCast.exe \
	VoidRTTI.exe \
	ConstructorOrder.exe \
	RTTIandMultipleInheritance.exe \
	Trash.$(OBJEXT) \
	Recycle.exe \
	Recycle2.exe \
	TESTHEADER_Security.exe \
	TESTHEADER_Trash.exe

g++:  \
	CheckedCast.exe \
	CheckedCast2.exe \
	CatchBadCast.exe \
	TypeInfo.exe \
	RTTIandNesting.exe \
	IntermediateCast.exe \
	VoidRTTI.exe \
	ConstructorOrder.exe \
	RTTIandMultipleInheritance.exe \
	Trash.$(OBJEXT) \
	Recycle.exe \
	Recycle2.exe \
	TESTHEADER_Security.exe \
	TESTHEADER_Trash.exe

edg:  \
	CheckedCast.exe \
	CheckedCast2.exe \
	CatchBadCast.exe \
	TypeInfo.exe \
	RTTIandNesting.exe \
	IntermediateCast.exe \
	VoidRTTI.exe \
	ConstructorOrder.exe \
	RTTIandMultipleInheritance.exe \
	Trash.$(OBJEXT) \
	Recycle.exe \
	Recycle2.exe \
	TESTHEADER_Security.exe \
	TESTHEADER_Trash.exe

Metrowerks:  \
	CheckedCast.exe \
	CheckedCast2.exe \
	CatchBadCast.exe \
	TypeInfo.exe \
	RTTIandNesting.exe \
	IntermediateCast.exe \
	VoidRTTI.exe \
	ConstructorOrder.exe \
	RTTIandMultipleInheritance.exe \
	Trash.$(OBJEXT) \
	Recycle.exe \
	Recycle2.exe \
	TESTHEADER_Security.exe \
	TESTHEADER_Trash.exe

DigitalMars:  \
	CheckedCast.exe \
	CheckedCast2.exe \
	CatchBadCast.exe \
	TypeInfo.exe \
	RTTIandNesting.exe \
	IntermediateCast.exe \
	VoidRTTI.exe \
	ConstructorOrder.exe \
	RTTIandMultipleInheritance.exe \
	Trash.$(OBJEXT) \
	Recycle.exe \
	Recycle2.exe \
	TESTHEADER_Security.exe \
	TESTHEADER_Trash.exe

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


CheckedCast.exe: CheckedCast.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

CheckedCast2.exe: CheckedCast2.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

CatchBadCast.exe: CatchBadCast.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TypeInfo.exe: TypeInfo.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

RTTIandNesting.exe: RTTIandNesting.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

IntermediateCast.exe: IntermediateCast.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

VoidRTTI.exe: VoidRTTI.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

ConstructorOrder.exe: ConstructorOrder.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

RTTIandMultipleInheritance.exe: RTTIandMultipleInheritance.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Trash.$(OBJEXT): Trash.cpp


Recycle.exe: Trash.$(OBJEXT) Recycle.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Recycle.$(OBJEXT): Recycle.cpp

Recycle2.exe: Trash.$(OBJEXT) Recycle2.$(OBJEXT)
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

Recycle2.$(OBJEXT): Recycle2.cpp

TESTHEADER_Security.exe: TESTHEADER_Security.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

TESTHEADER_Trash.exe: TESTHEADER_Trash.cpp
	$(CPP) $(CPPFLAGS) $(EXEFLAG)$@ $^
	$@

