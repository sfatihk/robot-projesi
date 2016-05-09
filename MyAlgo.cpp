#include "MyAlgo.h"
#include <bitset>
#include <cstdlib>
//Ogrenci_No:030113003

bool Algo1(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
* VL=50;* VR = 50;
return true;
}
bool Algo2(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
return Algo1(S, L, R, Init, VL, VR);
}

float Kp=20,Ki=0.0000001,Kd=405;
int ideal=8;
float eski_hata=0,I=0;
int MAX=100;
bool Algo3(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 float hata;
  int j;
  int toplam=0,okunan_sensor=0;
  for(int i=14; i>=0; i--){
    j=S>>i;
    if(j & 1){
      toplam+=(i+1);
      okunan_sensor++;
    }
  }
  if(okunan_sensor!=0){
    hata= ideal - toplam/okunan_sensor;
  }
  else if (okunan_sensor == 0){
    hata = eski_hata;
  }
  float P = hata;
  I += hata;
  float D = hata - eski_hata;

  eski_hata = hata;

  float hata_dengesi = Kp*P + Ki*I + Kd*D;

  if( hata_dengesi > MAX ){
    hata_dengesi=MAX;
  }
  if( hata_dengesi < -MAX){
    hata_dengesi=-MAX;
  }

  if(hata_dengesi < 0 ){
    //sag tam guc,sol azaltilmis
    *VR=MAX;
    *VL=MAX+hata_dengesi;
  }
  else{
    //sol tamguc, sag azaltilmis
    *VR=MAX-hata_dengesi;
    *VL=MAX;
  }
    return true;
}
bool Algo4(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return Algo1(S, L, R, Init, VL, VR);
}
bool Algo5(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return Algo1(S, L, R, Init, VL, VR);
}
bool Algo6(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return Algo1(S, L, R, Init, VL, VR);
}
bool Algo7(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return Algo1(S, L, R, Init, VL, VR);
}
