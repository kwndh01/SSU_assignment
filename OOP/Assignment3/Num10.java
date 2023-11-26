import java.util.Scanner;

public class Num10 {
    static class Dictionary {
        private static String[] kor = {"사랑", "아기", "돈", "미래", "희망"};
        private static String[] eng = {"love", "baby", "money", "future", "hope"};

        public static String kor2eng(String word) {
            int find = 0;
            for (int i = 0; i < 5; i++) {
                if (kor[i].equals(word)) {
                    System.out.println(eng[i]);
                    find = 1;
                    break;
                }
            }
            if (find == 0) {
                System.out.println(word + "는 저의 사전에 없습니다.");
            }
            return null;
        }
    }

    static class DicApp {
        Scanner scanner = new Scanner(System.in);

        void run() {
            Dictionary dict = new Dictionary();
            System.out.println("한영 단어 검색 프로그램입니다.");

            while (true) {
                System.out.print("한글 단어?");
                String word = scanner.next();
                if (word.equals("그만")) {
                    break;
                } else {
                    dict.kor2eng(word);
                }
            }

        }
    }

    public static void main(String[] args) {
        DicApp test = new DicApp();
        test.run();
    }
}
