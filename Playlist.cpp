#include "Playlist.h"
#include <QJsonArray>


Playlist::Playlist()
{
    list_ = new QVector<Song*>();
}

void Playlist::push_back(Song *song){
    list_->push_back(song);
}

QVector<Song* >* Playlist::list(){
     return list_;
}

void Playlist::setTitle(QString title){
    title_ = title;
}

QString Playlist::title(){
    return title_;
}

void Playlist::read(const QJsonObject &json){
    title_ = json["title"];
    QJsonArray songs = json["songs"].toArray();
    foreach(QJsonObject data, songs){
        Song* song = new Song();
        song->read(data);
        list_->push_back(song);
    }
}

void Playlist::write(QJsonObject &json){
    json["title"] = title_;
    QJsonArray songs;
    foreach(Song* song, list_){
      QJsonObject data;
      song->write(data);
      songs.push_back(data);
    }
    json["songs"] = QJsonValue(songs);
}
