package AbstractFactoryPattern;

public class MacApplication extends Application{
    public MacApplication() {
        this.guiFactory = new MacGuiFactory();
    }

    @Override
    void createGuiApplication() {
        guiFactory.createButton("Mac Button");
        guiFactory.createMenu();
    }
}
