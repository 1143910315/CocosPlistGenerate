#include "plistmanageitem.h"
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>

PlistManageItem::PlistManageItem(QQuickItem *parent)
    : QQuickItem{parent} {
}

void PlistManageItem::writePlist(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);

    writer.writeStartDocument();
    writer.writeStartElement("root");

    // Write your XML data here

    writer.writeEndElement();
    writer.writeEndDocument();

    file.close();
}
