#ifndef SPRITEITEM_H
#define SPRITEITEM_H

#include <QQuickItem>
#include <QList>
#include <QPointF>
#include <QPoint>
#include <QXmlStreamWriter>

class SpriteItem : public QQuickItem {
    Q_OBJECT
public:
    explicit SpriteItem(QQuickItem *parent = nullptr);
    void write(QXmlStreamWriter &writer);
signals:
private:
    QString toString(const QPointF& point);
    QString toString(const QPoint& point);
    QString toString(const QPoint point[], int size);
    /**
       - aliases：该小图的别名
       - anchor：该小图的中心点相对于小图左下角的坐标比例，范围为（0，0）到（1，1）。例如，一个值为（0.5，0.5）的anchor表示该小图的中心点位于小图的正中心。
       - spriteOffset：该小图相对于其原始位置的偏移量，通常用于校准小图的位置。
       - spriteSize：该小图在合图中的实际大小。
       - textureRect：该小图在合图中的矩形区域的左下角坐标以及宽度和高度。
       - spriteSourceSize：该小图在原始图片中的大小。
       - textureRotated：该小图是否被旋转了90度。
     */
    QString key = "";
    QList<QString> aliases();
    QPointF anchor = { 0.5f, 0.5f };
    QPoint spriteOffset = { 0, 0 };
    QPoint spriteSize = { 0, 0 };
    QPoint spriteSourceSize = { 0, 0 };
    QPoint textureRect[2] = { { 0, 0 }, { 0, 0 } };
    bool textureRotated = false;
};

#endif // SPRITEITEM_H
