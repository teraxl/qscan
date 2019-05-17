#ifndef DOCUMENTBLOCK_H
#define DOCUMENTBLOCK_H

#include <QSharedPointer>
#include <QMap>

class Block
{
public:
  explicit Block();

  virtual void toHtml() = 0;
signals:

public slots:

protected:

};
using DocumentBlock = QSharedPointer<Block>;




#endif // DOCUMENTBLOCK_H
