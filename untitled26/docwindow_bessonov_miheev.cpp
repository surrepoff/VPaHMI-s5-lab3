#include "docwindow_bessonov_miheev.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>

DocWindow_Bessonov_Miheev::DocWindow_Bessonov_Miheev(QWidget* pwgt): QTextEdit(pwgt)
{

}

void DocWindow_Bessonov_Miheev::slotLoad(){
    QString str = QFileDialog::getOpenFileName();
    if (str.isEmpty()){
        return;
    }

    QFile file(str);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        setPlainText(stream.readAll());
        file.close();

        m_strFileName = str;
        emit changeWindowTitle(m_strFilename);
    }
}

void DocWindow_Bessonov_Miheev::sloteSaveAs()
{
    QString str = QFileDialog::getSaveFileName(0, m_strFileName);
    if (!str.isEmpty()){
        m_strFileName=str;
        slotSave();
    }
}

void DocWindow_Bessonov_Miheev::slotSave()
{
    if(m_strFileName.isEmpty()){
        slotSaveAs();
        return;
    }

    QFile file(m_strFileName);

    if (file.open(QIODevice::WriteOnly)){
        QTextStream(&file)<<toPlainText();
        file.close();
        emit changeWindowTitle(m_strFileName);
        QMessageBox::information(this, "Файл сохранен", "Файл успешно сохранен");
    }
}

void DocWindow_Bessonov_Miheev::slotColor()
{
    setTextColor(QColorDialog::getColor());
}
