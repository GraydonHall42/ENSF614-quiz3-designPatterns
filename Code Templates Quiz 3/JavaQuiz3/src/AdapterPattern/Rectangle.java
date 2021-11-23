package AdapterPattern;

// meant to be our legacy code (adaptee class)
public class Rectangle {
    public void display(int x, int y, int width, int height){
        System.out.println("Coordinates of the Left-corner are " +
                "(" + x + "," + y + "), width: " +
                width + ", height: " + height);
    }
}
