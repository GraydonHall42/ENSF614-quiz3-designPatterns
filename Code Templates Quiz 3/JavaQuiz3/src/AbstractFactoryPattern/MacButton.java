package AbstractFactoryPattern;

public class MacButton extends Button{
    public MacButton(String type) {
        paint(type);
    }

    @Override
    public void paint(String type) {
        System.out.println(type + " created");
    }
}
