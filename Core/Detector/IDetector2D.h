// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Detector/IDetector2D.h
//! @brief     Defines interface IDetector2D.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_DETECTOR_IDETECTOR2D_H
#define BORNAGAIN_CORE_DETECTOR_IDETECTOR2D_H

#include "Core/Detector/DetectorMask.h"
#include "Core/Detector/IDetector.h"
#include <memory>

class Beam;
class IPixel;
class IShape2D;
class DetectorContext;

//! Abstract 2D detector interface.
//! @ingroup detector

class IDetector2D : public IDetector
{
public:
    IDetector2D();

    IDetector2D* clone() const override = 0;

    virtual ~IDetector2D();

    //! Sets detector parameters using angle ranges
    void setDetectorParameters(size_t n_x, double x_min, double x_max, size_t n_y, double y_min,
                               double y_max);

    //! Removes all masks from the detector
    void removeMasks();

    const DetectorMask* detectorMask() const override;

    //! Adds mask of given shape to the stack of detector masks. The mask value 'true' means
    //! that the channel will be excluded from the simulation. The mask which is added last
    //! has priority.
    //! @param shape The shape of mask (Rectangle, Polygon, Line, Ellipse)
    //! @param mask_value The value of mask
    void addMask(const IShape2D& shape, bool mask_value = true);

    //! Put the mask for all detector channels (i.e. exclude whole detector from the analysis)
    void maskAll();

    //! Returns region of  interest if exists.
    const RegionOfInterest* regionOfInterest() const override;

    //! Sets rectangular region of interest with lower left and upper right corners defined.
    void setRegionOfInterest(double xlow, double ylow, double xup, double yup);

    //! Resets region of interest making whole detector plane available for the simulation.
    void resetRegionOfInterest() override;

    //! Returns vector of unmasked detector indices.
    std::vector<size_t> active_indices() const;

    //! Creates an IPixel for the given OutputData object and index
    virtual IPixel* createPixel(size_t index) const = 0;

    //! Returns index of pixel that contains the specular wavevector.
    //! If no pixel contains this specular wavevector, the number of pixels is
    //! returned. This corresponds to an overflow index.
    virtual size_t indexOfSpecular(const Beam& beam) const = 0;

#ifndef SWIG
    std::unique_ptr<DetectorContext> createContext() const;
#endif

protected:
    IDetector2D(const IDetector2D& other);

    //! Calculate global index from two axis indices
    size_t getGlobalIndex(size_t x, size_t y) const;

private:
    DetectorMask m_detector_mask;
    std::unique_ptr<RegionOfInterest> m_region_of_interest;
};

#endif // BORNAGAIN_CORE_DETECTOR_IDETECTOR2D_H
