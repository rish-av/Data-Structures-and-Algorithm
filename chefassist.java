import java.util.ArrayList;
import java.util.Scanner;
import java.util.Arrays;
public class Main {
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[] nr = new int[n];
            ArrayList<Integer> chef = new ArrayList<Integer>();
            ArrayList<Integer> assist = new ArrayList<Integer>();
            for(int i=0;i<n;i++){
                nr[i] = i+1;
            }
            for(int i=0;i<m;i++){
                int a = sc.nextInt();
                nr[a-1] = -1;
            }
            Arrays.sort(nr);
            for(int i = 0;i<n;i++){
                if(nr[i]!=-1) {
                    if ((n - m) % 2 == 0) {
                        while (i <= n - 2) {
                            chef.add(nr[i]);
                            assist.add(nr[i + 1]);
                            i = i + 2;
                        }
                    }
                    else{
                        while(i<n-2){
                            chef.add(nr[i]);
                            assist.add(nr[i+1]);
                            i = i+2;
                        }
                        chef.add(nr[n-1]);
                    }
                }
                }
                for(int x : chef){
                 System.out.print(x + " ");
                }
                System.out.println();
                for(int x : assist){
                System.out.print(x + " ");
                }
            }

        }

    }

