// TestToneCapture.h

#ifndef _TESTTONECAPTURE_h
#define _TESTTONECAPTURE_h

#include "DataCapture.h"

class TestToneCapture :public DataCapture<double>
{
 

public:


	double read();
private:

};

#endif

