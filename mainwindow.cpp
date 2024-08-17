#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentBrightness(100)
    , currentFontSize(18)
{
    ui->setupUi(this);

    mainLayout = new QVBoxLayout;

    QHBoxLayout *profileLayout = new QHBoxLayout;
    profileLayout->addWidget(ui->profileDropdown, 1);
    profileLayout->addStretch(1);

    mainLayout->addLayout(profileLayout);

    QVBoxLayout *chatLayout = new QVBoxLayout;
    chatLayout->addWidget(ui->chatDisplay);

    mainLayout->addLayout(chatLayout);

    QHBoxLayout *inputAndBtnLayout = new QHBoxLayout;
    inputAndBtnLayout->addWidget(ui->messageInput);
    inputAndBtnLayout->addWidget(ui->sendButton);

    mainLayout->addLayout(inputAndBtnLayout);

    controlLayout = new QGridLayout;
    controlLayout->addWidget(new QLabel("Brightness:"), 0, 0);
    controlLayout->addWidget(ui->brightnessSlider, 0, 1);
    controlLayout->addWidget(ui->brightnessInput, 0, 2);
    controlLayout->addWidget(ui->brightnessRangeLabel, 0, 3);

    controlLayout->addWidget(new QLabel("Font Size:"), 1, 0);
    controlLayout->addWidget(ui->fontSizeSlider, 1, 1);
    controlLayout->addWidget(ui->fontSizeInput, 1, 2);
    controlLayout->addWidget(ui->fontSizeRangeLabel, 1, 3);

    mainLayout->addLayout(controlLayout);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    ui->profileDropdown->addItem("User 1");
    ui->profileDropdown->addItem("User 2");
    ui->profileDropdown->addItem("User 3");

    connect(ui->profileDropdown, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &MainWindow::changeUserProfile);

    connect(ui->sendButton, &QPushButton::clicked, this, &MainWindow::sendMessage);

    connect(ui->brightnessSlider, &QSlider::valueChanged, this, &MainWindow::adjustBrightness);
    connect(ui->fontSizeSlider, &QSlider::valueChanged, this, &MainWindow::adjustFontSize);

    connect(ui->brightnessInput, &QLineEdit::textChanged, this, &MainWindow::updateBrightnessFromInput);
    connect(ui->fontSizeInput, &QLineEdit::textChanged, this, &MainWindow::updateFontSizeFromInput);

    ui->brightnessSlider->setRange(50, 150);
    ui->brightnessSlider->setValue(currentBrightness);
    ui->brightnessInput->setText(QString::number(currentBrightness) + "%");

    ui->fontSizeSlider->setRange(10, 50);
    ui->fontSizeSlider->setValue(currentFontSize);
    ui->fontSizeInput->setText(QString::number(currentFontSize) + " pt");

    ui->brightnessRangeLabel->setText("Min: 50% Max: 150%");
    ui->fontSizeRangeLabel->setText("Min: 10pt Max: 50pt");

    applyUserSettings(ui->profileDropdown->currentIndex());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendMessage()
{
    QString message = ui->messageInput->text();
    if (!message.isEmpty()) {
        QString userName = ui->profileDropdown->currentText();

        ui->chatDisplay->append(userName + ": " + message);

        ui->messageInput->clear();
    }
}


void MainWindow::changeUserProfile()
{
    int profileIndex = ui->profileDropdown->currentIndex();

    applyUserSettings(profileIndex);
}

void MainWindow::applyUserSettings(int profileIndex)
{
    struct UserProfile {
        QString userId;
        int fontSize;
        QString colorScheme;
    };

    QVector<UserProfile> userProfiles = {
        {"User 1", 20, "High Contrast"},
        {"User 2", 18, "Low Contrast"},
        {"User 3", 16, "Dark Mode"}
    };

    UserProfile currentUser = userProfiles[profileIndex];

    currentFontSize = currentUser.fontSize;
    adjustFontSize(currentFontSize);

    QString commonStyle = "border-radius: 15px; padding: 8px;";

    if (currentUser.colorScheme == "High Contrast") {
        this->setStyleSheet("background-color: #000000; color: #FFFFFF;");
        ui->sendButton->setStyleSheet(commonStyle + "background-color: #0078D7; color: #FFFFFF;");
        ui->profileDropdown->setStyleSheet(commonStyle + "background-color: #333333; color: #FFFFFF;");
        ui->messageInput->setStyleSheet(commonStyle + "background-color: #FFFFFF; color: #000000;");
        ui->chatDisplay->setStyleSheet(commonStyle + "background-color: #FFFFFF; color: #000000;");
    } else if (currentUser.colorScheme == "Low Contrast") {
        this->setStyleSheet("background-color: #F0F0F0; color: #000000;");
        ui->sendButton->setStyleSheet(commonStyle + "background-color: #28A745; color: #FFFFFF;");
        ui->profileDropdown->setStyleSheet(commonStyle + "background-color: #E0E0E0; color: #000000;");
        ui->messageInput->setStyleSheet(commonStyle + "background-color: #FFFFFF; color: #000000;");
        ui->chatDisplay->setStyleSheet(commonStyle + "background-color: #FFFFFF; color: #000000;");
    } else if (currentUser.colorScheme == "Dark Mode") {
        this->setStyleSheet("background-color: #1E1E1E; color: #FFFFFF;");
        ui->sendButton->setStyleSheet(commonStyle + "background-color: #1E90FF; color: #FFFFFF;");
        ui->profileDropdown->setStyleSheet(commonStyle + "background-color: #2E2E2E; color: #FFFFFF;");
        ui->messageInput->setStyleSheet(commonStyle + "background-color: #FFFFFF; color: #000000;");
        ui->chatDisplay->setStyleSheet(commonStyle + "background-color: #FFFFFF; color: #000000;");
    }

    adjustBrightness(currentBrightness);

    QIcon sendIcon(":/resources/send-icon.png");
    ui->sendButton->setIcon(sendIcon);
    ui->sendButton->setIconSize(QSize(24, 24));
}

void MainWindow::adjustBrightness(int value)
{
    currentBrightness = value;
    qreal brightnessFactor = currentBrightness / 100.0;

    this->setWindowOpacity(brightnessFactor);

    ui->brightnessInput->setText(QString::number(currentBrightness) + "%");
}

void MainWindow::adjustFontSize(int value)
{
    currentFontSize = value;

    QFont customFont("Helvetica Neue", currentFontSize);
    ui->sendButton->setFont(customFont);
    ui->profileDropdown->setFont(customFont);
    ui->messageInput->setFont(customFont);
    ui->chatDisplay->setFont(customFont);

    QList<QLabel *> labels = this->findChildren<QLabel *>();
    for (QLabel *label : labels) {
        label->setFont(customFont);
    }

    ui->fontSizeInput->setText(QString::number(currentFontSize) + " pt");
}

void MainWindow::updateBrightnessFromInput()
{
    bool ok;
    int brightness = ui->brightnessInput->text().remove('%').toInt(&ok);
    if (ok && brightness >= 50 && brightness <= 150) {
        ui->brightnessSlider->setValue(brightness);
        adjustBrightness(brightness);
    }
}

void MainWindow::updateFontSizeFromInput()
{
    bool ok;
    int fontSize = ui->fontSizeInput->text().remove(" pt").toInt(&ok);
    if (ok && fontSize >= 10 && fontSize <= 50) {
        ui->fontSizeSlider->setValue(fontSize);
        adjustFontSize(fontSize);
    }
}
