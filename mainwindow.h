#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSlider>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeUserProfile();
    void sendMessage();
    void adjustBrightness(int value);
    void adjustFontSize(int value);
    void updateBrightnessFromInput();
    void updateFontSizeFromInput();

private:
    void applyUserSettings(int profileIndex);
    Ui::MainWindow *ui;
    int currentBrightness;
    int currentFontSize;

    // Layouts
    QVBoxLayout *mainLayout;
    QGridLayout *controlLayout;
};

#endif
