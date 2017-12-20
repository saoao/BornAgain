// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/model/layer.cpp
//! @brief     Implements Layer class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "layer.h"

namespace ba3d {
//------------------------------------------------------------------------------

Layer::Layer(dxyz d) : base(geometry::key(geometry::eid::Box)) {
  transform(d.size(), xyz::_0, d.mid());
}

//------------------------------------------------------------------------------
}
