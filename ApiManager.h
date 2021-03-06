#ifndef APIMANAGER_H
#define APIMANAGER_H

#include <QUrl>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include <functional>

namespace ThingSpeak {

class ApiManager
{
public:

    /// The default base URL, e.g. https://api.thingspeak.com
    static const QUrl apiUrlDefault;

    /**
     * @brief A manager to handle ThinSpeak API request.
     * @param apiUrl The base URL to send requests to
     */
    ApiManager(const QUrl &apiUrl = apiUrlDefault);

    /**
     * @brief Synchronously sends a HTTP POST request.
     * @param path The path that is append to the api url.
     * @param query The query to send as HTTP post request.
     * @return The network reply.
     */
    QNetworkReply* sendPostRequestSync(const QString &path, const QUrlQuery &query);

    /**
     * @brief Synchronously sends a HTTP GET request.
     * @param path The path that is append to the api url.
     * @param query The query to send as HTTP post request.
     * @return The network reply.
     */
    QNetworkReply* sendGetRequestSync(const QString &path, const QUrlQuery &query);

    void sendGetRequestAsync(const QString &path, const QUrlQuery &query, const std::function <void (QNetworkReply*)> &f);

    /**
     * @brief The time in seconds to wait between two API requests.
     * return The wait time in seconds.
     */
    unsigned int getTimeBetweenRequestsSec() const;

    /**
     * @brief Sets the time in seconds that have to be waited between two api requests.
     * @param value The wait time in seconds.
     */
    void setTimeBetweenRequestsSec(unsigned int value);

private:
    /// Base URL of the API requests. Query paths gets added
    QUrl apiUrl;

    /// EventLoop to synchronize network requests
    QEventLoop syncEventLoop;

    /// Last api access time
    QDateTime lastRequest;

    /// Network access manager
    QNetworkAccessManager manager;

    /// Timeout between two API queries
    unsigned int timeBetweenRequestsSec = 15;

    /// Returns the request url by appending the path to the api url.
    QUrl buildRequestUrl(const QString &path);

    /// Returns the time between now and the last request in seconds.
    qint64 getTimeSinceLastRequestSec();

    /// Returns the time that have to be wait until the next request can be performed in seconds.
    quint64 getWaitTimeSec();

    /// Waits for the next request
    void waitForTimeout();
};

}
#endif // APIMANAGER_H
