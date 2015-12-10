// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/MaskWidgets/MaskContainerView.h
//! @brief     Defines MaskContainerView class
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MASKCONTAINERVIEW_H
#define MASKCONTAINERVIEW_H

#include "IMaskView.h"
#include "SizeHandleElement.h"
#include <QMap>

//! The MaskContainerView is nothing move than just transparent rectangle to cover axes area
//! of ColorMapPlot inside MaskGraphicsScene. The goal of this rectangle is to hide all MaskViews
//! if they are going outside of ColorMapPlot.
//!
//! The size of the rectangle always matches axes viewport at any zoom level.
//! All MasksViews are added to MaskContainerView as children.

class BA_CORE_API_ MaskContainerView : public IMaskView
{
    Q_OBJECT
public:
    MaskContainerView();

public slots:
    void update_view();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif
