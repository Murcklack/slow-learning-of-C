#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
  double mks_heigt = 600; 
  double mks_speed = 7.56;
  double signal = 2.18*pow(10,9);
  double r_planet = 6371;
  double alpha;
  printf("Input a: ");
  scanf("%lf",&alpha);
  double a = alpha * (M_PI / 180);
  float svet = 299792.458;   


  double dist_m = sqrt(pow(r_planet,2)*pow(sin(a),2)+2*r_planet*mks_heigt+pow(mks_heigt,2))  - r_planet * sin(a); 
  long double rad_speed = mks_speed * (r_planet * cos(a) / (r_planet * sin(a) + dist_m));
  long double drift = rad_speed / svet * pow(10,9);
  long double shift = (signal * sqrt((1 + rad_speed/svet)/(1 - rad_speed/svet))-signal)/1000;

  printf("Enter elevation angle alpha (0..90 degrees): %.0lf\n",alpha);
  printf("Distance: %.2lf km\n",dist_m);
  printf("Radial velocity (vr): %.2Lf m/s\n", rad_speed*1000);
  printf("Time drift (dT): %.4Lf ns/s\n", drift);
  printf("Doppler shift (fd): %.4Lf kHz\n",shift);
  if ((shift > 42 || drift > 18) && dist_m > 1000){
    printf("PROFILE: CRITICAL ERROR\n");
  }
  else if (shift > 25 && drift>10){
    printf("PROFILE: HIGH DYNAMIC MODE\n");
  }
  else if (shift > 3 || abs(drift) > 1.0){
    printf("PROFILE: NORMAL ACCELERATION\n");
  }
  else{
    printf("PROFILE: ZENITH MODE\n");
  }

  return 0;
}
