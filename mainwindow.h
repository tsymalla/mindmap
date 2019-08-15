#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mindmapscene.hpp"
#include "about.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void nodeContentChanged(MindmapNode* node, const std::string& content);

public slots:
    void passNodeDoubleClick(MindmapNode* node);

private slots:
    void on_actionAdd_Node_triggered();
    void on_action_Exit_triggered();

    void on_action_Save_triggered();

    void on_action_New_Mindmap_triggered();

    void on_action_About_triggered();

    void on_action_Open_file_triggered();

    void on_actionRemove_node_triggered();

private:
    Ui::MainWindow *ui;
    MindmapScene *_mindmapScene;

    About* _about;
};

#endif // MAINWINDOW_H
