#include<stdio.h>
#include<stdlib.h>

void main()
{

  int ix,ia,iz,nx,na,nz;
  float val,stk;

  FILE *in,*out;

  in=fopen("adcigs.dat","rb");

 out=fopen("migration_stkADCIGs40-65.dat","wb");



  nx=711;
  na=65;
  nz=300;

  stk=0.0;

  for(ix=0;ix<nx;ix++)
    for(iz=0;iz<nz;iz++)
    {
       stk=0.0;
      for(ia=0;ia<na;ia++)
       {

        
         fseek(in,(ix*na*nz+ia*nz+iz)*4L,0);fread(&val,4L,1,in);

         if(ia>=40&&ia<65)stk+=val;








       }
      fseek(out,(ix*nz+iz)*4L,0);fwrite(&stk,4L,1,out);
   }


  fclose(in);
  fclose(out);






















}
