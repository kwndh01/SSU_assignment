import java.util.Scanner;

public class Num8 {

    static class Phone{
        private String name;
        private String tel;

        public Phone(String name, String tel){
            this.name = name;
            this.tel = tel;
        }

        String getName(){
            return name;
        }

        String getTel(){
            return tel;
        }
    }

    static class PhoneBook{
        private Phone[] data;
        Scanner scanner = new Scanner(System.in);

        void run() {
            System.out.print("인원수>>");
            int count = scanner.nextInt();
            data = new Phone[count];

            for (int i = 0; i < count; i++) {
                System.out.print("이름과 전화번호(이름과 번호는 빈칸없이 입력)>>");
                String inputName = scanner.next();
                String inputTel = scanner.next();
                data[i] = new Phone(inputName, inputTel);
            }

            System.out.println("저장되었습니다...");

            while(true){
                System.out.print("검색할 이름>>");
                String search = scanner.next();
                if (search.equals("그만")) {
                    break;
                } else {
                    int cantFind = 1;
                    for(int i = 0; i < count; i++) {
                        if (data[i].getName().equals(search)) {
                            System.out.println(search + "의 번호는 " +data[i].getTel());
                            cantFind = 0;
                            break;
                        }
                    }
                    if(cantFind == 1){
                        System.out.println(search + " 이 없습니다.");
                    }
                }
            }
        }
    }

    public static void main(String[] args){
        PhoneBook test = new PhoneBook();
        test.run();
    }
}

