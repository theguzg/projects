#pragma once

#ifndef _STRING_H
#define _STRING_H

//C Runtime Header Files

#ifndef _TCHAR_INC_
	#include <tchar.h>
#endif

#ifndef _STRING_
	#include <string>
#endif

//DEFINES
#ifdef UNICODE
	#define tstring wstring
	#define TOSTRING(value) std::to_wstring(value)
#else
	#define tstring string
	#define  TOSTRING(value) std::to_wstring(value)
#endif


#endif // _STRING_H