#pragma once

#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Framework {

class VBoxLayout : public QVBoxLayout {
public:
    using QVBoxLayout::QVBoxLayout;
};

class HBoxLayout : public QHBoxLayout {
public:
    using QHBoxLayout::QHBoxLayout;
};

}
