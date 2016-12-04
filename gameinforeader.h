#ifndef GameInfoReader_H
#define GameInfoReader_H

#include <QDebug>
#include <QVariantMap>
#include <QByteArray>
#include <QString>
#include "repreader.h"
#include <QTime>
#include "gameinfo.h"

#ifdef HAVE_QT5
#   include <QJsonDocument>
#else
#   include "json.h"
#endif

#define STEAM_API_KEY "B09655A1E41B5DE93AD3F27087D25884"

#define MINIMUM_DURATION 30


class GameInfoReader
{
public:
    GameInfoReader();
    ~GameInfoReader();

    GameInfo *get_game_info(QString profile, QString path_to_playback);
    QString get_sender_name(bool init=false);
    QString read_warnings_log(QString str, int offset=0);
    QString get_cur_profile_dir(QString path);
    QByteArray get_playback_file();

    void setAverageAPM(int apm);
    bool isPlayback();
    bool isGameGoing();
    bool timeCompare(QTime t1, QTime t2);
    QTime last_playback;
    QTime last_startgame;
    QTime last_stopgame;
    int average_apm;

//    inline QVariantMap to_map(QByteArray array)
//    {
//    #ifdef HAVE_QT5
//            return QJsonDocument::fromJson(array).toVariant().toMap();
//    #else
//            return QtJson::parse(array, "lua").toMap();
//    #endif
//    }
//    inline QVariantMap json_to_map(QByteArray array)
//    {
//    #ifdef HAVE_QT5
//            return QJsonDocument::fromJson(array).toVariant().toMap();
//    #else
//            return QtJson::parse(array, "json").toMap();
//    #endif
//    }

//    /// Перевод из массива в строку типа JSON
//    inline QByteArray map_to_json(QVariantMap map)
//    {
//    #ifdef HAVE_QT5
//        return  QJsonDocument::fromVariant(map).toJson(QJsonDocument::Compact);
//    #else
//        return QtJson::serialize(map).replace("\n", "");
//    #endif
//    }
private:
    GameInfo *_game_info;
    //  ридер реплеев
    RepReader *rep_reader;
    QByteArray _playback;

};

#endif // GameInfoReader_H
