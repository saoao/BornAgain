// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Algorithms/inc/DecoratedLayerDWBASimulation.h
//! @brief     Defines class DecoratedLayerDWBASimulation.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef DECORATEDLAYERDWBASIMULATION_H_
#define DECORATEDLAYERDWBASIMULATION_H_

#include "LayerDWBASimulation.h"
#include "IInterferenceFunctionStrategy.h"
#include "DiffuseDWBASimulation.h"

class Layer;

//! Calculates scattering cross sections in DWBA for a layer with particles in/on it

class DecoratedLayerDWBASimulation : public LayerDWBASimulation
{
public:
    DecoratedLayerDWBASimulation(const Layer *p_layer);
    virtual ~DecoratedLayerDWBASimulation();

    DecoratedLayerDWBASimulation *clone() const
    {
        throw NotImplementedException("LayerDecoratorDWBASimulation::clone() -> "
                                      "Error: not implemented.");
    }

    virtual void init(const Simulation& simulation);

    virtual void run();
protected:
    void runMagnetic(const IInterferenceFunctionStrategy *p_strategy);

    Layer *mp_layer;
    DiffuseDWBASimulation *mp_diffuseDWBA;

private:
    IInterferenceFunctionStrategy *createAndInitStrategy() const;
    void calculateCoherentIntensity(const IInterferenceFunctionStrategy *p_strategy);
    void calculateInCoherentIntensity();

};

#endif /* DECORATEDLAYERDWBASIMULATION_H_ */

