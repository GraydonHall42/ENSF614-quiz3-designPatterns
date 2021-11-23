package DecoratorPattern;

public class Scrollbar extends Decorator{
    private String type;

    public Scrollbar(Widget w, String type) {
        super(w);
        this.type = type;
    }

    @Override
    public void display() {
        widget.display();
        System.out.println("The scrollbar type is: " + type);
    }
}
