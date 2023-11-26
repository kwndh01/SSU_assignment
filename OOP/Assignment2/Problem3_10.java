import java.lang.Math;
public class Problem3_10 {
    public static void main(String[] args){
        int [][] array = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
        int [] temp = new int[10];
        for (int k = 0; k <10; k++){
            temp[k] = (int)(Math.random()*10 + 1);
        }
        int [] address = new int[16];
        for(int i = 0; i < 10; i++){
            int location = (int)(Math.random()*16);
            int x = location / 4;
            int y = location % 4;
            if (array[x][y] == 0){
                array[x][y] = temp[i];
            }
            else{
                i--;
            }
        }
        for (int l = 0; l < 4; l++){
            for (int j = 0; j< 4; j++){
                System.out.print(array[l][j] + " ");
            }
            System.out.print("\n");
        }
    }
}
