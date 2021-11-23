package AdapterPattern;

public class RectangleAdapter implements Target{
    private Rectangle adaptee;

    public RectangleAdapter(Rectangle adaptee) {
        this.adaptee = adaptee;
    }

    @Override
    public void display(int x, int y, int w, int h, String color) {
        adaptee.display(x, y, w, h);
        System.out.println("and its colour is " + color + "\n");
    }
}