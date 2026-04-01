



#include <QWidget>
#include <QRegularExpression>
#include <QValidator>
#include <iostream>
#include "ToolBarWidget.hpp"
#include "FormatChecker.hpp"
/*
 * TODO:
 * Test notepad and make necessary changes
 * Upload to github :)
 */
ToolBarWidget::ToolBarWidget
(
    NoteTextEditor *targetTextEditor,
    FormatChecker& checker,
    qreal& currentFontSize,
    QTextCursor& cursor,
    QTextCharFormat& format,
    QWidget *parent
)
    : QWidget(parent)
    , targetTextEditor(targetTextEditor)
    , layout(new QHBoxLayout(this))

    , currentFontSize(currentFontSize)
    , format(format)
    , cursor(cursor)

    // Increment Elements
    , decrementButton(new QPushButton("-", this))
    , incrementButton(new QPushButton("+", this))
    , textSizeDisplay(new QLineEdit(this))

    // Editor Customizations
    , boldButton(new QPushButton("B", this))
    , underlineButton(new QPushButton("U", this))
    , italicButton(new QPushButton("I", this))

    // Header Sizes and Button List
    , header1Size(50)
    , header2Size(40)
    , header3Size(30)
    , headerSizeList({new QPushButton("H1", this), new QPushButton("H2", this), new QPushButton("H3", this)})


{
    // Check if the font was reset
    connect(targetTextEditor, &QTextEdit::textChanged, [this]
    {
        if (this->targetTextEditor->getWasFontChanged())
        {
            this->currentFontSize = this->targetTextEditor->getFontSize();
            this->textSizeDisplay->setText(QString::number(this->currentFontSize));
        }
    });

    this->setMaximumHeight(40);
    this->textSizeDisplay->setText(QString::number(currentFontSize));
    this->textSizeDisplay->setAlignment(Qt::AlignCenter);

    // Append text size buttons
    this->layout->addWidget(decrementButton);
    this->layout->addWidget(textSizeDisplay, 1); // This must be in the middle :>
    this->layout->addWidget(incrementButton);

    // Append Text Customization buttons
    this->layout->addWidget(boldButton);
    this->layout->addWidget(underlineButton);
    this->layout->addWidget(italicButton);

    // Append Header Buttons
    for (const auto& button : this->headerSizeList) this->layout->addWidget(button);

    // Ensure User can only type ints into the text size display
    connect(textSizeDisplay, &QLineEdit::textChanged, this, &ToolBarWidget::validateTextSizeDisplay);



    // ---=== Adding Functionality to Buttons ===---
    connect(this->decrementButton, &QPushButton::clicked, this, &ToolBarWidget::decrementFontSize);

    connect(incrementButton, &QPushButton::clicked, this, &ToolBarWidget::incrementFontSize);

    connect(boldButton, &QPushButton::clicked, [&](){ checker.toggleBold(); });

    connect(underlineButton, &QPushButton::clicked, [&](){ checker.toggleUnderline(); });

    connect(italicButton, &QPushButton::clicked, [&](){ checker.toggleItalic(); });

    // Headers
    connect(this->headerSizeList[0], &QPushButton::clicked, this, &ToolBarWidget::setHeader1Size);
    connect(this->headerSizeList[1], &QPushButton::clicked, this, &ToolBarWidget::setHeader2Size);
    connect(this->headerSizeList[2], &QPushButton::clicked, this, &ToolBarWidget::setHeader3Size);
}

void ToolBarWidget::validateTextSizeDisplay()
{
    QIntValidator *validator = new QIntValidator(0, 99, this);
    this->textSizeDisplay->setValidator(validator);
    this->textSizeDisplay->setAlignment(Qt::AlignCenter);
    this->targetTextEditor->setFontPointSize(this->textSizeDisplay->text().toDouble());
}

void ToolBarWidget::decrementFontSize()
{
    if (currentFontSize > 1)
    {
        std::cout << "Attempting to decrement\n";
        this->currentFontSize--; // Decrement first

        targetTextEditor->setFontPointSize(currentFontSize);
        cursor.mergeCharFormat(format);
        targetTextEditor->mergeCurrentCharFormat(format);

        this->textSizeDisplay->setText(QString::number(this->currentFontSize));
    }
}

void ToolBarWidget::incrementFontSize()
{
    if (this->currentFontSize < 100)
    {
        this->currentFontSize++;
        targetTextEditor->setFontPointSize(currentFontSize);
        cursor.mergeCharFormat(format);
        targetTextEditor->mergeCurrentCharFormat(format);

        this->textSizeDisplay->setText(QString::number(this->currentFontSize));
    }

}


// --- Header Sizes ---
void ToolBarWidget::setHeader1Size()
{
    this->currentFontSize = this->header1Size;
    targetTextEditor->setFontPointSize(currentFontSize);
    cursor.mergeCharFormat(format);
    targetTextEditor->mergeCurrentCharFormat(format);

    this->textSizeDisplay->setText(QString::number(this->currentFontSize));
}

void ToolBarWidget::setHeader2Size()
{
    this->currentFontSize = this->header2Size;
    targetTextEditor->setFontPointSize(currentFontSize);
    cursor.mergeCharFormat(format);
    targetTextEditor->mergeCurrentCharFormat(format);

    this->textSizeDisplay->setText(QString::number(this->currentFontSize));
}

void ToolBarWidget::setHeader3Size()
{
    this->currentFontSize = this->header3Size;
    targetTextEditor->setFontPointSize(currentFontSize);
    cursor.mergeCharFormat(format);
    targetTextEditor->mergeCurrentCharFormat(format);

    this->textSizeDisplay->setText(QString::number(this->currentFontSize));
}