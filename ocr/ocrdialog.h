#ifndef OCRDIALOG_H
#define OCRDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QFrame>
#include <QLabel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QObject>
#include <QTextEdit>
#include <QPushButton>
#include <QGuiApplication>
#include <QScreen>
#include <QMessageBox>
#include <QSlider>

#include "scanpage.h"

class OcrImage;

class OcrDialog : public QDialog
{
  Q_OBJECT
public:
  explicit OcrDialog(QWidget* parent = nullptr);
  ~OcrDialog() override = default;

  QImage image();
  void setData(int index, const QImage& image, const Page&  page);
  void setOcrImage(int index, const QImage& image);
  void setOcrText(int page_no, const QString& text);
  QString text();

  bool imageChanged() const;
  QSize sizeHint() const override;

signals:
  void sendOcrRequest(int, const QImage&);
  void saveModifiedImage(int index, const QImage& image);
  void saveModifiedText(int index, const QString& text);

protected:
  QTextEdit* m_text_edit;
  OcrImage* m_image_display;
  int m_page_no{};
  Page m_page;
  bool m_image_changed;
  QPushButton* m_crop_btn{};
  QLabel* threshold_lbl;
  QStackedLayout* m_ctl_stack{};
  int m_btn_stack{}, m_threshold_stack{};

  void resizeEvent(QResizeEvent* event) override;

  void initGui();
  void requestOcr();
  void help();
  void setSelected();
  void setUnselected();
  void binarise();
  void invert();
  void denoise();
  void dewarp();
  void descew();
  void rescale();
  void saveText();
  void saveImage();
  void discard();
  void undoChanges();
  void close();

  void setThreshold(int threshold);
  void thresholdAccepted();
};

#endif // OCRDIALOG_H
