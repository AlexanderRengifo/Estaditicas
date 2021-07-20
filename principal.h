#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include <QMainWindow>
#include <QPainter>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_CmdGraficar_clicked();

    void on_actionSave_triggered();

private:
    Ui::Principal *ui;
    //Declarar el objeto sobre el cual se va a dibujar
    QPixmap lienzo;
    //metodo para dibujar
    void dibujar();
    //metod para guardar
    void Save();

};
#endif // PRINCIPAL_H
