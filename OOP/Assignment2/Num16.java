import java.util.Scanner;
import java.lang.String;
import java.util.Random;

public class Num16 {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        String [] Module = {"가위", "바위", "보"};
        Random rand = new Random();
        System.out.println("컴퓨터와 가위 바위 보 게임을 합니다.");
        String user = "";
        while(true){
            System.out.print("가위 바위 보!>>");
            user = scanner.next();
            if (user.equals("그만")){
                break;
            }
            int rd = rand.nextInt(3);
            int verify;
            if (user.equals("바위")) {
                if(Module[rd].equals("바위")){
                    verify = 0;
                } else if (Module[rd].equals("가위")) {
                    verify = 1;
                }
                else{
                    verify = 2;
                }
            }
            else if(user.equals("가위")){
                if(Module[rd].equals("바위")){
                    verify = 2;
                } else if (Module[rd].equals("가위")) {
                    verify = 0;
                }
                else{
                    verify = 1;
                }
            }
            else{
                if(Module[rd].equals("바위")){
                    verify = 1;
                } else if (Module[rd].equals("가위")) {
                    verify = 2;
                }
                else{
                    verify = 0;
                }
            }
            String [] result = {"사용자가 비겼습니다.", "사용자가 이겼습니다.", "사용자가 졌습니다."};
            String computer = result[verify];
            System.out.print("사용자 = " + user + " , " + "컴퓨터 = " + Module[rd] + " , " + computer + "\n");
        }
        System.out.print("게임을 종료합니다...");
    }
}
