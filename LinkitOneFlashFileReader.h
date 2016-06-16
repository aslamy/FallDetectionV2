// LinkitOneFlashFileReader.h

#ifndef _LINKITONEFLASHFILEREADER_h
#define _LINKITONEFLASHFILEREADER_h

#include <LFlash.h>


class LinkitOneFlashFileReader
{
 protected:
	 LFlashClass flash;
	 String fileName;

 public:
	 LinkitOneFlashFileReader(String fileName);
	 String read(void);
	 bool write(String text);
	
};


#endif

