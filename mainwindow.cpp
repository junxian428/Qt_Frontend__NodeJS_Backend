#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect the clicked signal of the pushButton to a lambda function
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButtonClicked()
{
    // Specify the URL for the HTTP GET request
    QUrl url("http://localhost:3000/api/greet");  // Replace with your actual API endpoint

    // Create a QNetworkRequest with the specified URL
    QNetworkRequest request(url);

    // Perform the HTTP GET request
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(request);

    // Connect the finished signal of the reply to a lambda function
    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            // Successful HTTP GET request
            QString response = reply->readAll();
            QMessageBox::information(this, "HTTP GET Successful", response);
        } else {
            // Error handling for the HTTP GET request
            QMessageBox::warning(this, "HTTP GET Error", reply->errorString());
        }

        // Clean up
        reply->deleteLater();
        manager->deleteLater();
    });
}
