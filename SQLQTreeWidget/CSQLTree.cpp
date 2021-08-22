#include "CSQLTree.h"
#include "QtSql"
#include "QErrorMessage"
#include <QtSql/QSqlDriver>

qint32 CSQLTree::s_id = 0;


void CSQLTree::serialize()
{
    QString TABLE = "TT1";
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("sql11.freemysqlhosting.net");
    db.setDatabaseName("sql11430638");
    db.setUserName("sql11430638");
    db.setPassword("K6xMQSUriz");
    db.setPort(3306);
    bool ok = db.open();
    if(ok)
    {
        QSqlQuery query(db);

        query.exec("SELECT id, parent_id, name FROM TestTable1");
        qDebug() << query.lastError();
        while (query.next()) {
        QString name = query.value(0).toString();
        int salary = query.value(1).toInt();
        qDebug() << name << salary;
        }

        if(!query.exec(
                    "CREATE TABLE 'TT1' ("
                            "`id` int(11) NOT NULL,"
                            "`parent_id` int(11) NOT NULL,"
                            "name` text NOT NULL"
                        ") ENGINE=InnoDB DEFAULT CHARSET=latin1;"
                        "INSERT INTO TestTable1 (id, parent_id, name)"
                        "VALUES (0, 0, 'Root'), (1, 0, '1');"
                        "COMMIT;"
                        ))
        {
            qDebug() << "DataBase: error of create " << TABLE;
            qDebug() << query.lastError().text();
        }
    }
}

void CSQLTree::deserialize()
{

}
