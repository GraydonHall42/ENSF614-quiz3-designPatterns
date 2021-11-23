package ObserverPattern;

public class HorizontalDisplay implements Observer{
    double temp;
    Subject weather;

    public HorizontalDisplay(Subject w) {
        this.weather = w;
        w.register(this);
    }

    @Override
    public void update(double temp) {
        this.temp = temp;
        display();
    }

    public void display() {
        System.out.println("Temp horizontally displayed: " + temp);
    }
}
