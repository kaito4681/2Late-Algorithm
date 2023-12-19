//
//2023.10.03 2 main
//
#include <stdio.h>

int main(){
  char s1[50],s2[50],s[100];
  int i,j;
  
  scanf("%s",s1);
  scanf("%s",s2);
  
  for(i = 0;s1[i] != '\0';i++){
    s[i] = s1[i];
  }
  
  for(j = 0;s2[j] != '\0';j++){
    s[i + j] = s2[j];
 }

  printf("%s\n",s);
  
  return 0;
}
