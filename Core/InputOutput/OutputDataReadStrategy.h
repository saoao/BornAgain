// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/InputOutput/OutputDataReadStrategy.h
//! @brief     Defines IOutputDataReadStrategy and related classes.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_INPUTOUTPUT_OUTPUTDATAREADSTRATEGY_H
#define BORNAGAIN_CORE_INPUTOUTPUT_OUTPUTDATAREADSTRATEGY_H

#include <istream>

template <class T> class OutputData;

//! Interface for reading strategy of OutputData from file.
//! @ingroup input_output_internal

class IOutputDataReadStrategy
{
public:
    virtual ~IOutputDataReadStrategy() {}
    virtual OutputData<double>* readOutputData(std::istream& input_stream) = 0;
};

//! Strategy to read BornAgain native IntensityData from ASCII file.
//! @ingroup input_output_internal

class OutputDataReadINTStrategy : public IOutputDataReadStrategy
{
public:
    OutputData<double>* readOutputData(std::istream& input_stream);
};

//! Strategy to read Reflectometry data from ASCII file.
//! @ingroup input_output_internal

class OutputDataReadReflectometryStrategy : public IOutputDataReadStrategy
{
public:
    OutputData<double>* readOutputData(std::istream& input_stream);
};

//! Strategy to read OutputData from simple ASCII file with the layout as in numpy.savetxt.
//! @ingroup input_output_internal

class OutputDataReadNumpyTXTStrategy : public IOutputDataReadStrategy
{
public:
    OutputData<double>* readOutputData(std::istream& input_stream);
};

#ifdef BORNAGAIN_TIFF_SUPPORT

class TiffHandler;

//! Strategy to read a TIFF file.
//! @ingroup input_output_internal

class OutputDataReadTiffStrategy : public IOutputDataReadStrategy
{
public:
    OutputDataReadTiffStrategy();
    virtual ~OutputDataReadTiffStrategy();
    virtual OutputData<double>* readOutputData(std::istream& input_stream);

private:
    TiffHandler* m_d;
};
#endif // BORNAGAIN_TIFF_SUPPORT

#endif // BORNAGAIN_CORE_INPUTOUTPUT_OUTPUTDATAREADSTRATEGY_H
