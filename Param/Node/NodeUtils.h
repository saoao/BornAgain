// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Param/Node/NodeUtils.h
//! @brief     Defines collection of utility functions for INode.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_PARAMETRIZATION_NODEUTILS_H
#define BORNAGAIN_CORE_PARAMETRIZATION_NODEUTILS_H

#include <string>

class INode;

namespace NodeUtils
{

//! Returns multiline string representing tree structure starting from given node.
std::string nodeToString(const INode& node);

//! Returns path composed of node's displayName, with respect to root node
std::string nodePath(const INode& node, const INode* root = nullptr);

} // namespace NodeUtils

#endif // BORNAGAIN_CORE_PARAMETRIZATION_NODEUTILS_H
