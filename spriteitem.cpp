#include "spriteitem.h"

SpriteItem::SpriteItem(QQuickItem *parent)
    : QQuickItem{parent} {
}

void SpriteItem::write(QXmlStreamWriter &writer) {
    writer.writeTextElement("key", key);
    writer.writeStartElement("dict");

    writer.writeTextElement("key", "aliases");
    writer.writeTextElement("array", "");// 未实现aliases，待定
    writer.writeTextElement("key", "anchor");
    writer.writeTextElement("string", "{0.5,0.203125}");// 未实现anchor，待定
    writer.writeTextElement("key", "spriteOffset");
    writer.writeTextElement("string", "{1,-9}");// 未实现spriteOffset，待定
    writer.writeTextElement("key", "spriteSize");
    writer.writeTextElement("string", "{42,76}");// 未实现spriteSize，待定
    writer.writeTextElement("key", "spriteSourceSize");
    writer.writeTextElement("string", "{64,128}");// 未实现spriteSourceSize，待定
    writer.writeTextElement("key", "textureRect");
    writer.writeTextElement("string", "{{81,77},{42,76}}");// 未实现textureRect，待定
    writer.writeTextElement("key", "textureRotated");
    writer.writeTextElement("false", "");// 未实现textureRotated，待定

    writer.writeEndElement(); // End dict
}
