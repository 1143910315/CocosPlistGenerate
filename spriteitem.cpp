#include "spriteitem.h"

SpriteItem::SpriteItem(QQuickItem *parent)
    : QQuickItem{parent} {
}

void SpriteItem::write(QXmlStreamWriter &writer) {
    writer.writeTextElement("key", key);
    writer.writeStartElement("dict");

    writer.writeTextElement("key", "aliases");
    writer.writeTextElement("array", "");// 实现aliases
    writer.writeTextElement("key", "anchor");
    writer.writeTextElement("string", toString(anchor));// 实现anchor
    writer.writeTextElement("key", "spriteOffset");
    writer.writeTextElement("string", toString(spriteOffset));// 实现spriteOffset
    writer.writeTextElement("key", "spriteSize");
    writer.writeTextElement("string", toString(spriteSize));// 实现spriteSize
    writer.writeTextElement("key", "spriteSourceSize");
    writer.writeTextElement("string", toString(spriteSourceSize));// 实现spriteSourceSize
    writer.writeTextElement("key", "textureRect");
    writer.writeTextElement("string", toString(textureRect, sizeof textureRect));// 实现textureRect
    writer.writeTextElement("key", "textureRotated");
    writer.writeTextElement(textureRotated ? "true" : "false", "");// 实现textureRotated

    writer.writeEndElement(); // End dict
}

QString SpriteItem::toString(const QPointF &point) {
    QString str;
    QTextStream out(&str);
    out << "{" << point.x() << "," << point.y() << "}";
    return str;
}

QString SpriteItem::toString(const QPoint &point) {
    QString str;
    QTextStream out(&str);
    out << "{" << point.x() << "," << point.y() << "}";
    return str;
}

QString SpriteItem::toString(const QPoint point[], int size) {
    QString str;
    QTextStream out(&str);
    out << "{";
    for (int i = 0; i < size; ++i) {
        if (i != 0) {
            out << ",{" << point[i].x() << "," << point[i].y();
        } else {
            out << "{" << point[i].x() << "," << point[i].y();
        }
    }
    out << "}";
    return str;
}
