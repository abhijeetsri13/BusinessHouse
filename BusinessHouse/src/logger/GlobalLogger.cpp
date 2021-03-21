//#include"pch.h"
#include"..\..\include\logger\GlobalLogger.h"
#include"..\..\include\logger\MyUtil.h"
#include <string>
#include<iostream>

std::string GlobalLogger::m_sFileName("Log.txt");
GlobalLogger* GlobalLogger::m_pThis = nullptr;
std::ofstream GlobalLogger::m_Logfile;
GlobalLogger::GlobalLogger()
{

}
GlobalLogger* GlobalLogger::GetLogger() {
	if (m_pThis == nullptr) {
		m_pThis = new GlobalLogger();
		m_Logfile.open(m_sFileName.c_str(), ios::out | ios::app);
	}
	return m_pThis;
}

void GlobalLogger::Log(const string& sMessage)
{
	m_Logfile << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
}

GlobalLogger& GlobalLogger::operator<<(const string& sMessage)
{
	m_Logfile << "\n" << Util::CurrentDateTime() << ":\t";
	m_Logfile << sMessage << "\n";
	return *this;
}
