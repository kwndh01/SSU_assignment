import java.util.Scanner;
public class problem2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("2자리수 정수 입력(10~99)>>");
        int value = scanner.nextInt();
        int ten = value / 10;
        int mod = value - 10 * ten;
        if (ten == mod){
            System.out.println("Yes! 10의 자리와 1의 자리가 같습니다.");
        }
        else{
            System.out.println("No! 10의 자리와 1의 자리가 다릅니다.");
        }
    scanner.close();
    }
}