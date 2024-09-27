# Master makefile for "Thinking in C++, 2nd Edition, Volume 2"
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Compiles all the code in the book

help: 
	@echo To compile all programs from 
	@echo "Thinking in C++, 2nd Edition, Volume 2"
	@echo type one of the following commands, according to your platform:
	@echo make g++ \(For version 3 and above only\)
	@echo make Borland \(Version 6\)
	@echo make Microsoft \(For Microsoft C++ 7 with .NET only\)
	@echo make Metrowerks \(For Metrowerks CodeWarrior on Mac OSX: Professional edition 
	@echo     with command-line compiler \)
	@echo make -f DigitalMars.mak \(For www.DigitalMars.com C++ in a DOS window \(You 
	@echo     must also install stlport \& set CFLAGS=-Ipath\to\your\stlport\)\)
	@echo make edg \(For Edison Design Group C++\)
	@echo make clean
	@echo
	@echo NOTE: You must install and build ZThreads from zthread.sourceforge.net for your 
	@echo particular compiler in order to build Chapter 11 \(C11\). Makefiles for some 
	@echo compilers can be found in C11.
	@echo
	@echo Designed for use with \(free\) Gnu-make, see www.gnu.org/software/make. This is
	@echo the default make for Cygwin under Windows \(free, www.Cygwin.com\), Linux, and OSX
	@echo www.gnu.org/software/make has sources and installations for other platforms
	@echo Other makes may work, but are not supported.


$(MAKECMDGOALS): 
	$(MAKE) $(MAKECMDGOALS) -C TestSuite
	$(MAKE) $(MAKECMDGOALS) -C C01
	$(MAKE) $(MAKECMDGOALS) -C C02
	$(MAKE) $(MAKECMDGOALS) -C C03
	$(MAKE) $(MAKECMDGOALS) -C C04
	$(MAKE) $(MAKECMDGOALS) -C C05
	$(MAKE) $(MAKECMDGOALS) -C C06
	$(MAKE) $(MAKECMDGOALS) -C C07
	$(MAKE) $(MAKECMDGOALS) -C C08
	$(MAKE) $(MAKECMDGOALS) -C C09
	$(MAKE) $(MAKECMDGOALS) -C C10
	$(MAKE) $(MAKECMDGOALS) -C C11
	$(MAKE) $(MAKECMDGOALS) -C C0B
