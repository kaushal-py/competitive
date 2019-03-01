import java.util.Arrays;
import java.util.Scanner;

class AVGPR {
    
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int t = sc.nextInt();

        for(int s=0; s<t; s++){
            int n = sc.nextInt();

            int arr[] = new int[n];

            for(int i=0; i<n; i++){
                arr[i] = sc.nextInt();
            }

            Arrays.sort(arr);
            
            long count = 0;

            for(int x: arr){
                for(int k=0; k<x; k++){
                    if(Arrays.binarySearch(arr, k) > -1){
                        if(Arrays.binarySearch(arr, 2*x-k) > -1){
                            count++;
                        }
                    }
                }
            }

            System.out.println(count);
        }
    }
          
}
