#include "apimanager.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <QThread>

using namespace ThingSpeak;

const QUrl ApiManager::API_URL_DEFAULT = QUrl("https://api.thingspeak.com");

ApiManager::ApiManager(const QUrl &apiUrl) : apiUrl(apiUrl)
{ }

qint64 ApiManager::getTimeSinceLastRequestSec()
{
    QDateTime currentDateTime(QDateTime::currentDateTime());
    return currentDateTime.toTime_t() - lastRequest.toTime_t();
}

quint64 ApiManager::getWaitTimeSec()
{
    qint64 timeDiffSec = getTimeSinceLastRequestSec();

    if (timeDiffSec < timeBetweenRequestsSec)
        return timeBetweenRequestsSec - timeDiffSec + 2;

    return 0;
}

void ApiManager::waitForRequest()
{
    quint64 waitTime = getWaitTimeSec();
    if (waitTime == 0)
        return;

    QThread::sleep(waitTime);
}


QUrl ApiManager::buildRequestUrl(const QString &path)
{
    QUrl url = apiUrl;
    url.setPath(path);

    return url;
}

QNetworkReply* ApiManager::sendPostRequestSync(const QString &path, const QUrlQuery &query)
{
    // Build the url.
    QUrl url = buildRequestUrl(path);

    // Create request
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Create an event loop to synchronize http request
    QEventLoop eventLoop;
    QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

    // Wait until we can issue the next request
    waitForRequest();
    lastRequest = QDateTime(QDateTime::currentDateTime());

    // Perform request and wait for completion
    QNetworkReply *reply = mgr.post(request, query.toString(QUrl::FullyEncoded).toUtf8());
    eventLoop.exec();

    return reply;
}

unsigned int ApiManager::getTimeBetweenRequestsSec() const
{
    return timeBetweenRequestsSec;
}

void ApiManager::setTimeBetweenRequestsSec(unsigned int value)
{
    timeBetweenRequestsSec = value;
}

