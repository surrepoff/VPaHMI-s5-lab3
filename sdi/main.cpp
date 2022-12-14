#include "sdiprogram_bessonov_miheev.h"
#include <QApplication>
#include <QSplashScreen>
#include <QtWidgets>

void loadModules(QSplashScreen* psplash)
{
    QTime time;
    time.start();

    for (int i = 0; i < 100;)
    {
        if (time.elapsed() > 40)
        {
            time.start();
            ++i;
        }

        psplash->showMessage("Loading Modules: " + QString::number(i) + "%",
                             Qt::AlignCenter, Qt::red);
        qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap("../s.png"));
    splash.show();
    SDIProgram_Bessonov_Miheev w;
    loadModules(&splash);
    splash.finish(&w);
    w.show();

    return a.exec();
}
