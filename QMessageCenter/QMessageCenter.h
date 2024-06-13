#pragma once

#include "QMessageCenter_global.h"

#include "Message.h"
#include "PluginInterface.h"

#ifndef MESSAGE_CENTER
#define MESSAGE_CENTER []() { auto&& opt = GetPluginPtr(QMessageCenter);return opt.value(); }()
#endif

class QMessageCenter : public PluginInterface {
public:
    virtual ~QMessageCenter() = 0;

    /**
     * @brief 批量初始化
     * @param args 程序启动参数
     * @param error 初始化错误信息
     * @return 初始化状态
     */
    virtual bool initialize(const QStringList& args, QString& error) = 0;

    /**
     * @brief 初始化之后扩展初始化
     * @return 初始化状态
     */
    virtual bool extensionsInitialize() = 0;

    /**
     * @brief 延迟初始化，执行信号功能
     * @return 初始化状态
     */
    virtual bool delayedInitialize() = 0;

    /**
     * @brief 发送消息
     * @param message 消息体
     */
    virtual void sendMessage(Message message) = 0;

public:
    /**
     * @brief 分发信息消息
     * @param message 消息体
     */
    virtual void nativeMessaged(Message message) = 0;
};

QT_BEGIN_NAMESPACE
Q_DECLARE_INTERFACE(QMessageCenter, "cn.hiyj.QMessageCenter")
QT_END_NAMESPACE