

import java.util.Scanner;

public class MatrixUtil {
        static {
            System.load("/home/huy/Desktop/Matrix_prj/Java-Call-C/lib.so");
        }

    native int[][] multiply(int[][] arr1, int[][] arr2);

    public static void main(String[] args) {
        int m,n,k;
        //Input m,n,k
        System.out.println("Input m,n,k: \n");
        m = new Scanner(System.in).nextInt();
        n = new Scanner(System.in).nextInt();
        k = new Scanner(System.in).nextInt();

        int[][] arr1 = new int[m][n];
        int[][] arr2 = new int[n][k];
        MatrixUtil Util = new MatrixUtil();

       //Input Two Matrices
        System.out.println("Input matrix 1:");
        for(int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                arr1[i][j] = new Scanner(System.in).nextInt();
        System.out.println("Input matrix 2:");
        for(int i = 0; i < n; i++)
            for (int j = 0; j < k; j++)
                arr2[i][j] = new Scanner(System.in).nextInt();
       //multiply
        int arr3[][] = Util.multiply(arr1,arr2);

	//Ouput result
        System.out.println("The product of two matrices:");
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++)
                System.out.print(arr3[i][j] + " ");
            System.out.println("");
        }
     }
}
