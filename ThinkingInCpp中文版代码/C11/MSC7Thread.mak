# From "Thinking in C++, 2nd Edition, Volume 2" 
# by Bruce Eckel & Chuck Allison
# Available at http://www.BruceEckel.com
# (c)2003 MindView Inc. Copyright notice in Copyright.txt

# Makefile to build ZThread library for the Microsoft C++ 7/.NET compiler under Windows
# First download ZThread source from http://zthread.sourceforge.net/
# Install Visual Studio .NET
# You'll have to set your PATH, INCLUDE, and LIB environment variables appropriately
# to run cl from the command line. In particular, you need to include the INCLUDE path for
# windows.h.
# Unpack the library into the book code tree like this:
# code/
#   C01/
#   C02/
#   ...
#   C10/
#   C11/
#   ZThread/
#     MSC7Thread.mak
#
# Place this makefile into the ZThread library as shown above.
#
# Compile the library using this makefile. The makefiles the code tree have the appropriate 
# settings for the CPPFLAGS variable and LIBLINK variable so that if you run
# make Microsoft
# in C11, or if you run
# make Microsoft
# from the root directory of the code tree, C11 will build correctly.
#

CXX=cl
CXXFLAGS=-Iinclude /EHsc -c
OBJEXT=obj
LIBPFX=
LIBEXT=lib
LIBPATH=C:/ProgTools/Microsoft Visual Studio .NET 2003/Vc7/bin/

.PREFIXES : $(LIBPFX)
.SUFFIXES : .cxx .$(OBJEXT) .exe .$(LIBEXT)

OBJECTS=src/AtomicCount.$(OBJEXT) src/ConcurrentExecutor.$(OBJEXT) src/Condition.$(OBJEXT) src/CountingSemaphore.$(OBJEXT) src/FastMutex.$(OBJEXT) src/FastRecursiveMutex.$(OBJEXT) src/Monitor.$(OBJEXT) src/Mutex.$(OBJEXT) src/PoolExecutor.$(OBJEXT) src/PriorityCondition.$(OBJEXT) src/PriorityInheritanceMutex.$(OBJEXT) src/PriorityMutex.$(OBJEXT) src/PrioritySemaphore.$(OBJEXT) src/RecursiveMutex.$(OBJEXT) src/RecursiveMutexImpl.$(OBJEXT) src/Semaphore.$(OBJEXT) src/SynchronousExecutor.$(OBJEXT) src/Thread.$(OBJEXT) src/ThreadImpl.$(OBJEXT) src/ThreadLocalImpl.$(OBJEXT) src/ThreadOps.$(OBJEXT) src/ThreadQueue.$(OBJEXT) src/ThreadedExecutor.$(OBJEXT) src/Time.$(OBJEXT)

LIBRARY=lib/$(LIBPFX)ZThread.$(LIBEXT)

.cxx.$(OBJEXT) :
	$(CXX) $(CXXFLAGS) $(OFLAGS) $< /Fo$@

$(LIBRARY): $(OBJECTS)
	mkdir -p lib 
	$(LIBPATH)lib -c -p32 $@ $(OBJECTS)

clean: 
	rm -f $(LIBRARY) $(OBJECTS)