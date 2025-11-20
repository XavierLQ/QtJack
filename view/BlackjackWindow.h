#pragma once

#include <QWidget>

class QLabel;
class QPushButton;
class BlackjackViewModel;

class BlackjackWindow : public QWidget {
    Q_OBJECT
public:
    explicit BlackjackWindow(QWidget* parent = nullptr);

private slots:
    void refresh() const;

private:
    // UI
    QLabel* m_dealerLabel{};
    QLabel* m_dealerTotal{};
    QLabel* m_playerLabel{};
    QLabel* m_playerTotal{};
    QLabel* m_statusLabel{};
    QLabel* m_chipsLabel{};
    QPushButton* m_dealBtn{};
    QPushButton* m_hitBtn{};
    QPushButton* m_standBtn{};

    BlackjackViewModel* m_vm{};
};
