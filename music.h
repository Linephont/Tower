#ifndef MUSIC_H
#define MUSIC_H

#include <QObject>
class QMediaPlayer;
class Music : public QObject
{
    Q_OBJECT
public:
    explicit Music(QObject *parent = nullptr);
    void playbgm();
    void playSound(int type);
    QMediaPlayer *bgm;
signals:

};

#endif // MUSIC_H
