package DecoratorPattern;

public class Text implements Widget{
    String text;
    protected int length;

    public Text(String text) {
        this.text = text;
        length = text.length();
    }

    @Override
    public void display() {
        System.out.println("This is a plain text: " + text + ", and its length is: " + length);
    }
}
