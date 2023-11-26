import java.util.Scanner;

abstract class Shape {
    private Shape next;

    public Shape() {
        next = null;
    }

    public void setNext(Shape obj) {
        next = obj;
    }

    public Shape getNext() {
        return next;
    }

    public abstract void draw();
}

class Line extends Shape {
    @Override
    public void draw() {
        System.out.println("Line");
    }
}

class Rect extends Shape {
    @Override
    public void draw() {
        System.out.println("Rect");
    }
}

class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Circle");
    }
}

class GraphicEditor {
    private Scanner scanner = new Scanner(System.in);
    private Shape pointer;
    private int count;

    public GraphicEditor() {
        pointer = null;
        count = 0;
        while (true) {
            System.out.print("삽입(1), 삭제(2), 모두 보기(3), 종료(4)>>");
            int keyboard = scanner.nextInt();
            if (keyboard == 1) {
                insert();
            } else if (keyboard == 2) {
                delete();
            } else if (keyboard == 3) {
                show();
            } else if (keyboard == 4) {
                end();
                break;
            }
        }
    }

    private void insert() {
        System.out.print("Line(1), Rect(2), Circle(3)>>");
        int value = scanner.nextInt();
        Shape shape;
        if (value == 1) {
            shape = new Line();
        } else if (value == 2) {
            shape = new Rect();
        } else if (value == 3) {
            shape = new Circle();
        } else {
            System.out.println("올바른 값을 입력해주세요.");
            return;
        }

        if (pointer == null) {
            pointer = shape;
        } else {
            Shape temp = pointer;
            while (temp.getNext() != null) {
                temp = temp.getNext();
            }
            temp.setNext(shape);
        }
        count++;
    }

    private void delete() {
        System.out.print("삭제할 도형의 위치 >>");
        int value = scanner.nextInt();
        if (value <= count && value > 0) {
            if (value == 1) {
                pointer = pointer.getNext();
            } else {
                Shape before = pointer;
                Shape current = pointer.getNext();
                for (int i = 2; i < value; i++) {
                    before = current;
                    current = current.getNext();
                }
                before.setNext(current.getNext());
            }
            count--;
        } else {
            System.out.println("삭제할 수 없습니다.");
        }
    }

    private void show() {
        Shape current = pointer;
        while (current != null) {
            current.draw();
            current = current.getNext();
        }
    }

    private void end() {
        System.out.println("beauty을 종료합니다.");
    }
}

public class Num12 {
    public static void main(String[] args) {
        System.out.println("그래픽 에디터 beauty을 실행합니다.");
        GraphicEditor a = new GraphicEditor();
    }
}
