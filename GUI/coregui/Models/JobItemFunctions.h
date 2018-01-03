// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/JobItemFunctions.h
//! @brief     Defines auxiliary functions in JobItemFunctions namespace.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef JOBITEMFUNCTIONS_H
#define JOBITEMFUNCTIONS_H

#include "WinDllMacros.h"
#include <QString>

class JobItem;
class RealDataItem;

//! Contains set of convenience methods for JobItem and its children.

namespace JobItemFunctions
{

BA_CORE_API_ QString jobResultsFileName(const JobItem& jobItem);

BA_CORE_API_ QString jobReferenceFileName(const JobItem& jobItem);

BA_CORE_API_ QString realDataFileName(const RealDataItem& realDataItem);

BA_CORE_API_ QStringList nonXMLFileNameFilters();

}

#endif // JOBITEMFUNCTIONS_H
