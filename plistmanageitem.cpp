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
    writer.writeDTD("<!DOCTYPE plist PUBLIC \"-//Apple Computer//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">");
    writer.writeStartElement("plist");
    writer.writeAttribute("version", "1.0");
    writer.writeStartElement("dict");
    // Write your data here
    writer.writeEndElement(); // End dict
    writer.writeEndElement(); // End plist
    writer.writeEndDocument();

    file.close();
}
