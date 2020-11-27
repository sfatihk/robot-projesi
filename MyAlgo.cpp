#include "MyAlgo.h"
#include <bitset>
#include <cstdlib>

bool algorithm1(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
  * VL=50;* VR = 50;
  return true;
}
bool algorithm2(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
  return algorithm1(S, L, R, Init, VL, VR);
}

 
float Kp=20,Ki=0.0000001,Kd=405;
int ideal=8;
float eski_hata=0,I=0;
int MAX=100;
bool algorithm3(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
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
    
    *VR=MAX;
    *VL=MAX+hata_dengesi;
  }
  else{
    
    *VR=MAX-hata_dengesi;
    *VL=MAX;
  }
    return true;
}
bool algorithm4(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return algorithm1(S, L, R, Init, VL, VR);
}
bool algorithm5(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return algorithm1(S, L, R, Init, VL, VR);
}
bool algorithm6(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return algorithm1(S, L, R, Init, VL, VR);
}
bool algorithm7(unsigned short S, unsigned short L, unsigned short R, int Init, int * VL, int * VR)
{
 return algorithm1(S, L, R, Init, VL, VR);
}
