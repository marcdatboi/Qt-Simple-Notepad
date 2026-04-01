



#pragma once

#include <qboxlayout.h>
#include <QPushButton>
#include <QLineEdit>
#include <QWidget>
#include "NoteTextEditor.hpp"
#include "FormatChecker.hpp"

class ToolBarWidget : public QWidget
{
    Q_OBJECT

public:
    ToolBarWidget(NoteTextEditor *targetTextEditor, FormatChecker& checker, qreal& currentFontSize, QTextCursor& cursor, QTextCharFormat& format, QWidget *parent = nullptr);

private slots:
    void validateTextSizeDisplay();

    // Incrementing fonts
    void incrementFontSize();
    void decrementFontSize();

    // Headers
    void setHeader1Size();
    void setHeader2Size();
    void setHeader3Size();

private:

    NoteTextEditor *targetTextEditor;

    qreal currentFontSize;
    QTextCursor cursor;
    QTextCharFormat format;


    // Layout
    QHBoxLayout *layout;

    // Text Size Increment Elements
    QPushButton *decrementButton;
    QPushButton *incrementButton;
    QLineEdit *textSizeDisplay;

    // Editor Customizations
    QPushButton *boldButton;
    QPushButton *underlineButton;
    QPushButton *italicButton;

    // Header Font sizes (50, 40, 30)
    int header1Size;
    int header2Size;
    int header3Size;

    QList<QPushButton*> headerSizeList; // 50, 40, 30

};