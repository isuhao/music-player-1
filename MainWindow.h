#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "Playlist.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setCurrentPlaylist(Playlist* playlist);
    Playlist* currentPlaylist();
    Playlist* initialPlaylist();

    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Playlist* currentPlaylist_;
    Playlist* initialPlaylist_;
    bool initialized_;

    void loadInitial();

};

#endif // MAINWINDOW_H
