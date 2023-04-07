#include <QApplication>
#include <QPushButton>

#include "gag.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    gag myGagWidget;
    myGagWidget.setWindowTitle("Gag Application");
    myGagWidget.show();

    return app.exec();
}
