#include "musicplayer.h"
#include <QFileDialog>
#include <QtAndroid>
#include <QStandardPaths>
#include <QDateTime>

QString fileName;

bool MusicPlayer::checkPermission()
{
    // Check if we have permission to read external storage
    QtAndroid::PermissionResult result = QtAndroid::checkPermission("android.permission.READ_EXTERNAL_STORAGE");
    if (result == QtAndroid::PermissionResult::Granted)
    {
        return true;
    } else {
        // Request permission if it has not been granted
        QtAndroid::requestPermissionsSync(QStringList() << "android.permission.READ_EXTERNAL_STORAGE");
        result = QtAndroid::checkPermission("android.permission.READ_EXTERNAL_STORAGE");
        return result == QtAndroid::PermissionResult::Granted;
    }
}

MusicPlayer::MusicPlayer()
{
    checkPermission();

    player = new QMediaPlayer();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MusicPlayer::playbackPosition);
    connect(player, &QMediaPlayer::durationChanged, this, &MusicPlayer::onDurationChanged);
    connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, &MusicPlayer::handleError);
}

void MusicPlayer::handleError(QMediaPlayer::Error /*error*/)
{
    qDebug() << "Media player error: " << player->errorString();
}

void MusicPlayer::openfile()
{
    checkPermission();
    fileName = QFileDialog::getOpenFileName(nullptr, tr("Select File"), QDir::homePath(), tr("All Files (*)"));
    if (!fileName.isEmpty()) {
        // Create a QFile object for the selected file
        QFile file(fileName);
        if (file.exists())
        {
            // Get the application data directory
            QString dataDir = QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
            QDir dir(dataDir);
            if (!dir.exists())
            {
                dir.mkpath(dataDir);
            }
            // Generate a unique file name in the data directory
            QString baseName = QFileInfo(fileName).baseName();
            QString suffix = QFileInfo(fileName).suffix();
            QString newFileName = baseName + "_" + QString::number(QDateTime::currentMSecsSinceEpoch()) + "." + suffix;
            QString newPath = dataDir + "/" + newFileName;
            if (file.copy(newPath))
            {
                fileName = newPath;
            }
            else
            {
                qDebug() << "Failed to copy file to" << newPath;
            }
        }
        else
        {
            qDebug() << "Selected file does not exist";
        }
    }
}

void MusicPlayer::playfile()
{
    player->setMedia(QUrl::fromLocalFile(fileName));
    player->play();
    duration();
    timer->start(1000);

}

void MusicPlayer::stop()
{
    player->stop();
    timer->stop();
}

qint64 MusicPlayer::playbackPosition()  {
    qint64 position = player->position();
    emit playbackPositionChanged(position);
    return position;
}

qint64 MusicPlayer::duration()  {
    qint64 duration = player->duration();

    emit durationChanged(duration);
    return duration;
}

void MusicPlayer::onDurationChanged(qint64 duration)
{
    emit durationChanged(duration);
}

qreal MusicPlayer::volume() const
{
    return m_volume;
}

void MusicPlayer::setVolume(qreal value)
{
    if (m_volume != value) {
        m_volume = value;
        player->setVolume(m_volume);
        emit volumeChanged(m_volume);
    }
}
