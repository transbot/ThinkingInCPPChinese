# DigitalMars C++ master makefile for "Thinking in C++, 2nd Edition, Volume 2"
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2004 MindView Inc. Copyright notice in Copyright.txt
# Compiles all the code in the book for the Digital Mars C++ compiler
# Free compiler download and instructions at www.DigitalMars.com

DigitalMars: # hack to compensate for this particular compiler
	$(MAKE) -C TestSuite DigitalMars -f DigitalMars.mak
	$(MAKE) -C C01 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C02 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C03 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C04 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C05 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C06 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C07 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C08 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C09 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C10 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C11 DigitalMars -f DigitalMars.mak
	$(MAKE) -C C0B DigitalMars -f DigitalMars.mak
