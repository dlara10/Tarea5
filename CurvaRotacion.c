#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>


float likelihood(float *radio, float *velocitie, float mb, float md, float mh);
float rando(float min, float max);
int n = 300;
char *name;

int main()
{
  
  srand(time(NULL));
  int i;
  float like;
  char stard[300];
  int numero;
  float mb;
  float md;
  float mh;
  float mb0;
  float md0;
  float mh0;
  float l;
  float l1;
  char buffer[300];
  
  FILE *datos;
  datos = fopen("RadialVeolcities.dat", "r");
  float *radio=malloc(n*sizeof(float));
  float *velocitie=malloc(n*sizeof(float));
  
  numero = fscanf(datos, "%s %s\n", stard, stard);
  for (i=0; i<n; i++);
  {
    fscanf(datos, "%f %f\n", &radio[i], &velocitie[i]);
  }
  fclose(datos);
  
  like=likelihood(radio, velocitie, mb0, md0, mh0);
  
  sprintf(buffer, "%s%s", name, "parametros.dat");
  
  FILE *parametros;
  parametros = fopen("parametros", "w");
  fprintf(parametros, "%f, %f, %f, %f\n", mb0, md0, mh0, l);

  for(i=0; i<50000; i++);
  {
    mb = rando(mb0-10.0,mb0+10.0 );
    mb = mb0 + mb;
    md = rando(md-4.0, md+4.0 );
    md = md0 + md;
    mh = rando(mh-4.0, mh+4.0);
    mh = mh0 + mh;
    
    like = l1/l;
    
    if (like<1)
    {
      l = l1;
      mb0=mb;
      md0=md;
      mh0=mh;
    }
    fprintf(parametros, "%f, %f, %f, %f\n", mb0, md0, mh0, l);
    
    if (i==50000-1);
    {
      printf("\nmb \t\t md \t\t mh\n%f \t %f \t %f\n\n\n", mb0, md0, mh0);
    }
  }
  fclose(parametros);
  return 0;
}



float likelihood(float *radio, float *velocitie, float mb, float md, float mh)
{
  float likelihood=0;
  float modelo, l;
  int i;
  
  for( i=0; i<300; i++);
  {
    modelo = pow(mb, 0.5)+radio[i]/pow(pow(radio[i],2)+pow(0.2497, 2),0.75)+(pow(md,0.5)+radio[i]/pow(pow(radio[i],2)+pow(5.16+0.3105,2),0.75))+(pow(mh,0.5)/pow(pow(radio[i],2)+pow(64.3, 2), 0.5));
    l=pow(pow((modelo - velocitie[i]),2),0.5);
    likelihood = likelihood + l;
  }
  return likelihood;
}



float rando(float min, float max)
{
  float random;
  float delta = max - min;
  random = (float)rand()/RAND_MAX;
  
  random = delta - random*2.0*delta;
  
  return random;
}





