



#include "FormatChecker.hpp"
#include <iostream>

FormatChecker::FormatChecker(QTextEdit* targetTextEditor)
    : targetTextEditor(targetTextEditor)
    , headerFontSizes({30, 40, 50}) {}


// --- Class Member Functions ---
void FormatChecker::toggleBold()
{
    bool isBold = this->targetTextEditor->fontWeight() == QFont::Bold;
    this->targetTextEditor->setFontWeight(isBold ?
        QFont::Normal :
        QFont::Bold
    );
}

void FormatChecker::toggleItalic()
{
    bool isItalic = this->targetTextEditor->fontItalic();
    this->targetTextEditor->setFontItalic(!isItalic);
}

void FormatChecker::toggleUnderline()
{
    bool isUnderlined = this->targetTextEditor->fontUnderline();
    this->targetTextEditor->setFontUnderline(!isUnderlined);
}

void FormatChecker::changeFontSize(int newFontSize)
{
    this->targetTextEditor->setStyleSheet(
        QString("QTextEdit { font-size: %1px; ").arg(newFontSize)
    );
}
