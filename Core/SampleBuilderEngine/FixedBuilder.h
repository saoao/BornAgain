// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/SampleBuilderEngine/FixedBuilder.h
//! @brief     Defines class FixedBuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2020
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef BORNAGAIN_CORE_SAMPLEBUILDERENGINE_FIXEDBUILDER_H
#define BORNAGAIN_CORE_SAMPLEBUILDERENGINE_FIXEDBUILDER_H

#include "Core/SampleBuilderEngine/ISampleBuilder.h"
#include <memory>

class MultiLayer;

//! A trivial sample builder class that builds a fixed sample.

class FixedBuilder : public ISampleBuilder
{
public:
    FixedBuilder() = delete;
    FixedBuilder(const MultiLayer&);
    MultiLayer* buildSample() const;

private:
    std::unique_ptr<const MultiLayer> m_sample;
};

#endif // BORNAGAIN_CORE_SAMPLEBUILDERENGINE_FIXEDBUILDER_H
