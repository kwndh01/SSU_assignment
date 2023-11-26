import java.util.Scanner;
import java.lang.String;
public class Num4{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        System.out.print("소문자 알파벳 하나를 입력하시오>>");
        String stringValue = scanner.next();
        char charValue = stringValue.charAt(0);
        for (char i = charValue; i >= 'a'; i--){
            for (char j = 'a'; j <= i; j++){
                System.out.print(j);
            }
            System.out.print("\n");
        }
    }
}