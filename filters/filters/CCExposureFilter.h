#ifndef CCEXPOSURE_FILTER
#define CCEXPOSURE_FILTER

#include "CCFilter.h"

NS_CC_EXT_BEGIN

//================== ExposureFilter

class ExposureFilter : public SingleFloatParamFilter
{

public:
	static ExposureFilter* create();
	static ExposureFilter* create(float param);

	ExposureFilter();

	virtual void setParameter(float param);
protected:
	virtual GLProgram* loadShader();
	virtual void setAttributes(GLProgram* glp);
	virtual void setUniforms(GLProgram* glp);
};

NS_CC_EXT_END

#endif //CCEXPOSURE_FILTER