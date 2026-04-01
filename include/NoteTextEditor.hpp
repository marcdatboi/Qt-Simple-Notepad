



#pragma once

#include <QTextEdit>
#include <QTextCharFormat>
#include "FormatChecker.hpp"

class NoteTextEditor : public QTextEdit
{
    Q_OBJECT

public:
    NoteTextEditor(QWidget *parent = nullptr);
    ~NoteTextEditor();

    FormatChecker& getChecker();
    qreal& getFontSize();
    QTextCursor& getCursor();
    QTextCharFormat& getFormat();
    void resetFontSize();
    bool getWasFontChanged();


private:
    void keyPressEvent(QKeyEvent* event) override;
    QTextCursor cursor;
    QTextCharFormat format;
    qreal currentFontSize;
    qreal lastDocumentedFontSize;
    FormatChecker checker;
    int currentLength;

    bool wasFontChanged;
};