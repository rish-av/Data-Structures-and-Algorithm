import java.util.Scanner;
public class Main{
public static void main(String args[]){
 Scanner sc = new Scanner(System.in);
 int t = sc.nextInt();
 while(t-->0){
   int n = sc.nextInt();
   String name[] = new String[n];
   for(int i=0;i<n;i++){
    name[i] = sc.next();
   }
   int namelen[] = new namelen[n];
   for(int i=0;i<n;i++){
    String temp = name[i];
    int count=1;
    int flag=0;
    for(int j=1;j<temp.length;j++){
      char ch = temp.getCharAt(j);
      for(int k=j;k<temp.length;k++){
         if(ch==temp.getCharAt(k)){
           flag=1;
           break;
         }
      }
      for(int m=0;m<j;m++){
        if(ch==temp.getCharAt(m))
        flag=1; 
        break; 
     }
    }
    if(flag==0){
     count++;
    }
    namelen[i] = count;
   }
   namelen = namelen.sort();
   int max = namelen[n-1];
   int j=namelen.length-1;
   while(namelen[j--]==max){
   }
   for(int i=j;j<n;j++){
    String min = name[i];
    if(min.compareTo(name[j])<0){
      min = name[j];
    }
   }
   System.out.println(name[j]);
  }
  
  
 
}
}
