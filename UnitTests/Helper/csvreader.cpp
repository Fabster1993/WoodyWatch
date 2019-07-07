#include "csvreader.h"
#include <QFile>
#include <QDebug>

const QString csvFileEnding = "csv";

CsvReader::CsvReader(const QString& filepath)
{
    if(QFile::exists(filepath) && filepath.endsWith(csvFileEnding))
    {
        QFile file(filepath);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        while (!file.atEnd())
        {
            fileContent.append(file.readLine().replace("\n",""));
        }
    }
    else
    {
        qDebug() << QString("File %1 not found").arg(filepath);
        Q_ASSERT(false);
    }
}

QStringList CsvReader::getContent()
{
    return fileContent;
}
