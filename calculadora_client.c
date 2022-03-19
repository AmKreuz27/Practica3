#include "calculadora.h"
 
 
float calculadora_prog_1(char *host,float n1,float n2,char opr,CLIENT *clnt)
{
  
 float *result_1;
 inputs add_1_arg;
 float *result_2;
 inputs sub_1_arg;
 float *result_3;
 inputs mul_1_arg;
 float *result_4;
 inputs div_1_arg;
 
if(opr=='+'){
 
 add_1_arg.num1=n1;
 add_1_arg.num2=n2;
 add_1_arg.operator=opr;
  
 result_1 = add_1(&add_1_arg, clnt);
 if (result_1 == (float *) NULL) {
 clnt_perror (clnt, "call failed");
 }
 return *result_1;
}
 
else if(opr=='-'){
 
 sub_1_arg.num1=n1;
 sub_1_arg.num2=n2;
 sub_1_arg.operator=opr;
  
 result_2 = sub_1(&sub_1_arg, clnt);
 if (result_2 == (float *) NULL) {
 clnt_perror (clnt, "call failed");
 }
 return *result_2;
}
 
else if(opr=='*'){
 
 mul_1_arg.num1=n1;
 mul_1_arg.num2=n2;
 mul_1_arg.operator=opr;
  
 result_3 = mul_1(&mul_1_arg, clnt);
 if (result_3 == (float *) NULL) {
 clnt_perror (clnt, "call failed");
 }
 return *result_3;
}
 
else if(opr=='/'){
 
 div_1_arg.num1=n1;
 div_1_arg.num2=n2;
 div_1_arg.operator=opr;
  
 if(n2 == 0){
 printf("Divicion de cero no es valida.\n");
 exit(0);
 }else{
  
 result_4 = div_1(&div_1_arg, clnt);
 if (result_4 == (float *) NULL) {
 clnt_perror (clnt, "call failed");
 }
 return *result_4;
 }
}
}
 
int main (int argc, char *argv[])
{
 char *host;
 float a,b;
 char op;
 CLIENT *clnt;
 
 if (argc < 2) {
 printf ("usage: %s server_host\n", argv[0]);
 exit (1);
 }
  
 printf("Bienvenido a la calculadoreichon\n");
 printf("+ for Suma\n-  Resta\n* for Multiplicacion\n/ for Division\n");
 printf("Ingresa un numero :\n");
 scanf("%f",&a);
 printf("Ingresa otro numero :\n");
 scanf("%f",&b);
 printf("Operacion :\n");
 scanf("%s",&op);
  
 host = argv[1];
  
 clnt = clnt_create (host, CALCULADORA_PROG, CALCULADORA_VER, "udp");
  
 if (clnt == NULL) {
 clnt_pcreateerror (host);
 exit (1);
 }
  
 printf("RESULTADO = %f\n",calculadora_prog_1 (host,a,b,op,clnt));
  
 clnt_destroy (clnt);
  
exit (0);
}
