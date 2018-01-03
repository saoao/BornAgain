// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/utils/LayoutUtils.h
//! @brief     Defines LayoutUtils namespace
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef LAYOUTUTILS_H
#define LAYOUTUTILS_H

#include "WinDllMacros.h"

class QGridLayout;

//! Utility functions to add/remove widgets to the layout on the fly.
//! Taken from https://stackoverflow.com/questions/5395266/removing-widgets-from-qgridlayout

namespace LayoutUtils
{

//! Removes row from grid layout (important: doesn't change row count).
BA_CORE_API_ void removeRow(QGridLayout *layout, int row, bool deleteWidgets = true);

//! Removes column from grid layout.
BA_CORE_API_ void removeColumn(QGridLayout *layout, int column, bool deleteWidgets = true);

//! Clear layout completely.
BA_CORE_API_ void clearLayout(QGridLayout* layout, bool deleteWidgets = true);
}

#endif
