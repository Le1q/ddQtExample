#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    connect(ui->fileBtn, &QPushButton::clicked, this, &MainWindow::on_fileBtn_Click);
    connect(ui->processBtn, &QPushButton::clicked, this, &MainWindow::on_processBtn_Click);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_fileBtn_Click()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"),
        QDir::homePath(),
        tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty()) {
        currentImageM = cv::imread(fileName.toStdString());
        cv::cvtColor(currentImageM, currentImageM, cv::COLOR_BGR2RGB);
        QImage img = QImage((const unsigned char*)(currentImageM.data), currentImageM.cols,
            currentImageM.rows, currentImageM.step, QImage::Format_RGB888);
        ui->origin_label->setPixmap(QPixmap::fromImage(img));
        ui->origin_label->setScaledContents(true);
    }
}

void MainWindow::on_processBtn_Click()
{
    if (currentImageM.empty()) {
        QMessageBox::warning(this, tr("Warning"), tr("No image loaded"));
        return;
    }

    // Convert to grayscale image
    cv::Mat grayImage;
    cv::cvtColor(currentImageM, grayImage, cv::COLOR_RGB2GRAY);

    // Calculate the proportion of pixels with a threshold greater than 100
    cv::Mat binaryImage;
    cv::threshold(grayImage, binaryImage, 100, 255, cv::THRESH_BINARY);

    // Display the processed image
    QImage img = QImage((const unsigned char*)(grayImage.data), grayImage.cols,
        grayImage.rows, grayImage.step, QImage::Format_Grayscale8);
    ui->process_label->setPixmap(QPixmap::fromImage(img));
    ui->process_label->setScaledContents(true);

    double whitePixels = cv::countNonZero(binaryImage);
    double totalPixels = binaryImage.total();
    double whitePixelRatio = whitePixels / totalPixels;

    // Determine if it exceeds 10%
    if (whitePixelRatio > 0.1) {
        QMessageBox::information(this, tr("Result"), tr("The image is OK"));
    }
    else {
        QMessageBox::information(this, tr("Result"), tr("The image is NOT OK"));
    }
}