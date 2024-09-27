//: C02:MemCheck.h
#ifndef MEMCHECK_H
#define MEMCHECK_H

#include <cstddef> // Ϊ��ʹ��size_t

// ����new������������������汾��
void* operator new(std::size_t, const char*, long);
void* operator new[](std::size_t, const char*, long);
#define new new (__FILE__, __LINE__)

extern bool traceFlag;
#define TRACE_ON() traceFlag = true
#define TRACE_OFF() traceFlag = false

extern bool activeFlag;
#define MEM_ON() activeFlag = true
#define MEM_OFF() activeFlag = false

#endif // MEMCHECK_H ///:~
