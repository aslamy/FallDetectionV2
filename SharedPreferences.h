// SharedPreferences.h

#ifndef _SHAREDPREFERENCES_h
#define _SHAREDPREFERENCES_h
#include <Arduino.h>
#include "LinkitOneFlashFileReader.h"
#include <ArduinoJson.h>


class SharedPreferences
{

public:
	SharedPreferences(String fileName);
	String getString(String key, String defValue);
	void putString(String key, String value);
private:
	LinkitOneFlashFileReader *fileReader;
	ArduinoJson::DynamicJsonBuffer jsonBuffer;
};



#endif

