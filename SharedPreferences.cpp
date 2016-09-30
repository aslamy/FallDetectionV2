// 
// 
// 

#include "SharedPreferences.h"

SharedPreferences::SharedPreferences(String fileName)
{
	fileReader = new LinkitOneFlashFileReader(fileName);
}

String SharedPreferences::getString(String key, String defValue)
{
	JsonObject& root = jsonBuffer.parseObject(fileReader->read());
	String value = root[key];
	return (value.length()) ? value : defValue;
}

void SharedPreferences::putString(String key, String value)
{
	JsonObject& root = jsonBuffer.parseObject(fileReader->read());
	root[key] = value;
	String newValue;
	root.prettyPrintTo(newValue);
	fileReader->write(newValue);
}
