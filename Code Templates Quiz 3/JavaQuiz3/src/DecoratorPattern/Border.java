package DecoratorPattern;

public class Border extends Decorator{
    private int thickness;

    public Border(Widget w, int thickness) {
        super(w);
        this.thickness = thickness;
    }

    @Override
    public void display() {
        widget.display();
        System.out.println("It's border thickness is: " + thickness);
    }
}
