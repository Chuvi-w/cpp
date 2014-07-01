#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <math.h>

double sqrFunc(double d){
    try{
        if(d < 0)
            throw QString("Square root: x = %1 < 0").arg(d);
        return sqrt(d);
    } catch(QString str){
        qDebug() << str;
        throw QString("Error in sqrFunc");
    }
}

void f1(){
    throw 1.3;
    //throw QString("ERROR");
}

void f1_x(){

}

void f2(){
    f1();
    f1_x();
}

void f3(){
    int localVarF3;
    try {
        f2();
    } catch(QString str){
        qDebug() << "QString: " << str;
    }
    catch (int param) {
        qDebug() << "int exception: " << param;
    }
    catch (char param) {
        qDebug() << "char exception" << param;
    }
}


int main(int argc, char *argv[])
{
    sqrFunc(-2);
    try{
        f3();
    }
    catch (...) { qDebug() << "default exception"; }
    return 0;
}
