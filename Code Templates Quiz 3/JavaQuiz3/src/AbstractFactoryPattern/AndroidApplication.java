package AbstractFactoryPattern;

public class AndroidApplication extends Application{
    public AndroidApplication() {
        this.guiFactory = new AndroidGuiFactory();
    }

    @Override
    void createGuiApplication() {
        guiFactory.createButton("Android Button");
        guiFactory.createMenu();
    }
}
