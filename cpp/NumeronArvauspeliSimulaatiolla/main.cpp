#include "arvauspeli.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ArvausPeli w;
    w.show();
    w.StartGame();
    w.displayProbability();
    return a.exec();
}
