#include "invites.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QObject>

invites::invites()
{

    Nom_Prenom="";CIN=0 ;Numero=0;Metier="";}


    invites::invites(QString Nom_Prenom,int CIN,int Numero ,QString Metier){

         this->Nom_Prenom=Nom_Prenom; this->Numero=Numero; this->CIN=CIN; this->Metier=Metier;}

    QString invites::getNom_Prenom(){return Nom_Prenom;}

    int invites::getCIN(){return CIN;}

    int invites::getNumero(){return Numero;}
    QString invites::getMetier(){return Metier;}

    //setter

    void invites::setNom_Prenom(QString Nom_Prenom){this->Nom_Prenom=Nom_Prenom;}

    void invites::setCIN(int CIN){this->CIN=CIN;}

    void invites::setNumero(int Numero){this->Numero=Numero;}

    void invites::setMetier(QString Metier){this->Metier=Metier;}

    bool invites::ajouter(){

    bool test =true ;

        QSqlQuery query;

              query.prepare("INSERT INTO INVITES (NOM_PRENOM,CIN,NUMERO,METIER) "

                            "VALUES (:Nom_Prenom, :CIN, :Numero, :Metier)");

              query.bindValue(":Nom_Prenom",Nom_Prenom);

              query.bindValue(":CIN",CIN);

              query.bindValue(":Numero",Numero);

              query.bindValue(":Metier",Metier);

              query.exec();

              qDebug() <<query.lastError();

        return  test;

    };


    QSqlQueryModel* invites::afficher(){

        QSqlQueryModel* model=new QSqlQueryModel();



        model->setQuery("SELECT* FROM INVITES");

               model->setHeaderData(0, Qt::Horizontal,QObject::tr("NOM_PRENOM"));

               model->setHeaderData(1, Qt::Horizontal,QObject::tr("CIN"));

               model->setHeaderData(2, Qt::Horizontal,QObject::tr("NUMERO"));

               model->setHeaderData(3, Qt::Horizontal,QObject::tr("METIER"));


               return model;



    }


    bool invites::supprimer(int CIN){

        QSqlQuery query;

        query.prepare("Delete from INVITES where CIN=:CIN");

        query.bindValue(":CIN",CIN);

        return query.exec();

    }






    bool invites::modifier(QString Nom_Prenom,int CIN,int Numero,QString Metier)

    {

        QSqlQuery query;


        query.prepare("UPDATE INVITES SET Nom_Prenom=:NOM_PRENOM, CIN=:CIN, Metier=:METIER WHERE Numero=:NUMERO");


        query.bindValue(":NOM_PRENOM", Nom_Prenom);

        query.bindValue(":CIN", CIN);

        query.bindValue(":NUMERO", Numero);

         query.bindValue(":METIER", Metier);

        return  query.exec();

        }


    QSqlQueryModel* invites::trierParNom_Prenom()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM INVITES ORDER BY Nom_Prenom ASC");
        model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM_PRENOM"));
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2,Qt::Horizontal, QObject::tr("NUMERO"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("METIER"));



        return model;
    }

    QSqlQueryModel* invites::trierParCIN()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT * FROM INVITES ORDER BY CIN ASC");
        model->setHeaderData(0,Qt::Horizontal, QObject::tr("NOM_PRENOM"));
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("CIN"));
        model->setHeaderData(2,Qt::Horizontal, QObject::tr("NUMERO"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("METIER"));



        return model;
    }
