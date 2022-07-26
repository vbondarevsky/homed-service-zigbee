#ifndef PROPERTY_H
#define PROPERTY_H

#include <QMap>
#include <QSharedPointer>
#include <QVariant>
#include "zcl.h"

class PropertyObject;
typedef QSharedPointer <PropertyObject> Property;

class PropertyObject
{

public:

    PropertyObject(const QString &name, quint16 clusterId, bool invalidable = false) :
        m_name(name), m_clusterId(clusterId), m_invalidable(invalidable) {}

    virtual ~PropertyObject(void) {}
    virtual void parseAttribte(quint16, quint8, const QByteArray &) {}
    virtual void parseCommand(quint8, const QByteArray &) {}

    inline QString name(void) { return m_name; }
    inline quint16 clusterId(void) { return m_clusterId; }
    inline QVariant value(void) { return m_value; }

    inline bool invalidable(void) { return m_invalidable; }
    inline void invalidate(void) { m_value = QVariant(); }

    static void registerMetaTypes(void);

protected:

    QString m_name;
    quint16 m_clusterId;
    QVariant m_value;
    bool m_invalidable;

};

namespace Properties
{
    class BatteryVoltage : public PropertyObject
    {

    public:

        BatteryVoltage(void) : PropertyObject("battery", CLUSTER_POWER_CONFIGURATION) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class BatteryVoltageLUMI : public PropertyObject
    {

    public:

        BatteryVoltageLUMI(void) : PropertyObject("battery", CLUSTER_BASIC) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class BatteryPercentage : public PropertyObject
    {

    public:

        BatteryPercentage(void) : PropertyObject("battery", CLUSTER_POWER_CONFIGURATION) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class BatteryPercentageIKEA : public PropertyObject
    {

    public:

        BatteryPercentageIKEA(void) : PropertyObject("battery", CLUSTER_POWER_CONFIGURATION) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class Status : public PropertyObject
    {

    public:

        Status(void) : PropertyObject("status", CLUSTER_ON_OFF) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class Level : public PropertyObject
    {

    public:

        Level(void) : PropertyObject("level", CLUSTER_LEVEL_CONTROL) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class AnalogCO2 : public PropertyObject
    {

    public:

        AnalogCO2(void) : PropertyObject("co2", CLUSTER_ANALOG_INPUT) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    private:

        QVariant m_buffer;

    };

    class AnalogTemperature: public PropertyObject
    {

    public:

        AnalogTemperature(void) : PropertyObject("temperature", CLUSTER_ANALOG_INPUT) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    private:

        QVariant m_buffer;

    };

    class ColorHS : public PropertyObject
    {

    public:

        ColorHS(void) : PropertyObject("colorHS", CLUSTER_COLOR_CONTROL) {};
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    private:

        QVariant m_colorH, m_colorS;

    };

    class ColorXY : public PropertyObject
    {

    public:

        ColorXY(void) : PropertyObject("colorXY", CLUSTER_COLOR_CONTROL) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    private:

        QVariant m_colorX, m_colorY;

    };

    class ColorTemperature : public PropertyObject
    {

    public:

        ColorTemperature(void) : PropertyObject("colorTemperature", CLUSTER_COLOR_CONTROL) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class Illuminance : public PropertyObject
    {

    public:

        Illuminance(void) : PropertyObject("illuminance", CLUSTER_ILLUMINANCE_MEASUREMENT) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class Temperature : public PropertyObject
    {

    public:

        Temperature(void) : PropertyObject("temperature", CLUSTER_TEMPERATURE_MEASUREMENT) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class Humidity : public PropertyObject
    {

    public:

        Humidity(void) : PropertyObject("humidity", CLUSTER_RELATIVE_HUMIDITY) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class Occupancy : public PropertyObject
    {

    public:

        Occupancy(void) : PropertyObject("occupancy", CLUSTER_OCCUPANCY_SENSING, true) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class CubeMovement : public PropertyObject
    {

    public:

        CubeMovement(void) :  PropertyObject("action", CLUSTER_MULTISTATE_INPUT, true) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class CubeRotation : public PropertyObject
    {

    public:

        CubeRotation(void) : PropertyObject("action", CLUSTER_ANALOG_INPUT, true) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class IdentifyAction : public PropertyObject
    {

    public:

        IdentifyAction(void) : PropertyObject("action", CLUSTER_IDENTIFY, true) {}
        void parseCommand(quint8 commandId, const QByteArray &payload) override;

    };

    class SwitchAction : public PropertyObject
    {

    public:

        SwitchAction(void) : PropertyObject("action", CLUSTER_ON_OFF, true) {}
        void parseCommand(quint8 commandId, const QByteArray &payload) override;

    };

    class SwitchActionLUMI : public PropertyObject
    {

    public:

        SwitchActionLUMI(void) : PropertyObject("action", CLUSTER_ON_OFF, true) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class SwitchActionPTVO : public PropertyObject
    {

    public:

        SwitchActionPTVO(void) : PropertyObject("action", CLUSTER_MULTISTATE_INPUT, true) {}
        void parseAttribte(quint16 attributeId, quint8 dataType, const QByteArray &data) override;

    };

    class LevelAction : public PropertyObject
    {

    public:

        LevelAction(void) : PropertyObject("action", CLUSTER_LEVEL_CONTROL, true) {}
        void parseCommand(quint8 commandId, const QByteArray &payload) override;

    };
}

Q_DECLARE_METATYPE(Properties::BatteryVoltage)
Q_DECLARE_METATYPE(Properties::BatteryVoltageLUMI)
Q_DECLARE_METATYPE(Properties::BatteryPercentage)
Q_DECLARE_METATYPE(Properties::BatteryPercentageIKEA)
Q_DECLARE_METATYPE(Properties::Status)
Q_DECLARE_METATYPE(Properties::Level)
Q_DECLARE_METATYPE(Properties::AnalogCO2)
Q_DECLARE_METATYPE(Properties::AnalogTemperature)
Q_DECLARE_METATYPE(Properties::ColorHS)
Q_DECLARE_METATYPE(Properties::ColorXY)
Q_DECLARE_METATYPE(Properties::ColorTemperature)
Q_DECLARE_METATYPE(Properties::Illuminance)
Q_DECLARE_METATYPE(Properties::Temperature)
Q_DECLARE_METATYPE(Properties::Humidity)
Q_DECLARE_METATYPE(Properties::Occupancy)
Q_DECLARE_METATYPE(Properties::CubeMovement)
Q_DECLARE_METATYPE(Properties::CubeRotation)
Q_DECLARE_METATYPE(Properties::IdentifyAction)
Q_DECLARE_METATYPE(Properties::SwitchAction)
Q_DECLARE_METATYPE(Properties::SwitchActionLUMI)
Q_DECLARE_METATYPE(Properties::SwitchActionPTVO)
Q_DECLARE_METATYPE(Properties::LevelAction)

#endif
