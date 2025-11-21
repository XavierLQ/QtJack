#pragma once

#include "framework/Window.h"

namespace Framework { class Label; class Button; }

class QLabel;
class QPushButton;
class BlackjackViewModel;

class BlackjackWindow : public Framework::Window {
    Q_OBJECT
public:
    explicit BlackjackWindow(QWidget* parent = nullptr);

private slots:
    void refresh() const;

private:
    // UI
    Framework::Label* m_dealerLabel{};
    Framework::Label* m_dealerTotal{};
    Framework::Label* m_playerLabel{};
    Framework::Label* m_playerTotal{};
    Framework::Label* m_statusLabel{};
    Framework::Label* m_chipsLabel{};
    Framework::Button* m_dealBtn{};
    Framework::Button* m_hitBtn{};
    Framework::Button* m_standBtn{};

    BlackjackViewModel* m_vm{};
};
