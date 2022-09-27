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
        DocWindow* pdoc = new DocWindow;

        pmnuFile->addAction("&Open...",pdoc,SLOT(slotLoad()),QKeySequence("CTRL+O"));
        pmnuFile->addAction("&Save",pdoc,SLOT(slotSave()),QKeySequence("CTRL+S"));
        pmnuFile->addAction("&Save As...",pdoc,SLOT(slotSaveAs()));

        pmnuFile->addSeparator();

        pmnuFile->addAction("&Quit",qApp,SLOT(quit()),QKeySequence("CTRL+Q"));
        pmnuFile->addAction("&About",this,SLOT(slotAbout()),Qt::Key_F1);

        MenuBar()->addMenu(pmnuFile);
        MenuBar()->addMenu(pmnuHelp);

        setCentralWidget(pdoc);

        connect(pdoc, SIGNAL(changeWindowTitle(const QString&)),SLOT(slotChangeWindowTitle(const QString&)));
        statusBar()->showMessage("Ready", 2000);

        pmnuFile->addAction("&Color", pdoc, SLOT(slotColor()));
    }

public slots:
    void slotAbout()
    {
        QMessageBox::about(this, "Application", "Bessonov, Miheev");
    }

    void slotChangeWindowTitle(const QString& str)
    {
        setWindowTitle(str);
    }

private:
    Ui::SDIProgram_Bessonov_Miheev *ui;
}

#endif // SDIPROGRAM_BESSONOV_MIHEEV_H
