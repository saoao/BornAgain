#ifndef PARTICLEVIEW_H
#define PARTICLEVIEW_H


#include "ConnectableView.h"
#include <QPixmap>

//! Class representing view of Particle item
class ParticleView : public ConnectableView
{
    Q_OBJECT

public:
    enum { Type = DesignerHelper::ParticleType };

    ParticleView(QGraphicsItem *parent = 0);

    int type() const { return Type; }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setParameterizedItem(ParameterizedItem *item);

    void onPropertyChange(QString propertyName);

private:
    QPixmap m_pixmap;

};



#endif