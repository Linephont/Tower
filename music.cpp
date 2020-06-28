 #include "music.h"
#include <QMediaPlaylist>
#include <QMediaPlayer>
#include <QDir>
Music::Music(QObject *parent) : QObject(parent)
  ,bgm(NULL)
{

    //QUrl backgroundMusicUrl = QUrl::fromLocalFile(":/bgm.mp3");
//    if (QFile::exists(backgroundMusicUrl.toLocalFile()))
//    {
        bgm = new QMediaPlayer(this);
        bgm->setMedia(QUrl::fromLocalFile(":/bgm.mp3"));


//        QMediaPlaylist *bgmList = new QMediaPlaylist();
//        QMediaContent media(backgroundMusicUrl);
//        bgmList->addMedia(media);
//        bgmList->setCurrentIndex(0);
//        // 设置背景音乐循环播放
//        bgmList->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
//        bgm->setPlaylist(bgmList);
   // }
}
void Music::playbgm()
{
    if(bgm!=NULL)
        bgm->play();



}
