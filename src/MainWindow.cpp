



#include <QMainWindow>
#include "MainWindow.hpp"
#include "NoteTextEditor.hpp"
#include "ToolBarWidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , centralWidget(new QWidget(this))
    , mainLayout(new QVBoxLayout(this))
{
    this->setupWindow();



    // Text Editor
    NoteTextEditor *textEditor = new NoteTextEditor(this);


    // Toolbar widget
    ToolBarWidget *toolbar = new ToolBarWidget
    (
        textEditor,
        textEditor->getChecker(),
        textEditor->getFontSize(),
        textEditor->getCursor(),
        textEditor->getFormat(),
        this
    );

    // Add to layout
    this->mainLayout->addWidget(toolbar);
    this->mainLayout->addWidget(textEditor);
}

void MainWindow::setupWindow()
{
    this->setMinimumSize(300, 500);
    this->setCentralWidget(this->centralWidget);
    this->centralWidget->setLayout(this->mainLayout);
}
MainWindow::~MainWindow() {}