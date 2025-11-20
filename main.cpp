#include <QApplication>
#include "view/BlackjackWindow.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    BlackjackWindow w;
    w.show();
    return QApplication::exec();
}