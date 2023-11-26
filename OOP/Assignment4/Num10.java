public class Num10 {
    abstract class PairMap{
        protected String keyArray[];
        protected String valueArray[];
        abstract String get(String key);
        abstract void put(String key, String key2);
        abstract String delete(String key);
        abstract int length();
    }
    class Dictionary extends PairMap {
        public Dictionary(int i){
            keyArray = new String[i];
            valueArray = new String[i];
        }
        @Override
        int length() {
            return keyArray.length;
        }

        @Override
        String delete(String key) {
            for(int i=0; i <keyArray.length; i++){
                if(keyArray[i].equals(key) && keyArray[i] != null){
                    String value = valueArray[i];
                    for(int j = i;  j<keyArray.length-1; j++){
                        keyArray[j] = keyArray[j+1];
                        valueArray[j] = valueArray[j+1];
                    }
                    keyArray[keyArray.length - 1] = null;
                    valueArray[keyArray.length - 1] = null;
                    return value;
                }
            }
            return null;
        }

        @Override
        String get(String key) {
            for (int i = 0; i < keyArray.length; i++) {
                if (keyArray[i] != null && keyArray[i].equals(key)) {
                    return valueArray[i];
                }
            }
            return null;
        }


        @Override
        void put(String key, String key2) {
            int checkValue = 0;
            for (int i = 0; i < keyArray.length; i++) {
                if (keyArray[i] != null && keyArray[i].equals(key)) {
                    valueArray[i] = key2;
                    checkValue = 1;
                    break;
                }
            }
            if (checkValue == 0) {
                for (int i = 0; i < keyArray.length; i++) {
                    if (keyArray[i] == null) {
                        keyArray[i] = key;
                        valueArray[i] = key2;
                        break;
                    }
                }
            }
        }
    }
    public static void main(String[] args) {
        Num10 num10 = new Num10();
        Dictionary dic = num10.new Dictionary(10);
        dic.put("황기태", "자바");
        dic.put("이재문", "파이선");
        dic.put("이재문", "C++");
        System.out.println("이재문의 값은 " + dic.get("이재문"));
        System.out.println("황기태의 값은 " + dic.get("황기태"));
        dic.delete("황기태");
        System.out.println("황기태의 값은 " + dic.get("황기태"));
    }
}











