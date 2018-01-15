// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ImportDataWidgets/ImportDataUtils.h
//! @brief     Defines ImportDataUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef IMPORTDATAUTILS_H
#define IMPORTDATAUTILS_H

#include "WinDllMacros.h"
#include <QString>

template <class T> class OutputData;
class RealDataItem;
class GISASInstrumentItem;

//! Provides utility methods to import data files.

namespace ImportDataUtils
{

BA_CORE_API_ OutputData<double>* importData(QString& baseNameOfLoadedFile);

BA_CORE_API_ OutputData<double>* createSimplifiedOutputData(const OutputData<double>& data);

BA_CORE_API_ bool hasSameDimensions(const GISASInstrumentItem* instrumentItem,
                                    const RealDataItem* realDataItem);

BA_CORE_API_ bool hasSameDimensions(const GISASInstrumentItem* instrumentItem,
                                    const RealDataItem* realDataItem, QString& message);

BA_CORE_API_ void realDataShape(const RealDataItem* realData, int& nx, int& ny);

BA_CORE_API_ void detectorShape(const GISASInstrumentItem* instrumentItem, int& nx, int& ny);

BA_CORE_API_ void setInstrumentShapeToData(GISASInstrumentItem* instrumentItem,
                                           const RealDataItem* realDataItemItem);
};

#endif // IMPORTDATAUTILS_H
