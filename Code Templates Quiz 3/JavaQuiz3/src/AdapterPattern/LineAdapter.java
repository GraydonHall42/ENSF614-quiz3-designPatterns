package AdapterPattern;

public class LineAdapter implements Target{
    private Line adaptee;

    public LineAdapter(Line adaptee) {
        this.adaptee = adaptee;
    }

    @Override
    public void display(int x1, int y1, int x2, int y2, String color) {
        adaptee.display(x1, y1, x2, y2);
        System.out.println("and its colour is " + color + "\n");
    }
}
