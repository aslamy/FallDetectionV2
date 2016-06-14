// DataCapture.h

#ifndef _DATACAPTURE_h
#define _DATACAPTURE_h

template <class T>
class DataCapture
{
public:
	virtual ~DataCapture(){}
	virtual T read(void) = 0;
};


#endif

