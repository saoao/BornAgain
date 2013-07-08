#ifndef ISGISAXS02BUILDER_H
#define ISGISAXS02BUILDER_H

#include "ISampleBuilder.h"

//! The IsGISAXS02Builder class to build sample: mixture cylinder particles with
//! different size distribution (IsGISAXS example #2)
class IsGISAXS02Builder : public ISampleBuilder
{
public:
    IsGISAXS02Builder();
    ISample *buildSample() const;

protected:
    void init_parameters();

private:
    double m_radius1;
    double m_radius2;
    double m_height1;
    double m_height2;
    double m_sigma1_ratio;
    double m_sigma2_ratio;
};

#endif // ISGISAXS02BUILDER_H
