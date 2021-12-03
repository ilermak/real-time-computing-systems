#include<stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc , char *argv[])
{
    //FILE *file = fopen("etalon.txt", "w");
    double samplerate = 48000; // частота сэмплов
    double wavefrequency = 425; // частота волны
    int wavevolume = 65536; // громкость волны
    int samplelenght = 113;
    unsigned short buffer[113];

    double period = samplerate / wavefrequency / 2; //вычисляем период волны
    double pi = 3.14; //число pi
    int n;
    double val;
    long L_val;

    for(int a = 0;a < samplelenght; a++) //устанавливаем цикл на длину сэмпла
    {
        val =  sin(a * pi / period); //вычисление sine-волны
        L_val= (long) (0x7FFFFFFF * val);   // результат в Q31
        buffer[a] = (unsigned short) (L_val >> 16); //заносим вычисленное значение в буфер
    }

    for (int i = 0; i < samplelenght; i++) {
        //b = sin(i);

        printf("0x%04X, 0x%04X, ", buffer[i], buffer[i]);
        if ((i + 1 ) % 5 == 0 ) {
            printf("\n");
        }


       // fclose(file);
//            if (i % 11 == 0 && i != 0)
//                printf("\n");

//            printf("%d,\n", buffer[i]);



//            fscanf(file, "0x%04X", buffer);
//            fclose(file);

    }
}


//
//#include<stdio.h>
//#include <math.h>
//#include <stdint.h>
//
//int main(int argc , char *argv[])
//{
//    //FILE *file = fopen("examples.txt", "w");
//    double samplerate = 48000; // частота сэмплов
//    double wavefrequency = 425; // частота волны
//    int wavevolume = 65536; // громкость волны
//    int samplelenght = 230;
//    unsigned short buffer[230];
//
//    double period = samplerate / wavefrequency / 2; //вычисляем период волны
//    double pi = 3.14; //число pi
//    int n;
//    double val;
//    long L_val;
//
//    for(int a = 0;a < samplelenght; a++) //устанавливаем цикл на длину сэмпла
//    {
//        val =  (sin(a * pi / period) + 1) * 32767; //вычисление sine-волны
//
////        L_val= (long) (0x7FFFFFFF * val);   // результат в Q31
//        buffer[a] = (unsigned short) val; //заносим вычисленное значение в буфер
//    }
//
//    for (int i = 0; i < samplelenght / 2; i++) {
//        //b = sin(i);
//
//        printf("0x%04X, 0x%04X,\n", buffer[i], buffer[i]);
//
//
//
//    }
//}