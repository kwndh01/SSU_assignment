import java.util.Scanner;
import java.lang.String;

public class problem12 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("연산>>");
        int value1 = scanner.nextInt();
        String operator = scanner.next();
        int value2 = scanner.nextInt();
        int result;
        switch (operator) {
            case ("+"):
                result = value1 + value2;
                System.out.println(result);
                break;
            case ("-"):
                result = value1 - value2;
                System.out.println(result);
                break;
            case ("*"):
                result = value1 * value2;
                System.out.println(result);
                break;
            case ("/"):
                switch (value2) {
                    case (0):
                        System.out.println("0으로 나눌 수 없습니다");
                        break;
                    default:
                        result = value1 / value2;
                        System.out.println(result);
                }
        }
        scanner.close();
    }
}
