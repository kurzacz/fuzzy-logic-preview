#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ArchitekturaMamdani.h"
#include "LiczbaRozmyta.h"
#include "ObslugaPrzynaleznosci.h"
#include "Regula.h"
#include "TrojkatnaFunkcjaPrzynaleznosci.h"
#include "WejscieRozmyte.h"
#include "WyjscieRozmyte.h"
#include "WyostrzanieCOS.h"
#include "ZbiorRozmyty.h"

#include "Rozmywanie.h"

#include <string>
#include <sstream>

using namespace std;

float nasycenie (float x, float min, float max)
{
    if (x < min)
        return min;
    else if (x > max)
        return max;
    else
        return x;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Inicjalizacja parametrów regulatorów
    pKp = 1.1;
    piKp = 0.7;
    piTi = 5;

    MainWindow::makePlot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makePlot()
{
    QString qs1, qs2, qtext;
    // zakresy dla e, de, d2e



    Regula *reg;

    // Część wyostrzania
    WyjscieRozmyte Wy;
    Wyostrzanie *dv;
    FunkcjaPrzynaleznosci *pDV, *zDV, *nDV;
    dv = Wy.dodajWyostrzanieCOS("dv", -1, 1);
    int nDVnum = -1;
    int zDVnum = 0;
    int pDVnum = 1;
    nDV = dv->dodajRozmywanieSingletonowe("N dv", nDVnum);
    zDV = dv->dodajRozmywanieSingletonowe("Z dv", zDVnum);
    pDV = dv->dodajRozmywanieSingletonowe("P dv", pDVnum);

    qtext = QString("Singleton %1").arg(nDVnum);
    ui->cvN->setText(qtext);
    qtext = QString("Singleton %1").arg(zDVnum);
    ui->cvZ->setText(qtext);
    qtext = QString("Singleton %1").arg(pDVnum);
    ui->cvP->setText(qtext);

    // Regulator P
    float PeMin = -1;
    float PeMax = 1;

    WejscieRozmyte WeP;
    Rozmywanie *eP;
    FunkcjaPrzynaleznosci *nEp, *pEp;

    if (pKp > 1) {
        PeMin = -1;
        PeMax = 1;
        eP = WeP.dodajWejscie("e", PeMin, PeMax);
        nEp = eP->dodajRozmywanieTrapezowe("N e", PeMin, (1/MainWindow::pKp)*PeMin);
        pEp = eP->dodajRozmywanieTrapezowe("P e", (1/MainWindow::pKp)*PeMax, PeMax);
        qs1 = QString::number(PeMin);
        qs2 = QString::number((1/MainWindow::pKp)*PeMin);

        qtext = QString("Trapezowe: %1, %2").arg(qs1,qs2);
        ui->eN->setText(qtext);

        qs1 = QString::number((1/MainWindow::pKp)*PeMax);
        qs2 = QString::number(PeMax);
        qtext = QString("Trapezowe: %1, %2").arg(qs1,qs2);
        ui->eP->setText(qtext);

    }
    else if (pKp == 1) {
        PeMin = -1;
        PeMax = 1;
        eP = WeP.dodajWejscie("e", PeMin, PeMax);
        nEp = eP->dodajRozmywanieTrojkatne("N e", PeMin);
        pEp = eP->dodajRozmywanieTrojkatne("P e", PeMax);
        ui->eN->setText("Trojkatne: 1");
        ui->eP->setText("Trojkatne: 1");
        // Powrót do granic -1, 1 aby limitowanie działało
        PeMin = -1;
        PeMax = 1;
    }
    else {
        PeMin = -1/pKp;
        PeMax = 1/pKp;
        eP = WeP.dodajWejscie("e", PeMin, PeMax);
        nEp = eP->dodajRozmywanieTrojkatne("N e", PeMin);
        pEp = eP->dodajRozmywanieTrojkatne("P e", PeMax);

        qs1 = QString::number(PeMin);
        qtext = QString("Trojkatne: %1").arg(qs1);
        ui->eN->setText(qtext);

        qs1 = QString::number(PeMax);
        qtext = QString("Trojkatne: %1").arg(qs1);
        ui->eP->setText(qtext);


    }

    // Wrzuć wartości do interfejsu


    ArchitekturaMamdani RegulatorP(&WeP, &Wy);

    reg = RegulatorP.stworzNowaRegule();
    reg->dodajPoprzednik(eP,nEp);
    reg->dodajNastepnik(dv, nDV);

    reg = RegulatorP.stworzNowaRegule();
    reg->dodajPoprzednik(eP,pEp);
    reg->dodajNastepnik(dv, pDV);

    // Regulator PI

    float PIeMin = -1;
    float PIeMax = 1;
    float PIdeMin = -10;
    float PIdeMax = 10;

    WejscieRozmyte WePI;
    Rozmywanie *ePI, *dePI;
    FunkcjaPrzynaleznosci *nEpi, *pEpi, *nDEpi, *pDEpi;
    if (piKp > 1) {
        PIeMin = -1;
        PIeMax = 1;
        ePI = WePI.dodajWejscie("e", PIeMin, PIeMax);
        nEpi = ePI->dodajRozmywanieTrapezowe("N e", PIeMin, (-1/MainWindow::piKp)*PIeMin);
        pEpi = ePI->dodajRozmywanieTrapezowe("P e", (1/MainWindow::piKp)*PIeMax, PIeMax);
    }
    else if (piKp == 1) {
        PIeMin = -1;
        PIeMax = 1;
        ePI = WePI.dodajWejscie("e", PIeMin, PIeMax);
        nEpi = ePI->dodajRozmywanieTrojkatne("N e", PIeMin);
        pEpi = ePI->dodajRozmywanieTrojkatne("P e", PIeMax);
        PIeMin = -1;
        PIeMax = 1;
    }
    else {
        PIeMin = -1/piKp;
        PIeMax = 1/piKp;
        ePI = WePI.dodajWejscie("e", PIeMin, PIeMax);
        nEpi = ePI->dodajRozmywanieTrojkatne("N e", PIeMin);
        pEpi = ePI->dodajRozmywanieTrojkatne("P e", PIeMax);
    }

    dePI = WePI.dodajWejscie("de", PIdeMin, PIdeMax);
    nDEpi = dePI->dodajRozmywanieTrapezowe("N e", PIdeMin, (1/piTi)*PIdeMin);
    pDEpi = dePI->dodajRozmywanieTrapezowe("P e", (1/piTi)*PIdeMax, PIdeMax);

    ArchitekturaMamdani RegulatorPI(&WePI, &Wy);

    reg = RegulatorPI.stworzNowaRegule();
    reg->dodajPoprzednik(ePI,nEpi);
    reg->dodajPoprzednik(dePI,nDEpi);
    reg->dodajNastepnik(dv, nDV);

    reg = RegulatorPI.stworzNowaRegule();
    reg->dodajPoprzednik(ePI,nEpi);
    reg->dodajPoprzednik(dePI,pDEpi);
    reg->dodajNastepnik(dv, zDV);

    reg = RegulatorPI.stworzNowaRegule();
    reg->dodajPoprzednik(ePI,pEpi);
    reg->dodajPoprzednik(dePI,nDEpi);
    reg->dodajNastepnik(dv, zDV);

    reg = RegulatorPI.stworzNowaRegule();
    reg->dodajPoprzednik(ePI,pEpi);
    reg->dodajPoprzednik(dePI,pDEpi);
    reg->dodajNastepnik(dv, pDV);





    // tablica wejsc obiektu
    float u[] = {0, 0, 0};
    // tablica wyjsc obiektu
    float y[] = {0, 0, 0, 0};

    float E = 0;
    // Wartości primowane do przeliczeń
    float CV = 0;
    float DCV = 0;
    float Tp = 0.1;

    float SP = 0.3;

    const int ileKrokow = 100;

    // na wykres
    QVector<double> x(ileKrokow), outP(ileKrokow), sp(ileKrokow);

    // Regulacja P
    for (int i=0; i<ileKrokow; i++) {
        x[i] = i*Tp;
        sp[i] = SP;
        E = y[0] - SP;

        // Kontrola stanów nasycenia
        E = nasycenie(E, PeMin, PeMax);
        // Załaduj wejścia
        WeP.wczytajWartosc(0, E);

       // Poprzesuwaj stany i wyjścia obiektu
       for (int j=2; j>0; j--)
           u[j] = u[j-1];
       for (int j=3; j>0; j--)
           y[j] = y[j-1];


       RegulatorP.przelicz();

       DCV = Wy.getWynik(0);
       //cout << DCV << endl;
       CV = -1*DCV;

       u[0] = CV;
       //y[0] = (b2*u[2]+b1*u[1]+b0*u[0]-(a3*y[3]+a2*y[2]+a1*y[1]))/a0;
       y[0] = 0.1*u[1]+0.99*y[1];
       //y[0] = (u[0]+10*y[1]/Tp)/(1+10/Tp);
       outP[i] = y[0];
    }

    // Regulacja PI
    E = 0;
    CV = 0;
    float Ep = 0;
    float DE = 0;

    for (int j=0; j<3; j++)
        u[j] = 0;
    for (int j=0; j<4; j++)
        y[j] = 0;

    QVector<double> outPI(ileKrokow);

    for (int i=0; i<ileKrokow; i++) {
        Ep = E;
        E = y[0] - SP;
        DE = (E-Ep)/Tp;

        // Kontrola stanów nasycenia
        E = nasycenie(E, PIeMin, PIeMax);
        DE = nasycenie(DE, PIdeMin, PIdeMax);
        // Załaduj wejścia
        WePI.wczytajWartosc(0, E);
        WePI.wczytajWartosc(1, DE);

       // Poprzesuwaj stany i wyjścia obiektu
       for (int j=2; j>0; j--)
           u[j] = u[j-1];
       for (int j=3; j>0; j--)
           y[j] = y[j-1];


       RegulatorPI.przelicz();

       DCV = Wy.getWynik(0);
       //cout << DCV << endl;
       CV += -1*DCV;

       u[0] = CV;
       //y[0] = (b2*u[2]+b1*u[1]+b0*u[0]-(a3*y[3]+a2*y[2]+a1*y[1]))/a0;
       y[0] = 0.1*u[1]+0.99*y[1];
       //y[0] = (u[0]+10*y[1]/Tp)/(1+10/Tp);
       outPI[i] = y[0];
    }


    // Wykres P
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, outP);
    ui->customPlot->graph(0)->setPen(QPen(Qt::red));
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setData(x, sp);
    ui->customPlot->graph(1)->setPen(QPen(Qt::blue));

    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("czas T [s]");
    ui->customPlot->yAxis->setLabel("regulator P");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(0, ileKrokow*0.1);
    ui->customPlot->yAxis->setRange(0, 0.5);
    ui->customPlot->replot();

    // Wykres PI

    ui->customPlot2->addGraph();
    ui->customPlot2->graph(0)->setData(x, sp);
    ui->customPlot2->graph(0)->setPen(QPen(Qt::blue));
    ui->customPlot2->addGraph();
    ui->customPlot2->graph(1)->setData(x, outPI);
    ui->customPlot2->graph(1)->setPen(QPen(Qt::red));

    ui->customPlot2->xAxis->setLabel("czas T [s]");
    ui->customPlot2->yAxis->setLabel("regulator PI");
    ui->customPlot2->xAxis->setRange(0, ileKrokow*0.1);
    ui->customPlot2->yAxis->setRange(0, 0.5);
    ui->customPlot2->replot();
}


void MainWindow::on_pKp_valueChanged(double arg1)
{
    double dpKp = ui->pKp->value();
    pKp = (float) dpKp;

    MainWindow::makePlot();
}

void MainWindow::on_piKp_valueChanged(double arg1)
{
    double dpiKp = ui->piKp->value();
    piKp = (float) dpiKp;

    MainWindow::makePlot();
}

void MainWindow::on_piTi_valueChanged(double arg1)
{
    double dpiTi = ui->piTi->value();
    piTi = (float) dpiTi;

    MainWindow::makePlot();
}
