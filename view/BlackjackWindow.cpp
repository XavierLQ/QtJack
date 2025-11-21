#include "BlackjackWindow.h"
#include "BlackjackViewModel.h"
#include "Strings.h"
#include "Constants.h"
#include "Styles.h"

#include "framework/Layouts.h"
#include "framework/Label.h"
#include "framework/Button.h"

BlackjackWindow::BlackjackWindow(QWidget* parent)
    : Framework::Window(parent)
    , m_vm(new BlackjackViewModel(this))
{
    setWindowTitle(Strings::WINDOW_TITLE);

    auto* root = new Framework::VBoxLayout(this);
    root->setSpacing(Styles::ROOT_SPACING);
    root->setContentsMargins(Styles::ROOT_MARGIN, Styles::ROOT_MARGIN, Styles::ROOT_MARGIN, Styles::ROOT_MARGIN);

    auto* dealerBox = new Framework::VBoxLayout();
    auto* dealerTitle = new Framework::Label(Strings::DEALER_TITLE, this);
    dealerTitle->setStyleSheet(Styles::TITLE_LABEL);
    m_dealerLabel = new Framework::Label(Strings::EMPTY, this);
    m_dealerTotal = new Framework::Label(Strings::EMPTY, this);
    dealerBox->addWidget(dealerTitle);
    dealerBox->addWidget(m_dealerLabel);
    dealerBox->addWidget(m_dealerTotal);

    auto* playerBox = new Framework::VBoxLayout();
    auto* playerTitle = new Framework::Label(Strings::PLAYER_TITLE, this);
    playerTitle->setStyleSheet(Styles::TITLE_LABEL);
    m_playerLabel = new Framework::Label(Strings::EMPTY, this);
    m_playerTotal = new Framework::Label(Strings::EMPTY, this);
    playerBox->addWidget(playerTitle);
    playerBox->addWidget(m_playerLabel);
    playerBox->addWidget(m_playerTotal);

    auto* mid = new Framework::HBoxLayout();
    mid->addLayout(dealerBox);
    mid->addSpacing(Styles::MID_SPACING);
    mid->addLayout(playerBox);

    m_statusLabel = new Framework::Label(Strings::STATUS_START, this);
    m_statusLabel->setWordWrap(true);
    m_statusLabel->setStyleSheet(Styles::STATUS_LABEL);

    auto* controls = new Framework::HBoxLayout();
    controls->setSpacing(Styles::CONTROLS_SPACING);
    m_dealBtn = new Framework::Button(Strings::BTN_DEAL, this);
    m_hitBtn = new Framework::Button(Strings::BTN_HIT, this);
    m_standBtn = new Framework::Button(Strings::BTN_STAND, this);
    controls->addWidget(m_dealBtn);
    controls->addWidget(m_hitBtn);
    controls->addWidget(m_standBtn);

    m_chipsLabel = new Framework::Label(this);
    m_chipsLabel->setStyleSheet(Styles::CHIPS_LABEL);

    root->addLayout(mid, 1);
    root->addSpacing(Styles::ROOT_SECTION_SPACING);
    root->addWidget(m_statusLabel);
    root->addWidget(m_chipsLabel);
    root->addLayout(controls);

    resize(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT);

    // Wire view to viewmodel
    connect(m_dealBtn, &Framework::Button::clicked, m_vm, &BlackjackViewModel::deal);
    connect(m_hitBtn, &Framework::Button::clicked, m_vm, &BlackjackViewModel::hit);
    connect(m_standBtn, &Framework::Button::clicked, m_vm, &BlackjackViewModel::stand);
    connect(m_vm, &BlackjackViewModel::viewDataChanged, this, &BlackjackWindow::refresh);

    refresh();
}

void BlackjackWindow::refresh() const
{
    // Pull state from VM
    m_dealerLabel->setText(m_vm->dealerText());
    m_dealerTotal->setText(m_vm->dealerTotalText());
    m_playerLabel->setText(m_vm->playerText());
    m_playerTotal->setText(m_vm->playerTotalText());
    m_statusLabel->setText(m_vm->statusText());
    m_chipsLabel->setText(m_vm->chipsText());

    m_dealBtn->setEnabled(m_vm->dealEnabled());
    m_hitBtn->setEnabled(m_vm->hitEnabled());
    m_standBtn->setEnabled(m_vm->standEnabled());
}
