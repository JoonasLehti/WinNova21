#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMediaPlayer>
#include <QTimer>

    class MusicPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qreal volume READ volume WRITE setVolume NOTIFY volumeChanged)

public:
    MusicPlayer();

public slots:
    void openfile();
    void playfile();
    void stop();
    bool checkPermission();
    void handleError(QMediaPlayer::Error error);
    qint64 playbackPosition();
    qint64 duration();
    void setVolume(qreal value);

private:
    QMediaPlayer *player;
    QString filePath;
    QTimer *timer;
    qreal m_volume = 50.0;
    qreal volume() const;

private slots:
    void onDurationChanged(qint64 duration);

signals:
    void playbackPositionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void volumeChanged(qreal value);
};

#endif // MUSICPLAYER_H
