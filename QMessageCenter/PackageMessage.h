#pragma once

#include <QObject>

template <typename T>
class Package : public QObject {

private:
    T _data;

public:
    Package(T data)
        : QObject(nullptr)
        , _data(data)
    {
    }

    inline T data() const
    {
        return _data;
    }
};