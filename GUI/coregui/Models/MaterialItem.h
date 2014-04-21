#ifndef MATERIALITEM_H
#define MATERIALITEM_H

#include <QString>
#include <QStringList>
#include <QColor>
#include <QMap>
#include <QVariant>
#include <QMetaType>

class QXmlStreamWriter;


class MaterialPropertyItem : public QObject
{
    Q_OBJECT
};


namespace MaterialProperties {
const QString RefractiveIndex("Refractive index");
const QString MagneticField("Magnetic field");
}


class MaterialItem : public QObject
{
    Q_OBJECT

public:
    enum MaterialType {
        HomogeneousMaterial,
        HomogeneousMagneticMaterial,
        MaterialProperty
    };

    MaterialItem(const QString &name, MaterialType type);
    ~MaterialItem();
    void setName(const QString &name) { m_name = name;}
    QString getName() const { return m_name; }
    void setType(MaterialType type);
    MaterialType getType() const { return m_type; }
    QString getTypeName() const { return m_type_names.at(int(m_type)); }

    QStringList getMaterialTypes() const;

    virtual QString getTitleString() { return QString(); }

    void setColor(const QColor color) { m_color = color; }
    QColor getColor() const { return m_color;}

    QMap<QString, MaterialItem *> getSubItems() const {
        return m_sub_items;
    }

    bool event(QEvent * e );

    void updateProperties();



    bool setMaterialProperty(QString name, const QVariant &value);

    virtual void writeTo(QXmlStreamWriter *writer);

    virtual void writeProperty(QXmlStreamWriter *writer, MaterialItem *item, const char *property_name);


signals:
    void propertyChanged(QString propertyName);
    void propertyItemChanged(QString propertyName);

public slots:
    void onPropertyItemChanged(QString propertyName);

private:
    void addSubProperty(QString name);
    void removeSubProperty(QString name);

    QString m_name;
    MaterialType m_type;
    QColor m_color;

    static QStringList m_type_names;

    QMap<QString, MaterialItem *> m_sub_items;
};


class RefractiveIndexItem : public MaterialItem
{
    Q_OBJECT

public:
    RefractiveIndexItem() : MaterialItem(MaterialProperties::RefractiveIndex, MaterialItem::MaterialProperty)
    {
        setProperty("delta", QString("1e-3"));
        setProperty("gamma", QString("1e-5"));
    }

    QString getTitleString()
    {

        return QString("(%1, %2)").arg(property("delta").toString(), property("gamma").toString());
    }

    void writeTo(QXmlStreamWriter *writer);

};


class MagneticFieldProperty : public MaterialItem
{
    Q_OBJECT

public:
    MagneticFieldProperty() : MaterialItem(MaterialProperties::MagneticField, MaterialItem::MaterialProperty)
    {
        setProperty("Bx", 0.0);
        setProperty("By", 0.0);
        setProperty("Bz", 0.0);
    }

    QString getTitleString()
    {

        return QString("(%1, %2, %3)").arg(property("Bx").toString(), property("By").toString(), property("Bz").toString());
    }

    void writeTo(QXmlStreamWriter *writer);

};




//Q_DECLARE_METATYPE(RefractiveIndexItem)




#endif
