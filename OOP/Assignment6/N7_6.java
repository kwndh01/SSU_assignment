import java.util.Scanner;
import java.util.HashMap;

class Location {
    private String city;
    private int longitude;
    private int latitude;

    public Location(String city, int longitude, int latitude) {
        this.city = city;
        this.longitude = longitude;
        this.latitude = latitude;
    }

    public String get() {
        String retun = (longitude + " " + latitude);
        return retun;
    }
}

public class N7_6 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, Location> h = new HashMap<String, Location>();
        System.out.println("도시, 경도, 위도를 입력하세요.");
        for (int i = 0; i < 4; i++) {
            System.out.print(">> ");
            String input = scanner.nextLine();
            String[] str = input.split(", ");
            Location l = new Location(str[0], Integer.parseInt(str[1]), Integer.parseInt(str[2]));

            h.put(str[0], l);
        }
        System.out.println("-------------");
        for (String city : h.keySet()) {
            Location location = h.get(city);
            System.out.println(city + " " + location.get());
        }
        System.out.println("-------------");
        while(true){
            System.out.print("도시 이름 >> ");
            String city = scanner.next();
            if(city.equals("그만")){
                break;
            }
            if(h.get(city) != null){
                Location location = h.get(city);
                System.out.println(city + " " + location.get());
            }
            else{
                System.out.println(city +"는 없습니다.");
            }
        }
    }
}
