#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);


  //// OpenCV example code
  //cv::Mat image = cv::imread("C:/workspace/Untitled.png");
  //if (!image.empty()) {
  //    cv::imshow("Display window", image);
  //    cv::waitKey(0);
  //}
  //else {
  //    std::cout << "Could not open or find the image" << std::endl;
  //}
}

MainWindow::~MainWindow() { delete ui; }
