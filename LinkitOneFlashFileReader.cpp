// 
// 
// 

#include "LinkitOneFlashFileReader.h"


LinkitOneFlashFileReader::LinkitOneFlashFileReader(String fileName)
{
	this->fileName = fileName;
	flash.begin();
}

String LinkitOneFlashFileReader::read()
{
	LFile file = flash.open(fileName.c_str(), FILE_READ);
	String text;
	if (file)
	{
		file.seek(0);
		while(file.available())
		{
			text += (char)file.read();
		}
		file.close();
	}

	return text;
}

bool LinkitOneFlashFileReader::write(String text)
{
	flash.remove((char*)fileName.c_str());
	LFile file = flash.open(fileName.c_str(), FILE_WRITE);

	if (file)
	{
		file.seek(0);
		file.write(text.c_str());
		file.close();
		return true;
	}
	return false;
}
