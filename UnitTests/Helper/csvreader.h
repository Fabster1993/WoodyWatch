#ifndef CSVREADER_H
#define CSVREADER_H

#include <QStringList>

class QString;

class CsvReader
{
public:
    CsvReader(const QString& filepath);
    QStringList getContent();
private:
    QStringList fileContent;
};

#endif // CSVREADER_H
