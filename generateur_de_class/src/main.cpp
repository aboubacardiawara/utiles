#include <QApplication>
#include <mafenetre.h>
#include <fenetrecodegenere.h>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MaFenetre form_window;

    form_window.show();

    return app.exec();
}
