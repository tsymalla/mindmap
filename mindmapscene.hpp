#ifndef MINDMAPSCENE_HPP
#define MINDMAPSCENE_HPP

#include <QGraphicsScene>
#include "mindmap.hpp"
#include "mindmapnodegraphicsitem.hpp"

class MindmapScene : public QGraphicsScene
{
    Q_OBJECT
private:
    QBrush _backgroundBrush;
    QBrush _brush;
    QPen _pen;
    QFont _font;

    MindmapNodeGraphicsItem* _selectedGraphicsNode;
    NodeRawPtr _selectedNode;
    Mindmap _mindmap;

    void _focusSelection(MindmapNodeGraphicsItem* item);
public:
    MindmapScene(QObject* parent = nullptr);
    QString toJSON() const;
    void fromJSON(const QString& json);

    void addNode();
    void addNode(const QString& nodeName);
    void removeSelectedNodes();
    void changeNodeContent(MindmapNodeGraphicsItem* item, const QString& content);

    int getNodeCount() const;

    void reset();

public slots:
    void nodePositionChanged(MindmapNodeGraphicsItem* item, NodeRawPtr node);
    void nodeSelectionChanged(MindmapNodeGraphicsItem* item, NodeRawPtr node);
    void nodeDoubleClicked(MindmapNodeGraphicsItem* item, NodeRawPtr node);

signals:
    void passNodeDoubleClick(MindmapNodeGraphicsItem* item, NodeRawPtr node);
    void notifyMindmapChanged(bool wasSaved);

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
};

#endif // MINDMAPSCENE_HPP
