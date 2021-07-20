#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //crear el lienzo
    lienzo =QPixmap(500,500);
    //invocar al metodo dibujar
    this->dibujar();
    //mostrar el lienzo en el cuadro
    ui->Cuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    int x=50;
    int y =50;
    int ancho=100;
    int alto_1=ui->inNota1->value();
    int alto_2=ui->inNota2->value();
    int alto_3=ui->inNota3->value();
    //rellenar el lienzo de color blanco
    lienzo.fill(Qt::white);

    //crear el pintor
    QPainter painter(&lienzo);
    //crear pincel para el borde
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::red);
    pincel.setJoinStyle(Qt::MiterJoin);

    //establecer el pincel al pintor
    painter.setPen(pincel);

    //dibujar primera barra
    painter.drawRect(x,y+(400-alto_1),ancho,alto_1);

    //crear un color para el borde y el relleno
    QColor colorborde2(78,3,48);
    QColor colorRelleno2(190,120,162);

    //establecer el color al pincel
    pincel.setColor(colorborde2);

    //volver a establecer el pincel al objeto painter
    painter.setPen(pincel);

    //establecer el colo de la borcha del objeto painter
    painter.setBrush(colorRelleno2);

    //dibujar la segunda barra
    painter.drawRect(x+150,y+(400-alto_2),ancho,alto_2);

    //creando los colores de la tercera barra
    QColor colorRelleno3(253,253,115);
    QColor colorBorde3(174,174,51);

    //establecer el pincle y la brocha pal painter
    pincel.setColor(colorBorde3);
    painter.setPen(pincel);
    painter.setBrush(colorBorde3);

    //dibuja la tervera barra
    painter.drawRect(x+300,y+(400-alto_3),ancho,alto_3);
    ui->Cuadro->setPixmap(lienzo);

}

void Principal::Save()
{
    //crear un objeto QDir a partir del directorio del usuario
    QDir directorio = QDir::home();
    // agregar el path absoluto del objetos , un nombre por defecto del archivo
    QString pathArchivo = directorio.absolutePath()+"/sin_nombre.PNG";
    //abrir un cuadro de dialogo para seleccionar el nombre y el archivo a guardar
    QString fileName = QFileDialog::getSaveFileName(this,"Guardar Archivo",
                                                    pathArchivo,
                                                    "Imagen(*.PNG)");
    ///guardar datos en el archivo
    //crear el archivo a partir del nombre arrojado por el cuadro de dialogo
    QFile f(fileName);
    //crear el objeto QTextStream(permite escribir el archivo)
    QTextStream out(&f);
    //intentar abrir el archivo ya sea para escibirlo o para agregar texto si existiera
    if(!f.open(QIODevice::WriteOnly)){
        //si no se puede abrir muestra un mensaje de adrvertencia
        QMessageBox::warning(this,"Estaditicas","No se puede abrir el archivos"+fileName);
        //salir de la funcion
        return;

    }
    //guardar contenido del texto de resultado en el archivo

    lienzo.save(&f,"PNG");
    //cerrar el archivoi
    f.close();
}


void Principal::on_CmdGraficar_clicked()
{
    dibujar();
}

void Principal::on_actionSave_triggered()
{
    Save();
}
