#include "stdafx.h"
#include "mCJson.h"

mCJson::mCJson()
{
}
mCJson::~mCJson()
{

}

void strtojson(CStringW str, Json::Value &json)
{
	string s = utoa(str);

	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if( r->parse(s.c_str(), s.c_str() + s.size(), &json, &e) )
	{
	}
	else
	{
	}
	delete r;
}
void strtojson(CStringA str, Json::Value &json)
{
	string s = string(str);

	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(s.c_str(), s.c_str() + s.size(), &json, &e))
	{
	}
	else
	{
	}
	delete r;
}
void strtojson(string str, Json::Value &json)
{
	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(str.c_str(), str.c_str() + str.size(), &json, &e))
	{
	}
	else
	{
	}
	delete r;
}
void strtojson(const char *str, Json::Value &json)
{
	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(str, str + strlen(str), &json, &e))
	{
	}
	else
	{
	}
	delete r;
}
Json::Value strtojson(CStringW str)
{
	Json::Value json;

	string s = utoa(str);

	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(s.c_str(), s.c_str() + s.size(), &json, &e))
	{
	}
	else
	{
	}
	delete r;

	return json;
}
Json::Value strtojson(CStringA str)
{
	Json::Value json;

	string s = string(str);

	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(s.c_str(), s.c_str() + s.size(), &json, &e))
	{
	}
	else
	{
	}
	delete r;

	return json;
}
Json::Value strtojson(string str)
{
	Json::Value json;

	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(str.c_str(), str.c_str() + str.size(), &json, &e))
	{
	}
	else
	{
	}
	delete r;

	return json;
}
Json::Value strtojson(const char *str)
{
	Json::Value json;

	Json::CharReaderBuilder b;
	Json::CharReader *r(b.newCharReader());
	string e;
	if (r->parse(str, str + strlen(str), &json, &e))
	{
	}
	else
	{
	}
	delete r;

	return json;
}

void jsontostr(Json::Value json, CStringW &str)
{
	Json::StreamWriterBuilder writer;

	str = atou(Json::writeString(writer, json).c_str());
}
void jsontostr(Json::Value json, CStringA &str)
{
	Json::StreamWriterBuilder writer;

	str = Json::writeString(writer, json).c_str();
}
void jsontostr(Json::Value json, string &str)
{
	Json::StreamWriterBuilder writer;

	str = Json::writeString(writer, json);
}
CStringW jsontostrU(Json::Value json)
{
	CStringW str;

	Json::StreamWriterBuilder writer;

	str = atou(Json::writeString(writer, json).c_str());

	return str;
}
CStringA jsontostrA(Json::Value json)
{
	CStringA str;

	Json::StreamWriterBuilder writer;

	str = Json::writeString(writer, json).c_str();

	return str;
}
string jsontostr(Json::Value json)
{
	string str;

	Json::StreamWriterBuilder writer;

	str = Json::writeString(writer, json);

	return str;
}

void filetojson(CStringW file, Json::Value &json)
{
	::ToAbsolutePath(file);
	CStringW str;
	::filetostr(file, str);
	::strtojson(str, json);
}
Json::Value filetojson(CStringW file)
{
	return ::strtojson(::filetostr(::ToAbsolutePath(file)));
}
void jsontofile(Json::Value json, CStringW file)
{
	string str;
	::jsontostr(json, str);
	::strtofile(str, file);
}

void FillRs(Json::Value &rs)
{
	SYSTEMTIME systime; ::GetLocalTime(&systime);
	CTime tm(systime);
	CStringA csa;
	csa.Format("%d-%02d-%02d %02d:%02d:%02d",
		systime.wYear, systime.wMonth, systime.wDay,
		systime.wHour, systime.wMinute, systime.wSecond
	);

	SYSTEMTIME systimeUTC; ::GetSystemTime(&systimeUTC);
	CTime tmUTC(systimeUTC);
	CStringA csaUTC;
	csaUTC.Format("%d-%02d-%02d %02d:%02d:%02d",
		systimeUTC.wYear, systimeUTC.wMonth, systimeUTC.wDay,
		systimeUTC.wHour, systimeUTC.wMinute, systimeUTC.wSecond
	);

	rs["biClientTime"] = tm.GetTime() * 1000i64 + systime.wMilliseconds;
	rs["dtClientTime"] = string(csa);
	rs["dtClientTimeUTC"] = string(csaUTC);
	rs["siClientTimeMS"] = systime.wMilliseconds;
	rs["siClientTimezone"] = (tm - tmUTC).GetHours();
	rs["tiClientWeek"] = systime.wDayOfWeek;
	rs["tiClientWeekUTC"] = systimeUTC.wDayOfWeek;

	rs["biSyncTime"] = rs["biClientTime"];
	rs["dtSyncTime"] = rs["dtClientTime"];
	rs["dtSyncTimeUTC"] = rs["dtClientTimeUTC"];
	rs["siSyncTimeMS"] = rs["siClientTimeMS"];
	rs["siSyncTimezone"] = rs["siClientTimezone"];
	rs["tiSyncWeek"] = rs["tiClientWeek"];
	rs["tiSyncWeekUTC"] = rs["tiClientWeekUTC"];
}