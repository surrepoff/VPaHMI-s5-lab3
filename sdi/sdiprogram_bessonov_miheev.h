#ifndef SDIPROGRAM_BESSONOV_MIHEEV_H
#define SDIPROGRAM_BESSONOV_MIHEEV_H

#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>
#include "docwindow_bessonov_miheev.h"

namespace Ui {
class SDIProgram_Bessonov_Miheev;
}


class SDIProgram_Bessonov_Miheev : public QMainWindow
{
    Q_OBJECT

public:
    SDIProgram_Bessonov_Miheev(QWidget *pwgt = 0): QMainWindow(pwgt)
    {
        QMenu* pmnuFile = new QMenu("&File");
        QMenu* pmnuHelp = new QMenu("&Help");
        DocWindow_Bessonov_Miheev* pdoc = new DocWindow_Bessonov_Miheev;

        pmnuFile->addAction("&Open...",pdoc,SLOT(slotLoad()),QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save",pdoc,SLOT(slotSave()),QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save As...",pdoc,SLOT(slotSaveAs()));

        pmnuFile->addSeparator();

        pmnuFile->addAction("&Color", pdoc, SLOT(slotColor()));

        pmnuFile->addSeparator();

        pmnuFile->addAction("&Quit",qApp,SLOT(quit()),QKeySequence("CTRL+Q"));

        pmnuHelp->addAction("&About",this,SLOT(slotAbout()),Qt::Key_F1);

        menuBar()->addMenu(pmnuFile);
        menuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)),SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);
    }

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "About", "IP-014 Bessonov\nIP-014 Miheev");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }

private:
    Ui::SDIProgram_Bessonov_Miheev *ui;
};

#endif // SDIPROGRAM_BESSONOV_MIHEEV_H
