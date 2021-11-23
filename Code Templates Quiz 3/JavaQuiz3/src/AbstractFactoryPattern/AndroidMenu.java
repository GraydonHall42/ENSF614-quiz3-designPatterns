package AbstractFactoryPattern;

public class AndroidMenu extends Menu{
    public AndroidMenu() {
        paint();
    }

    @Override
    public void paint() {
        System.out.println("Android menu created");
    }
}
