#ifndef IMAGEANALYZER_H
#define IMAGEANALYZER_H

#include <QObject>
#include <QImage>
class ImageAnalyzer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString resultStr READ resultStr WRITE setResultStr NOTIFY resultStrChanged FINAL)

public:
    ImageAnalyzer();

    Q_INVOKABLE void analyzeImage(QImage img);
    QString resultStr() const;
    void setResultStr(const QString &newResultStr);
Q_SIGNALS:
    void resultStrChanged();
private:
    QString m_resultStr = "Default";

};

#endif // IMAGEANALYZER_H
