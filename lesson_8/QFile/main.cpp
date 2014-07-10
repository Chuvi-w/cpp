#include <QCoreApplication>
#include <QString>
#include <QFile>
#include <QTextStream>

int main()
{
    // Выводить в текстовый файл с помощью Qt
    QFile file("qt_output.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
      // QIODevice::WriteOnly - создаём файл для записи
      // QIODevice::Text - к выводу применяются правила
      //   для текстового файла

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << QString("Любой текст!") << endl;
    out << QString("2 * 3 = ") << (2*3) << endl;

    file.close();

    return 0;
}
