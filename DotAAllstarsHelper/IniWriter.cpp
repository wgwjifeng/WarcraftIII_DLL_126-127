#include <iostream>
#include <Windows.h> 

#include "IniWriter.h"

CIniWriter::CIniWriter(const char*  szFileName)
{
	memset(m_szFileName, 0x00, 255);
	memcpy(m_szFileName, szFileName, strlen(szFileName));
}
void CIniWriter::WriteInteger(char* szSection, char* szKey, int iValue)
{
	char szValue[255];
	sprintf_s(szValue, 255, "%d", iValue);
	WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteFloat(char* szSection, char* szKey, float fltValue)
{
	char szValue[255];
	sprintf_s(szValue, 255, "%f", fltValue);
	WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteBOOLean(char* szSection, char* szKey, BOOL bolValue)
{
	char szValue[255];
	sprintf_s(szValue, 255, "%s", bolValue ? "TRUE" : "FALSE");
	WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName);
}
void CIniWriter::WriteString(char* szSection, char* szKey, const char* szValue)
{
	WritePrivateProfileStringA(szSection, szKey, szValue, m_szFileName);
}