#ifndef EX_1_H
#define EX_1_H

#include <QString>

class Exercise
{
public:
    char result;
    bool getDoubleFromText(QString str, double & dt);
    virtual char getResult(double * res)=0;
    virtual void getStringResult(QString * str)=0;

};


class Ex_1 : public Exercise
{
public:
    Ex_1(QString a, QString b, QString c);
    char getResult(double * res);
    void getStringResult(QString * str);

private:
    double x1;
    double x2;

};

class Ex_2 : public Exercise
{
public:
    Ex_2(QString s1, QString s2, QString ang, bool deg);
    char getResult(double * res);
    void getStringResult(QString * str);

private:
    double s3;
};

#endif // EX_1_H
