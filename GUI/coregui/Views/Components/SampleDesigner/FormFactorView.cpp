#include "FormFactorView.h"
#include "DesignerHelper.h"


FormFactorView::FormFactorView(QGraphicsItem *parent)
    : ISampleRectView(parent)
    , m_weight(1.0)
{
    setName("FormFactorView");
    setColor(DesignerHelper::getDefaultFormFactorColor());
    setRectangle( QRect(0, 0, DesignerHelper::getDefaultFormFactorWidth(), DesignerHelper::getDefaultFormFactorHeight()) );
    addPort("out", NodeEditorPort::Output, NodeEditorPort::FormFactor);
    addPort("transformation", NodeEditorPort::Input, NodeEditorPort::GeometryTransformation);
    m_roundpar = 5;
}