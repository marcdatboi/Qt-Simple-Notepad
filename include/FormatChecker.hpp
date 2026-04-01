



#pragma once
#include <QTextEdit>
#include <vector>
#include <QKeyEvent>

class FormatChecker
{

public:
    FormatChecker(QTextEdit *targetTextEditor);

    void toggleBold();
    void toggleItalic();
    void toggleUnderline();
    void changeFontSize(int newFontSize);


private:
    QTextEdit *targetTextEditor;
    std::vector<int> headerFontSizes; // Try 30, 40, 50
};