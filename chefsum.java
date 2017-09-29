import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
    Scanner sc  = new Scanner(System.in);
    int t = sc.nextInt();
    while(t-->0){
        int n = sc.nextInt();
        long ar[] = new long[n];
        for(int i=0;i<n;i++){
            ar[i] = sc.nextLong();
        }
        long min = ar[n-1];
        int minind = 0;
        int i;
        for(i=n-1;i>=0;i--){
            if(ar[i]<=min){
                min = ar[i];
                minind = i;
            }
        }
        System.out.println(minind+1);
    }

    }
}

