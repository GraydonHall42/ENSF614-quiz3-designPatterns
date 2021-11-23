package BridgePattern;

public class BridgeDemoTest {
    public static void main(String[] args) {
        // Red square
        Shape squareRed = new Square(new Red());
        System.out.println(squareRed.draw());

        // Blue square
        Shape squareBlue = new Square(new Blue());
        System.out.println(squareBlue.draw());

        // Red Triangle
        Shape triangleRed = new Triangle(new Red());
        System.out.println(triangleRed.draw());

        // Blue Triangle
        Shape triangleBlue = new Triangle(new Blue());
        System.out.println(triangleBlue.draw());
    }
}
