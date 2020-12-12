#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QTime>
#include <QFile>
#include <QString>

class TCPConnection : public QObject
{
    Q_OBJECT
public:
    explicit TCPConnection(QObject *parent = nullptr);
    ~TCPConnection();
    int idleTime();

    //void sendMessage(QTcpSocket *socket,QString message);
signals:
    void opened();
    void closed();

public slots:
    virtual void quit();
    virtual void accept(qintptr descriptor);
    virtual void connected();
    virtual void disconnected();
    virtual void readyRead();
    virtual void bytesWritten(qint64 bytes);
    virtual void stateChanged(QAbstractSocket::SocketState socketState);
    virtual void error(QAbstractSocket::SocketError socketError);

private:
    bool is_upload_request(QByteArray& msg);
    bool is_new_folder_request(QByteArray& msg);
    bool is_cut_request(QByteArray& msg);
    bool is_copy_request(QByteArray& msg);
    bool is_paste_request(QByteArray& msg);
    bool upload_file(QTcpSocket *socket, QByteArray file_path);

protected:
    QList<QTcpSocket*> sockets;
    QTime activity;

    QTcpSocket* createSocket();
    void active();
};

#endif // TCPCONNECTION_H