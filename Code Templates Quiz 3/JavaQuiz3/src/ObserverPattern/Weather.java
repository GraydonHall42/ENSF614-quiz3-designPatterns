package ObserverPattern;

import java.util.ArrayList;

public class Weather implements Subject{
    private double temp;
    private ArrayList<Observer> observers;

    public Weather(double temp) {
        observers = new ArrayList<Observer>();
        this.temp = temp;
    }

    @Override
    public void register(Observer o) {
        observers.add(o);
        o.update(temp);
    }

    @Override
    public void remove(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObserver() {
        for (Observer o : observers) {
            o.update(temp);
        }
    }

    public double getTemp() {
        return temp;
    }

    public void setTemp(double temp) {
        this.temp = temp;
        notifyObserver();
    }
}
