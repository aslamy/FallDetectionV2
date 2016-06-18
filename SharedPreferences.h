// SharedPreferences.h

#ifndef _SHAREDPREFERENCES_h
#define _SHAREDPREFERENCES_h
#include <Arduino.h>
#include "LinkitOneFlashFileReader.h"
#include <ArduinoJson.h>

#define  FILE_NAME "settings.txt"

class SharedPreferences
{

public:
	static SharedPreferences* getInstance();
	String getString(String key, String defValue);
	void putString(String key, String value);
private:
	SharedPreferences() : fileReader(FILE_NAME)
	{};
	static SharedPreferences *preferences;
	LinkitOneFlashFileReader fileReader;
	DynamicJsonBuffer jsonBuffer;
};



#endif

