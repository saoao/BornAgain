// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/ParticleDistributionItem.h
//! @brief     Defines class ParticleDistributionItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef PARTICLEDISTRIBUTIONITEM_H
#define PARTICLEDISTRIBUTIONITEM_H

#include "SessionGraphicsItem.h"
#include "ParticleDistribution.h"

class BA_CORE_API_ ParticleDistributionItem : public SessionGraphicsItem
{
public:
    static const QString P_DISTRIBUTED_PARAMETER;
    static const QString P_DISTRIBUTION;
    static const QString NO_SELECTION;
    static const QString T_PARTICLES;
    ParticleDistributionItem();

    std::unique_ptr<ParticleDistribution> createParticleDistribution() const;

    void setDomainCacheName(const QString& name);

private:
    void updateParameterList();
    void initDistributionItem();
    QStringList childParameterNames() const;
    QString translateParameterNameToGUI(const QString& domainName);
    const SessionItem* childParticle() const;
    QString m_domain_cache_name;
};

#endif // PARTICLEDISTRIBUTIONITEM_H

