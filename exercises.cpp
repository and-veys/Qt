#include "exercises.h"
#include <QtMath>

bool Exercise::getDoubleFromText(QString str, double & ret)
{
    bool ok;
    ret = str.toDouble(&ok);
    return ok;
}

Ex_1::Ex_1(QString s_a, QString s_b, QString s_c)
{
    double a;
    double b;
    double c;
    bool ok = getDoubleFromText(s_a, a);
    ok &= getDoubleFromText(s_b, b);
    ok &= getDoubleFromText(s_c, c);
    x1=0;
    x2=0;
    if(ok)
    {
        if(a == 0)
        {
            x1 = (-c/b);
            x2 = x1;
            result = 1;
        }
        else
        {
           double d = b*b-4*a*c;
           if(d >= 0)
           {
               d = qSqrt(d);
               x1 = (-b+d)/(2*a);
               x2 = (-b-d)/(2*a);
               result = 2;
           }
           else
               result = 0;
        }
    }
    else
        result = -1;
}

char Ex_1::getResult(double * res)
{
    res[0]=x1;
    res[1]=x2;
    return result;
}

void Ex_1::getStringResult(QString *str)
{
    double res[2];
    switch(getResult(res))
    {
    case 0:
        str[0] = "нет вещественного корня";
        str[1] = "нет вещественного корня";
        break;
     case 1:
        str[0] = QString::number(x1);
        str[1] = "нет корня";
        break;
    case 2:
        str[0] = QString::number(x1);
        str[1] = QString::number(x2);
        break;
    default:
        str[0] = "ошибка ввода";
        str[1] = "ошибка ввода";
    }
}

Ex_2::Ex_2(QString s1, QString s2, QString ang, bool deg)
{
    double a;
    double b;
    double an;
    bool ok = getDoubleFromText(s1, a);
    ok &= getDoubleFromText(s2, b);
    ok &= getDoubleFromText(ang, an);
    s3 = 0;
    if(ok)
    {
        if(deg)
            an = qDegreesToRadians(an);
        s3 = qSqrt(a*a + b*b - 2*a*b*qCos(an));
        result = 1;
    }
    else
        result = -1;
}

char Ex_2::getResult(double *res)
{
    *res = s3;
    return result;
}

void Ex_2::getStringResult(QString *str)
{
    double res;
    switch(getResult(&res))
    {
     case 1:
        *str = QString::number(s3);
        break;
    default:
        *str = "ошибка ввода";
    }
}
