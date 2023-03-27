#ifndef PLISTMANAGEITEM_H
#define PLISTMANAGEITEM_H

#include <QQuickItem>
#include "spriteitem.h"

class PlistManageItem : public QQuickItem {
    Q_OBJECT
    QML_ELEMENT
public:
    explicit PlistManageItem(QQuickItem *parent = nullptr);
    Q_INVOKABLE void writePlist(const QString &fileName);
signals:
};

#endif // PLISTMANAGEITEM_H
