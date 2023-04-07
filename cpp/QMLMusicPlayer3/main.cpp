#include "musicplayer.h"
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;

    MusicPlayer player;

    engine.rootContext()->setContextProperty("musicPlayer", &player);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
