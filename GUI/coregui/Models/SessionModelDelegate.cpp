// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/SessionModelDelegate.cpp
//! @brief     Implements class SessionModelDelegate
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "SessionModelDelegate.h"
#include "PropertyBrowserUtils.h"
#include <QApplication>

namespace {

bool isComboProperty(const QModelIndex& index)
{
    return index.data().canConvert<ComboProperty>();
}

bool isGroupProperty(const QModelIndex& index)
{
    return index.data().canConvert<GroupProperty_t>();
}

}


SessionModelDelegate::SessionModelDelegate(QWidget *parent)
    : QStyledItemDelegate(parent)
{

}

void SessionModelDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option,
                                 const QModelIndex& index) const
{
    QVariant prop_value = index.model()->data(index, Qt::EditRole);

    if (isComboProperty(index)) {
        ComboProperty property = prop_value.value<ComboProperty>();
        paintCustomLabel(painter, option, index, property.getValue());

    } else if (isGroupProperty(index)) {
        GroupProperty_t property = prop_value.value<GroupProperty_t>();
        paintCustomLabel(painter, option, index, property->currentType());

    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}

QWidget *SessionModelDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    if (isComboProperty(index)) {
        ComboPropertyEdit *editor = new ComboPropertyEdit(parent);
        ComboProperty combo = index.data().value<ComboProperty>();
        editor->setComboProperty(combo);
        connect(editor, SIGNAL(comboPropertyChanged(const ComboProperty &)),
                this, SLOT(onComboPropertyChanged(const ComboProperty &)));
        return editor;

    }else if (isGroupProperty(index)) {
        return nullptr;

    } else {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }

}

void SessionModelDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                        const QModelIndex &index) const
{
    if (isComboProperty(index)) {
        ComboPropertyEdit *comboEditor = qobject_cast<ComboPropertyEdit *>(editor);
        model->setData(index, comboEditor->getComboProperty().getVariant());
    } else {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

}

void SessionModelDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if (isComboProperty(index)) {
        //as using custom widget, doing nothing here
    } else {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void SessionModelDelegate::onComboPropertyChanged(const ComboProperty &property)
{
    Q_UNUSED(property);
    ComboPropertyEdit *editor = qobject_cast<ComboPropertyEdit *>(sender());
    Q_ASSERT(editor);
    emit commitData(editor);
    //emit closeEditor(editor); // Qt by default leaves editor alive after editing finished
}

//! Paints custom text in a a place corresponding given index.

void SessionModelDelegate::paintCustomLabel(QPainter *painter,
                                            const QStyleOptionViewItem& option,
                                            const QModelIndex& index,
                                            const QString& text) const
{
    QStyleOptionViewItem opt = option;
    initStyleOption(&opt, index); // calling original method to take into accounts colors etc
    opt.text = displayText(text, option.locale); // by overriding text with ours
    const QWidget *widget = opt.widget;
    QStyle *style = widget ? widget->style() : QApplication::style();
    style->drawControl(QStyle::CE_ItemViewItem, &opt, painter, widget);
}
