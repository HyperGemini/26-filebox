#include "ui_filebox.h"
#include "filebox.h"
#include "tcpclient.h"

#include <QMessageBox>

FileBox::FileBox(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FileBox)
{
    ui->setupUi(this);
    ui->twLocalFiles->setViewFolder("");
    ui->twRemoteFiles->setViewFolder("");
}

FileBox::~FileBox()
{
    delete ui->twLocalFiles->model();
    delete ui->twRemoteFiles->model();
    m_socket->close();
    delete m_socket;
    delete ui;
}

void FileBox::paintEvent(QPaintEvent*)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void FileBox::setFormLogin(Login *l)
{
    login = l;
}
void FileBox::setSocket(TCPClient *socket)
{
    m_socket=socket;
}
void FileBox::on_pbUpload_clicked()
{
    //TCPClient socket("127.0.0.1", 5000);

    auto [localFolders, localFiles] = ui->twLocalFiles->getSelectedFiles();
            auto [remoteFolders, remoteFiles] = ui->twRemoteFiles->getSelectedFiles();
            if(remoteFolders.size() + remoteFiles.size() > 1)
    {
        QMessageBox::warning(this, "Upload", "Only one folder can be selected!");
    } else if(remoteFiles.size() > 0)
    {
        QMessageBox::warning(this, "Upload", "Folder can be selected!");
    }

    /*socket.sendMessage("UPLOAD\r\n");
    socket.sendMessage("C:\\Users\\Petar\\Desktop\\testSlanje.png\r\n");
    socket.sendFile("C:\\Users\\Petar\\Desktop\\warning_1_filebox.png");

    socket.waitForReadyRead(-1);
    qDebug() << socket.readLine(1000);*/

    ui->twRemoteFiles->getServerFilesystem(m_socket);
    //socket.sendAll(localFiles,localFolders);
    //socket.close();
}

void FileBox::on_pbNewFolder_clicked()
{
    TCPClient socket("127.0.0.1", 5000);
    socket.sendMessage("NEW FOLDER");

    socket.close();
}

void FileBox::on_pbCut_clicked()
{
    TCPClient socket("127.0.0.1", 5000);
    socket.sendMessage("CUT");

    socket.close();
}

void FileBox::on_pbCopy_clicked()
{
    TCPClient socket("127.0.0.1", 5000);
    socket.sendMessage("COPY");

    socket.close();
}

void FileBox::on_pbPaste_clicked()
{
    TCPClient socket("127.0.0.1", 5000);
    socket.sendMessage("PASTE");

    socket.close();
}

void FileBox::on_pbDelete_clicked()
{
    TCPClient socket("127.0.0.1", 5000);
    socket.sendMessage("DELETE");

    socket.close();
}
