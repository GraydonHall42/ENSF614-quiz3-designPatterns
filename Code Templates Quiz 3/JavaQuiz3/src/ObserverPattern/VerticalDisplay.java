package ObserverPattern;

public class VerticalDisplay implements Observer{
    double temp;
    Subject weather;

    public VerticalDisplay(Subject w) {
        this.weather = w;
        w.register(this);
    }

    @Override
    public void update(double temp) {
        this.temp = temp;
        display();
    }

    public void display() {
        System.out.println("Temp displayed vertically: " + temp);
    }
}
