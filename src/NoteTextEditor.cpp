



#include "NoteTextEditor.hpp"
#include <QKeyEvent>
#include <iostream>

NoteTextEditor::NoteTextEditor(QWidget *parent)
    : QTextEdit(parent)
    , cursor(this->textCursor())
    , format(this->cursor.charFormat())
    , currentFontSize(18.0)
    , checker(this)
    , currentLength(this->toPlainText().length())
    , wasFontChanged(false)
    , lastDocumentedFontSize(18.0)
{
    // --- Starter Customizations ---
    this->setFontPointSize(this->currentFontSize);
    connect(this, &QTextEdit::textChanged, [this]()
    {
        // If the font size changes, set wasFontRequested to false
        if (this->currentFontSize == lastDocumentedFontSize) this->wasFontChanged = false;

        else
        {
            this->lastDocumentedFontSize = this->currentFontSize;
        }

        // Re-apply font size if length == 0
        if (this->toPlainText().length() == 0)
        {
            this->currentFontSize = 18.0;
            this->setFontPointSize(this->currentFontSize);
        }

    }); // Check if length == 0
}

void NoteTextEditor::keyPressEvent(QKeyEvent* event)
{

    bool isBoldRequested = event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_B;
    bool isItalicRequested = event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_I;
    bool isUnderlineRequested = event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_U;

    // Font Size Changes
    bool isFontDecrementRequested = event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_Minus;
    bool isFontIncrementRequested = event->modifiers() & Qt::ControlModifier && event->key() == Qt::Key_Equal;
    bool isFontResetRequested = event->modifiers() & Qt::AltModifier && event->key() == Qt::Key_Minus;

    if (isBoldRequested) checker.toggleBold();
    else if (isItalicRequested) checker.toggleItalic();
    else if (isUnderlineRequested) checker.toggleUnderline();

    // Font Sizes
    else if (isFontDecrementRequested)
    {
        if (this->currentFontSize > 1)
        {
            this->currentFontSize--; // Decrement first

            this->setFontPointSize(this->currentFontSize);
            this->cursor.mergeCharFormat(format);
            this->mergeCurrentCharFormat(format);
            this->wasFontChanged = true;
        }
    }
    else if (isFontIncrementRequested)
    {
        this->currentFontSize++; // Increment first

        this->setFontPointSize(this->currentFontSize);
        this->cursor.mergeCharFormat(format);
        this->mergeCurrentCharFormat(format);
        this->wasFontChanged = true;
    }
    else if (isFontResetRequested) this->resetFontSize();
    else QTextEdit::keyPressEvent(event);
}


// --- Getters xd ---
FormatChecker& NoteTextEditor::getChecker(){ return this->checker; }
qreal& NoteTextEditor::getFontSize() { return this->currentFontSize; }
QTextCursor& NoteTextEditor::getCursor() { return this->cursor; }
QTextCharFormat& NoteTextEditor::getFormat() { return this->format; }
bool NoteTextEditor::getWasFontChanged() { return this->wasFontChanged; }
void NoteTextEditor::resetFontSize()
{
    std::cout << "Resetting font size...\n";
    this->currentFontSize = 18.0;

    this->setFontPointSize(this->currentFontSize);
    this->cursor.mergeCharFormat(format);
    this->mergeCurrentCharFormat(format);
    this->wasFontChanged = true;
}

NoteTextEditor::~NoteTextEditor() {}