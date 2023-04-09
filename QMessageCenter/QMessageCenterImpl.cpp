#include "QMessageCenterImpl.h"

QMessageCenterImpl::~QMessageCenterImpl()
{
}

bool QMessageCenterImpl::initialize(const QStringList& args, QString& error)
{
    return true;
}

bool QMessageCenterImpl::extensionsInitialize()
{
    return true;
}

bool QMessageCenterImpl::delayedInitialize()
{
    return true;
}

void QMessageCenterImpl::sendMessage(Message message)
{
    emit this->nativeMessaged(message);
}
