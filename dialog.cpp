#include "dialog.h"
#include "ui_dialog.h"

/////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
#include "QFile"
#include "QTextStream"
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QFile inputFile("/home/viktor/my_projects_qt_2/Avtokopirovaniye_GIT_TSIKL/spisok.txt");
    if (inputFile.open(QIODevice::ReadOnly))
    {
      //  QString full_string;
       QTextStream in(&inputFile);
       while (!in.atEnd())
       {
          QString line = in.readLine();
       //   full_string="/home/viktor/my_projects_qt_2/"+line;
          // echo <password> | sudo -S -u <user> <command>
          // echo 1970 | sudo -S -u viktor <command>
          QString  comanda_vsia="cd /home/viktor/my_projects_qt_2/"+line +
 " && echo 1970 | sudo -S -u viktor "
          //"&& rm -rf /home/viktor/my_projects_qt_2/"+line +"/.git/index.lock "
     "git config --global --add safe.directory /home/viktor/my_projects_qt_2/"+line+" && git checkout master";
            system (comanda_vsia.toStdString().c_str() );
       //   ...
       }
       inputFile.close();
    }
}

Dialog::~Dialog()
{
    delete ui;
}

