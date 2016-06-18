// 
// 
// 

#include "SharedPreferences.h"

SharedPreferences* SharedPreferences::preferences = NULL;

SharedPreferences* SharedPreferences::getInstance()
{

	return (preferences)? preferences : preferences = new SharedPreferences() ;
}

String SharedPreferences::getString(String key, String defValue)
{
	JsonObject& root = jsonBuffer.parseObject(fileReader.read());
	String value = root[key];
	return (value.length()) ? value : defValue;
}

void SharedPreferences::putString(String key, String value)
{
	JsonObject& root = jsonBuffer.parseObject(fileReader.read());
	root[key] = value;
	String newValue;
	root.prettyPrintTo(newValue);
	fileReader.write(newValue);
}
