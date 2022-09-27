#ifndef DOCWINDOW_BESSONOV_MIHEEV_H
#define DOCWINDOW_BESSONOV_MIHEEV_H

#include <QTextEdit>

class DocWindow_Bessonov_Miheev: public QTextEdit{
    Q_OBJECT
private:
    QString m_strFileName;
public:
    DocWindow_Bessonov_Miheev(QWidget* pwgt = 0);
signals:
    void changeWindowTitle(const QString&);
public slots:
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotColor();
};

#endif // DOCWINDOW_BESSONOV_MIHEEV_H
