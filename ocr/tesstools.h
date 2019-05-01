/**********************************************************************
 * File:        TessTools.cpp
 * Description: Tesseract tools
 * Author:      Zdenko Podobny
 * Created:     2012-03-27
 *
 * (C) Copyright 2012-2013, Zdenko Podobny
 **
 ** Licensed under the Apache License, Version 2.0 (the "License");
 ** you may not use this file except in compliance with the License.
 ** You may obtain a copy of the License at
 **
 **    http://www.apache.org/licenses/LICENSE-2.0
 **
 ** Unless required by applicable law or agreed to in writing, software
 ** distributed under the License is distributed on an "AS IS" BASIS,
 ** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 ** See the License for the specific language governing permissions and
 ** limitations under the License.
 *
 **********************************************************************/
#ifndef TESSTOOLS_H
#define TESSTOOLS_H

#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QImage>
#include <QMessageBox>
#include <QObject>
#include <QStringLiteral>

#include "logger.h"
#include <leptonica/allheaders.h>
#include <tesseract/baseapi.h>

#include "ocr_global.h"

class OCRSHARED_EXPORT TessTools : public QObject
{
  Q_OBJECT
public:
  explicit TessTools(const QString& datapath,
                     const QString& lang,
                     QObject* parent = nullptr);

  QString makeBoxes(const QImage& qImage, int page);

  PIX* qImage2PIX(const QImage& qImage);
  QImage PIX2qImage(PIX* pixImage);
  QImage GetThresholded(const QImage& qImage);
  const char* qString2Char(QString string);
  QList<QString> getLanguages(const QString& datapath);

signals:
  void log(LogLevel, const QString&);

protected:
  QString m_datapath;
  QString m_lang;

  static const char* kTrainedDataSuffix;
};

#endif // TESSTOOLS_H