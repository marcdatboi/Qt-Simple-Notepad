



#pragma once

// Imports
#include <QWidget>
#include <QVBoxLayout>
#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private:
        QWidget *centralWidget;
        QVBoxLayout *mainLayout;

        // Member Functions
        void setupWindow();
};