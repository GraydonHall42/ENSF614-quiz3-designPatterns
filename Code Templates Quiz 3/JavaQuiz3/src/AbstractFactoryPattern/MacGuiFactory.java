package AbstractFactoryPattern;


public class MacGuiFactory implements GuiFactory{
    Button b;
    Menu m;

    @Override
    public Button createButton(String label) {
        b = new MacButton(label);
        return b;
    }

    @Override
    public Menu createMenu() {
        m = new MacMenu();
        return m;
    }
}
