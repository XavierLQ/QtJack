#include "framework/App.h"
#include "view/BlackjackWindow.h"

int main(int argc, char* argv[])
{
    Framework::App a(argc, argv);
    BlackjackWindow w;
    w.show();
    return Framework::App::exec();
}