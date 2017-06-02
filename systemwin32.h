#ifndef SYSTEMWIN32_H
#define SYSTEMWIN32_H

#include <windows.h>
#include <w32api.h>
#include <tlhelp32.h>

#include <QMap>
#include <QString>
#include <QStringList>
//#include <QMessageBox>
#include <QDebug>

class systemWin32
{
public:
    systemWin32();
    ~systemWin32();
    void updateProcessList();
    bool findProcess(QString findProcName);
    void closehSnapHandle();
    int findProcessCount(QString findProcName);
    QString getProcessName(int idProcess);
    QStringList getAllProcessList();
private:
//    HANDLE hSnap;
    QMap <int, QString> win32sysMap;
    QString copyToQString(WCHAR array[MAX_PATH]);

};

#endif // SYSTEMWIN32_H