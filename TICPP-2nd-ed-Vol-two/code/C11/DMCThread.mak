# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt

# Makefile to build ZThread library for the Digital Mars (dmc) compiler under Windows
# First download ZThread source from http://zthread.sourceforge.net/
# Download the Digital Mars compiler from http://www.DigitalMars.com 
# (You must also download and install stlport from that site)
# Unpack the library into the book code tree like this:
# code\
#   C01\
#   C02\
#   ...
#   C10\
#   C11\
#   ZThread\
#     DMCThread.mak
#
# Place this makefile into the ZThread library as shown above.
#
# Compile the library using this makefile and GNU make (see notes about Cywgin below):
#   make -f DMCThread.mak
# The DigitalMars.mak file in C11 and the
# DigitalMars.mak file in the root directory of the code tree have the appropriate 
# settings for the CPPFLAGS variable and LIBLINK variable so that if you run
# make -f DigitalMars.mak DigitalMars
# in C11, or if you run
# make -f DigitalMars.mak
# from the root directory of the code tree, C11 will build correctly.
#
# NOTE: In order to compile ZThread with DMC, you must make the following 
# changes to the ZThread source code, and compile under Cygwin's (www.cygwin.com) GNU make:
#
# 1) Because _handle is a keyword in DMC++, you must rename _handle to xhandle in Monitor.h and Monitor.cxx.
#
# 2) DMC incorrectly requires objects contained in STL containers to have default constructors.
# You must add a default constructor (this should never be called) to struct group_t in 
# PoolExecutor.cxx and ThreadedExecutor.cxx:
# #ifdef __DMC__
#        group_t() { assert(0); } // Fixes www.DigitalMars.com compiler problem
# #endif
#
# 3) For the same reason, you also need to add a default constructor declaration in class Task in Task.h:
# #ifdef __DMC__
#     Task() { assert(0); } // Fixes www.DigitalMars.com compiler problem
# #endif
#

CXX=dmc
CXXFLAGS=-Iinclude -DZT_WIN32=1 -DNDEBUG=1 -Ae -w18 -Nc -c
OBJEXT=obj
LIBPFX=
LIBEXT=lib
# The default librarian name for dmc is "lib" which may conflict with others; change the following
# to that if DMC is the only compiler you have, otherwise change dm/bin/lib.exe to dm/bin/dmlib.exe.
LIBRARIAN=dmlib

.PREFIXES : $(LIBPFX)
.SUFFIXES : .cxx .$(OBJEXT) .exe .$(LIBEXT)

OBJECTS=src\AtomicCount.$(OBJEXT) src\ConcurrentExecutor.$(OBJEXT) src\Condition.$(OBJEXT) src\CountingSemaphore.$(OBJEXT) src\FastMutex.$(OBJEXT) src\FastRecursiveMutex.$(OBJEXT) src\Monitor.$(OBJEXT) src\Mutex.$(OBJEXT) src\PoolExecutor.$(OBJEXT) src\PriorityCondition.$(OBJEXT) src\PriorityInheritanceMutex.$(OBJEXT) src\PriorityMutex.$(OBJEXT) src\PrioritySemaphore.$(OBJEXT) src\RecursiveMutex.$(OBJEXT) src\RecursiveMutexImpl.$(OBJEXT) src\Semaphore.$(OBJEXT) src\SynchronousExecutor.$(OBJEXT) src\Thread.$(OBJEXT) src\ThreadImpl.$(OBJEXT) src\ThreadLocalImpl.$(OBJEXT) src\ThreadOps.$(OBJEXT) src\ThreadQueue.$(OBJEXT) src\ThreadedExecutor.$(OBJEXT) src\Time.$(OBJEXT)

LIBRARY=lib\$(LIBPFX)ZThread.$(LIBEXT)

.cxx.$(OBJEXT) :
	$(CXX) $(CXXFLAGS) $(OFLAGS) $< -o$@

$(LIBRARY): $(OBJECTS)
	mkdir -p lib 
	$(LIBRARIAN) -c -p32 $@ $(OBJECTS)

clean: 
	rm -f $(LIBRARY) $(OBJECTS)