#ifndef APIHELPER_H
#define APIHELPER_H

#include <QNetworkReply>

namespace ThingSpeak
{
    typedef quint64 tsid_t;
    static const tsid_t kInvalidId = 0;

    tsid_t parseReplyForID(QNetworkReply *reply);
}

#endif // APIHELPER_H
