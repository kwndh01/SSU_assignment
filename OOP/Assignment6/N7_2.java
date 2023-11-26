import java.util.Scanner;
import java.util.ArrayList;


public class N7_2 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("6개의 학점을 빈 칸으로 분리 입력(A/B/C/D/F)>>");

        ArrayList<String> a =new ArrayList<String>();
        for(int i=0; i<6; i++){
            a.add(scanner.next());
        }
        double b = 0;
        for(int i=0; i<6; i++){
            String tmp = a.get(i);
            switch(tmp){
                case "A":
                    b+= 4.0;
                    break;
                case "B":
                    b+= 3.0;
                    break;
                case "C":
                    b+= 2.0;
                    break;
                case "D":
                    b+= 1.0;
                    break;
                case "F":
                    b+= 0.0;
            }
        }
        b = b/6;
        System.out.println(b);
    }
}
