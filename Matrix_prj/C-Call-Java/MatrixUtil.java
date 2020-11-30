import java.util.Scanner;

public class MatrixUtil {

        public int[][] multiply ( int[][] arr1, int[][] arr2,int m,int n,int k){
            int[][] arr3 = new int[m][k];
            for (int i = 0; i <= m - 1; i++)
                for (int j = 0; j <= k - 1; j++) {
                    arr3[i][j] = 0;
                    for (int h = 0; h <= n - 1; h++)
                        arr3[i][j] += arr1[i][h] * arr2[h][j];
                }
            return arr3;
        }

}
