#ifndef CSQLTREE_H
#define CSQLTREE_H

#include <QWidget>
#include <QTreeWidget>

class CSQLTree
{
public:
    CSQLTree(QTreeWidget* ui_base, QString name = "Default") : m_name(name)
    {
        m_id = s_id++;
        ui_base->setColumnCount(1);
        ui_base->insertTopLevelItem(0, createTreeWidgetItem(m_name));
        m_parent = nullptr;
        m_uiItem = ui_base->topLevelItem(0);
    }

    void serialize();
    void deserialize();

    void deleteNode()
    {
        m_parent->m_aNode.append(m_aNode);
        m_parent->m_uiItem->removeChild(m_uiItem);
        m_parent->m_aNode.removeAll(this);
        for(auto& c : m_aNode)
            m_uiItem->parent()->addChild(c->m_uiItem);
    }

    void editNode(QString text)
    {
        m_name = text;
        m_uiItem->setText(0, text);
    }

    CSQLTree* findNode(QTreeWidgetItem* item)
    {
        if(item == m_uiItem)
            return this;
        for(int i = 0, n = m_aNode.size();i<n;i++)
        {
            auto* nodeItem = m_aNode[i]->findNode(item);
            if(nodeItem != nullptr)
                return nodeItem;
        }
        return  nullptr;
    }

    void addNode(QString name)
    {
        m_aNode.append(new CSQLTree(name));
        m_aNode.back()->m_parent = this;
        m_uiItem->addChild(m_aNode.back()->m_uiItem);
    }

protected:
    CSQLTree(QString name = "Default") : m_name(name)
    {
        m_id = s_id++;
        m_name = name;
        m_uiItem = createTreeWidgetItem(m_name);
    }
    static QTreeWidgetItem* createTreeWidgetItem(QString text)
    { return new QTreeWidgetItem(static_cast<QTreeWidget *>(nullptr), QStringList(text)); }
protected:
    static qint32 s_id;
    qint32 m_id;
    QString m_name;
    CSQLTree * m_parent;
    QList<CSQLTree*> m_aNode;
    QTreeWidgetItem * m_uiItem;
};

#endif // CSQLTREE_H
