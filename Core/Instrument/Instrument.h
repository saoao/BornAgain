// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Instrument/Instrument.h
//! @brief     Defines class Instrument.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include "INode.h"
#include "Beam.h"
#include "IDetector2D.h"
#include <memory>

template<class T> class OutputData;
class IAxis;
class IResolutionFunction2D;
class SimulationElement;

//! Assembles beam, detector and their relative positions wrt the sample.
//! @ingroup simulation_internal

class BA_CORE_API_ Instrument : public INode
{
public:
    Instrument();
    Instrument(const Instrument& other);
    Instrument& operator=(const Instrument& other);

    virtual ~Instrument();

    void accept(INodeVisitor* visitor) const final { visitor->visit(this); }

    Beam& getBeam() { return m_beam; }
    const Beam& getBeam() const { return m_beam; }
    void setBeam(const Beam& beam);

    //! Sets the beam wavelength and incoming angles
    void setBeamParameters(double wavelength, double alpha_i, double phi_i);

    //! Sets the beam's intensity
    void setBeamIntensity(double intensity);

    //! Sets the beam's polarization according to the given Bloch vector
    void setBeamPolarization(const kvector_t bloch_vector);

    //! Returns the beam's intensity
    double getBeamIntensity() const;

    //! Returns the detector data
    const IDetector2D* getDetector() const;
    IDetector2D* getDetector();

    //! Returns 2D detector data if detector is truly 2D. Otherwise returns nullptr
    IDetector2D* detector2D();

    const DetectorMask *getDetectorMask() const;

    //! Returns a detector axis
    const IAxis& getDetectorAxis(size_t index) const;

    //! Returns the detector's dimension
    size_t getDetectorDimension() const;

    //! Sets the detector (axes can be overwritten later)
    void setDetector(const IDetector2D& detector);

    //! Sets detector resolution function
    void setDetectorResolutionFunction(const IResolutionFunction2D& p_resolution_function);

    //! Removes detector resolution function.
    void removeDetectorResolution();

    //! Sets the polarization analyzer characteristics of the detector
    void setAnalyzerProperties(const kvector_t direction, double efficiency,
                               double total_transmission);

    //! apply the detector resolution to the given intensity map
    void applyDetectorResolution(OutputData<double>* p_intensity_map) const;

    //! Returns new intensity map with detector resolution applied and axes in requested units
    OutputData<double>* createDetectorIntensity(const std::vector<SimulationElement> &elements,
            AxesUnits units=AxesUnits::DEFAULT) const;

    //! Returns histogram representing intensity map in requested axes units
    Histogram2D* createIntensityData(const std::vector<SimulationElement> &elements,
            AxesUnits units_type = AxesUnits::DEFAULT) const;

    //! Returns empty detector map in given axes units.
    virtual OutputData<double>* createDetectorMap(
            AxesUnits units=AxesUnits::DEFAULT) const;

#ifndef SWIG
    //! Create a vector of SimulationElement objects according to the beam, detector and its mask
    std::vector<SimulationElement> createSimulationElements();
#endif

    //! init detector with beam settings
    void initDetector();

    std::vector<const INode*> getChildren() const;

protected:
    //! Registers some class members for later access via parameter pool
    virtual void init_parameters() {}

    std::unique_ptr<IDetector2D> mP_detector;
    Beam m_beam;
};

#endif // INSTRUMENT_H
