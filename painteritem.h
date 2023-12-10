#ifndef PAINTERITEM_H
#define PAINTERITEM_H

#include <QObject>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QImage>

class PainterItem : public QQuickPaintedItem
{
    Q_OBJECT
public:
    PainterItem(QQuickItem* parent = nullptr);
    void paint(QPainter *painter);

    Q_INVOKABLE QImage toQImage();
    Q_INVOKABLE void clearImage();


protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    std::vector<QPointF> m_linePoints{};
};

#endif // PAINTERITEM_H
