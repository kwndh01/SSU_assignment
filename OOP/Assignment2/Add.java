public class Add {
    public static void main(String[] args){
        double sum = 0.0;
        for (int i = 0; i < args.length; i++) {
            double temp;
            try {
                temp = Double.parseDouble(args[i]);
            } catch (NumberFormatException e) {
                temp = 0.0;
            }
            sum += temp;
        }
        System.out.println("Sum= " + sum);
    }
}
