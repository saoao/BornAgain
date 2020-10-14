// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Base/Pixel/IPixel.h
//! @brief     Defines pure virtual interface IPixel (has no cpp file)
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_PIXEL_IPIXEL_H
#define BORNAGAIN_CORE_PIXEL_IPIXEL_H

#include "Base/Vector/Vectors3D.h"

//! Interface for a function that maps [0,1]x[0,1] to the kvectors in a pixel.
//! @ingroup detector

class IPixel
{
public:
    virtual ~IPixel() {}

    virtual IPixel* clone() const = 0;
    virtual IPixel* createZeroSizePixel(double x, double y) const = 0;
    virtual kvector_t getK(double x, double y, double wavelength) const = 0;
    virtual double getIntegrationFactor(double x, double y) const = 0;
    virtual double getSolidAngle() const = 0;
};

#endif // BORNAGAIN_CORE_PIXEL_IPIXEL_H
