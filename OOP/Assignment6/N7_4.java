import java.util.Scanner;
import java.util.Vector;
public class N7_4 {
    public static void main(String [] args){
        Scanner scanner = new Scanner(System.in);
        Vector<Integer> v = new Vector<Integer>();
        while(true){
            System.out.print("강수량 입력 (0 입력시 종료)>> ");
            int value = scanner.nextInt();
            if(value == 0){
                break;
            }
            v.add(value);
            int b = 0;
            for(int i=0; i<v.size();i++){
                System.out.print(v.get(i) + " ");
                b += v.get(i);
            }
            System.out.println("");
            System.out.println("현재 평균 " + b/v.size());
        }
    }
}
