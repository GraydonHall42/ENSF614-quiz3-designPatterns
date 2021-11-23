package ObserverPattern;

public class Client {
    public static void main(String[] args) {
        Weather w = new Weather(34.5);
        HorizontalDisplay h = new HorizontalDisplay(w);
        VerticalDisplay v = new VerticalDisplay(w);
        w.setTemp(55);
    }
}

/* Output:
Temp horizontally displayed: 34.5
Temp displayed vertically: 34.5
Temp horizontally displayed: 55.0
Temp displayed vertically: 55.0
*/

