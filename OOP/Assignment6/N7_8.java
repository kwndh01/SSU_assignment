import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;

public class N7_8 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.println("** 포인트 관리 프로그램입니다 **");
        HashMap<String, Integer> h = new HashMap<String, Integer>();
        ArrayList<String> a = new ArrayList<String>();

        while(true){
            System.out.print("이름과 포인트 입력>> ");
            String name = scanner.next();
            if(name.equals("그만")){
                break;
            }
            int point = scanner.nextInt();
            if(h.get(name) != null){
                h.remove(name);
            }
            h.put(name, point);
            a.add(name);

            for(int i=0; i<h.size();i++){
                System.out.print("("+a.get(i)+","+h.get(a.get(i))+")");
            }
            System.out.print("\n");

        }
    }
}
