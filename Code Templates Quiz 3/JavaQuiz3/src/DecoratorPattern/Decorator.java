package DecoratorPattern;

abstract class Decorator implements Widget{
    Widget widget;

    public Decorator(Widget w) {
        this.widget = w;
    }
}
