import java.util.Scanner;
public class Num12 {
    static class Program{
        Scanner scanner = new Scanner(System.in);
        public void run(){
            System.out.println("명품콘서트홀 예약 시스템입니다.");
            Seat seat = new Seat();
            while(true) {
                System.out.print("예약:1, 조회:2, 취소:3, 끝내기:4>>");
                int selectNum = scanner.nextInt();
                if(selectNum == 1){
                    System.out.print("좌석구분 S(1), A(2), B(3)>>");
                    int seatVar = scanner.nextInt();
                    if(seatVar == 1){
                        seat.Swrite();
                    }
                    else if(seatVar == 2){
                        seat.Awrite();
                    }
                    else{
                        seat.Bwrite();
                    }
                }
                else if(selectNum == 2){
                    seat.SeatView();
                }
                else if(selectNum == 3){
                    System.out.print("좌석구분 S(1), A(2), B(3)>>");
                    int seatVar = scanner.nextInt();
                    if(seatVar == 1){
                        seat.Sdel();
                    }
                    else if(seatVar == 2){
                        seat.Adel();
                    }
                    else{
                        seat.Bdel();
                    }
                }
                else if(selectNum == 4){
                    break;
                }
            }
        }

    }
    static class Seat{
        Scanner scanner = new Scanner(System.in);
        String [] S = new String[10];
        String [] A = new String[10];
        String [] B = new String[10];

        public Seat(){
            for(int i = 0; i < 10; i++){
                S[i] = "---";
                A[i] = "---";
                B[i] = "---";
            }
        }
        public void Swrite(){
            System.out.print("S>>");
            for(int i = 0; i<10; i++){
                System.out.print(S[i] + " ");
            }
            System.out.print("\n");
            System.out.print("이름>>");
            String inputName = scanner.next();
            System.out.print("번호>>");
            int inputNum = scanner.nextInt();
            if(S[inputNum-1].equals("---")){
                S[inputNum-1] = inputName;
            }
            else{
                System.out.println("이미 등록된 사람이 존재합니다.");
            }

        }
        public void Awrite(){
            System.out.print("A>>");
            for(int i = 0; i<10; i++){
                System.out.print(A[i] + " ");
            }
            System.out.print("\n");
            System.out.print("이름>>");
            String inputName = scanner.next();
            System.out.print("번호>>");
            int inputNum = scanner.nextInt();
            if(A[inputNum-1].equals("---")){
                A[inputNum-1] = inputName;
            }
            else{
                System.out.println("이미 등록된 사람이 존재합니다.");
            }
        }
        public void Bwrite(){
            System.out.print("B>>");
            for(int i = 0; i<10; i++){
                System.out.print(B[i] + " ");
            }
            System.out.print("\n");
            System.out.print("이름>>");
            String inputName = scanner.next();
            System.out.print("번호>>");
            int inputNum = scanner.nextInt();
            if(B[inputNum-1].equals("---")){
                B[inputNum-1] = inputName;
            }
            else{
                System.out.println("이미 등록된 사람이 존재합니다.");
            }
        }
        public void SeatView(){
            System.out.print("S>>");
            for(int j = 0; j<10; j++){
                System.out.print(S[j] + " ");
            }
            System.out.print("\n");
            System.out.print("A>>");
            for(int j = 0; j<10; j++){
                System.out.print(A[j] + " ");
            }
            System.out.print("\n");
            System.out.print("B>>");
            for(int j = 0; j<10; j++){
                System.out.print(B[j] + " ");
            }
            System.out.print("\n");
            System.out.println("<<조회를 완료하였습니다.>>");
        }
        public void Sdel(){
            System.out.print("이름>>");
            String delName = scanner.next();
            int find= 0;
            for(int i = 0; i<10; i++){
                if(delName.equals(S[i])){
                    S[i] = "---";
                    find = 1;
                    break;
                }
            }
            if(find == 0){
                System.out.println("해당 이름은 없습니다.");
            }
        }
        public void Adel(){
            System.out.print("이름>>");
            String delName = scanner.next();
            int find= 0;
            for(int i = 0; i<10; i++){
                if(delName.equals(A[i])){
                    A[i] = "---";
                    find = 1;
                    break;
                }
            }
            if(find == 0){
                System.out.println("해당 이름은 없습니다.");
            }
        }
        public void Bdel(){
            System.out.print("이름>>");
            String delName = scanner.next();
            int find= 0;
            for(int i = 0; i<10; i++){
                if(delName.equals(B[i])){
                    B[i] = "---";
                    find = 1;
                    break;
                }
            }
            if(find == 0){
                System.out.println("해당 이름은 없습니다.");
            }
        }

    }
    public static void main(String[] args){
        Program test = new Program();
        test.run();
    }
}
