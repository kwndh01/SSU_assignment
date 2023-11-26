import java.util.Scanner;

public class Problem8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("문자열을 입력하세요. 빈칸이나 있어도 되고 영어 한글 모두 됩니다.");
        String in = scanner.nextLine();
        StringBuffer st = new StringBuffer(in);
        int length = st.length();
        for (int i = 0; i < length; i++) {
            char temp = st.charAt(0);
            st.delete(0,1);
            st.insert(length-1,temp);
            System.out.println(st);
        }
    }
}