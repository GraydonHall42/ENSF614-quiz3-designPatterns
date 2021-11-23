package AbstractFactoryPattern;

public class AndroidButton extends Button{
    public AndroidButton(String type) {
        paint(type);
    }

    @Override
    public void paint(String type) {
        System.out.println(type + " created");
    }
}
