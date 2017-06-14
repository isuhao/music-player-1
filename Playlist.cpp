#include "Playlist.h"
#include <QJsonArray>


Playlist::Playlist()
{
    list_ = new QVector<Song*>();
    idx_ = -1;
    time_ = time_.currentTime();
}

void Playlist::push_back(Song *song){
    list_->push_back(song);
}

QVector<Song* >* Playlist::list(){
     return list_;
}

void Playlist::setTitle(const QString& title){
    title_ = title;
}

QString Playlist::title(){
    return title_;
}

void Playlist::read(const QJsonObject& json){
    title_ = json["title"].toString();
    QJsonArray songs = json["songs"].toArray();
    for(QJsonValue data: songs){
        Song* song = new Song();
        song->read(data.toObject());
        list_->push_back(song);
    }
}

void Playlist::write(QJsonObject& json){
    json["title"] = title_;
    QJsonArray songs;
    for(Song* song : (*list_)){
      QJsonObject data;
      song->write(data);
      songs.push_back(data);
    }
    json["songs"] = QJsonValue(songs);
}

QTime Playlist::time()
{
    return time_;
}

void Playlist::open(QJsonObject& json){
    time_ = time_.currentTime();
    QJsonObject o;
    o["hour"] = time_.hour();
    o["minute"] = time_.minute();
    o["ms"] = time_.msec();

    json["time"] = o;

}
