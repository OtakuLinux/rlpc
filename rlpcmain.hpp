#pragma once

#include <QMainWindow>
#include <QMediaPlayer>
#include <QStandardItem>
#include "yandexmusic.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class rlpcMain;
}
QT_END_NAMESPACE

void createSearchWindow(void);

class rlpcMain : public QMainWindow
{
  Q_OBJECT

public:
  rlpcMain(QWidget *parent = nullptr);
  ~rlpcMain();


private slots:
  void on_OpenFile_clicked(void);
  void on_Play_clicked(void);
  void on_Previous_clicked(void);
  void on_Next_clicked(void);

  void SetDuration(qint64);
  void StatusChanged(QMediaPlayer::State);
  void setTrackPos(int);
  void changeTrackPos(qint64);
  void changeTheme(QString);
  void trackTags(void);
  void playlistUpdate(void);

  void on_replay_toggled(bool checked);

  void on_playlistView_clicked(const QModelIndex &index);

  void on_search_butt_clicked();

  void on_PlaylistSearch_doubleClicked(const QModelIndex &index);

private:
  Ui::rlpcMain *ui;

  QString icon_path = "";

  QString timeToString(qint64);

  QString fileName;
  QMediaPlayer* player;
  QMediaPlaylist* playlist;
  QStandardItemModel* playlist_IModel;
  QStandardItemModel* playlistSearch_IModel;
  tracks* tracks_struct;
  void table_fill(tracks*);
};
