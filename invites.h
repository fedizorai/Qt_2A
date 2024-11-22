#ifndef INVITES_H
#define INVITES_H
#include<QString>
#include<QSqlQueryModel>


class invites
{
public:
    invites();
    invites(QString,int,int,QString);
        int getCIN();
        QString getNom_Prenom();
        int getNumero();
        void setCIN(int);
        void setNom_Prenom(QString);
        void setNumero(int);
        QString getMetier();
        void setMetier(QString);
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int);
        bool modifier(QString,int,int,QString);
        QSqlQueryModel *trierParCIN();
        QSqlQueryModel *trierParNom_Prenom();
private:
        QString Nom_Prenom,Metier;
        int CIN, Numero;

};

#endif // INVITES_H
