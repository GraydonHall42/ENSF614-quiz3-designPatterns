package AdapterPattern;

// meant to be our legacy code (adaptee class)
public class Line {
    public void display(int x1, int y1, int x2, int y2){
        System.out.println("Coordinates of the lines are " +
                "(" + x1 + "," + y1 + "), and (" + x2 + "," + y2 + ")");
    }
}
