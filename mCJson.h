#pragma once

#include "json/json.h"

#if _MSC_VER == 1600
	#if defined _M_X64
		#ifdef _DEBUG
			#pragma comment(lib, "../../../base/mCJson/VS2010/64/Debug/lib-jsoncpp.lib")
		#else
			#pragma comment(lib, "../../../base/mCJson/VS2010/64/Release/lib-jsoncpp.lib")
		#endif
	#else
		#ifdef _DEBUG
			#pragma comment(lib, "../../../base/mCJson/VS2010/32/Debug/lib-jsoncpp.lib")
		#else
			#pragma comment(lib, "../../../base/mCJson/VS2010/32/Release/lib-jsoncpp.lib")
		#endif
	#endif
#else
	#if defined _M_X64
		#ifdef _DEBUG
			#pragma comment(lib, "../../../base/mCJson/VS2015/64/Debug/lib-jsoncpp.lib")
		#else
			#pragma comment(lib, "../../../base/mCJson/VS2015/64/Release/lib-jsoncpp.lib")
		#endif
	#else
		#ifdef _DEBUG
			#pragma comment(lib, "../../../base/mCJson/VS2015/32/Debug/lib-jsoncpp.lib")
		#else
			#pragma comment(lib, "../../../base/mCJson/VS2015/32/Release/lib-jsoncpp.lib")
		#endif
	#endif
#endif

class mCJson
{
public:
	mCJson();
	~mCJson();
};

void strtojson(CStringW cstr, Json::Value &json);
void strtojson(CStringA cstr, Json::Value &json);
void strtojson(string str, Json::Value &json);
void strtojson(const char *pstr, Json::Value &json);
Json::Value strtojson(CStringW str);
Json::Value strtojson(CStringA str);
Json::Value strtojson(string str);
Json::Value strtojson(const char *str);

void jsontostr(Json::Value json, CStringW &str);
void jsontostr(Json::Value json, CStringA &str);
void jsontostr(Json::Value json, string &str);
CStringW jsontostrU(Json::Value json);
CStringA jsontostrA(Json::Value json);
string jsontostr(Json::Value json);

void filetojson(CStringW file, Json::Value &json);
Json::Value filetojson(CStringW file);
void jsontofile(Json::Value json, CStringW file);

void FillRs(Json::Value &rs);