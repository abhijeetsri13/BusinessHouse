#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>
using namespace std;
#define LOGGER GlobalLogger::GetLogger()

class GlobalLogger
{
public:
	void Log(const std::string& sMessage);
	GlobalLogger& operator<<(const string& sMessage);
	static GlobalLogger* GetLogger();
private:
	
	GlobalLogger();
	
	GlobalLogger(const GlobalLogger&) {};             
	
	GlobalLogger& operator=(const GlobalLogger&) { return *this; };  

	static std::string m_sFileName;
	
	static GlobalLogger* m_pThis;
	
	static ofstream m_Logfile;
};
