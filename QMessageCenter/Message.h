#pragma once

#include <QObject>
#include <QPointer>
#include <QSharedPointer>

class Message {
public:
    inline explicit Message()
    {
    }

    inline explicit Message(const QString& type, QPointer<QObject> from, QSharedPointer<QObject> rData)
        : _type(type)
        , _from(from)
        , _data(nullptr)
    {
        _rData = rData;
    }

    inline explicit Message(const QString& type, QPointer<QObject> from, QObject* data)
        : _type(type)
        , _from(from)
    {
        _data = data;
    }
    inline explicit Message(const QString& type, QPointer<QObject> from, QSharedPointer<QObject> rData, QObject* data)
        : _type(type)
        , _from(from)
    {
        _rData = rData;
        _data = data;
    }

    inline ~Message() { }

    /**
     * @brief 来源智能指针，不进行释放操作
     * @return QPointer{from}
     */
    inline QPointer<QObject> from()
    {
        return _from;
    }
    /**
     * @brief 携带数据共享智能指针,零引用时自动释放
     * @return QSharedDataPointer{data}
     */
    inline QSharedPointer<QObject> rData() const
    {
        return _rData;
    }

    /**
     * @brief 携带数据原始指针,不自动释放
     * @return data
     */
    inline QObject* data() const
    {
        return _data;
    }

    /**
     * @brief 消息类型
     */
    inline QString type() const
    {
        return _type;
    }

    /**
     * @brief 复制构造
     * @param other 消息体
     */
    inline Message(const Message& other)
    {
        _from = other._from;
        _data = other._data;
        _type = other._type;
        _rData = other._rData;
    }

protected:
    /**
     * @brief  来源QObject
     */
    QPointer<QObject> _from;

    /**
     * @brief 携带数据
     */
    QSharedPointer<QObject> _rData;

    /**
     * @brief 携带数据
     */
    QObject* _data;

    /**
     * @brief 消息类型
     */
    QString _type;
};
