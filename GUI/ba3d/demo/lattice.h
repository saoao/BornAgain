// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/ba3d/demo/lattice.h
//! @brief     Defines Lattice class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BA3D_LATTICE_H
#define BA3D_LATTICE_H

#include <ba3d/def.h>
#include <QVector>

//------------------------------------------------------------------------------

class Lattice : public QVector<ba3d::xyz> {
public:
  using super = QVector<ba3d::xyz>;

  Lattice();
  Lattice(uint n, uint nn);

  uint index(int ix, int iy);
  int ix(uint);
  int iy(uint);
  uint n;
};

Lattice squareLattice(uint n, float sigma); // n half-size

//------------------------------------------------------------------------------
#endif
