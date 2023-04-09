#pragma once

#include <QObject>

#include "QMessageCenter.h"

class QMessageCenterImpl : public QMessageCenter {
    Q_OBJECT;
    Q_INTERFACES(QMessageCenter)
    Q_PLUGIN_METADATA(IID "cn.hiyj.QMessageCenter" FILE "QMessageCenter.json")

public:
    ~QMessageCenterImpl() override;

    /**
     * @brief 批量初始化
     * @param args 程序启动参数
     * @param error 初始化错误信息
     * @return 初始化状态
     */
    bool initialize(const QStringList& args, QString& error) override;

    /**
     * @brief 初始化之后扩展初始化
     * @return 初始化状态
     */
    bool extensionsInitialize() override;

    /**
     * @brief 延迟初始化，执行信号功能
     * @return 初始化状态
     */
    bool delayedInitialize() override;

    /**
     * @brief 发送消息
     * @param message 消息体
     */
    void sendMessage(Message message) override;

public:
signals:
    /**
     * @brief 分发信息消息
     * @param message 消息体
     */
    void nativeMessaged(Message message) override;
};