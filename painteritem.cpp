#include "painteritem.h"


PainterItem::PainterItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::LeftButton);
}

void PainterItem::paint(QPainter *painter)
{
    painter->fillRect(0,0,100,100, Qt::black);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->setPen(QPen(Qt::white, 5));

    if(m_linePoints.size() > 1)
    {
        for(int i=1; i<(int) m_linePoints.size(); i++)
        {
            painter->drawLine(m_linePoints[i-1], m_linePoints[i]);
        }
    }
}

QImage PainterItem::toQImage()
{
    qDebug() <<"toQImage";

    QImage qimage(100,100,QImage::Format_ARGB32);
    qimage.fill(Qt::black);

    QPainter painter(&qimage);
    paint(&painter);

    return qimage;
}

void PainterItem::clearImage()
{
    m_linePoints.clear();
    update();
}

void PainterItem::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_linePoints.push_back(event->pos());
        update();
        event->accept();
    }
}

void PainterItem::mouseMoveEvent(QMouseEvent *event)
{
    if(event->buttons() & Qt::LeftButton)
    {
        m_linePoints.push_back(event->pos());
        update();
        event->accept();
    }
}

void PainterItem::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        m_linePoints.push_back(event->pos());
        update();
        event->accept();
    }
}
