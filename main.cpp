#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <Windows.h>

bool toTCharPtr(TCHAR **dest, QString const &src) {
    *dest = (TCHAR*) malloc(sizeof(TCHAR) * src.size());
    TCHAR *s = *dest;
    src.toWCharArray((wchar_t*)s);
    s[src.size()] = 0;
    return true;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString s ("hola");
    TCHAR *pc;
    toTCharPtr(&pc, s);
    qDebug() << "pc:" << s;
    return a.exec();
}
