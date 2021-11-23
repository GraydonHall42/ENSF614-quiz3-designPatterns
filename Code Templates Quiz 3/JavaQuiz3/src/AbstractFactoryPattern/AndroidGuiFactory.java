package AbstractFactoryPattern;

public class AndroidGuiFactory implements GuiFactory{
    Button b;
    Menu m;

    @Override
    public Button createButton(String label) {
        b = new AndroidButton(label);
        return b;
    }

    @Override
    public Menu createMenu() {
        m = new AndroidMenu();
        return m;
    }
}
