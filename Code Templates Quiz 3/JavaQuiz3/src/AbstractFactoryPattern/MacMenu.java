package AbstractFactoryPattern;

public class MacMenu extends Menu{
    public MacMenu() {
        paint();
    }

    @Override
    public void paint() {
        System.out.println("Mac menu created");
    }
}
