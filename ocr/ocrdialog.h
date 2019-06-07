#ifndef OCRDIALOG_H
#define OCRDIALOG_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QFrame>
#include <QLabel>
#include <QFont>
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

//#include "scanpage.h"
#include "documentdata.h"

class OcrImage;
class ScanList;

class OcrDialog : public QDialog
{
  Q_OBJECT
public:
  explicit OcrDialog(QWidget* parent = nullptr);
  ~OcrDialog() override = default;

  QImage image();
  void setData(int index, const QImage& image, const DocumentData& page);
  void setOcrImage(int index, const QImage& image);
  void setOcrText(int page_no, const QString& text);
  QStringList text();

  bool imageChanged() const;
  QSize sizeHint() const override;

  QImage modifiedImage();
  int pageNumber();

  DocumentData page() const;

  void open() override;

signals:
  void sendOcrRequest(int, const QImage&);
  void saveModifiedImage(int index, const QImage& image);
  void saveModifiedText(int index, const QStringList &text);

  protected:
  ScanList *m_text_edit;
  OcrImage *m_image_display;
  int m_page_no{};
  DocumentData m_page;
  bool m_image_changed;
  QPushButton *m_crop_btn{};
  QPushButton *m_cut_btn{};
  QPushButton *m_binarise_btn{};
  QPushButton *m_ocr_btn{};
  QPushButton *m_ocr_sel_btn{};
  QPushButton *denoise_btn{}, *dewarp_btn{}, *descew_btn{};
  QSlider *threshold_slider{};
  QLabel *threshold_lbl{};
  QStackedLayout *m_ctl_stack{};
  int m_btn_stack{}, m_threshold_stack{};

  void resizeEvent(QResizeEvent *event) override;

  void initGui();
  void requestOcr();
  void requestOcrOnSelection();
  void help();
  void setSelected();
  void setUnselected();
  void crop();
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

  void setThresholdLabel(int threshold);
  void thresholdAccepted();
  void applyThreshold();

  void disableBinarise();
  void enableBinarise();

  void enableBtns(bool enable);
};

#endif // OCRDIALOG_H
