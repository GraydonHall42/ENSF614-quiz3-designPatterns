package AdapterPattern;

public class AdapterDemo {
    public static void main(String[] args) {
        Target[] shapes = {
                new RectangleAdapter(new Rectangle()),
                new LineAdapter(new Line())
        };
        int a=10, b=20, c=30, d=60;
        for(Target shape:shapes){
            shape.display(a,b,c,d,"Red");
        }
    }
}
