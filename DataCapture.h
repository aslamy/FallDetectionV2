// DataCapture.h

#ifndef _DATACAPTURE_h
#define _DATACAPTURE_h

template <class T,class V>
class DataCapture
{
public:
	virtual ~DataCapture()
	{
	}

	virtual T read(V) = 0;
};


#endif
