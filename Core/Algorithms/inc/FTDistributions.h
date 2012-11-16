#ifndef FTDISTRIBUTIONS_H_
#define FTDISTRIBUTIONS_H_
// ********************************************************************
// * The BornAgain project                                            *
// * Simulation of neutron and x-ray scattering at grazing incidence  *
// *                                                                  *
// * LICENSE AND DISCLAIMER                                           *
// * Lorem ipsum dolor sit amet, consectetur adipiscing elit.  Mauris *
// * eget quam orci. Quisque  porta  varius  dui,  quis  posuere nibh *
// * mollis quis. Mauris commodo rhoncus porttitor.                   *
// ********************************************************************
//! @file   FTDistributions.h
//! @brief  Definition of Fourier Transformed distributions
//! @author Scientific Computing Group at FRM II
//! @date   Oct 26, 2012

#include "IParameterized.h"
#include "ParameterPool.h"
#include <cmath>

class IFTDistribution1D
{
public:
    IFTDistribution1D(double omega) : m_omega(omega) {}
    virtual ~IFTDistribution1D() {}

    virtual double evaluate(double q) const=0;
protected:
    double m_omega;
};

class IFTDistribution2D : public IParameterized
{
public:
    IFTDistribution2D(double omega_x, double omega_y) : m_omega_x(omega_x), m_omega_y(omega_y),
        m_gamma(0.0), m_delta(M_PI/2.0) {}
    virtual ~IFTDistribution2D() {}

    virtual IFTDistribution2D *clone() const=0;

    double getGamma() { return m_gamma; }
    double getDelta() { return m_delta; }
    virtual double evaluate(double qx, double qy) const=0;
protected:
    double m_omega_x;
    double m_omega_y;
    double m_gamma;
    double m_delta;
};

class FTDistribution2DCauchy : public IFTDistribution2D
{
public:
    FTDistribution2DCauchy(double omega_x, double omega_y);
    virtual ~FTDistribution2DCauchy() {}

    virtual FTDistribution2DCauchy *clone() const;

    virtual double evaluate(double qx, double qy) const;
protected:
    virtual void init_parameters();
};

#endif /* FTDISTRIBUTIONS_H_ */